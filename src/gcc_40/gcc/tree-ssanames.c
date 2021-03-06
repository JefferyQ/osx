/* Generic routines for manipulating SSA_NAME expressions
   Copyright (C) 2003, 2004 Free Software Foundation, Inc.
                                                                                
This file is part of GCC.
                                                                                
GCC is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2, or (at your option)
any later version.
                                                                                
GCC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
                                                                                
You should have received a copy of the GNU General Public License
along with GCC; see the file COPYING.  If not, write to
the Free Software Foundation, 59 Temple Place - Suite 330,
Boston, MA 02111-1307, USA.  */
                                                                                
#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "tm.h"
#include "tree.h"
#include "varray.h"
#include "ggc.h"
#include "tree-flow.h"

/* Rewriting a function into SSA form can create a huge number of SSA_NAMEs,
   many of which may be thrown away shortly after their creation if jumps
   were threaded through PHI nodes.  

   While our garbage collection mechanisms will handle this situation, it
   is extremely wasteful to create nodes and throw them away, especially
   when the nodes can be reused.

   For PR 8361, we can significantly reduce the number of nodes allocated
   and thus the total amount of memory allocated by managing SSA_NAMEs a
   little.  This additionally helps reduce the amount of work done by the
   garbage collector.  Similar results have been seen on a wider variety
   of tests (such as the compiler itself).

   Right now we maintain our free list on a per-function basis.  It may
   or may not make sense to maintain the free list for the duration of
   a compilation unit. 

   External code should rely solely upon HIGHEST_SSA_VERSION and the
   externally defined functions.  External code should not know about
   the details of the free list management.

   External code should also not assume the version number on nodes is
   monotonically increasing.  We reuse the version number when we
   reuse an SSA_NAME expression.  This helps keep arrays and bitmaps
   more compact.

   We could also use a zone allocator for these objects since they have
   a very well defined lifetime.  If someone wants to experiment with that
   this is the place to try it.  */
   
/* Array of all SSA_NAMEs used in the function.  */
varray_type ssa_names;

/* Bitmap of ssa names marked for rewriting.  */
bitmap ssa_names_to_rewrite;

/* Free list of SSA_NAMEs.  This list is wiped at the end of each function
   after we leave SSA form.  */
static GTY (()) tree free_ssanames;

/* Version numbers with special meanings.  We start allocating new version
   numbers after the special ones.  */
#define UNUSED_NAME_VERSION 0

#ifdef GATHER_STATISTICS
unsigned int ssa_name_nodes_reused;
unsigned int ssa_name_nodes_created;
#endif

/* Returns true if ssa name VAR is marked for rewrite.  */

bool
marked_for_rewrite_p (tree var)
{
  if (ssa_names_to_rewrite
      && bitmap_bit_p (ssa_names_to_rewrite, SSA_NAME_VERSION (var)))
    return true;

  return false;
}

/* Returns true if any ssa name is marked for rewrite.  */

bool
any_marked_for_rewrite_p (void)
{
  if (!ssa_names_to_rewrite)
    return false;

  return bitmap_first_set_bit (ssa_names_to_rewrite) != -1;
}

/* Mark ssa name VAR for rewriting.  */

void
mark_for_rewrite (tree var)
{
  if (!ssa_names_to_rewrite)
    ssa_names_to_rewrite = BITMAP_XMALLOC ();

  bitmap_set_bit (ssa_names_to_rewrite, SSA_NAME_VERSION (var));
}

/* Unmark all ssa names marked for rewrite.  */

void
unmark_all_for_rewrite (void)
{
  if (!ssa_names_to_rewrite)
    return;

  bitmap_clear (ssa_names_to_rewrite);
}

/* Return the bitmap of ssa names to rewrite.  Copy the bitmap,
   so that the optimizers cannot access internals directly  */

bitmap
marked_ssa_names (void)
{
  bitmap ret = BITMAP_XMALLOC ();
  if (ssa_names_to_rewrite)
    bitmap_copy (ret, ssa_names_to_rewrite);

  return ret;
}

/* Initialize management of SSA_NAMEs.  */

void
init_ssanames (void)
{
  VARRAY_TREE_INIT (ssa_names, 50, "ssa_names table");

  /* Version 0 is special, so reserve the first slot in the table.  Though
     currently unused, we may use version 0 in alias analysis as part of
     the heuristics used to group aliases when the alias sets are too
     large.  */
  VARRAY_PUSH_TREE (ssa_names, NULL_TREE);
  free_ssanames = NULL;
}

/* Finalize management of SSA_NAMEs.  */

void
fini_ssanames (void)
{
  ggc_free (ssa_names);
  ssa_names = NULL;
  free_ssanames = NULL;
}

/* Dump some simple statistics regarding the re-use of SSA_NAME nodes.  */

#ifdef GATHER_STATISTICS
void
ssanames_print_statistics (void)
{
  fprintf (stderr, "SSA_NAME nodes allocated: %u\n", ssa_name_nodes_created);
  fprintf (stderr, "SSA_NAME nodes reused: %u\n", ssa_name_nodes_reused);
}
#endif

/* Return an SSA_NAME node for variable VAR defined in statement STMT.
   STMT may be an empty statement for artificial references (e.g., default
   definitions created when a variable is used without a preceding
   definition).  */

