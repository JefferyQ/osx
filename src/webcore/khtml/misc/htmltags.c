/* ANSI-C code produced by gperf version 2.7.2 */
/* Command-line: gperf -a -L ANSI-C -D -E -C -l -o -t -k '*' -NfindTag -Hhash_tag -Wwordlist_tag htmltags.gperf  */
/* This file is automatically generated from htmltags.in by maketags, do not edit */
/* Copyright 1999 Lars Knoll */
#include "htmltags.h"
struct tags {
    const char *name;
    int id;
};
/* maximum key range = 305, duplicates = 1 */

#ifdef __GNUC__
__inline
#else
#ifdef __cplusplus
inline
#endif
#endif
static unsigned int
hash_tag (register const char *str, register unsigned int len)
{
  static const unsigned short asso_values[] =
    {
      306, 306, 306, 306, 306, 306, 306, 306, 306, 306,
      306, 306, 306, 306, 306, 306, 306, 306, 306, 306,
      306, 306, 306, 306, 306, 306, 306, 306, 306, 306,
      306, 306, 306, 306, 306, 306, 306, 306, 306, 306,
      306, 306, 306, 306, 306, 306, 306, 306, 306,  25,
       30,  35,  40,  10,  15, 306, 306, 306, 306, 306,
      306, 306, 306, 306, 306, 306, 306, 306, 306, 306,
      306, 306, 306, 306, 306, 306, 306, 306, 306, 306,
      306, 306, 306, 306, 306, 306, 306, 306, 306, 306,
      306, 306, 306, 306, 306, 306, 306,   0,   5,  30,
       35,   0, 105,   5,  47,  10,   0,  25,  45,  30,
       15,   0, 100,  25,   5,  30,   0,  87,  90,   0,
       20, 115, 306, 306, 306, 306, 306, 306, 306, 306,
      306, 306, 306, 306, 306, 306, 306, 306, 306, 306,
      306, 306, 306, 306, 306, 306, 306, 306, 306, 306,
      306, 306, 306, 306, 306, 306, 306, 306, 306, 306,
      306, 306, 306, 306, 306, 306, 306, 306, 306, 306,
      306, 306, 306, 306, 306, 306, 306, 306, 306, 306,
      306, 306, 306, 306, 306, 306, 306, 306, 306, 306,
      306, 306, 306, 306, 306, 306, 306, 306, 306, 306,
      306, 306, 306, 306, 306, 306, 306, 306, 306, 306,
      306, 306, 306, 306, 306, 306, 306, 306, 306, 306,
      306, 306, 306, 306, 306, 306, 306, 306, 306, 306,
      306, 306, 306, 306, 306, 306, 306, 306, 306, 306,
      306, 306, 306, 306, 306, 306, 306, 306, 306, 306,
      306, 306, 306, 306, 306, 306
    };
  register int hval = len;

  switch (hval)
    {
      default:
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
const struct tags *
findTag (register const char *str, register unsigned int len)
{
  enum
    {
      TOTAL_KEYWORDS = 104,
      MIN_WORD_LENGTH = 1,
      MAX_WORD_LENGTH = 10,
      MIN_HASH_VALUE = 1,
      MAX_HASH_VALUE = 305
    };

  static const unsigned char lengthtable[] =
    {
       1,  2,  1,  2,  4,  1,  2,  3,  4,  3,  1,  4,  1,  2,
       8,  4,  2,  2,  4,  6,  3,  4,  2,  3,  2,  5,  3,  2,
       5,  6,  2,  3,  2,  5,  6,  2,  3,  4,  2,  2,  5,  6,
       3,  2,  2,  3,  2,  4,  5,  1,  2,  7,  3,  4,  5,  1,
       6,  6,  3,  5,  6,  6,  7,  4,  3,  4,  7,  6,  3,  2,
       4,  3,  5,  7,  4,  5,  4,  3,  7,  5,  6,  3,  4,  5,
       7,  8,  4,  6,  5,  8,  6,  7,  8,  5,  8,  9,  7,  5,
       3, 10,  8,  6,  8,  8
    };
  static const struct tags wordlist_tag[] =
    {
      {"a", ID_A},
      {"tt", ID_TT},
      {"b", ID_B},
      {"tr", ID_TR},
      {"area", ID_AREA},
      {"i", ID_I},
      {"br", ID_BR},
      {"wbr", ID_WBR},
      {"abbr", ID_ABBR},
      {"big", ID_BIG},
      {"q", ID_Q},
      {"nobr", ID_NOBR},
      {"s", ID_S},
      {"em", ID_EM},
      {"textarea", ID_TEXTAREA},
      {"meta", ID_META},
      {"dt", ID_DT},
      {"td", ID_TD},
      {"base", ID_BASE},
      {"object", ID_OBJECT},
      {"bdo", ID_BDO},
      {"cite", ID_CITE},
      {"ol", ID_OL},
      {"img", ID_IMG},
      {"th", ID_TH},
      {"image", ID_IMG},
      {"dir", ID_DIR},
      {"hr", ID_HR},
      {"table", ID_TABLE},
      {"center", ID_CENTER},
      {"li", ID_LI},
      {"ins", ID_INS},
      {"h5", ID_H5},
      {"title", ID_TITLE},
      {"strong", ID_STRONG},
      {"h6", ID_H6},
      {"kbd", ID_KBD},
      {"code", ID_CODE},
      {"dd", ID_DD},
      {"h1", ID_H1},
      {"embed", ID_EMBED},
      {"strike", ID_STRIKE},
      {"col", ID_COL},
      {"h2", ID_H2},
      {"dl", ID_DL},
      {"del", ID_DEL},
      {"h3", ID_H3},
      {"head", ID_HEAD},
      {"thead", ID_THEAD},
      {"u", ID_U},
      {"h4", ID_H4},
      {"noembed", ID_NOEMBED},
      {"var", ID_VAR},
      {"link", ID_LINK},
      {"label", ID_LABEL},
      {"p", ID_P},
      {"anchor", ID_A},
      {"legend", ID_LEGEND},
      {"pre", ID_PRE},
      {"tfoot", ID_TFOOT},
      {"select", ID_SELECT},
      {"button", ID_BUTTON},
      {"listing", ID_PRE},
      {"font", ID_FONT},
      {"sub", ID_SUB},
      {"html", ID_HTML},
      {"isindex", ID_ISINDEX},
      {"option", ID_OPTION},
      {"map", ID_MAP},
      {"ul", ID_UL},
      {"menu", ID_MENU},
      {"div", ID_DIV},
      {"param", ID_PARAM},
      {"address", ID_ADDRESS},
      {"form", ID_FORM},
      {"frame", ID_FRAME},
      {"span", ID_SPAN},
      {"xmp", ID_XMP},
      {"marquee", ID_MARQUEE},
      {"small", ID_SMALL},
      {"iframe", ID_IFRAME},
      {"dfn", ID_DFN},
      {"body", ID_BODY},
      {"tbody", ID_TBODY},
      {"caption", ID_CAPTION},
      {"basefont", ID_BASEFONT},
      {"samp", ID_SAMP},
      {"keygen", ID_KEYGEN},
      {"layer", ID_LAYER},
      {"frameset", ID_FRAMESET},
      {"script", ID_SCRIPT},
      {"nolayer", ID_NOLAYER},
      {"noframes", ID_NOFRAMES},
      {"style", ID_STYLE},
      {"noscript", ID_NOSCRIPT},
      {"plaintext", ID_PLAINTEXT},
      {"acronym", ID_ACRONYM},
      {"input", ID_INPUT},
      {"sup", ID_SUP},
      {"blockquote", ID_BLOCKQUOTE},
      {"fieldset", ID_FIELDSET},
      {"applet", ID_APPLET},
      {"colgroup", ID_COLGROUP},
      {"optgroup", ID_OPTGROUP}
    };

  static const short lookup[] =
    {
        -1,    0,    1,   -1,   -1,   -1,    2,    3,
        -1,    4,   -1,    5,    6,    7,   -1,   -1,
        -1,   -1,   -1,    8,   -1,   -1,   -1,    9,
        -1,   -1,   10,   -1,   -1,   11,   -1,   12,
        13,   14,   15,   -1,   -1, -150,   -1,   18,
        -1,   19,   -1,   20,   21,  -88,   -2,   22,
        23,   24,   25,   -1,   -1,   26,   27,   28,
        29,   30,   31,   32,   33,   34,   -1,   -1,
        35,   -1,   -1,   -1,   36,   37,   -1,   -1,
        38,   -1,   39,   40,   41,   -1,   42,   43,
        -1,   -1,   44,   45,   46,   -1,   47,   48,
        49,   50,   -1,   -1,   51,   -1,   -1,   -1,
        -1,   -1,   52,   53,   54,   55,   -1,   56,
        -1,   -1,   57,   -1,   58,   -1,   59,   60,
        -1,   61,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   62,   -1,   63,   64,   65,   66,
        -1,   -1,   -1,   67,   -1,   68,   69,   -1,
        70,   -1,   71,   -1,   72,   -1,   73,   -1,
        74,   75,   -1,   -1,   -1,   76,   -1,   -1,
        -1,   77,   78,   79,   80,   -1,   81,   82,
        83,   -1,   84,   85,   86,   -1,   87,   -1,
        -1,   -1,   88,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   89,   -1,   -1,   90,   -1,   -1,
        -1,   -1,   -1,   91,   -1,   -1,   -1,   -1,
        -1,   92,   -1,   93,   -1,   -1,   94,   95,
        -1,   -1,   96,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   97,   -1,   -1,   98,   -1,   -1,   -1,
        -1,   -1,   -1,   99,   -1,   -1,   -1,   -1,
        -1,  100,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,  101,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
       102,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,  103
    };

  if (len <= MAX_WORD_LENGTH && len >= MIN_WORD_LENGTH)
    {
      register int key = hash_tag (str, len);

      if (key <= MAX_HASH_VALUE && key >= 0)
        {
          register int index = lookup[key];

          if (index >= 0)
            {
              if (len == lengthtable[index])
                {
                  register const char *s = wordlist_tag[index].name;

                  if (*str == *s && !memcmp (str + 1, s + 1, len - 1))
                    return &wordlist_tag[index];
                }
            }
          else if (index < -TOTAL_KEYWORDS)
            {
              register int offset = - 1 - TOTAL_KEYWORDS - index;
              register const unsigned char *lengthptr = &lengthtable[TOTAL_KEYWORDS + lookup[offset]];
              register const struct tags *wordptr = &wordlist_tag[TOTAL_KEYWORDS + lookup[offset]];
              register const struct tags *wordendptr = wordptr + -lookup[offset + 1];

              while (wordptr < wordendptr)
                {
                  if (len == *lengthptr)
                    {
                      register const char *s = wordptr->name;

                      if (*str == *s && !memcmp (str + 1, s + 1, len - 1))
                        return wordptr;
                    }
                  lengthptr++;
                  wordptr++;
                }
            }
        }
    }
  return 0;
}


static const char * const tagList[] = {
"",
    "A",
    "ABBR",
    "ACRONYM",
    "ADDRESS",
    "APPLET",
    "AREA",
    "B",
    "BASE",
    "BASEFONT",
    "BDO",
    "BIG",
    "BLOCKQUOTE",
    "BODY",
    "BR",
    "BUTTON",
    "CAPTION",
    "CENTER",
    "CITE",
    "CODE",
    "COL",
    "COLGROUP",
    "DD",
    "DEL",
    "DFN",
    "DIR",
    "DIV",
    "DL",
    "DT",
    "EM",
    "EMBED",
    "FIELDSET",
    "FONT",
    "FORM",
    "FRAME",
    "FRAMESET",
    "H1",
    "H2",
    "H3",
    "H4",
    "H5",
    "H6",
    "HEAD",
    "HR",
    "HTML",
    "I",
    "IFRAME",
    "IMG",
    "INPUT",
    "INS",
    "ISINDEX",
    "KBD",
    "KEYGEN",
    "LABEL",
    "LAYER",
    "LEGEND",
    "LI",
    "LINK",
    "MAP",
    "MARQUEE",
    "MENU",
    "META",
    "NOBR",
    "NOEMBED",
    "NOFRAMES",
    "NOSCRIPT",
    "NOLAYER",
    "OBJECT",
    "OL",
    "OPTGROUP",
    "OPTION",
    "P",
    "PARAM",
    "PLAINTEXT",
    "PRE",
    "Q",
    "S",
    "SAMP",
    "SCRIPT",
    "SELECT",
    "SMALL",
    "SPAN",
    "STRIKE",
    "STRONG",
    "STYLE",
    "SUB",
    "SUP",
    "TABLE",
    "TBODY",
    "TD",
    "TEXTAREA",
    "TFOOT",
    "TH",
    "THEAD",
    "TITLE",
    "TR",
    "TT",
    "U",
    "UL",
    "VAR",
    "WBR",
    "XMP",
"TEXT",
"COMMENT",
    "/A",
    "/ABBR",
    "/ACRONYM",
    "/ADDRESS",
    "/APPLET",
    "/AREA",
    "/B",
    "/BASE",
    "/BASEFONT",
    "/BDO",
    "/BIG",
    "/BLOCKQUOTE",
    "/BODY",
    "/BR",
    "/BUTTON",
    "/CAPTION",
    "/CENTER",
    "/CITE",
    "/CODE",
    "/COL",
    "/COLGROUP",
    "/DD",
    "/DEL",
    "/DFN",
    "/DIR",
    "/DIV",
    "/DL",
    "/DT",
    "/EM",
    "/EMBED",
    "/FIELDSET",
    "/FONT",
    "/FORM",
    "/FRAME",
    "/FRAMESET",
    "/H1",
    "/H2",
    "/H3",
    "/H4",
    "/H5",
    "/H6",
    "/HEAD",
    "/HR",
    "/HTML",
    "/I",
    "/IFRAME",
    "/IMG",
    "/INPUT",
    "/INS",
    "/ISINDEX",
    "/KBD",
    "/KEYGEN",
    "/LABEL",
    "/LAYER",
    "/LEGEND",
    "/LI",
    "/LINK",
    "/MAP",
    "/MARQUEE",
    "/MENU",
    "/META",
    "/NOBR",
    "/NOEMBED",
    "/NOFRAMES",
    "/NOSCRIPT",
    "/NOLAYER",
    "/OBJECT",
    "/OL",
    "/OPTGROUP",
    "/OPTION",
    "/P",
    "/PARAM",
    "/PLAINTEXT",
    "/PRE",
    "/Q",
    "/S",
    "/SAMP",
    "/SCRIPT",
    "/SELECT",
    "/SMALL",
    "/SPAN",
    "/STRIKE",
    "/STRONG",
    "/STYLE",
    "/SUB",
    "/SUP",
    "/TABLE",
    "/TBODY",
    "/TD",
    "/TEXTAREA",
    "/TFOOT",
    "/TH",
    "/THEAD",
    "/TITLE",
    "/TR",
    "/TT",
    "/U",
    "/UL",
    "/VAR",
    "/WBR",
    "/XMP",
    0
};
DOMString getTagName(unsigned short id)
{
    if(id > ID_CLOSE_TAG*2) id = ID_CLOSE_TAG+1;
    return DOMString(tagList[id]);
};
