/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

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
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

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
     MOVIMIENTO = 258,
     COGER = 259,
     ATACAR = 260,
     INVENTARIO = 261,
     MIRAR = 262,
     DORMIR = 263,
     EQUIPAR = 264,
     ABRIR = 265,
     USAR = 266,
     HUIR = 267,
     N = 268,
     S = 269,
     E = 270,
     O = 271,
     DIRECCION = 272,
     OBJETO = 273,
     ANIMAL = 274,
     LUGAR = 275,
     SALIR = 276,
     AYUDA = 277,
     ESTADO = 278,
     ERROR = 279
   };
#endif
/* Tokens.  */
#define MOVIMIENTO 258
#define COGER 259
#define ATACAR 260
#define INVENTARIO 261
#define MIRAR 262
#define DORMIR 263
#define EQUIPAR 264
#define ABRIR 265
#define USAR 266
#define HUIR 267
#define N 268
#define S 269
#define E 270
#define O 271
#define DIRECCION 272
#define OBJETO 273
#define ANIMAL 274
#define LUGAR 275
#define SALIR 276
#define AYUDA 277
#define ESTADO 278
#define ERROR 279




/* Copy the first part of user declarations.  */
#line 1 "aventura.y"


#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h> //Needed for strcat()
#include <ctype.h>
#include <ctype.h>
#include "namegen.c"

#include "slowprint.c"

#include "tipos.h"

#define ENEMPROB 50

int numMedidas = 0;

int accion;
int argumento;
int setup =1;
struct JUGADOR jugador;
struct MAPA mapa;
void actualizar();
void ayuda();

//struct MAPA mapa;
void inven(struct JUGADOR j);
void yyerror (char const *);


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

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 31 "aventura.y"
{
	int valInt;
	float valFloat;
	char * valString;
}
/* Line 193 of yacc.c.  */
#line 181 "aventura.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 194 "aventura.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
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
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  48
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   49

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  25
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  20
/* YYNRULES -- Number of rules.  */
#define YYNRULES  52
/* YYNRULES -- Number of states.  */
#define YYNSTATES  60

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   279

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     7,    10,    12,    14,    16,    18,
      20,    22,    24,    26,    28,    30,    32,    34,    36,    38,
      40,    42,    44,    46,    48,    50,    52,    54,    56,    58,
      60,    62,    64,    66,    69,    72,    74,    77,    80,    82,
      85,    88,    91,    94,    96,    99,   101,   104,   107,   110,
     112,   114,   117
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      26,     0,    -1,    27,    -1,    30,    -1,    30,    27,    -1,
       3,    -1,     4,    -1,     9,    -1,     7,    -1,    10,    -1,
       5,    -1,     9,    -1,    13,    -1,    14,    -1,    15,    -1,
      16,    -1,    17,    -1,    18,    -1,    19,    -1,    20,    -1,
      31,    -1,    32,    -1,    34,    -1,    35,    -1,    30,    -1,
      37,    -1,    36,    -1,    38,    -1,    39,    -1,    40,    -1,
      33,    -1,    41,    -1,    42,    -1,     3,    17,    -1,     4,
      18,    -1,    22,    -1,     9,    18,    -1,     5,    19,    -1,
       6,    -1,     7,    17,    -1,     7,    20,    -1,     7,    18,
      -1,     7,    19,    -1,    21,    -1,    10,    18,    -1,    23,
      -1,    28,    42,    -1,    42,    29,    -1,    29,    28,    -1,
      43,    -1,    44,    -1,    44,    43,    -1,    24,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    40,    40,    41,    41,    42,    42,    42,    42,    42,
      42,    42,    43,    43,    43,    43,    43,    43,    43,    43,
      44,    44,    44,    44,    44,    44,    44,    44,    44,    44,
      44,    44,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    58,    58,    59,
      60,    60,    61
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "MOVIMIENTO", "COGER", "ATACAR",
  "INVENTARIO", "MIRAR", "DORMIR", "EQUIPAR", "ABRIR", "USAR", "HUIR", "N",
  "S", "E", "O", "DIRECCION", "OBJETO", "ANIMAL", "LUGAR", "SALIR",
  "AYUDA", "ESTADO", "ERROR", "$accept", "ST", "ListaAcciones", "AcciTok",
  "ArgTok", "Accion", "Mover", "Coger", "Ayuda", "Equipar", "Atacar",
  "Inventario", "Mirar", "Salir", "Abrir", "Estado", "AcciError", "DefErr",
  "Error", "Errchar", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    25,    26,    27,    27,    28,    28,    28,    28,    28,
      28,    28,    29,    29,    29,    29,    29,    29,    29,    29,
      30,    30,    30,    30,    30,    30,    30,    30,    30,    30,
      30,    30,    30,    31,    32,    33,    34,    35,    36,    37,
      37,    37,    37,    38,    39,    40,    41,    41,    41,    42,
      43,    43,    44
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     1,     2,     2,     1,     2,
       2,     2,     2,     1,     2,     1,     2,     2,     2,     1,
       1,     2,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     5,     6,    10,    38,     8,     7,     9,    12,    13,
      14,    15,    16,    17,    18,    19,    43,    35,    45,    52,
       0,     2,     0,     0,     3,    20,    21,    30,    22,    23,
      26,    25,    27,    28,    29,    31,    32,    49,    50,    33,
      34,    37,    39,    41,    42,    40,    36,    44,     1,    46,
       5,     6,    10,     8,     7,     9,    48,     4,    47,    51
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -13
static const yytype_int8 yypact[] =
{
      -3,   -12,   -10,    14,   -13,    21,    -9,    17,   -13,   -13,
     -13,   -13,   -13,   -13,   -13,   -13,   -13,   -13,   -13,   -13,
      42,   -13,    19,    27,    -3,   -13,   -13,   -13,   -13,   -13,
     -13,   -13,   -13,   -13,   -13,   -13,     9,   -13,    19,   -13,
     -13,   -13,   -13,   -13,   -13,   -13,   -13,   -13,   -13,   -13,
     -13,   -13,   -13,   -13,   -13,   -13,   -13,   -13,   -13,   -13
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -13,   -13,    20,    22,    10,   -13,   -13,   -13,   -13,   -13,
     -13,   -13,   -13,   -13,   -13,   -13,   -13,    25,    11,   -13
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
       1,     2,     3,     4,     5,    39,     6,     7,    40,    46,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,     8,     9,    10,    11,    12,    13,    14,    15,
      50,    51,    52,    41,    53,    47,    54,    55,    42,    43,
      44,    45,    48,    19,    57,    56,    58,    49,     0,    59
};

