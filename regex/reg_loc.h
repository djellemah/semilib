/*
 *
 * Copyright (c) 1998
 * Dr John Maddock
 *
 * Permission to use, copy, modify, distribute and sell this software
 * and its documentation for any purpose is hereby granted without fee,
 * provided that the above copyright notice appear in all copies and
 * that both that copyright notice and this permission notice appear
 * in supporting documentation.  Dr John Maddock makes no representations
 * about the suitability of this software for any purpose.  
 * It is provided "as is" without express or implied warranty.
 *
 */

 /*
  *	FILE     reg_loc.h
  *	VERSION  1.10
  */

//
// include file for regex.cpp
//
// this file contains all the localisable static data declaractions
// for regex.cpp, if you need to localise this library then this
// is the only file you should need to change.

const char *re_error_msg[] =
{  NULL,					/* REG_NOERROR */
   "No match",					/* REG_NOMATCH */
   "Invalid regular expression",		/* REG_BADPAT */
   "Invalid collation character",		/* REG_ECOLLATE */
   "Invalid character class name",		/* REG_ECTYPE */
   "Trailing backslash",			/* REG_EESCAPE */
   "Invalid back reference",			/* REG_ESUBREG */
   "Unmatched [ or [^",			/* REG_EBRACK */
   "Unmatched ( or \\(",			/* REG_EPAREN */
   "Unmatched \\{",				/* REG_EBRACE */
   "Invalid content of \\{\\}",		/* REG_BADBR */
   "Invalid range end",			/* REG_ERANGE */
   "Memory exhausted",				/* REG_ESPACE */
   "Invalid preceding regular expression",	/* REG_BADRPT */
   "Premature end of regular expression",	/* REG_EEND */
   "Regular expression too big",		/* REG_ESIZE */
   "Unmatched ) or \\)",			/* REG_ERPAREN */
   "Empty expression",           /* REG_EMPTY */
   "Out of memory",    /* REG_E_MEMORY */
   "Unknown error",    /* REG_E_UNKNOWN */
   "",
   "",
   "",
};

