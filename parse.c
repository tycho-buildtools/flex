/* A Bison parser, made by GNU Bison 2.0.  */

/* Skeleton parser for Yacc-like parsing with Bison,
   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

/* Written by Richard Stallman by simplifying the original so called
   ``semantic'' parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     CHAR = 258,
     NUMBER = 259,
     SECTEND = 260,
     SCDECL = 261,
     XSCDECL = 262,
     NAME = 263,
     PREVCCL = 264,
     EOF_OP = 265,
     OPTION_OP = 266,
     OPT_OUTFILE = 267,
     OPT_PREFIX = 268,
     OPT_YYCLASS = 269,
     OPT_HEADER = 270,
     CCE_ALNUM = 271,
     CCE_ALPHA = 272,
     CCE_BLANK = 273,
     CCE_CNTRL = 274,
     CCE_DIGIT = 275,
     CCE_GRAPH = 276,
     CCE_LOWER = 277,
     CCE_PRINT = 278,
     CCE_PUNCT = 279,
     CCE_SPACE = 280,
     CCE_UPPER = 281,
     CCE_XDIGIT = 282,
     BEGIN_REPEAT_POSIX = 283,
     END_REPEAT_POSIX = 284,
     BEGIN_REPEAT_FLEX = 285,
     END_REPEAT_FLEX = 286
   };
#endif
#define CHAR 258
#define NUMBER 259
#define SECTEND 260
#define SCDECL 261
#define XSCDECL 262
#define NAME 263
#define PREVCCL 264
#define EOF_OP 265
#define OPTION_OP 266
#define OPT_OUTFILE 267
#define OPT_PREFIX 268
#define OPT_YYCLASS 269
#define OPT_HEADER 270
#define CCE_ALNUM 271
#define CCE_ALPHA 272
#define CCE_BLANK 273
#define CCE_CNTRL 274
#define CCE_DIGIT 275
#define CCE_GRAPH 276
#define CCE_LOWER 277
#define CCE_PRINT 278
#define CCE_PUNCT 279
#define CCE_SPACE 280
#define CCE_UPPER 281
#define CCE_XDIGIT 282
#define BEGIN_REPEAT_POSIX 283
#define END_REPEAT_POSIX 284
#define BEGIN_REPEAT_FLEX 285
#define END_REPEAT_FLEX 286




/* Copy the first part of user declarations.  */
#line 28 "parse.y"

/*  Copyright (c) 1990 The Regents of the University of California. */
/*  All rights reserved. */

/*  This code is derived from software contributed to Berkeley by */
/*  Vern Paxson. */

/*  The United States Government has rights in this work pursuant */
/*  to contract no. DE-AC03-76SF00098 between the United States */
/*  Department of Energy and the University of California. */

/*  This file is part of flex. */

/*  Redistribution and use in source and binary forms, with or without */
/*  modification, are permitted provided that the following conditions */
/*  are met: */

/*  1. Redistributions of source code must retain the above copyright */
/*     notice, this list of conditions and the following disclaimer. */
/*  2. Redistributions in binary form must reproduce the above copyright */
/*     notice, this list of conditions and the following disclaimer in the */
/*     documentation and/or other materials provided with the distribution. */

/*  Neither the name of the University nor the names of its contributors */
/*  may be used to endorse or promote products derived from this software */
/*  without specific prior written permission. */

/*  THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR */
/*  IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED */
/*  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR */
/*  PURPOSE. */

/* Some versions of bison are broken in that they use alloca() but don't
 * declare it properly.  The following is the patented (just kidding!)
 * #ifdef chud to fix the problem, courtesy of Francois Pinard.
 */
#ifdef YYBISON
/* AIX requires this to be the first thing in the file.  What a piece.  */
# ifdef _AIX
 #pragma alloca
# endif
#endif

#include "flexdef.h"

/* The remainder of the alloca() cruft has to come after including flexdef.h,
 * so HAVE_ALLOCA_H is (possibly) defined.
 */
#ifdef YYBISON
# ifdef __GNUC__
#  ifndef alloca
#   define alloca __builtin_alloca
#  endif
# else
#  if HAVE_ALLOCA_H
#   include <alloca.h>
#  else
#   ifdef __hpux
void *alloca ();
#   else
#    ifdef __TURBOC__
#     include <malloc.h>
#    else
char *alloca ();
#    endif
#   endif
#  endif
# endif
#endif

/* Bletch, ^^^^ that was ugly! */


int pat, scnum, eps, headcnt, trailcnt, anyccl, lastchar, i, rulelen;
int trlcontxt, xcluflg, currccl, cclsorted, varlength, variable_trail_rule;

int *scon_stk;
int scon_stk_ptr;

static int madeany = false;  /* whether we've made the '.' character class */
int previous_continued_action;	/* whether the previous rule's action was '|' */

/* Expand a POSIX character class expression. */
#define CCL_EXPR(func) \
	{ \
	int c; \
	for ( c = 0; c < csize; ++c ) \
		if ( isascii(c) && func(c) ) \
			ccladd( currccl, c ); \
	}

/* While POSIX defines isblank(), it's not ANSI C. */
#define IS_BLANK(c) ((c) == ' ' || (c) == '\t')

/* On some over-ambitious machines, such as DEC Alpha's, the default
 * token type is "long" instead of "int"; this leads to problems with
 * declaring yylval in flexdef.h.  But so far, all the yacc's I've seen
 * wrap their definitions of YYSTYPE with "#ifndef YYSTYPE"'s, so the
 * following should ensure that the default token type is "int".
 */
#define YYSTYPE int



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 213 of yacc.c.  */
#line 253 "parse.c"

#if ! defined (yyoverflow) || YYERROR_VERBOSE

# ifndef YYFREE
#  define YYFREE free
# endif
# ifndef YYMALLOC
#  define YYMALLOC malloc
# endif

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   else
#    define YYSTACK_ALLOC alloca
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning. */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
# else
#  if defined (__STDC__) || defined (__cplusplus)
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   define YYSIZE_T size_t
#  endif
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
# endif
#endif /* ! defined (yyoverflow) || YYERROR_VERBOSE */