static const yytype_int8 yycheck[] =
{
       3,     4,     5,     6,     7,    17,     9,    10,    18,    18,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    13,    14,    15,    16,    17,    18,    19,    20,
       3,     4,     5,    19,     7,    18,     9,    10,    17,    18,
      19,    20,     0,    24,    24,    23,    36,    22,    -1,    38
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     9,    10,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    17,
      18,    19,    17,    18,    19,    20,    18,    18,     0,    42,
       3,     4,     5,     7,     9,    10,    28,    27,    29,    43
};

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
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
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
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
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
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
  YYUSE (yyvaluep);

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
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

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

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
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

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

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

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
        case 11:
#line 42 "aventura.y"
    {;}
    break;

  case 33:
#line 45 "aventura.y"
    { accion = 1;argumento = dirToInt((yyvsp[(2) - (2)].valString));actualizar();printf("\n>>");}
    break;

  case 34:
#line 46 "aventura.y"
    { accion = 7;actualizar();printf("\n>>");}
    break;

  case 35:
#line 47 "aventura.y"
    { ayuda();printf("\n>>");}
    break;

  case 36:
#line 48 "aventura.y"
    { accion = 10;argumento = objToInt((yyvsp[(2) - (2)].valString));actualizar();printf("\n>>");}
    break;

  case 37:
#line 49 "aventura.y"
    {accion = 2;argumento = enemToInt((yyvsp[(2) - (2)].valString));actualizar();printf("\n>>");}
    break;

  case 38:
#line 50 "aventura.y"
    { accion = 8;actualizar();printf("\n>>");}
    break;

  case 39:
#line 51 "aventura.y"
    {  accion =5;argumento =dirToInt((yyvsp[(2) - (2)].valString));actualizar();;printf("\n>>");}
    break;

  case 40:
#line 52 "aventura.y"
    { accion =4;argumento =locToInt((yyvsp[(2) - (2)].valString));actualizar();printf("\n>>");}
    break;

  case 41:
#line 53 "aventura.y"
    { accion = 11;argumento = objToInt((yyvsp[(2) - (2)].valString));actualizar();printf("\n>>");}
    break;

  case 42:
#line 54 "aventura.y"
    { accion =3;argumento =enemToInt((yyvsp[(2) - (2)].valString));actualizar();printf("\n>>");}
    break;

  case 43:
#line 55 "aventura.y"
    {exit(1);}
    break;

  case 44:
#line 56 "aventura.y"
    {accion= 9;actualizar();printf("\n>>");}
    break;

  case 45:
#line 57 "aventura.y"
    {accion = 6; actualizar();printf("\n>>");}
    break;

  case 46:
#line 58 "aventura.y"
    {;}
    break;

  case 47:
#line 58 "aventura.y"
    {;}
    break;

  case 48:
#line 58 "aventura.y"
    {;}
    break;

  case 49:
#line 59 "aventura.y"
    {;}
    break;

  case 51:
#line 60 "aventura.y"
    {}
    break;

  case 52:
#line 61 "aventura.y"
    {;}
    break;


/* Line 1267 of yacc.c.  */
#line 1538 "aventura.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
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
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
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


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
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
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 62 "aventura.y"


void printEnem(struct ENEMIGO e);

struct ENEMIGO enegen(){
  struct ENEMIGO enemigo;

  enemigo.ataque = (rand() % 15)+1;
  enemigo.defensa = (rand() % 5)+1;
  enemigo.tipo = (rand()%6);
	enemigo.vida = (rand() % 20)+1;
	if (enemigo.tipo==juandopico){
		strcpy(enemigo.nombre ,"Juan Dopico");
	}else{
		NameGen(enemigo.nombre);
	}
  //enemigo.inventario = 0;

  //printEnem(enemigo);
  return enemigo;

}

void printEnem(struct ENEMIGO e){

  char* nombre = e.nombre;

  int ataque = e.ataque;
  int defensa = e.defensa;
  int tipo = e.tipo;
  if (tipo == 7){
    sp("No hay enemigo\n" );
  }else{

    printf("Nombre %s, Atk: %i, Def: %i,Tipo: %s \n",nombre,ataque,defensa,enemNam[tipo] );
  }

}

struct CASILLA casGen(){


  struct CASILLA casilla;

  casilla.tipo = (rand()%6);
  casilla.enemigo = enegen();
	casilla.inventario = ninguno;
  if (!randPercent(ENEMPROB)){
    casilla.enemigo.tipo=6;
  }
  return casilla;
}
void ayuda(){
	sp("Comandos disponibles:\n");
	sp("Movimiento:\n");
	sp("ir, caminar <direccion>\n");
	sp("Mirar:\n");
	sp("Mirar, observar <enemigo,lugar,direccion,objeto>\n");
	sp("Atacar:\n");
	sp("Atacar <enemigo>:\n");
	sp("Coger:\n");
	sp("Coger <objeto>\n");
	sp("Abrir:\n");
	sp("Abrir <objeto>\n");
	sp("Ver inventario:\n");
	sp("inventario\n");
	sp("Equipar:\n");
	sp("Equipar <Objeto>\n");
	sp("Estado actual:\n");
	sp("estado\n");
	sp("Para salir del juego, utiliza el comando salir\n");
	sp("El objetivo del juego es encontrar el cofre del tesoro\n");
	sp("y su llave para abrirlo, que se encuentran en alguna\n");
	sp("parte del mapa\n");
}
void printCas(struct CASILLA c){

  int tipo = c.tipo;

  struct ENEMIGO enem = c.enemigo;

  printf(" %c ",(lugNam[tipo][0]));

  //printEnem(enem);

}

void printPos(struct JUGADOR j) {
	printf("%i,%i\n",j.posX,j.posY );

}

struct MAPA mapGen(){
  struct MAPA m;


  for (int i = 0; i < MAPTAMX; i++) {

    for (int j = 0; j < MAPTAMY; j++) {
        m.casillas[i][j]=casGen();
    }
  }
	int x = rand()%MAPTAMX;
	int y = rand()%MAPTAMY;

	x = rand()%MAPTAMX;
	y = rand()%MAPTAMY;

	m.casillas[x][y].inventario = espada;
	x = rand()%MAPTAMX;
	y = rand()%MAPTAMY;

	m.casillas[x][y].inventario = pala;
	x = rand()%MAPTAMX;
	y = rand()%MAPTAMY;
	m.casillas[x][y].inventario = palo;
	x = rand()%MAPTAMX;
	y = rand()%MAPTAMY;