//
// classes determines the nature of the current character set
// either MS DOS, MS Windows, or ASCII 7-bit.
// Modify this to change the character set to match your locale.
//
unsigned int classes[] = {
   char_class_cntrl,        // ''  0
   char_class_cntrl,        // ''  1
   char_class_cntrl,        // ''  2
   char_class_cntrl,        // ''  3
   char_class_cntrl,        // ''  4
   char_class_cntrl,        // ''  5
   char_class_cntrl,        // ''  6
   char_class_cntrl,        // ''  7
   char_class_cntrl,        // ''  8
   char_class_cntrl | char_class_space | char_class_blank,        // ''  9
   char_class_cntrl | char_class_space,        // ''  10
   char_class_cntrl | char_class_space,        // ''  11
   char_class_cntrl | char_class_space,        // ''  12
   char_class_cntrl | char_class_space,        // ''  13
   char_class_cntrl,        // ''  14
   char_class_cntrl,        // ''  15
   char_class_cntrl,        // ''  16
   char_class_cntrl,        // ''  17
   char_class_cntrl,        // ''  18
   char_class_cntrl,        // ''  19
   char_class_cntrl,        // ''  20
   char_class_cntrl,        // ''  21
   char_class_cntrl,        // ''  22
   char_class_cntrl,        // ''  23
   char_class_cntrl,        // ''  24
   char_class_cntrl,        // ''  25
   char_class_cntrl,        // ''  26
   char_class_cntrl,        // ''  27
   char_class_cntrl,        // ''  28
   char_class_cntrl,        // ''  29
   char_class_cntrl,        // ''  30
   char_class_cntrl,        // ''  31
   char_class_print | char_class_space | char_class_blank,        // ' '  32
   char_class_graph | char_class_print | char_class_punct,        // '!'  33
   char_class_graph | char_class_print | char_class_punct,        // '"'  34
   char_class_graph | char_class_print | char_class_punct,        // '#'  35
   char_class_graph | char_class_print | char_class_punct,        // '$'  36
   char_class_graph | char_class_print | char_class_punct,        // '%'  37
   char_class_graph | char_class_print | char_class_punct,        // '&'  38
   char_class_graph | char_class_print | char_class_punct,        // '''  39
   char_class_graph | char_class_print | char_class_punct,        // '('  40
   char_class_graph | char_class_print | char_class_punct,        // ')'  41
   char_class_graph | char_class_print | char_class_punct,        // '*'  42
   char_class_graph | char_class_print | char_class_punct,        // '+'  43
   char_class_graph | char_class_print | char_class_punct,        // ','  44
   char_class_graph | char_class_print | char_class_punct,        // '-'  45
   char_class_graph | char_class_print | char_class_punct,        // '.'  46
   char_class_graph | char_class_print | char_class_punct,        // '/'  47
   char_class_word | char_class_word | char_class_alnum | char_class_digit | char_class_graph | char_class_print | char_class_xdigit,        // '0'  48
   char_class_word | char_class_alnum | char_class_digit | char_class_graph | char_class_print | char_class_xdigit,        // '1'  49
   char_class_word | char_class_alnum | char_class_digit | char_class_graph | char_class_print | char_class_xdigit,        // '2'  50
   char_class_word | char_class_alnum | char_class_digit | char_class_graph | char_class_print | char_class_xdigit,        // '3'  51
   char_class_word | char_class_alnum | char_class_digit | char_class_graph | char_class_print | char_class_xdigit,        // '4'  52
   char_class_word | char_class_alnum | char_class_digit | char_class_graph | char_class_print | char_class_xdigit,        // '5'  53
   char_class_word | char_class_alnum | char_class_digit | char_class_graph | char_class_print | char_class_xdigit,        // '6'  54
   char_class_word | char_class_alnum | char_class_digit | char_class_graph | char_class_print | char_class_xdigit,        // '7'  55
   char_class_word | char_class_alnum | char_class_digit | char_class_graph | char_class_print | char_class_xdigit,        // '8'  56
   char_class_word | char_class_alnum | char_class_digit | char_class_graph | char_class_print | char_class_xdigit,        // '9'  57
   char_class_graph | char_class_print | char_class_punct,        // ':'  58
   char_class_graph | char_class_print | char_class_punct,        // ';'  59
   char_class_graph | char_class_print | char_class_punct,        // '<'  60
   char_class_graph | char_class_print | char_class_punct,        // '='  61
   char_class_graph | char_class_print | char_class_punct,        // '>'  62
   char_class_graph | char_class_print | char_class_punct,        // '?'  63
   char_class_graph | char_class_print | char_class_punct,        // '@'  64
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_print | char_class_upper | char_class_xdigit,        // 'A'  65
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_print | char_class_upper | char_class_xdigit,        // 'B'  66
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_print | char_class_upper | char_class_xdigit,        // 'C'  67
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_print | char_class_upper | char_class_xdigit,        // 'D'  68
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_print | char_class_upper | char_class_xdigit,        // 'E'  69
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_print | char_class_upper | char_class_xdigit,        // 'F'  70
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_print | char_class_upper,        // 'G'  71
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_print | char_class_upper,        // 'H'  72
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_print | char_class_upper,        // 'I'  73
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_print | char_class_upper,        // 'J'  74
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_print | char_class_upper,        // 'K'  75
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_print | char_class_upper,        // 'L'  76
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_print | char_class_upper,        // 'M'  77
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_print | char_class_upper,        // 'N'  78
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_print | char_class_upper,        // 'O'  79
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_print | char_class_upper,        // 'P'  80
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_print | char_class_upper,        // 'Q'  81
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_print | char_class_upper,        // 'R'  82
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_print | char_class_upper,        // 'S'  83
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_print | char_class_upper,        // 'T'  84
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_print | char_class_upper,        // 'U'  85
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_print | char_class_upper,        // 'V'  86
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_print | char_class_upper,        // 'W'  87
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_print | char_class_upper,        // 'X'  88
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_print | char_class_upper,        // 'Y'  89
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_print | char_class_upper,        // 'Z'  90
   char_class_graph | char_class_print | char_class_punct,        // '['  91
   char_class_graph | char_class_print | char_class_punct,        // '\'  92
   char_class_graph | char_class_print | char_class_punct,        // ']'  93
   char_class_graph | char_class_print | char_class_punct,        // '^'  94
   char_class_word | char_class_graph | char_class_print | char_class_punct,        // '_'  95
   char_class_graph | char_class_print | char_class_punct,        // '`'  96
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_lower | char_class_print | char_class_xdigit,        // 'a'  97
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_lower | char_class_print | char_class_xdigit,        // 'b'  98
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_lower | char_class_print | char_class_xdigit,        // 'c'  99
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_lower | char_class_print | char_class_xdigit,        // 'd'  100
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_lower | char_class_print | char_class_xdigit,        // 'e'  101
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_lower | char_class_print | char_class_xdigit,        // 'f'  102
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_lower | char_class_print,        // 'g'  103
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_lower | char_class_print,        // 'h'  104
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_lower | char_class_print,        // 'i'  105
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_lower | char_class_print,        // 'j'  106
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_lower | char_class_print,        // 'k'  107
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_lower | char_class_print,        // 'l'  108
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_lower | char_class_print,        // 'm'  109
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_lower | char_class_print,        // 'n'  110
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_lower | char_class_print,        // 'o'  111
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_lower | char_class_print,        // 'p'  112
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_lower | char_class_print,        // 'q'  113
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_lower | char_class_print,        // 'r'  114
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_lower | char_class_print,        // 's'  115
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_lower | char_class_print,        // 't'  116
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_lower | char_class_print,        // 'u'  117
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_lower | char_class_print,        // 'v'  118
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_lower | char_class_print,        // 'w'  119
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_lower | char_class_print,        // 'x'  120
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_lower | char_class_print,        // 'y'  121
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_lower | char_class_print,        // 'z'  122
   char_class_graph | char_class_print | char_class_punct,        // '{'  123
   char_class_graph | char_class_print | char_class_punct,        // '|'  124
   char_class_graph | char_class_print | char_class_punct,        // '}'  125
   char_class_graph | char_class_print | char_class_punct,        // '~'  126
#ifdef JM_PLATFORM_WINDOWS
   char_class_cntrl,        // ''  127
   char_class_none,        // '�'  128
   char_class_none,        // '�'  129
   char_class_graph | char_class_print,        // '�'  130
   char_class_graph | char_class_print,        // '�'  131
   char_class_graph | char_class_print,        // '�'  132
   char_class_graph | char_class_print,        // '�'  133
   char_class_graph | char_class_print,        // '�'  134
   char_class_graph | char_class_print,        // '�'  135
   char_class_graph | char_class_print,        // '�'  136
   char_class_graph | char_class_print,        // '�'  137
   char_class_graph | char_class_print,        // '�'  138
   char_class_graph | char_class_print,        // '�'  139
   char_class_graph | char_class_print,        // '�'  140
   char_class_none,        // '�'  141
   char_class_none,        // '�'  142
   char_class_none,        // '�'  143
   char_class_none,        // '�'  144
   char_class_graph | char_class_print,        // '�'  145
   char_class_graph | char_class_print,        // '�'  146
   char_class_graph | char_class_print,        // '�'  147
   char_class_graph | char_class_print,        // '�'  148
   char_class_graph | char_class_print,        // '�'  149
   char_class_graph | char_class_print,        // '�'  150
   char_class_graph | char_class_print,        // '�'  151
   char_class_graph | char_class_print,        // '�'  152
   char_class_graph | char_class_print,        // '�'  153
   char_class_graph | char_class_print,        // '�'  154
   char_class_graph | char_class_print,        // '�'  155
   char_class_graph | char_class_print,        // '�'  156
   char_class_none,        // '�'  157
   char_class_none,        // '�'  158
   char_class_graph | char_class_print,        // '�'  159
   char_class_none,        // '�'  160
   char_class_graph | char_class_print,        // '�'  161
   char_class_graph | char_class_print,        // '�'  162
   char_class_graph | char_class_print,        // '�'  163
   char_class_graph | char_class_print,        // '�'  164
   char_class_graph | char_class_print,        // '�'  165
   char_class_graph | char_class_print,        // '�'  166
   char_class_graph | char_class_print,        // '�'  167
   char_class_graph | char_class_print,        // '�'  168
   char_class_graph | char_class_print,        // '�'  169
   char_class_graph | char_class_print,        // '�'  170
   char_class_graph | char_class_print,        // '�'  171
   char_class_graph | char_class_print,        // '�'  172
   char_class_graph | char_class_print,        // '�'  173
   char_class_graph | char_class_print,        // '�'  174
   char_class_graph | char_class_print,        // '�'  175
   char_class_graph | char_class_print,        // '�'  176
   char_class_graph | char_class_print,        // '�'  177
   char_class_graph | char_class_print,        // '�'  178
   char_class_graph | char_class_print,        // '�'  179
   char_class_graph | char_class_print,        // '�'  180
   char_class_graph | char_class_print,        // '�'  181
   char_class_graph | char_class_print,        // '�'  182
   char_class_graph | char_class_print,        // '�'  183
   char_class_graph | char_class_print,        // '�'  184
   char_class_graph | char_class_print,        // '�'  185
   char_class_graph | char_class_print,        // '�'  186
   char_class_graph | char_class_print,        // '�'  187
   char_class_graph | char_class_print,        // '�'  188
   char_class_graph | char_class_print,        // '�'  189
   char_class_graph | char_class_print,        // '�'  190
   char_class_graph | char_class_print,        // '�'  191
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_print | char_class_upper,        // '�'  192
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_print | char_class_upper,        // '�'  193
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_print | char_class_upper,        // '�'  194
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_print | char_class_upper,        // '�'  195
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_print | char_class_upper,        // '�'  196
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_print | char_class_upper,        // '�'  197
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_print | char_class_upper,        // '�'  198
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_print | char_class_upper,        // '�'  199
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_print | char_class_upper,        // '�'  200
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_print | char_class_upper,        // '�'  201
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_print | char_class_upper,        // '�'  202
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_print | char_class_upper,        // '�'  203
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_print | char_class_upper,        // '�'  204
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_print | char_class_upper,        // '�'  205
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_print | char_class_upper,        // '�'  206
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_print | char_class_upper,        // '�'  207
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_print | char_class_upper,        // '�'  208
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_print | char_class_upper,        // '�'  209
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_print | char_class_upper,        // '�'  210
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_print | char_class_upper,        // '�'  211
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_print | char_class_upper,        // '�'  212
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_print | char_class_upper,        // '�'  213
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_print | char_class_upper,        // '�'  214
   char_class_graph | char_class_print,        // '�'  215
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_print | char_class_upper,        // '�'  216
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_print | char_class_upper,        // '�'  217
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_print | char_class_upper,        // '�'  218
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_print | char_class_upper,        // '�'  219
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_print | char_class_upper,        // '�'  220
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_print | char_class_upper,        // '�'  221
   char_class_graph | char_class_print,        // '�'  222
   char_class_graph | char_class_print,        // '�'  223
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_lower | char_class_print,        // '�'  224
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_lower | char_class_print,        // '�'  225
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_lower | char_class_print,        // '�'  226
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_lower | char_class_print,        // '�'  227
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_lower | char_class_print,        // '�'  228
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_lower | char_class_print,        // '�'  229
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_lower | char_class_print,        // '�'  230
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_lower | char_class_print,        // '�'  231
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_lower | char_class_print,        // '�'  232
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_lower | char_class_print,        // '�'  233
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_lower | char_class_print,        // '�'  234
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_lower | char_class_print,        // '�'  235
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_lower | char_class_print,        // '�'  236
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_lower | char_class_print,        // '�'  237
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_lower | char_class_print,        // '�'  238
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_lower | char_class_print,        // '�'  239
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_lower | char_class_print,        // '�'  240
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_lower | char_class_print,        // '�'  241
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_lower | char_class_print,        // '�'  242
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_lower | char_class_print,        // '�'  243
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_lower | char_class_print,        // '�'  244
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_lower | char_class_print,        // '�'  245
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_lower | char_class_print,        // '�'  246
   char_class_graph | char_class_print,        // '�'  247
   char_class_graph | char_class_print,        // '�'  248
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_lower | char_class_print,        // '�'  249
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_lower | char_class_print,        // '�'  250
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_lower | char_class_print,        // '�'  251
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_lower | char_class_print,        // '�'  252
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_lower | char_class_print,        // '�'  253
   char_class_graph | char_class_print,        // '�'  254
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_lower | char_class_print,        // '�'  255
#elif defined(JM_PLATFORM_DOS)
   char_class_cntrl,        // ''  127
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_print | char_class_upper,        // '�'  128
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_lower | char_class_print,        // '�'  129
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_lower | char_class_print,        // '�'  130
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_lower | char_class_print,        // '�'  131
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_lower | char_class_print,        // '�'  132
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_lower | char_class_print,        // '�'  133
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_lower | char_class_print,        // '�'  134
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_lower | char_class_print,        // '�'  135
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_lower | char_class_print,        // '�'  136
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_lower | char_class_print,        // '�'  137
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_lower | char_class_print,        // '�'  138
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_lower | char_class_print,        // '�'  139
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_lower | char_class_print,        // '�'  140
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_lower | char_class_print,        // '�'  141
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_print | char_class_upper,        // '�'  142
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_print | char_class_upper,        // '�'  143
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_print | char_class_upper,        // '�'  144
   char_class_graph | char_class_print,        // '�'  145
   char_class_graph | char_class_print,        // '�'  146
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_lower | char_class_print,        // '�'  147
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_lower | char_class_print,        // '�'  148
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_lower | char_class_print,        // '�'  149
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_lower | char_class_print,        // '�'  150
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_lower | char_class_print,        // '�'  151
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_lower | char_class_print,        // '�'  152
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_print | char_class_upper,        // '�'  153
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_print | char_class_upper,        // '�'  154
   char_class_graph | char_class_print,        // '�'  155
   char_class_graph | char_class_print,        // '�'  156
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_print | char_class_upper,        // '�'  157
   char_class_graph | char_class_print,        // '�'  158
   char_class_graph | char_class_print,        // '�'  159
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_lower | char_class_print,        // '�'  160
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_lower | char_class_print,        // '�'  161
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_lower | char_class_print,        // '�'  162
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_lower | char_class_print,        // '�'  163
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_lower | char_class_print,        // '�'  164
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_print | char_class_upper,        // '�'  165
   char_class_graph | char_class_print,        // '�'  166
   char_class_graph | char_class_print,        // '�'  167
   char_class_graph | char_class_print,        // '�'  168
   char_class_graph | char_class_print,        // '�'  169
   char_class_graph | char_class_print,        // '�'  170
   char_class_graph | char_class_print,        // '�'  171
   char_class_graph | char_class_print,        // '�'  172
   char_class_graph | char_class_print,        // '�'  173
   char_class_graph | char_class_print,        // '�'  174
   char_class_graph | char_class_print,        // '�'  175
   char_class_graph | char_class_print,        // '�'  176
   char_class_graph | char_class_print,        // '�'  177
   char_class_graph | char_class_print,        // '�'  178
   char_class_graph | char_class_print,        // '�'  179
   char_class_graph | char_class_print,        // '�'  180
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_print | char_class_upper,        // '�'  181
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_print | char_class_upper,        // '�'  182
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_print | char_class_upper,        // '�'  183
   char_class_graph | char_class_print,        // '�'  184
   char_class_graph | char_class_print,        // '�'  185
   char_class_graph | char_class_print,        // '�'  186
   char_class_graph | char_class_print,        // '�'  187
   char_class_graph | char_class_print,        // '�'  188
   char_class_graph | char_class_print,        // '�'  189
   char_class_graph | char_class_print,        // '�'  190
   char_class_graph | char_class_print,        // '�'  191
   char_class_graph | char_class_print,        // '�'  192
   char_class_graph | char_class_print,        // '�'  193
   char_class_graph | char_class_print,        // '�'  194
   char_class_graph | char_class_print,        // '�'  195
   char_class_graph | char_class_print,        // '�'  196
   char_class_graph | char_class_print,        // '�'  197
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_lower | char_class_print,        // '�'  198
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_print | char_class_upper,        // '�'  199
   char_class_graph | char_class_print,        // '�'  200
   char_class_graph | char_class_print,        // '�'  201
   char_class_graph | char_class_print,        // '�'  202
   char_class_graph | char_class_print,        // '�'  203
   char_class_graph | char_class_print,        // '�'  204
   char_class_graph | char_class_print,        // '�'  205
   char_class_graph | char_class_print,        // '�'  206
   char_class_graph | char_class_print,        // '�'  207
   char_class_graph | char_class_print,        // '�'  208
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_print | char_class_upper,        // '�'  209
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_print | char_class_upper,        // '�'  210
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_print | char_class_upper,        // '�'  211
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_print | char_class_upper,        // '�'  212
   char_class_graph | char_class_print,        // '�'  213
   char_class_graph | char_class_print,        // '�'  214
   char_class_graph | char_class_print,        // '�'  215
   char_class_graph | char_class_print,        // '�'  216
   char_class_graph | char_class_print,        // '�'  217
   char_class_graph | char_class_print,        // '�'  218
   char_class_graph | char_class_print,        // '�'  219
   char_class_graph | char_class_print,        // '�'  220
   char_class_graph | char_class_print,        // '�'  221
   char_class_graph | char_class_print,        // '�'  222
   char_class_graph | char_class_print,        // '�'  223
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_print | char_class_upper,        // '�'  224
   char_class_graph | char_class_print,        // '�'  225
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_print | char_class_upper,        // '�'  226
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_print | char_class_upper,        // '�'  227
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_lower | char_class_print,        // '�'  228
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_print | char_class_upper,        // '�'  229
   char_class_graph | char_class_print,        // '�'  230
   char_class_graph | char_class_print,        // '�'  231
   char_class_graph | char_class_print,        // '�'  232
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_print | char_class_upper,        // '�'  233
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_print | char_class_upper,        // '�'  234
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_print | char_class_upper,        // '�'  235
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_lower | char_class_print,        // '�'  236
   char_class_word | char_class_alnum | char_class_alpha | char_class_graph | char_class_print | char_class_upper,        // '�'  237
   char_class_graph | char_class_print,        // '�'  238
   char_class_graph | char_class_print,        // '�'  239
   char_class_graph | char_class_print,        // '�'  240
   char_class_graph | char_class_print,        // '�'  241
   char_class_graph | char_class_print,        // '�'  242
   char_class_graph | char_class_print,        // '�'  243
   char_class_graph | char_class_print,        // '�'  244
   char_class_graph | char_class_print,        // '�'  245
   char_class_graph | char_class_print,        // '�'  246
   char_class_graph | char_class_print,        // '�'  247
   char_class_graph | char_class_print,        // '�'  248
   char_class_graph | char_class_print,        // '�'  249
   char_class_graph | char_class_print,        // '�'  250
   char_class_graph | char_class_print,        // '�'  251
   char_class_graph | char_class_print,        // '�'  252
   char_class_graph | char_class_print,        // '�'  253
   char_class_graph | char_class_print,        // '�'  254
   char_class_graph | char_class_print,        // '�'  255
#else
   char_class_cntrl,        // ''  127
   char_class_none,        // '�'  128
   char_class_none,        // '�'  129
   char_class_none,        // '�'  130
   char_class_none,        // '�'  131
   char_class_none,        // '�'  132
   char_class_none,        // '�'  133
   char_class_none,        // '�'  134
   char_class_none,        // '�'  135
   char_class_none,        // '�'  136
   char_class_none,        // '�'  137
   char_class_none,        // '�'  138
   char_class_none,        // '�'  139
   char_class_none,        // '�'  140
   char_class_none,        // '�'  141
   char_class_none,        // '�'  142
   char_class_none,        // '�'  143
   char_class_none,        // '�'  144
   char_class_none,        // '�'  145
   char_class_none,        // '�'  146
   char_class_none,        // '�'  147
   char_class_none,        // '�'  148
   char_class_none,        // '�'  149
   char_class_none,        // '�'  150
   char_class_none,        // '�'  151
   char_class_none,        // '�'  152
   char_class_none,        // '�'  153
   char_class_none,        // '�'  154
   char_class_none,        // '�'  155
   char_class_none,        // '�'  156
   char_class_none,        // '�'  157
   char_class_none,        // '�'  158
   char_class_none,        // '�'  159
   char_class_none,        // '�'  160
   char_class_none,        // '�'  161
   char_class_none,        // '�'  162
   char_class_none,        // '�'  163
   char_class_none,        // '�'  164
   char_class_none,        // '�'  165
   char_class_none,        // '�'  166
   char_class_none,        // '�'  167
   char_class_none,        // '�'  168
   char_class_none,        // '�'  169
   char_class_none,        // '�'  170
   char_class_none,        // '�'  171
   char_class_none,        // '�'  172
   char_class_none,        // '�'  173
   char_class_none,        // '�'  174
   char_class_none,        // '�'  175
   char_class_none,        // '�'  176
   char_class_none,        // '�'  177
   char_class_none,        // '�'  178
   char_class_none,        // '�'  179
   char_class_none,        // '�'  180
   char_class_none,        // '�'  181
   char_class_none,        // '�'  182
   char_class_none,        // '�'  183
   char_class_none,        // '�'  184
   char_class_none,        // '�'  185
   char_class_none,        // '�'  186
   char_class_none,        // '�'  187
   char_class_none,        // '�'  188
   char_class_none,        // '�'  189
   char_class_none,        // '�'  190
   char_class_none,        // '�'  191
   char_class_none,        // '�'  192
   char_class_none,        // '�'  193
   char_class_none,        // '�'  194
   char_class_none,        // '�'  195
   char_class_none,        // '�'  196
   char_class_none,        // '�'  197
   char_class_none,        // '�'  198
   char_class_none,        // '�'  199
   char_class_none,        // '�'  200
   char_class_none,        // '�'  201
   char_class_none,        // '�'  202
   char_class_none,        // '�'  203
   char_class_none,        // '�'  204
   char_class_none,        // '�'  205
   char_class_none,        // '�'  206
   char_class_none,        // '�'  207
   char_class_none,        // '�'  208
   char_class_none,        // '�'  209
   char_class_none,        // '�'  210
   char_class_none,        // '�'  211
   char_class_none,        // '�'  212
   char_class_none,        // '�'  213
   char_class_none,        // '�'  214
   char_class_none,        // '�'  215
   char_class_none,        // '�'  216
   char_class_none,        // '�'  217
   char_class_none,        // '�'  218
   char_class_none,        // '�'  219
   char_class_none,        // '�'  220
   char_class_none,        // '�'  221
   char_class_none,        // '�'  222
   char_class_none,        // '�'  223
   char_class_none,        // '�'  224
   char_class_none,        // '�'  225
   char_class_none,        // '�'  226
   char_class_none,        // '�'  227
   char_class_none,        // '�'  228
   char_class_none,        // '�'  229
   char_class_none,        // '�'  230
   char_class_none,        // '�'  231
   char_class_none,        // '�'  232
   char_class_none,        // '�'  233
   char_class_none,        // '�'  234
   char_class_none,        // '�'  235
   char_class_none,        // '�'  236
   char_class_none,        // '�'  237
   char_class_none,        // '�'  238
   char_class_none,        // '�'  239
   char_class_none,        // '�'  240
   char_class_none,        // '�'  241
   char_class_none,        // '�'  242
   char_class_none,        // '�'  243
   char_class_none,        // '�'  244
   char_class_none,        // '�'  245
   char_class_none,        // '�'  246
   char_class_none,        // '�'  247
   char_class_none,        // '�'  248
   char_class_none,        // '�'  249
   char_class_none,        // '�'  250
   char_class_none,        // '�'  251
   char_class_none,        // '�'  252
   char_class_none,        // '�'  253
   char_class_none,        // '�'  254
   char_class_none,        // '�'  255
#endif
};