tree
make_ssa_name (tree var, tree stmt)
{
  tree t;

  gcc_assert (DECL_P (var)
	      || TREE_CODE (var) == INDIRECT_REF);

  gcc_assert (!stmt || EXPR_P (stmt) || TREE_CODE (stmt) == PHI_NODE);

  /* If our free list has an element, then use it.  */
  if (free_ssanames)
    {
      t = free_ssanames;
      free_ssanames = TREE_CHAIN (free_ssanames);
#ifdef GATHER_STATISTICS
      ssa_name_nodes_reused++;
#endif

      /* The node was cleared out when we put it on the free list, so
	 there is no need to do so again here.  */
      gcc_assert (ssa_name (SSA_NAME_VERSION (t)) == NULL);
      VARRAY_TREE (ssa_names, SSA_NAME_VERSION (t)) = t;
    }
  else
    {
      t = make_node (SSA_NAME);
      SSA_NAME_VERSION (t) = num_ssa_names;
      VARRAY_PUSH_TREE (ssa_names, t);
#ifdef GATHER_STATISTICS
      ssa_name_nodes_created++;
#endif
    }

  TREE_TYPE (t) = TREE_TYPE (var);
  SSA_NAME_VAR (t) = var;
  SSA_NAME_DEF_STMT (t) = stmt;
  SSA_NAME_PTR_INFO (t) = NULL;
  SSA_NAME_IN_FREE_LIST (t) = 0;

  return t;
}


/* We no longer need the SSA_NAME expression VAR, release it so that
   it may be reused. 

   Note it is assumed that no calls to make_ssa_name will be made
   until all uses of the ssa name are released and that the only
   use of the SSA_NAME expression is to check its SSA_NAME_VAR.  All
   other fields must be assumed clobbered.  */

void
release_ssa_name (tree var)
{
  if (!var)
    return;

  /* Never release the default definition for a symbol.  It's a
     special SSA name that should always exist once it's created.  */
  if (var == var_ann (SSA_NAME_VAR (var))->default_def)
    return;

  /* If the ssa name is marked for rewriting, it may have multiple definitions,
     but we may happen to remove just one of them.  So do not remove the
     ssa name now.  */
  if (marked_for_rewrite_p (var))
    return;

  /* release_ssa_name can be called multiple times on a single SSA_NAME.
     However, it should only end up on our free list one time.   We
     keep a status bit in the SSA_NAME node itself to indicate it has
     been put on the free list. 

     Note that once on the freelist you can not reference the SSA_NAME's
     defining statement.  */
  if (! SSA_NAME_IN_FREE_LIST (var))
    {
      tree saved_ssa_name_var = SSA_NAME_VAR (var);
      int saved_ssa_name_version = SSA_NAME_VERSION (var);

      VARRAY_TREE (ssa_names, SSA_NAME_VERSION (var)) = NULL;
      memset (var, 0, tree_size (var));

      /* First put back the right tree node so that the tree checking
	 macros do not complain.  */
      TREE_SET_CODE (var, SSA_NAME);

      /* Restore the version number.  */
      SSA_NAME_VERSION (var) = saved_ssa_name_version;

      /* Hopefully this can go away once we have the new incremental
         SSA updating code installed.  */
      SSA_NAME_VAR (var) = saved_ssa_name_var;

      /* Note this SSA_NAME is now in the first list.  */
      SSA_NAME_IN_FREE_LIST (var) = 1;

      /* And finally link it into the free list.  */
      TREE_CHAIN (var) = free_ssanames;
      free_ssanames = var;
    }
}

/* Creates a duplicate of a ssa name NAME defined in statement STMT.  */

tree
duplicate_ssa_name (tree name, tree stmt)
{
  tree new_name = make_ssa_name (SSA_NAME_VAR (name), stmt);
  struct ptr_info_def *old_ptr_info = SSA_NAME_PTR_INFO (name);
  struct ptr_info_def *new_ptr_info;

  if (!old_ptr_info)
    return new_name;

  new_ptr_info = ggc_alloc (sizeof (struct ptr_info_def));
  *new_ptr_info = *old_ptr_info;

  if (old_ptr_info->pt_vars)
    {
      new_ptr_info->pt_vars = BITMAP_GGC_ALLOC ();
      bitmap_copy (new_ptr_info->pt_vars, old_ptr_info->pt_vars);
    }

  SSA_NAME_PTR_INFO (new_name) = new_ptr_info;
  return new_name;
}


/* Release all the SSA_NAMEs created by STMT.  */

void
release_defs (tree stmt)
{
  tree def;
  ssa_op_iter iter;

  FOR_EACH_SSA_TREE_OPERAND (def, stmt, iter, SSA_OP_ALL_DEFS)
    if (TREE_CODE (def) == SSA_NAME)
      release_ssa_name (def);
}


/* Replace the symbol associated with SSA_NAME with SYM.  */

void
replace_ssa_name_symbol (tree ssa_name, tree sym)
{
  SSA_NAME_VAR (ssa_name) = sym;
  TREE_TYPE (ssa_name) = TREE_TYPE (sym);
}

#include "gt-tree-ssanames.h"
