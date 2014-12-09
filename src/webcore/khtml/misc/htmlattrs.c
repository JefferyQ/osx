/* ANSI-C code produced by gperf version 2.7.2 */
/* Command-line: gperf -c -a -L ANSI-C -D -E -C -o -t -k '*' -NfindAttr -Hhash_attr -Wwordlist_attr -s 2 htmlattrs.gperf  */
/* This file is automatically generated from
#htmlattrs.in by makeattrs, do not edit */
/* Copyright 1999 Lars Knoll */
#include "htmlattrs.h"
struct attrs {
    const char *name;
    int id;
};
/* maximum key range = 898, duplicates = 1 */

#ifdef __GNUC__
__inline
#else
#ifdef __cplusplus
inline
#endif
#endif
static unsigned int
hash_attr (register const char *str, register unsigned int len)
{
  static const unsigned short asso_values[] =
    {
      922, 922, 922, 922, 922, 922, 922, 922, 922, 922,
      922, 922, 922, 922, 922, 922, 922, 922, 922, 922,
      922, 922, 922, 922, 922, 922, 922, 922, 922, 922,
      922, 922, 922, 922, 922, 922, 922, 922, 922, 922,
      922, 922, 922, 922, 922,   0, 922, 922, 922, 922,
      922, 922, 922, 922, 922, 922, 922, 922, 922, 922,
      922, 922, 922, 922, 922, 922, 922, 922, 922, 922,
      922, 922, 922, 922, 922, 922, 922, 922, 922, 922,
      922, 922, 922, 922, 922, 922, 922, 922, 922, 922,
      922, 922, 922, 922, 922, 922, 922,  20,  35,   0,
      195,   0,  35,  40,  95,  15,   5,  55,   0,  70,
        0,   0,  45,   0, 185,  20,  15,  65,  80,  40,
       10, 140,  45, 922, 922, 922, 922, 922, 922, 922,
      922, 922, 922, 922, 922, 922, 922, 922, 922, 922,
      922, 922, 922, 922, 922, 922, 922, 922, 922, 922,
      922, 922, 922, 922, 922, 922, 922, 922, 922, 922,
      922, 922, 922, 922, 922, 922, 922, 922, 922, 922,
      922, 922, 922, 922, 922, 922, 922, 922, 922, 922,
      922, 922, 922, 922, 922, 922, 922, 922, 922, 922,
      922, 922, 922, 922, 922, 922, 922, 922, 922, 922,
      922, 922, 922, 922, 922, 922, 922, 922, 922, 922,
      922, 922, 922, 922, 922, 922, 922, 922, 922, 922,
      922, 922, 922, 922, 922, 922, 922, 922, 922, 922,
      922, 922, 922, 922, 922, 922, 922, 922, 922, 922,
      922, 922, 922, 922, 922, 922, 922, 922, 922, 922,
      922, 922, 922, 922, 922, 922
    };
  register int hval = len;

  switch (hval)
    {
      default:
      case 14:
        hval += asso_values[(unsigned char)str[13]];
      case 13:
        hval += asso_values[(unsigned char)str[12]];
      case 12:
        hval += asso_values[(unsigned char)str[11]];
      case 11:
        hval += asso_values[(unsigned char)str[10]];
      case 10:
        hval += asso_values[(unsigned char)str[9]];
      case 9:
        hval += asso_values[(unsigned char)str[8]];
      case 8:
        hval += asso_values[(unsigned char)str[7]];
      case 7:
        hval += asso_values[(unsigned char)str[6]];
      case 6:
        hval += asso_values[(unsigned char)str[5]];
      case 5:
        hval += asso_values[(unsigned char)str[4]];
      case 4:
        hval += asso_values[(unsigned char)str[3]];
      case 3:
        hval += asso_values[(unsigned char)str[2]];
      case 2:
        hval += asso_values[(unsigned char)str[1]];
      case 1:
        hval += asso_values[(unsigned char)str[0]];
        break;
    }
  return hval;
}