	m.casillas[x][y].inventario = escudo;
	x = rand()%MAPTAMX;
	y = rand()%MAPTAMY;
	m.casillas[x][y].inventario = cofre;
	x = rand()%MAPTAMX;
	y = rand()%MAPTAMY;
	m.casillas[x][y].inventario = llave;

  return m;
}

void printMap(struct MAPA m){
	printf("   0  1  2  3  4  5  6  7  8  9\n" );
  for (int i = 0; i < MAPTAMX; i++) {
		printf("%i ",i );
    for (int j = 0; j < MAPTAMY; j++) {
        //printf("(%i,%i)\n\t",i,j);

        printCas(m.casillas[i][j]);
    }
		printf("\n" );
  }
}

int randPercent(int porcentaje){
  int genNum = rand()%100;
  if (genNum<porcentaje){
    return 1;
  }else{
    return 0;
  }

}

struct JUGADOR coger(struct JUGADOR j,struct MAPA *m){
	int aux = m->casillas[j.posX][j.posY].inventario;
	if (m->casillas[j.posX][j.posY].enemigo.tipo==ausente){
		if (m->casillas[j.posX][j.posY].inventario!=ninguno){
			if (j.inventario == ninguno){
			j.inventario = m->casillas[j.posX][j.posY].inventario;
			sp("Has recogido una ");
			ws();
			sp(objNam[j.inventario]);
			m->casillas[j.posX][j.posY].inventario = ninguno;
			printf("\n" );
			return j;}
			else{

				sp("Tienes los bolsillos llenos, \n¿quieres intercambiar los objetos? [si/no]\n");
				char resp[10];
				scanf("%s",resp);

				if(strcmp(resp,"si")==0){

					m->casillas[j.posX][j.posY].inventario = j.inventario;

					j.inventario = aux;

					sp("Has intercambiado objetos\n");

				}
				else{
					sp("Decides mantener tu objeto actual\n");
				}

				return j;
			}

		}else{
			sp("No hay nada que recoger.\n");

			return j;
		}
}else{
	sp("Enemigos guardan la zona, no has podido coger nada\n");
	return j;
}

}
int dirToInt(char * dir){

	if (strcmp(dir,"norte")==0){
		return 1;
	}
	if (strcmp(dir,"este")==0){
		return 2;
	}
	if (strcmp(dir,"sur")==0){
		return 3;
	}
	if (strcmp(dir,"oeste")==0){
		return 4;
	}
}
void inven(struct JUGADOR j) {
	if(j.inventario==ninguno){
		sp("Miras en tus bolsillos, pero estan vacios");
	}else{
		sp("Miras lo que llevas encima y encuentras un");
		ws();
		sp(objNam[j.inventario]);
		sp("\n");


	}
	if (j.equipado != ninguno){
		sp("\n");
		sp("en tus manos llevas un");
		ws();
		sp(objNam[j.equipado]);

	}
	sp("\n");
	/* code */
}
int enemToInt(char * enem){
	if (strcmp(enem,"oso")==0){
		return 0;
	}
	if (strcmp(enem,"araña")==0){
		return 1;
	}
	if (strcmp(enem,"perro")==0){
		return 2;
	}
	if (strcmp(enem,"lobo")==0){
		return 3;
	}
	if (strcmp(enem,"murloc")==0){
		return 4;
	}
	if (strcmp(enem,"juandopico")==0){
		return 5;
	}
}

int objToInt(char * o){
	if (strcmp(o,"llave")==0){
		return 0;
	}
	if (strcmp(o,"espada")==0){
		return 1;
	}
	if (strcmp(o,"palo")==0){
		return 2;
	}
	if (strcmp(o,"escudo")==0){
		return 3;
	}
	if (strcmp(0,"pala")==0){
		return 4;
	}
	if (strcmp(o,"cofre")==0){
		return 5;
	}
}

int locToInt(char * enem){
	if (strcmp(enem,"casa")==0){
		return 0;
	}
	if (strcmp(enem,"bosque")==0){
		return 1;
	}
	if (strcmp(enem,"valle")==0){
		return 2;
	}
	if (strcmp(enem,"volcan")==0){
		return 3;
	}
	if (strcmp(enem,"cueva")==0){
		return 4;
	}
	if (strcmp(enem,"playa")==0){
		return 5;
	}
	if (strcmp(enem,"oceano")==0){
		return 6;
	}
}