// define our character maps for case conversion:

char* lower_case_map_c =
#ifdef JM_PLATFORM_WINDOWS
// MS windows character set:
"\x0\x1\x2\x3\x4\x5\x6\x7\x8\x9\xa\xb\xc\xd\xe\xf\x10\x11\x12\x13\x14\x15\x16\x17\x18\x19\x1a\x1b\x1c\x1d\x1e\x1f !\"#$%&'()*+,-./0123456789:;<=>?@abcdefghijklmnopqrstuvwxyz[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~��������������������������������������������������������������������������������������������������������������������������������"
#elif defined(JM_PLATFORM_DOS)
// MS Dos charcter set:
"\x0\x1\x2\x3\x4\x5\x6\x7\x8\x9\xa\xb\xc\xd\xe\xf\x10\x11\x12\x13\x14\x15\x16\x17\x18\x19\x1a\x1b\x1c\x1d\x1e\x1f !\"#$%&'()*+,-./0123456789:;<=>?@abcdefghijklmnopqrstuvwxyz[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~���������������������������������������������������������������������������������ш��ա��������ߢᓕ����裖���������������������"
#else
// strict ascii character set:
"\x0\x1\x2\x3\x4\x5\x6\x7\x8\x9\xa\xb\xc\xd\xe\xf\x10\x11\x12\x13\x14\x15\x16\x17\x18\x19\x1a\x1b\x1c\x1d\x1e\x1f !\"#$%&'()*+,-./0123456789:;<=>?@abcdefghijklmnopqrstuvwxyz[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~��������������������������������������������������������������������������������������������������������������������������������"
#endif
;