#ifdef __GNUC__
__inline
#endif
const struct attrs *
findAttr (register const char *str, register unsigned int len)
{
  enum
    {
      TOTAL_KEYWORDS = 144,
      MIN_WORD_LENGTH = 2,
      MAX_WORD_LENGTH = 14,
      MIN_HASH_VALUE = 24,
      MAX_HASH_VALUE = 921
    };

  static const struct attrs wordlist_attr[] =
    {
      {"cols", ATTR_COLS},
      {"cite", ATTR_CITE},
      {"content", ATTR_CONTENT},
      {"alt", ATTR_ALT},
      {"onselect", ATTR_ONSELECT},
      {"text", ATTR_TEXT},
      {"title", ATTR_TITLE},
      {"left", ATTR_LEFT},
      {"action", ATTR_ACTION},
      {"face", ATTR_FACE},
      {"label", ATTR_LABEL},
      {"object", ATTR_OBJECT},
      {"top", ATTR_TOP},
      {"lang", ATTR_LANG},
      {"class", ATTR_CLASS},
      {"axis", ATTR_AXIS},
      {"scope", ATTR_SCOPE},
      {"link", ATTR_LINK},
      {"onclick", ATTR_ONCLICK},
      {"align", ATTR_ALIGN},
      {"size", ATTR_SIZE},
      {"plain", ATTR_PLAIN},
      {"accept", ATTR_ACCEPT},
      {"span", ATTR_SPAN},
      {"colspan", ATTR_COLSPAN},
      {"name", ATTR_NAME},
      {"alink", ATTR_ALINK},
      {"pagex", ATTR_PAGEX},
      {"nosave", ATTR_NOSAVE},
      {"onfocus", ATTR_ONFOCUS},
      {"cellspacing", ATTR_CELLSPACING},
      {"vlink", ATTR_VLINK},
      {"compact", ATTR_COMPACT},
      {"valign", ATTR_VALIGN},
      {"onchange", ATTR_ONCHANGE},
      {"challenge", ATTR_CHALLENGE},
      {"unknown", ATTR_UNKNOWN},
      {"value", ATTR_VALUE},
      {"vspace", ATTR_VSPACE},
      {"ismap", ATTR_ISMAP},
      {"style", ATTR_STYLE},
      {"html", ATTR_HTML},
      {"shape", ATTR_SHAPE},
      {"hspace", ATTR_HSPACE},
      {"rel", ATTR_REL},
      {"color", ATTR_COLOR},
      {"scheme", ATTR_SCHEME},
      {"language", ATTR_LANGUAGE},
      {"code", ATTR_CODE},
      {"type", ATTR_TYPE},
      {"enctype", ATTR_ENCTYPE},
      {"src", ATTR_SRC},
      {"clear", ATTR_CLEAR},
      {"id", ATTR_ID},
      {"multiple", ATTR_MULTIPLE},
      {"onload", ATTR_ONLOAD},
      {"for", ATTR_FOR},
      {"usemap", ATTR_USEMAP},
      {"onreset", ATTR_ONRESET},
      {"onsubmit", ATTR_ONSUBMIT},
      {"selected", ATTR_SELECTED},
      {"autocomplete", ATTR_AUTOCOMPLETE},
      {"onmouseout", ATTR_ONMOUSEOUT},
      {"rows", ATTR_ROWS},
      {"pagey", ATTR_PAGEY},
      {"data", ATTR_DATA},
      {"maxlength", ATTR_MAXLENGTH},
      {"start", ATTR_START},
      {"onabort", ATTR_ONABORT},
      {"longdesc", ATTR_LONGDESC},
      {"accesskey", ATTR_ACCESSKEY},
      {"height", ATTR_HEIGHT},
      {"bgcolor", ATTR_BGCOLOR},
      {"rev", ATTR_REV},
      {"scrolling", ATTR_SCROLLING},
      {"z-index", ATTR_Z_INDEX},
      {"noresize", ATTR_NORESIZE},
      {"onresize", ATTR_ONRESIZE},
      {"onmouseup", ATTR_ONMOUSEUP},
      {"rules", ATTR_RULES},
      {"classid", ATTR_CLASSID},
      {"codebase", ATTR_CODEBASE},
      {"abbr", ATTR_ABBR},
      {"pluginpage", ATTR_PLUGINPAGE},
      {"target", ATTR_TARGET},
      {"profile", ATTR_PROFILE},
      {"onunload", ATTR_ONUNLOAD},
      {"onblur", ATTR_ONBLUR},
      {"wrap", ATTR_WRAP},
      {"nowrap", ATTR_NOWRAP},
      {"tabindex", ATTR_TABINDEX},
      {"pluginspage", ATTR_PLUGINSPAGE},
      {"char", ATTR_CHAR},
      {"media", ATTR_MEDIA},
      {"version", ATTR_VERSION},
      {"ondblclick", ATTR_ONDBLCLICK},
      {"onkeyup", ATTR_ONKEYUP},
      {"frame", ATTR_FRAME},
      {"onmousemove", ATTR_ONMOUSEMOVE},
      {"rowspan", ATTR_ROWSPAN},
      {"href", ATTR_HREF},
      {"nohref", ATTR_NOHREF},
      {"noshade", ATTR_NOSHADE},
      {"datetime", ATTR_DATETIME},
      {"http-equiv", ATTR_HTTP_EQUIV},
      {"charset", ATTR_CHARSET},
      {"checked", ATTR_CHECKED},
      {"visibility", ATTR_VISIBILITY},
      {"width", ATTR_WIDTH},
      {"prompt", ATTR_PROMPT},
      {"valuetype", ATTR_VALUETYPE},
      {"charoff", ATTR_CHAROFF},
      {"method", ATTR_METHOD},
      {"hreflang", ATTR_HREFLANG},
      {"leftmargin", ATTR_LEFTMARGIN},
      {"dir", ATTR_DIR},
      {"topmargin", ATTR_TOPMARGIN},
      {"onmousedown", ATTR_ONMOUSEDOWN},
      {"archive", ATTR_ARCHIVE},
      {"codetype", ATTR_CODETYPE},
      {"coords", ATTR_COORDS},
      {"declare", ATTR_DECLARE},
      {"defer", ATTR_DEFER},
      {"pluginurl", ATTR_PLUGINURL},
      {"accept-charset", ATTR_ACCEPT_CHARSET},
      {"onmouseover", ATTR_ONMOUSEOVER},
      {"standby", ATTR_STANDBY},
      {"onkeydown", ATTR_ONKEYDOWN},
      {"onkeypress", ATTR_ONKEYPRESS},
      {"oversrc", ATTR_OVERSRC},
      {"disabled", ATTR_DISABLED},
      {"hidden", ATTR_HIDDEN},
      {"cellpadding", ATTR_CELLPADDING},
      {"headers", ATTR_HEADERS},
      {"readonly", ATTR_READONLY},
      {"onerror", ATTR_ONERROR},
      {"summary", ATTR_SUMMARY},
      {"bgproperties", ATTR_BGPROPERTIES},
      {"marginheight", ATTR_MARGINHEIGHT},
      {"background", ATTR_BACKGROUND},
      {"border", ATTR_BORDER},
      {"marginwidth", ATTR_MARGINWIDTH},
      {"bordercolor", ATTR_BORDERCOLOR},
      {"frameborder", ATTR_FRAMEBORDER}
    };

  static const short lookup[] =
    {
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
         0,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,    1,   -1,   -1,    2,    3,   -1,
        -1,   -1,   -1,    4,    5,   -1,   -1,   -1,
        -1,   -1,    6,   -1,   -1,   -1,    7,   -1,
         8,   -1,   -1,    9,   10,   11,   -1,   12,
        13,   14,   -1,   -1,   -1,   15,   16,   -1,
        -1,   -1,   17,   -1,   -1,   18,   -1,   -1,
        19,   -1,   -1,   -1,   20,   21,   22,   -1,
        -1,   23,   -1,   -1,   24,   -1,   25,   26,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        27,   -1,   -1,   -1,   -1,   -1,   28,   29,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   30,
        -1,   -1,   -1,   31,   -1,   32,   -1,   -1,
        -1,   33,   -1,   34,   35,   -1,   -1,   36,
        -1,   -1,   37,   38,   -1,   -1,   -1,   39,
        -1,   -1,   -1,   -1,   40,   -1,   -1,   -1,
        41,   42,   43,   -1,   44,   -1,   45,   46,
        -1,   47,   -1,   -1,   -1,   -1,   -1,   48,
        -1,   -1,   -1,   -1,   49,   -1,   -1,   50,
        51,   -1,   52,   -1,   53,   -1,   -1,   -1,
        -1,   -1,   54,   -1,   -1,   55,   -1,   56,
        -1,   -1,   57,   58,   59,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   60,   -1,
        -1,   -1,   61,   -1,   -1,   62,   -1,   -1,
        -1,   63,   64,   -1,   -1,   -1,   65,   -1,
        -1,   -1,   -1,   66,   67,   -1,   68,   69,
        70,   -1,   71,   72,   73,   74,   -1,   -1,
        75, -427,   78,   79,   -1,   80,   81,   82,
        83,   84,  -68,   -2,   -1,   -1,   -1,   85,
        86,   -1,   -1,   87,   -1,   -1,   88,   -1,
        89,   -1,   90,   -1,   -1,   91,   -1,   -1,
        92,   93,   -1,   94,   -1,   -1,   95,   -1,
        96,   -1,   -1,   97,   98,   99,   -1,  100,
        -1,  101,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,  102,  103,   -1,  104,   -1,  105,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
       106,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
       107,   -1,   -1,   -1,   -1,  108,  109,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,  110,   -1,
        -1,  111,   -1,   -1,   -1,  112,   -1,  113,
        -1,   -1,   -1,   -1,   -1,   -1,  114,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,  115,  116,
        -1,  117,  118,  119,   -1,   -1,  120,  121,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,  122,   -1,   -1,   -1,
       123,   -1,   -1,   -1,   -1,  124,   -1,  125,
       126,   -1,   -1,   -1,   -1,   -1,   -1,  127,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,  128,   -1,  129,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
       130,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,  131,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,  132,  133,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,  134,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,  135,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,  136,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,  137,   -1,   -1,
        -1,   -1,  138,   -1,   -1,  139,  140,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,  141,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,  142,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,  143
    };

  if (len <= MAX_WORD_LENGTH && len >= MIN_WORD_LENGTH)
    {
      register int key = hash_attr (str, len);

      if (key <= MAX_HASH_VALUE && key >= 0)
        {
          register int index = lookup[key];

          if (index >= 0)
            {
              register const char *s = wordlist_attr[index].name;

              if (*str == *s && !strncmp (str + 1, s + 1, len - 1) && s[len] == '\0')
                return &wordlist_attr[index];
            }
          else if (index < -TOTAL_KEYWORDS)
            {
              register int offset = - 1 - TOTAL_KEYWORDS - index;
              register const struct attrs *wordptr = &wordlist_attr[TOTAL_KEYWORDS + lookup[offset]];
              register const struct attrs *wordendptr = wordptr + -lookup[offset + 1];

              while (wordptr < wordendptr)
                {
                  register const char *s = wordptr->name;

                  if (*str == *s && !strncmp (str + 1, s + 1, len - 1) && s[len] == '\0')
                    return wordptr;
                  wordptr++;
                }
            }
        }
    }
  return 0;
}