#if (! defined (yyoverflow) \
     && (! defined (__cplusplus) \
	 || (defined (YYSTYPE_IS_TRIVIAL) && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  short int yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (short int) + sizeof (YYSTYPE))			\
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined (__GNUC__) && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  register YYSIZE_T yyi;		\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (0)
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (0)

#endif

#if defined (__STDC__) || defined (__cplusplus)
   typedef signed char yysigned_char;
#else
   typedef short int yysigned_char;
#endif

/* YYFINAL -- State number of the termination state. */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   129

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  26
/* YYNRULES -- Number of rules. */
#define YYNRULES  80
/* YYNRULES -- Number of states. */
#define YYNSTATES  117

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   286

#define YYTRANSLATE(YYX) 						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const unsigned char yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      33,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    47,     2,    41,     2,     2,     2,
      48,    49,    39,    44,    40,    52,    46,    43,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      37,    32,    38,    45,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    50,     2,    51,    36,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    34,    42,    35,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const unsigned char yyprhs[] =
{
       0,     0,     3,     9,    10,    14,    17,    18,    20,    22,
      24,    26,    29,    31,    33,    36,    39,    40,    44,    48,
      52,    56,    62,    68,    69,    70,    73,    75,    77,    79,
      80,    85,    89,    90,    94,    96,    98,   100,   103,   107,
     110,   112,   116,   118,   121,   124,   126,   133,   139,   144,
     147,   150,   153,   160,   166,   171,   173,   175,   177,   181,
     185,   187,   191,   196,   201,   204,   207,   208,   210,   212,
     214,   216,   218,   220,   222,   224,   226,   228,   230,   232,
     235
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const yysigned_char yyrhs[] =
{
      54,     0,    -1,    55,    56,    57,    63,    64,    -1,    -1,
      56,    58,    59,    -1,    56,    60,    -1,    -1,     1,    -1,
       5,    -1,     6,    -1,     7,    -1,    59,     8,    -1,     8,
      -1,     1,    -1,    11,    61,    -1,    61,    62,    -1,    -1,
      12,    32,     8,    -1,    13,    32,     8,    -1,    14,    32,
       8,    -1,    15,    32,     8,    -1,    63,    67,    64,    65,
      33,    -1,    63,    67,    34,    63,    35,    -1,    -1,    -1,
      36,    70,    -1,    70,    -1,    10,    -1,     1,    -1,    -1,
      37,    66,    68,    38,    -1,    37,    39,    38,    -1,    -1,
      68,    40,    69,    -1,    69,    -1,     1,    -1,     8,    -1,
      72,    71,    -1,    72,    71,    41,    -1,    71,    41,    -1,
      71,    -1,    71,    42,    73,    -1,    73,    -1,    71,    43,
      -1,    73,    74,    -1,    74,    -1,    73,    28,     4,    40,
       4,    29,    -1,    73,    28,     4,    40,    29,    -1,    73,
      28,     4,    29,    -1,    74,    39,    -1,    74,    44,    -1,
      74,    45,    -1,    74,    30,     4,    40,     4,    31,    -1,
      74,    30,     4,    40,    31,    -1,    74,    30,     4,    31,
      -1,    46,    -1,    75,    -1,     9,    -1,    47,    78,    47,
      -1,    48,    71,    49,    -1,     3,    -1,    50,    76,    51,
      -1,    50,    36,    76,    51,    -1,    76,     3,    52,     3,
      -1,    76,     3,    -1,    76,    77,    -1,    -1,    16,    -1,
      17,    -1,    18,    -1,    19,    -1,    20,    -1,    21,    -1,
      22,    -1,    23,    -1,    24,    -1,    25,    -1,    26,    -1,
      27,    -1,    78,     3,    -1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short int yyrline[] =
{
       0,   133,   133,   163,   170,   171,   172,   173,   177,   185,
     188,   192,   195,   198,   202,   205,   206,   209,   214,   216,
     218,   222,   224,   226,   230,   242,   278,   302,   325,   330,
     333,   336,   354,   357,   359,   361,   365,   388,   443,   446,
     489,   507,   513,   518,   545,   553,   556,   584,   598,   620,
     627,   633,   639,   667,   681,   700,   722,   740,   747,   750,
     753,   764,   767,   774,   802,   813,   821,   828,   829,   830,
     831,   832,   833,   834,   835,   836,   837,   838,   844,   847,
     858
};
#endif

#if YYDEBUG || YYERROR_VERBOSE
/* YYTNME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals. */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CHAR", "NUMBER", "SECTEND", "SCDECL",
  "XSCDECL", "NAME", "PREVCCL", "EOF_OP", "OPTION_OP", "OPT_OUTFILE",
  "OPT_PREFIX", "OPT_YYCLASS", "OPT_HEADER", "CCE_ALNUM", "CCE_ALPHA",
  "CCE_BLANK", "CCE_CNTRL", "CCE_DIGIT", "CCE_GRAPH", "CCE_LOWER",
  "CCE_PRINT", "CCE_PUNCT", "CCE_SPACE", "CCE_UPPER", "CCE_XDIGIT",
  "BEGIN_REPEAT_POSIX", "END_REPEAT_POSIX", "BEGIN_REPEAT_FLEX",
  "END_REPEAT_FLEX", "'='", "'\\n'", "'{'", "'}'", "'^'", "'<'", "'>'",
  "'*'", "','", "'$'", "'|'", "'/'", "'+'", "'?'", "'.'", "'\"'", "'('",
  "')'", "'['", "']'", "'-'", "$accept", "goal", "initlex", "sect1",
  "sect1end", "startconddecl", "namelist1", "options", "optionlist",
  "option", "sect2", "initforrule", "flexrule", "scon_stk_ptr", "scon",
  "namelist2", "sconname", "rule", "re", "re2", "series", "singleton",
  "fullccl", "ccl", "ccl_expr", "string", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const unsigned short int yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,    61,    10,   123,   125,    94,    60,    62,    42,
      44,    36,   124,    47,    43,    63,    46,    34,    40,    41,
      91,    93,    45
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned char yyr1[] =
{
       0,    53,    54,    55,    56,    56,    56,    56,    57,    58,
      58,    59,    59,    59,    60,    61,    61,    62,    62,    62,
      62,    63,    63,    63,    64,    65,    65,    65,    65,    66,
      67,    67,    67,    68,    68,    68,    69,    70,    70,    70,
      70,    71,    71,    72,    73,    73,    73,    73,    73,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    75,    75,    76,    76,    76,    76,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    78,
      78
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,     5,     0,     3,     2,     0,     1,     1,     1,
       1,     2,     1,     1,     2,     2,     0,     3,     3,     3,
       3,     5,     5,     0,     0,     2,     1,     1,     1,     0,
       4,     3,     0,     3,     1,     1,     1,     2,     3,     2,
       1,     3,     1,     2,     2,     1,     6,     5,     4,     2,
       2,     2,     6,     5,     4,     1,     1,     1,     3,     3,
       1,     3,     4,     4,     2,     2,     0,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       0
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned char yydefact[] =
{
       3,     0,     0,     1,     7,     0,     8,     9,    10,    16,
      23,     0,     5,    14,    32,    13,    12,     4,     0,     0,
       0,     0,    15,    29,     2,    24,    11,     0,     0,     0,
       0,     0,     0,    23,     0,    17,    18,    19,    20,    31,
      35,    36,     0,    34,    32,    28,    60,    57,    27,     0,
      55,    80,     0,    66,     0,    26,    40,     0,    42,    45,
      56,    30,     0,    22,    25,     0,     0,    66,     0,    21,
      39,     0,    43,    37,     0,    44,     0,    49,    50,    51,
      33,    79,    58,    59,     0,    64,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    61,    65,
      41,    38,     0,     0,    62,     0,    48,     0,    54,     0,
      63,     0,    47,     0,    53,    46,    52
};

/* YYDEFGOTO[NTERM-NUM]. */
static const yysigned_char yydefgoto[] =
{
      -1,     1,     2,     5,    10,    11,    17,    12,    13,    22,
      14,    24,    54,    32,    25,    42,    43,    55,    56,    57,
      58,    59,    60,    68,    99,    65
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -58
static const yysigned_char yypact[] =
{
     -58,    14,    77,   -58,   -58,    88,   -58,   -58,   -58,   -58,
     -58,    29,   -58,    89,     5,   -58,   -58,    23,     4,     8,
       9,    12,   -58,    11,   -58,    47,   -58,    78,    82,    83,
      92,    59,    68,   -58,    -1,   -58,   -58,   -58,   -58,   -58,
     -58,   -58,    58,   -58,    75,   -58,   -58,   -58,   -58,    25,
     -58,   -58,    25,    69,    73,   -58,   -30,    25,    61,    35,
     -58,   -58,   105,   -58,   -58,     1,    43,   -58,     0,   -58,
     -58,    25,   -58,    26,   110,    35,   111,   -58,   -58,   -58,
     -58,   -58,   -58,   -58,    36,    64,   -58,   -58,   -58,   -58,
     -58,   -58,   -58,   -58,   -58,   -58,   -58,   -58,   -58,   -58,
      61,   -58,    37,    -2,   -58,   114,   -58,     3,   -58,     2,
     -58,    90,   -58,    87,   -58,   -58,   -58
};

/* YYPGOTO[NTERM-NUM].  */
static const yysigned_char yypgoto[] =
{
     -58,   -58,   -58,   -58,   -58,   -58,   -58,   -58,   -58,   -58,
      91,    95,   -58,   -58,   -58,   -58,    60,    72,   -42,   -58,
      52,   -57,   -58,    62,   -58,   -58
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -25
static const yysigned_char yytable[] =
{
      45,    75,    46,    85,    81,   -24,   113,   111,    47,    48,
      66,    70,    71,    72,     3,    73,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    46,   108,
      15,    26,   112,   114,    47,    49,    27,    16,   109,    85,
      28,    29,    23,    75,    30,    50,    51,    52,    82,    53,
      31,    98,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    46,    76,   106,   101,    71,    40,
      47,    50,    51,    52,    77,    53,    41,   107,     4,    78,
      79,    33,    -6,    -6,    -6,    71,    35,   104,    -6,    74,
      36,    37,    83,     6,     7,     8,    61,    39,    62,     9,
      38,    18,    19,    20,    21,    67,    69,    50,    51,    52,
      63,    53,    23,    41,   102,   103,   105,   110,   116,   115,
      34,    64,    80,   100,    44,     0,     0,     0,     0,    84
};

static const yysigned_char yycheck[] =
{
       1,    58,     3,     3,     3,     0,     4,     4,     9,    10,
      52,    41,    42,    43,     0,    57,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,     3,    31,
       1,     8,    29,    31,     9,    36,    32,     8,    40,     3,
      32,    32,    37,   100,    32,    46,    47,    48,    47,    50,
      39,    51,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,     3,    30,    29,    41,    42,     1,
       9,    46,    47,    48,    39,    50,     8,    40,     1,    44,
      45,    34,     5,     6,     7,    42,     8,    51,    11,    28,
       8,     8,    49,     5,     6,     7,    38,    38,    40,    11,
       8,    12,    13,    14,    15,    36,    33,    46,    47,    48,
      35,    50,    37,     8,     4,     4,    52,     3,    31,    29,
      25,    49,    62,    71,    33,    -1,    -1,    -1,    -1,    67
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned char yystos[] =
{
       0,    54,    55,     0,     1,    56,     5,     6,     7,    11,
      57,    58,    60,    61,    63,     1,     8,    59,    12,    13,
      14,    15,    62,    37,    64,    67,     8,    32,    32,    32,
      32,    39,    66,    34,    64,     8,     8,     8,     8,    38,
       1,     8,    68,    69,    63,     1,     3,     9,    10,    36,
      46,    47,    48,    50,    65,    70,    71,    72,    73,    74,
      75,    38,    40,    35,    70,    78,    71,    36,    76,    33,
      41,    42,    43,    71,    28,    74,    30,    39,    44,    45,
      69,     3,    47,    49,    76,     3,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    51,    77,
      73,    41,     4,     4,    51,    52,    29,    40,    31,    40,
       3,     4,    29,     4,    31,    29,    31
};

#if ! defined (YYSIZE_T) && defined (__SIZE_TYPE__)
# define YYSIZE_T __SIZE_TYPE__
#endif
#if ! defined (YYSIZE_T) && defined (size_t)
# define YYSIZE_T size_t
#endif
#if ! defined (YYSIZE_T)
# if defined (__STDC__) || defined (__cplusplus)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# endif
#endif
#if ! defined (YYSIZE_T)
# define YYSIZE_T unsigned int
#endif

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { 								\
      yyerror ("syntax error: cannot back up");\
      YYERROR;							\
    }								\
while (0)


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (N)								\
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (0)
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
              (Loc).first_line, (Loc).first_column,	\
              (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (0)

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)		\
do {								\
  if (yydebug)							\
    {								\
      YYFPRINTF (stderr, "%s ", Title);				\
      yysymprint (stderr, 					\
                  Type, Value);	\
      YYFPRINTF (stderr, "\n");					\
    }								\
} while (0)

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_stack_print (short int *bottom, short int *top)
#else
static void
yy_stack_print (bottom, top)
    short int *bottom;
    short int *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (/* Nothing. */; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_reduce_print (int yyrule)
#else
static void
yy_reduce_print (yyrule)
    int yyrule;
#endif
{
  int yyi;
  unsigned int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %u), ",
             yyrule - 1, yylno);
  /* Print the symbols being reduced, and their result.  */
  for (yyi = yyprhs[yyrule]; 0 <= yyrhs[yyi]; yyi++)
    YYFPRINTF (stderr, "%s ", yytname [yyrhs[yyi]]);
  YYFPRINTF (stderr, "-> %s\n", yytname [yyr1[yyrule]]);
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (Rule);		\
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   SIZE_MAX < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined (__GLIBC__) && defined (_STRING_H)
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
#   if defined (__STDC__) || defined (__cplusplus)
yystrlen (const char *yystr)
#   else
yystrlen (yystr)
     const char *yystr;
#   endif
{
  register const char *yys = yystr;

  while (*yys++ != '\0')
    continue;

  return yys - yystr - 1;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined (__GLIBC__) && defined (_STRING_H) && defined (_GNU_SOURCE)
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
#   if defined (__STDC__) || defined (__cplusplus)
yystpcpy (char *yydest, const char *yysrc)
#   else
yystpcpy (yydest, yysrc)
     char *yydest;
     const char *yysrc;
#   endif
{
  register char *yyd = yydest;
  register const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

#endif /* !YYERROR_VERBOSE */



#if YYDEBUG
/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yysymprint (FILE *yyoutput, int yytype, YYSTYPE *yyvaluep)
#else
static void
yysymprint (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;

  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);


# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  switch (yytype)
    {
      default:
        break;
    }
  YYFPRINTF (yyoutput, ")");
}

#endif /* ! YYDEBUG */
/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
        break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM);
# else
int yyparse ();
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM)
# else
int yyparse (YYPARSE_PARAM)
  void *YYPARSE_PARAM;
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  register int yystate;
  register int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  short int yyssa[YYINITDEPTH];
  short int *yyss = yyssa;
  register short int *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  register YYSTYPE *yyvsp;



#define YYPOPSTACK   (yyvsp--, yyssp--)

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* When reducing, the number of symbols on the RHS of the reduced
     rule.  */
  int yylen;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;


  yyvsp[0] = yylval;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed. so pushing a state here evens the stacks.
     */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack. Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	short int *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow ("parser stack overflow",
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyoverflowlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyoverflowlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	short int *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyoverflowlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

/* Do appropriate processing given the current state.  */
/* Read a look-ahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to look-ahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;


  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  yystate = yyn;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 134 "parse.y"
    { /* add default rule */
			int def_rule;

			pat = cclinit();
			cclnegate( pat );

			def_rule = mkstate( -pat );

			/* Remember the number of the default rule so we
			 * don't generate "can't match" warnings for it.
			 */
			default_rule = num_rules;

			finish_rule( def_rule, false, 0, 0 );

			for ( i = 1; i <= lastsc; ++i )
				scset[i] = mkbranch( scset[i], def_rule );

			if ( spprdflt )
				add_action(
				"YY_FATAL_ERROR( \"flex scanner jammed\" )" );
			else
				add_action( "ECHO" );

			add_action( ";\n\tYY_BREAK\n" );
			}
    break;

  case 3:
#line 163 "parse.y"
    { /* initialize for processing rules */

			/* Create default DFA start condition. */
			scinstal( "INITIAL", false );
			}
    break;

  case 7:
#line 174 "parse.y"
    { synerr( _("unknown error processing section 1") ); }
    break;

  case 8:
#line 178 "parse.y"
    {
			check_options();
			scon_stk = allocate_integer_array( lastsc + 1 );
			scon_stk_ptr = 0;
			}
    break;

  case 9:
#line 186 "parse.y"
    { xcluflg = false; }
    break;

  case 10:
#line 189 "parse.y"
    { xcluflg = true; }
    break;

  case 11:
#line 193 "parse.y"
    { scinstal( nmstr, xcluflg ); }
    break;

  case 12:
#line 196 "parse.y"
    { scinstal( nmstr, xcluflg ); }
    break;

  case 13:
#line 199 "parse.y"
    { synerr( _("bad start condition list") ); }
    break;

  case 17:
#line 210 "parse.y"
    {
			outfilename = copy_string( nmstr );
			did_outfilename = 1;
			}
    break;

  case 18:
#line 215 "parse.y"
    { prefix = copy_string( nmstr ); }
    break;

  case 19:
#line 217 "parse.y"
    { yyclass = copy_string( nmstr ); }
    break;

  case 20:
#line 219 "parse.y"
    { headerfilename = copy_string( nmstr ); }
    break;

  case 21:
#line 223 "parse.y"
    { scon_stk_ptr = (yyvsp[-3]); }
    break;

  case 22:
#line 225 "parse.y"
    { scon_stk_ptr = (yyvsp[-3]); }
    break;

  case 24:
#line 230 "parse.y"
    {
			/* Initialize for a parse of one rule. */
			trlcontxt = variable_trail_rule = varlength = false;
			trailcnt = headcnt = rulelen = 0;
			current_state_type = STATE_NORMAL;
			previous_continued_action = continued_action;
			in_rule = true;

			new_rule();
			}
    break;

  case 25:
#line 243 "parse.y"
    {
			pat = (yyvsp[0]);
			finish_rule( pat, variable_trail_rule,
				headcnt, trailcnt );

			if ( scon_stk_ptr > 0 )
				{
				for ( i = 1; i <= scon_stk_ptr; ++i )
					scbol[scon_stk[i]] =
						mkbranch( scbol[scon_stk[i]],
								pat );
				}

			else
				{
				/* Add to all non-exclusive start conditions,
				 * including the default (0) start condition.
				 */

				for ( i = 1; i <= lastsc; ++i )
					if ( ! scxclu[i] )
						scbol[i] = mkbranch( scbol[i],
									pat );
				}

			if ( ! bol_needed )
				{
				bol_needed = true;

				if ( performance_report > 1 )
					pinpoint_message(
			"'^' operator results in sub-optimal performance" );
				}
			}
    break;

  case 26:
#line 279 "parse.y"
    {
			pat = (yyvsp[0]);
			finish_rule( pat, variable_trail_rule,
				headcnt, trailcnt );

			if ( scon_stk_ptr > 0 )
				{
				for ( i = 1; i <= scon_stk_ptr; ++i )
					scset[scon_stk[i]] =
						mkbranch( scset[scon_stk[i]],
								pat );
				}

			else
				{
				for ( i = 1; i <= lastsc; ++i )
					if ( ! scxclu[i] )
						scset[i] =
							mkbranch( scset[i],
								pat );
				}
			}
    break;

  case 27:
#line 303 "parse.y"
    {
			if ( scon_stk_ptr > 0 )
				build_eof_action();
	
			else
				{
				/* This EOF applies to all start conditions
				 * which don't already have EOF actions.
				 */
				for ( i = 1; i <= lastsc; ++i )
					if ( ! sceof[i] )
						scon_stk[++scon_stk_ptr] = i;

				if ( scon_stk_ptr == 0 )
					warn(
			"all start conditions already have <<EOF>> rules" );

				else
					build_eof_action();
				}
			}
    break;

  case 28:
#line 326 "parse.y"
    { synerr( _("unrecognized rule") ); }
    break;

  case 29:
#line 330 "parse.y"
    { (yyval) = scon_stk_ptr; }
    break;

  case 30:
#line 334 "parse.y"
    { (yyval) = (yyvsp[-2]); }
    break;

  case 31:
#line 337 "parse.y"
    {
			(yyval) = scon_stk_ptr;

			for ( i = 1; i <= lastsc; ++i )
				{
				int j;

				for ( j = 1; j <= scon_stk_ptr; ++j )
					if ( scon_stk[j] == i )
						break;

				if ( j > scon_stk_ptr )
					scon_stk[++scon_stk_ptr] = i;
				}
			}
    break;

  case 32:
#line 354 "parse.y"
    { (yyval) = scon_stk_ptr; }
    break;

  case 35:
#line 362 "parse.y"
    { synerr( _("bad start condition list") ); }
    break;

  case 36:
#line 366 "parse.y"
    {
			if ( (scnum = sclookup( nmstr )) == 0 )
				format_pinpoint_message(
					"undeclared start condition %s",
					nmstr );
			else
				{
				for ( i = 1; i <= scon_stk_ptr; ++i )
					if ( scon_stk[i] == scnum )
						{
						format_warn(
							"<%s> specified twice",
							scname[scnum] );
						break;
						}

				if ( i > scon_stk_ptr )
					scon_stk[++scon_stk_ptr] = scnum;
				}
			}
    break;

  case 37:
#line 389 "parse.y"
    {
			if ( transchar[lastst[(yyvsp[0])]] != SYM_EPSILON )
				/* Provide final transition \now/ so it
				 * will be marked as a trailing context
				 * state.
				 */
				(yyvsp[0]) = link_machines( (yyvsp[0]),
						mkstate( SYM_EPSILON ) );

			mark_beginning_as_normal( (yyvsp[0]) );
			current_state_type = STATE_NORMAL;

			if ( previous_continued_action )
				{
				/* We need to treat this as variable trailing
				 * context so that the backup does not happen
				 * in the action but before the action switch
				 * statement.  If the backup happens in the
				 * action, then the rules "falling into" this
				 * one's action will *also* do the backup,
				 * erroneously.
				 */
				if ( ! varlength || headcnt != 0 )
					warn(
		"trailing context made variable due to preceding '|' action" );

				/* Mark as variable. */
				varlength = true;
				headcnt = 0;
				}

			if ( lex_compat || (varlength && headcnt == 0) )
				{ /* variable trailing context rule */
				/* Mark the first part of the rule as the
				 * accepting "head" part of a trailing
				 * context rule.
				 *
				 * By the way, we didn't do this at the
				 * beginning of this production because back
				 * then current_state_type was set up for a
				 * trail rule, and add_accept() can create
				 * a new state ...
				 */
				add_accept( (yyvsp[-1]),
					num_rules | YY_TRAILING_HEAD_MASK );
				variable_trail_rule = true;
				}
			
			else
				trailcnt = rulelen;

			(yyval) = link_machines( (yyvsp[-1]), (yyvsp[0]) );
			}
    break;

  case 38:
#line 444 "parse.y"
    { synerr( _("trailing context used twice") ); }
    break;

  case 39:
#line 447 "parse.y"
    {
			headcnt = 0;
			trailcnt = 1;
			rulelen = 1;
			varlength = false;

			current_state_type = STATE_TRAILING_CONTEXT;

			if ( trlcontxt )
				{
				synerr( _("trailing context used twice") );
				(yyval) = mkstate( SYM_EPSILON );
				}

			else if ( previous_continued_action )
				{
				/* See the comment in the rule for "re2 re"
				 * above.
				 */
				warn(
		"trailing context made variable due to preceding '|' action" );

				varlength = true;
				}

			if ( lex_compat || varlength )
				{
				/* Again, see the comment in the rule for
				 * "re2 re" above.
				 */
				add_accept( (yyvsp[-1]),
					num_rules | YY_TRAILING_HEAD_MASK );
				variable_trail_rule = true;
				}

			trlcontxt = true;

			eps = mkstate( SYM_EPSILON );
			(yyval) = link_machines( (yyvsp[-1]),
				link_machines( eps, mkstate( '\n' ) ) );
			}
    break;

  case 40:
#line 490 "parse.y"
    {
			(yyval) = (yyvsp[0]);

			if ( trlcontxt )
				{
				if ( lex_compat || (varlength && headcnt == 0) )
					/* Both head and trail are
					 * variable-length.
					 */
					variable_trail_rule = true;
				else
					trailcnt = rulelen;
				}
			}
    break;

  case 41:
#line 508 "parse.y"
    {
			varlength = true;
			(yyval) = mkor( (yyvsp[-2]), (yyvsp[0]) );
			}
    break;

  case 42:
#line 514 "parse.y"
    { (yyval) = (yyvsp[0]); }
    break;

  case 43:
#line 519 "parse.y"
    {
			/* This rule is written separately so the
			 * reduction will occur before the trailing
			 * series is parsed.
			 */

			if ( trlcontxt )
				synerr( _("trailing context used twice") );
			else
				trlcontxt = true;

			if ( varlength )
				/* We hope the trailing context is
				 * fixed-length.
				 */
				varlength = false;
			else
				headcnt = rulelen;

			rulelen = 0;

			current_state_type = STATE_TRAILING_CONTEXT;
			(yyval) = (yyvsp[-1]);
			}
    break;

  case 44:
#line 546 "parse.y"
    {
			/* This is where concatenation of adjacent patterns
			 * gets done.
			 */
			(yyval) = link_machines( (yyvsp[-1]), (yyvsp[0]) );
			}
    break;

  case 45:
#line 554 "parse.y"
    { (yyval) = (yyvsp[0]); }
    break;

  case 46:
#line 557 "parse.y"
    {
			varlength = true;

			if ( (yyvsp[-3]) > (yyvsp[-1]) || (yyvsp[-3]) < 0 )
				{
				synerr( _("bad iteration values") );
				(yyval) = (yyvsp[-5]);
				}
			else
				{
				if ( (yyvsp[-3]) == 0 )
					{
					if ( (yyvsp[-1]) <= 0 )
						{
						synerr(
						_("bad iteration values") );
						(yyval) = (yyvsp[-5]);
						}
					else
						(yyval) = mkopt(
							mkrep( (yyvsp[-5]), 1, (yyvsp[-1]) ) );
					}
				else
					(yyval) = mkrep( (yyvsp[-5]), (yyvsp[-3]), (yyvsp[-1]) );
				}
			}
    break;

  case 47:
#line 585 "parse.y"
    {
			varlength = true;

			if ( (yyvsp[-2]) <= 0 )
				{
				synerr( _("iteration value must be positive") );
				(yyval) = (yyvsp[-4]);
				}

			else
				(yyval) = mkrep( (yyvsp[-4]), (yyvsp[-2]), INFINITY );
			}
    break;

  case 48:
#line 599 "parse.y"
    {
			/* The series could be something like "(foo)",
			 * in which case we have no idea what its length
			 * is, so we punt here.
			 */
			varlength = true;

			if ( (yyvsp[-1]) <= 0 )
				{
				  synerr( _("iteration value must be positive")
					  );
				(yyval) = (yyvsp[-3]);
				}

			else
				(yyval) = link_machines( (yyvsp[-3]),
						copysingl( (yyvsp[-3]), (yyvsp[-1]) - 1 ) );
			}
    break;

  case 49:
#line 621 "parse.y"
    {
			varlength = true;

			(yyval) = mkclos( (yyvsp[-1]) );
			}
    break;

  case 50:
#line 628 "parse.y"
    {
			varlength = true;
			(yyval) = mkposcl( (yyvsp[-1]) );
			}
    break;

  case 51:
#line 634 "parse.y"
    {
			varlength = true;
			(yyval) = mkopt( (yyvsp[-1]) );
			}
    break;

  case 52:
#line 640 "parse.y"
    {
			varlength = true;

			if ( (yyvsp[-3]) > (yyvsp[-1]) || (yyvsp[-3]) < 0 )
				{
				synerr( _("bad iteration values") );
				(yyval) = (yyvsp[-5]);
				}
			else
				{
				if ( (yyvsp[-3]) == 0 )
					{
					if ( (yyvsp[-1]) <= 0 )
						{
						synerr(
						_("bad iteration values") );
						(yyval) = (yyvsp[-5]);
						}
					else
						(yyval) = mkopt(
							mkrep( (yyvsp[-5]), 1, (yyvsp[-1]) ) );
					}
				else
					(yyval) = mkrep( (yyvsp[-5]), (yyvsp[-3]), (yyvsp[-1]) );
				}
			}
    break;

  case 53:
#line 668 "parse.y"
    {
			varlength = true;

			if ( (yyvsp[-2]) <= 0 )
				{
				synerr( _("iteration value must be positive") );
				(yyval) = (yyvsp[-4]);
				}

			else
				(yyval) = mkrep( (yyvsp[-4]), (yyvsp[-2]), INFINITY );
			}
    break;

  case 54:
#line 682 "parse.y"
    {
			/* The singleton could be something like "(foo)",
			 * in which case we have no idea what its length
			 * is, so we punt here.
			 */
			varlength = true;

			if ( (yyvsp[-1]) <= 0 )
				{
				synerr( _("iteration value must be positive") );
				(yyval) = (yyvsp[-3]);
				}

			else
				(yyval) = link_machines( (yyvsp[-3]),
						copysingl( (yyvsp[-3]), (yyvsp[-1]) - 1 ) );
			}
    break;

  case 55:
#line 701 "parse.y"
    {
			if ( ! madeany )
				{
				/* Create the '.' character class. */
				anyccl = cclinit();
				ccladd( anyccl, '\n' );
				cclnegate( anyccl );

				if ( useecs )
					mkeccl( ccltbl + cclmap[anyccl],
						ccllen[anyccl], nextecm,
						ecgroup, csize, csize );

				madeany = true;
				}

			++rulelen;

			(yyval) = mkstate( -anyccl );
			}
    break;

  case 56:
#line 723 "parse.y"
    {
			if ( ! cclsorted )
				/* Sort characters for fast searching.  We
				 * use a shell sort since this list could
				 * be large.
				 */
				cshell( ccltbl + cclmap[(yyvsp[0])], ccllen[(yyvsp[0])], true );

			if ( useecs )
				mkeccl( ccltbl + cclmap[(yyvsp[0])], ccllen[(yyvsp[0])],
					nextecm, ecgroup, csize, csize );

			++rulelen;

			(yyval) = mkstate( -(yyvsp[0]) );
			}
    break;

  case 57:
#line 741 "parse.y"
    {
			++rulelen;

			(yyval) = mkstate( -(yyvsp[0]) );
			}
    break;

  case 58:
#line 748 "parse.y"
    { (yyval) = (yyvsp[-1]); }
    break;

  case 59:
#line 751 "parse.y"
    { (yyval) = (yyvsp[-1]); }
    break;

  case 60:
#line 754 "parse.y"
    {
			++rulelen;

			if ( caseins && (yyvsp[0]) >= 'A' && (yyvsp[0]) <= 'Z' )
				(yyvsp[0]) = clower( (yyvsp[0]) );

			(yyval) = mkstate( (yyvsp[0]) );
			}
    break;

  case 61:
#line 765 "parse.y"
    { (yyval) = (yyvsp[-1]); }
    break;

  case 62:
#line 768 "parse.y"
    {
			cclnegate( (yyvsp[-1]) );
			(yyval) = (yyvsp[-1]);
			}
    break;

  case 63:
#line 775 "parse.y"
    {
			if ( caseins )
				{
				if ( (yyvsp[-2]) >= 'A' && (yyvsp[-2]) <= 'Z' )
					(yyvsp[-2]) = clower( (yyvsp[-2]) );
				if ( (yyvsp[0]) >= 'A' && (yyvsp[0]) <= 'Z' )
					(yyvsp[0]) = clower( (yyvsp[0]) );
				}

			if ( (yyvsp[-2]) > (yyvsp[0]) )
				synerr( _("negative range in character class") );

			else
				{
				for ( i = (yyvsp[-2]); i <= (yyvsp[0]); ++i )
					ccladd( (yyvsp[-3]), i );

				/* Keep track if this ccl is staying in
				 * alphabetical order.
				 */
				cclsorted = cclsorted && ((yyvsp[-2]) > lastchar);
				lastchar = (yyvsp[0]);
				}

			(yyval) = (yyvsp[-3]);
			}
    break;

  case 64:
#line 803 "parse.y"
    {
			if ( caseins && (yyvsp[0]) >= 'A' && (yyvsp[0]) <= 'Z' )
				(yyvsp[0]) = clower( (yyvsp[0]) );

			ccladd( (yyvsp[-1]), (yyvsp[0]) );
			cclsorted = cclsorted && ((yyvsp[0]) > lastchar);
			lastchar = (yyvsp[0]);
			(yyval) = (yyvsp[-1]);
			}
    break;

  case 65:
#line 814 "parse.y"
    {
			/* Too hard to properly maintain cclsorted. */
			cclsorted = false;
			(yyval) = (yyvsp[-1]);
			}
    break;

  case 66:
#line 821 "parse.y"
    {
			cclsorted = true;
			lastchar = 0;
			currccl = (yyval) = cclinit();
			}
    break;

  case 67:
#line 828 "parse.y"
    { CCL_EXPR(isalnum) }
    break;

  case 68:
#line 829 "parse.y"
    { CCL_EXPR(isalpha) }
    break;

  case 69:
#line 830 "parse.y"
    { CCL_EXPR(IS_BLANK) }
    break;

  case 70:
#line 831 "parse.y"
    { CCL_EXPR(iscntrl) }
    break;

  case 71:
#line 832 "parse.y"
    { CCL_EXPR(isdigit) }
    break;

  case 72:
#line 833 "parse.y"
    { CCL_EXPR(isgraph) }
    break;

  case 73:
#line 834 "parse.y"
    { CCL_EXPR(islower) }
    break;

  case 74:
#line 835 "parse.y"
    { CCL_EXPR(isprint) }
    break;

  case 75:
#line 836 "parse.y"
    { CCL_EXPR(ispunct) }
    break;

  case 76:
#line 837 "parse.y"
    { CCL_EXPR(isspace) }
    break;

  case 77:
#line 838 "parse.y"
    {
				if ( caseins )
					CCL_EXPR(islower)
				else
					CCL_EXPR(isupper)
				}
    break;

  case 78:
#line 844 "parse.y"
    { CCL_EXPR(isxdigit) }
    break;

  case 79:
#line 848 "parse.y"
    {
			if ( caseins && (yyvsp[0]) >= 'A' && (yyvsp[0]) <= 'Z' )
				(yyvsp[0]) = clower( (yyvsp[0]) );

			++rulelen;

			(yyval) = link_machines( (yyvsp[-1]), mkstate( (yyvsp[0]) ) );
			}
    break;

  case 80:
#line 858 "parse.y"
    { (yyval) = mkstate( SYM_EPSILON ); }
    break;


    }

/* Line 1037 of yacc.c.  */
#line 2136 "parse.c"

  yyvsp -= yylen;
  yyssp -= yylen;


  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (YYPACT_NINF < yyn && yyn < YYLAST)
	{
	  YYSIZE_T yysize = 0;
	  int yytype = YYTRANSLATE (yychar);
	  const char* yyprefix;
	  char *yymsg;
	  int yyx;

	  /* Start YYX at -YYN if negative to avoid negative indexes in
	     YYCHECK.  */
	  int yyxbegin = yyn < 0 ? -yyn : 0;

	  /* Stay within bounds of both yycheck and yytname.  */
	  int yychecklim = YYLAST - yyn;
	  int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
	  int yycount = 0;

	  yyprefix = ", expecting ";
	  for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	      {
		yysize += yystrlen (yyprefix) + yystrlen (yytname [yyx]);
		yycount += 1;
		if (yycount == 5)
		  {
		    yysize = 0;
		    break;
		  }
	      }
	  yysize += (sizeof ("syntax error, unexpected ")
		     + yystrlen (yytname[yytype]));
	  yymsg = (char *) YYSTACK_ALLOC (yysize);
	  if (yymsg != 0)
	    {
	      char *yyp = yystpcpy (yymsg, "syntax error, unexpected ");
	      yyp = yystpcpy (yyp, yytname[yytype]);

	      if (yycount < 5)
		{
		  yyprefix = ", expecting ";
		  for (yyx = yyxbegin; yyx < yyxend; ++yyx)
		    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
		      {
			yyp = yystpcpy (yyp, yyprefix);
			yyp = yystpcpy (yyp, yytname[yyx]);
			yyprefix = " or ";
		      }
		}
	      yyerror (yymsg);
	      YYSTACK_FREE (yymsg);
	    }
	  else
	    yyerror ("syntax error; also virtual memory exhausted");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror ("syntax error");
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* If at end of input, pop the error token,
	     then the rest of the stack, then return failure.  */
	  if (yychar == YYEOF)
	     for (;;)
	       {

		 YYPOPSTACK;
		 if (yyssp == yyss)
		   YYABORT;
		 yydestruct ("Error: popping",
                             yystos[*yyssp], yyvsp);
	       }
        }
      else
	{
	  yydestruct ("Error: discarding", yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

#ifdef __GNUC__
  /* Pacify GCC when the user code never invokes YYERROR and the label
     yyerrorlab therefore never appears in user code.  */
  if (0)
     goto yyerrorlab;
#endif

yyvsp -= yylen;
  yyssp -= yylen;
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping", yystos[yystate], yyvsp);
      YYPOPSTACK;
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token. */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yydestruct ("Error: discarding lookahead",
              yytoken, &yylval);
  yychar = YYEMPTY;
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*----------------------------------------------.
| yyoverflowlab -- parser overflow comes here.  |
`----------------------------------------------*/
yyoverflowlab:
  yyerror ("parser stack overflow");
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  return yyresult;
}


#line 861 "parse.y"



/* build_eof_action - build the "<<EOF>>" action for the active start
 *                    conditions
 */

void build_eof_action()
	{
	register int i;
	char action_text[MAXLINE];

	for ( i = 1; i <= scon_stk_ptr; ++i )
		{
		if ( sceof[scon_stk[i]] )
			format_pinpoint_message(
				"multiple <<EOF>> rules for start condition %s",
				scname[scon_stk[i]] );

		else
			{
			sceof[scon_stk[i]] = true;
			sprintf( action_text, "case YY_STATE_EOF(%s):\n",
				scname[scon_stk[i]] );
			add_action( action_text );
			}
		}

	line_directive_out( (FILE *) 0, 1 );

	/* This isn't a normal rule after all - don't count it as
	 * such, so we don't have any holes in the rule numbering
	 * (which make generating "rule can never match" warnings
	 * more difficult.
	 */
	--num_rules;
	++num_eof_rules;
	}


/* format_synerr - write out formatted syntax error */

void format_synerr( msg, arg )
const char *msg, arg[];
	{
	char errmsg[MAXLINE];

	(void) sprintf( errmsg, msg, arg );
	synerr( errmsg );
	}


/* synerr - report a syntax error */

void synerr( str )
const char *str;
	{
	syntaxerror = true;
	pinpoint_message( str );
	}


/* format_warn - write out formatted warning */

void format_warn( msg, arg )
const char *msg, arg[];
	{
	char warn_msg[MAXLINE];

	(void) sprintf( warn_msg, msg, arg );
	warn( warn_msg );
	}


/* warn - report a warning, unless -w was given */

void warn( str )
const char *str;
	{
	line_warning( str, linenum );
	}

/* format_pinpoint_message - write out a message formatted with one string,
 *			     pinpointing its location
 */

void format_pinpoint_message( msg, arg )
const char *msg, arg[];
	{
	char errmsg[MAXLINE];

	(void) sprintf( errmsg, msg, arg );
	pinpoint_message( errmsg );
	}


/* pinpoint_message - write out a message, pinpointing its location */

void pinpoint_message( str )
const char *str;
	{
	line_pinpoint( str, linenum );
	}


/* line_warning - report a warning at a given line, unless -w was given */

void line_warning( str, line )
const char *str;
int line;
	{
	char warning[MAXLINE];

	if ( ! nowarn )
		{
		sprintf( warning, "warning, %s", str );
		line_pinpoint( warning, line );
		}
	}


/* line_pinpoint - write out a message, pinpointing it at the given line */

void line_pinpoint( str, line )
const char *str;
int line;
	{
	fprintf( stderr, "%s: %d: %s\n", infilename, line, str );
	}


/* yyerror - eat up an error message from the parser;
 *	     currently, messages are ignore
 */

void yyerror( msg )
const char *msg;
	{
	}