struct JUGADOR mover(struct JUGADOR j,int dir){
  switch (dir) {
    case 1://NORTE

      j.posY = j.posY+1;
			if (j.posY>=MAPTAMY){
				sp("Has llegado al fin del mundo, felicidades!\n");
				sp("No puedes seguir caminando\n");
				j.posY = j.posY-1;
				return j;
			}
			sp("Caminas hacia el Norte\n");
			return j;


    case 2://ESTE
		j.posX = j.posX+1;
		if (j.posX>=MAPTAMX){
			sp("Has llegado al fin del mundo, felicidades!\n");
			sp("No puedes seguir caminando\n");
			j.posX = j.posX-1;
			return j;
		}
			sp("Caminas hacia el Este\n");
			return j;

    case 3://SUR
			sp("Caminas hacia el Sur\n");
      j.posY = j.posY-1;
			if (j.posY<0){
				sp("Has llegado al fin del mundo, felicidades!\n");
				sp("No puedes seguir caminando\n");
				j.posY = j.posY+1;
				return j;
			}
			return j;

    case 4://OESTE
		j.posX = j.posX-1;
		if (j.posX<0){
			sp("Has llegado al fin del mundo, felicidades!\n");
			sp("No puedes seguir caminando\n");
			j.posX = j.posX+1;
			return j;
		}
			sp("Caminas hacia el Oeste\n");
			return j;
  	}

}
void mirarObj(struct JUGADOR j,struct CASILLA c,enum OBJ o){
	if ((j.inventario== o)||(j.equipado == o)||(c.inventario == o)){
		sp(objDesc[o]);
		sp("\n");
	}else{
		sp("No encuentras lo que buscas\n");
	}
}
struct JUGADOR huir(struct JUGADOR j){
  int dir = (rand()%4)+1;
  return mover(j,dir);
}

void gameover(){
	sp("Has sido derrotado!\n\n");
	sp("GAME OVER\n");
	exit(1);
}
struct JUGADOR equipar(struct JUGADOR j, enum OBJ o){
	enum OBJ aux = j.inventario;
	if (j.inventario!=o){
		sp("No puedes equipar algo que no tienes\n");
		return j;
	}else{

		j.inventario = j.equipado;
		j.equipado = aux;
		sp("Equipas un");
		ws();
		sp(objNam[aux]);
		sp("\n");

		return j;
	}
}
struct JUGADOR atacar(struct JUGADOR j,struct MAPA * m){


	struct ENEMIGO enem = (*m).casillas[j.posX][j.posY].enemigo;
	//printEnem(enem);

  if (enem.tipo == 6){
    sp("Atacas, ¡pero no sabes a quien!\n");
		return j;
  }else{

		//printMap(*m);
    enem.vida = enem.vida+ enem.defensa - j.ataque-atkMod[j.equipado];
		sp("Atacas a tu enemigo, ");
		printf(" %i ",j.ataque+atkMod[j.equipado]-enem.defensa);
		sp("puntos de daño!\n");
		if (enem.vida<1){
			sp("Has vencido a");
			ws();
			sp(enem.nombre);
			sp("!\n");
			enem.tipo = ausente;
			(*m).casillas[j.posX][j.posY].enemigo= enem;
			//printEnem(enem);
			return j;

		}else{
			int daño = enem.ataque-j.defensa-defMod[j.equipado];
			if (daño<=0){
				daño = 0;
			}
			sp(enem.nombre);
			ws();
			sp("te ataca!\n Recibes ");

			printf(" %i ",enem.ataque-j.defensa );
			sp(" puntos de daño!\n");
			j.vida = j.vida-enem.ataque+j.defensa;

			if (j.vida<=0){
				gameover();
			}
			//printEnem(enem);
			(*m).casillas[j.posX][j.posY].enemigo= enem;
			return j;
		}

  }

}
void abrir(struct JUGADOR j, struct MAPA * m){
	if (m->casillas[j.posX][j.posY].inventario != cofre){
		sp("Aqui no hay nada que abrir\n");
	}else if (j.inventario != llave){
		sp("No eres capaz de abrir el cofre, quizas haya una llave en la zona...\n");
	}else if(m->casillas[j.posX][j.posY].enemigo.tipo != ausente){
		sp("Hay un enemigo cerca, parece que tendras que pelear por el cofre");
	}else{
		sp("Abres el cofre y está lleno de oro!\nFIN DE LA PARTIDA");
		exit(0);
	}
}
void mirarLugar(struct CASILLA c){
  sp("Ves un");
	ws();
  sp(lugNam[c.tipo] );
	ws();
  if (c.enemigo.tipo==6){
    sp("\nNo parece haber enemigos en la zona\n");
  }else{
    sp("\nrondando la zona hay un ");
		ws();
    sp(enemNam[c.enemigo.tipo] );
		printf("\n");
  }
	if (c.inventario != ninguno){
		sp("Alguien se ha dejado un");
		ws();
		sp(objNam[c.inventario]);
		ws();
		sp("en el suelo\n");
	}
}