static const char * const attrList[] = {
    "ABBR",
    "ACCEPT-CHARSET",
    "ACCEPT",
    "ACCESSKEY",
    "ACTION",
    "ALIGN",
    "ALINK",
    "ALT",
    "ARCHIVE",
    "AUTOCOMPLETE",
    "AXIS",
    "BACKGROUND",
    "BGCOLOR",
    "BGPROPERTIES",
    "BORDER",
    "BORDERCOLOR",
    "CELLPADDING",
    "CELLSPACING",
    "CHAR",
    "CHALLENGE",
    "CHAROFF",
    "CHARSET",
    "CHECKED",
    "CITE",
    "CLASS",
    "CLASSID",
    "CLEAR",
    "CODE",
    "CODEBASE",
    "CODETYPE",
    "COLOR",
    "COLS",
    "COLSPAN",
    "COMPACT",
    "CONTENT",
    "COORDS",
    "DATA",
    "DATETIME",
    "DECLARE",
    "DEFER",
    "DIR",
    "DISABLED",
    "ENCTYPE",
    "FACE",
    "FOR",
    "FRAME",
    "FRAMEBORDER",
    "HEADERS",
    "HEIGHT",
    "HIDDEN",
    "HREF",
    "HREFLANG",
    "HSPACE",
    "HTML",
    "HTTP-EQUIV",
    "ID",
    "ISMAP",
    "LABEL",
    "LANG",
    "LANGUAGE",
    "LEFT",
    "LEFTMARGIN",
    "LINK",
    "LONGDESC",
    "MARGINHEIGHT",
    "MARGINWIDTH",
    "MAXLENGTH",
    "MEDIA",
    "METHOD",
    "MULTIPLE",
    "NAME",
    "NOHREF",
    "NORESIZE",
    "NOSAVE",
    "NOSHADE",
    "NOWRAP",
    "OBJECT",
    "ONABORT",
    "ONBLUR",
    "ONCHANGE",
    "ONCLICK",
    "ONDBLCLICK",
    "ONERROR",
    "ONFOCUS",
    "ONKEYDOWN",
    "ONKEYPRESS",
    "ONKEYUP",
    "ONLOAD",
    "ONMOUSEDOWN",
    "ONMOUSEMOVE",
    "ONMOUSEOUT",
    "ONMOUSEOVER",
    "ONMOUSEUP",
    "ONRESET",
    "ONRESIZE",
    "ONSELECT",
    "ONSUBMIT",
    "ONUNLOAD",
    "OVERSRC",
    "PAGEX",
    "PAGEY",
    "PLAIN",
    "PLUGINPAGE",
    "PLUGINSPAGE",
    "PLUGINURL",
    "PROFILE",
    "PROMPT",
    "READONLY",
    "REL",
    "REV",
    "ROWS",
    "ROWSPAN",
    "RULES",
    "SCHEME",
    "SCOPE",
    "SCROLLING",
    "SELECTED",
    "SHAPE",
    "SIZE",
    "SPAN",
    "SRC",
    "STANDBY",
    "START",
    "STYLE",
    "SUMMARY",
    "TABINDEX",
    "TARGET",
    "TEXT",
    "TITLE",
    "TOP",
    "TOPMARGIN",
    "TYPE",
    "UNKNOWN",
    "USEMAP",
    "VALIGN",
    "VALUE",
    "VALUETYPE",
    "VERSION",
    "VISIBILITY",
    "VLINK",
    "VSPACE",
    "WIDTH",
    "WRAP",
    "Z-INDEX",
    0
};
DOMString getAttrName(unsigned short id)
{
    return attrList[id-1];
};