wchar_t* lower_case_map_w =
#ifdef JM_PLATFORM_WINDOWS
// MS windows character set:
L"\x0\x1\x2\x3\x4\x5\x6\x7\x8\x9\xa\xb\xc\xd\xe\xf\x10\x11\x12\x13\x14\x15\x16\x17\x18\x19\x1a\x1b\x1c\x1d\x1e\x1f !\"#$%&'()*+,-./0123456789:;<=>?@abcdefghijklmnopqrstuvwxyz[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~��������������������������������������������������������������������������������������������������������������������������������"
#elif defined(JM_PLATFORM_DOS)
// MS Dos charcter set:
L"\x0\x1\x2\x3\x4\x5\x6\x7\x8\x9\xa\xb\xc\xd\xe\xf\x10\x11\x12\x13\x14\x15\x16\x17\x18\x19\x1a\x1b\x1c\x1d\x1e\x1f !\"#$%&'()*+,-./0123456789:;<=>?@abcdefghijklmnopqrstuvwxyz[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~���������������������������������������������������������������������������������ш��ա��������ߢᓕ����裖���������������������"
#else
// strict ascii character set:
L"\x0\x1\x2\x3\x4\x5\x6\x7\x8\x9\xa\xb\xc\xd\xe\xf\x10\x11\x12\x13\x14\x15\x16\x17\x18\x19\x1a\x1b\x1c\x1d\x1e\x1f !\"#$%&'()*+,-./0123456789:;<=>?@abcdefghijklmnopqrstuvwxyz[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~��������������������������������������������������������������������������������������������������������������������������������"
#endif
;