void mirarLoc(int i){
	sp(lugDesc[i]);

}

void mirarAnimal(struct ENEMIGO e){
  if (e.tipo==7){
    sp("No parece haber enemigos en la zona");
  }else{
    sp("Observas un ");
    printf("%s\n",enemNam[e.tipo] );
		sp("\tNombre: ");
		printf(" %s\n",e.nombre );
    sp("\tPuntos de Vida:");
    printf(" %i\n",e.vida );
    sp("\tAtaque:");
    printf(" %i\n",e.ataque );
    sp("\tDefensa:");
    printf(" %i\n",e.defensa );
		sp(enemDesc[e.tipo] );
		printf("\n");
  }
}
void printStatus(struct JUGADOR j) {
	sp("Vida:");
	printf(" %i\n",j.vida );
	sp("Ataque:");
	printf(" %i\n",j.ataque+atkMod[j.equipado] );
	sp("Defensa:");
	printf(" %i\n",j.defensa+defMod[j.equipado] );
}
void actualizar(){

	if (setup){

		jugador.vida = 20;
		jugador.ataque = 5;
		jugador.defensa = 0;
		jugador.posX = MAPTAMX/2;
		jugador.posY = MAPTAMY/2;
		jugador.inventario = palo;
		jugador.equipado = ninguno;

		mapa = mapGen();

		mirarLugar(mapa.casillas[jugador.posX][jugador.posY]);
		setup = 0;
		printf(">>" );
	}
	switch (accion) {

		case  1:

			jugador=mover(jugador,argumento);
			mirarLugar(mapa.casillas[jugador.posX][jugador.posY]);
			printPos(jugador);
			break;

		case 2:
			if (mapa.casillas[jugador.posX][jugador.posY].enemigo.tipo == argumento){
				jugador =atacar(jugador,&mapa);
			}else{
				sp("Has atacado a alguien que no esta presente!\n");
			}
			break;
		case 3:
			if (mapa.casillas[jugador.posX][jugador.posY].enemigo.tipo == argumento){
				mirarAnimal(mapa.casillas[jugador.posX][jugador.posY].enemigo);
			}else{
				sp("Miras a tu alrededor, pero no encuentras lo que buscas\n");
			}
		break;
		case 4:
			if (mapa.casillas[jugador.posX][jugador.posY].tipo == argumento){
				mirarLoc(mapa.casillas[jugador.posX][jugador.posY].tipo);
			}else{
				sp("Miras a tu alrededor, pero no encuentras lo que buscas\n");
			}
			break;
		case 5:
			switch (argumento) {
				case 1:
					mirarLugar(mapa.casillas[jugador.posX][jugador.posY+1]);
					break;
				case 2:
					mirarLugar(mapa.casillas[jugador.posX+1][jugador.posY]);
					break;
				case 3:
					mirarLugar(mapa.casillas[jugador.posX][jugador.posY-1]);
					break;
				case 4:
					mirarLugar(mapa.casillas[jugador.posX-1][jugador.posY]);
					break;

			}
			break;
		case 6:
			printStatus(jugador);
			break;

		case 7:
			jugador = coger(jugador, &mapa);
			break;

		case 8:
			inven(jugador);
			break;

		case 9:
			abrir(jugador, &mapa);
			break;
		case 10:
			jugador = equipar(jugador,argumento);
			break;
		case 11:
			mirarObj(jugador,mapa.casillas[jugador.posX][jugador.posY],argumento);
			break;
	}

}

int main(int argc, char *argv[]) {
	srand(time(NULL));
	actualizar();
	yyparse();


	return 0;
}

void yyerror (char const *message) { fprintf (stderr, "%s\n", message);}