wchar_t* other_case_map_w =
#ifdef JM_PLATFORM_WINDOWS
// MS windows character set:
L"\x0\x1\x2\x3\x4\x5\x6\x7\x8\x9\xa\xb\xc\xd\xe\xf\x10\x11\x12\x13\x14\x15\x16\x17\x18\x19\x1a\x1b\x1c\x1d\x1e\x1f !\"#$%&'()*+,-./0123456789:;<=>?@abcdefghijklmnopqrstuvwxyz[\\]^_`ABCDEFGHIJKLMNOPQRSTUVWXYZ{|}~��������������������������������������������������������������������������������������������������������������������������������"
#elif defined(JM_PLATFORM_DOS)
// MS Dos charcter set:
L"\x0\x1\x2\x3\x4\x5\x6\x7\x8\x9\xa\xb\xc\xd\xe\xf\x10\x11\x12\x13\x14\x15\x16\x17\x18\x19\x1a\x1b\x1c\x1d\x1e\x1f !\"#$%&'()*+,-./0123456789:;<=>?@abcdefghijklmnopqrstuvwxyz[\\]^_`ABCDEFGHIJKLMNOPQRSTUVWXYZ{|}~�������������ބ��������Y����������饥�������������������������������������������ш��ա��������ߢᓕ����裖���������������������"
#else
// strict ascii character set:
L"\x0\x1\x2\x3\x4\x5\x6\x7\x8\x9\xa\xb\xc\xd\xe\xf\x10\x11\x12\x13\x14\x15\x16\x17\x18\x19\x1a\x1b\x1c\x1d\x1e\x1f !\"#$%&'()*+,-./0123456789:;<=>?@abcdefghijklmnopqrstuvwxyz[\\]^_`ABCDEFGHIJKLMNOPQRSTUVWXYZ{|}~��������������������������������������������������������������������������������������������������������������������������������"
#endif
;

// define our character class names and id's:

#define max_classes 13
#define wmax_classes 14

unsigned int char_class_id[] = {
   char_class_alnum,
   char_class_alpha,
   char_class_cntrl,
   char_class_digit,
   char_class_graph,
   char_class_lower,
   char_class_print,
   char_class_punct,
   char_class_space,
   char_class_upper,
   char_class_xdigit,
   char_class_blank,
   char_class_word,
   char_class_unicode,
};

const char* char_class_names[] = {
"alnum",
"alpha",
"cntrl",
"digit",
"graph",
"lower",
"print",
"punct",
"space",
"upper",
"xdigit",
"blank",
"word",
};

const wchar_t* wchar_class_names[] = {
L"alnum",
L"alpha",
L"cntrl",
L"digit",
L"graph",
L"lower",
L"print",
L"punct",
L"space",
L"upper",
L"xdigit",
L"blank",
L"word",
L"unicode",
};









