
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "TP5.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define YYDEBUG 1

extern int lineno;
extern FILE * yyin;

//NODOS

typedef struct tNodoParametro
{
	char* tipo;
	struct tNodoParametro* sgte;
} tNodoParametro;

typedef tNodoParametro* tColaParametro;

typedef struct tNodoTablaDeSimb
{
	char* tipo;
	char* identificador;
	int validar;
	tColaParametro principioParametros = NULL;
	tColaParametro finalParametros = NULL;
	struct tNodoTablaDeSimb* sgte;
} tNodoTablaDeSimb;

tNodoTablaDeSimb* tablaDeSimb = NULL;


int flag_error=0;
int contador=0;

int yylex();
int yywrap(){
	return(1);
}

void yyerror (char const *s);



/* Line 189 of yacc.c  */
#line 119 "TP5.tab.c"

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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     CCHAR = 258,
     NUM = 259,
     LITERALCADENA = 260,
     ID = 261,
     TIPO_DATO = 262,
     REAL = 263,
     TOKEN_VOID = 264,
     FOR = 265,
     IF = 266,
     WHILE = 267,
     DO = 268,
     CASE = 269,
     DEFAULT = 270,
     SWITCH = 271,
     ELSE = 272,
     RETURN = 273,
     BREAK = 274,
     CONTINUE = 275,
     OP_DECREMENTO = 276,
     OP_INCREMENTO = 277,
     MAYORIGUAL = 278,
     MENORIGUAL = 279,
     NOIGUAL = 280,
     IGUALIGUAL = 281,
     YLOGICO = 282,
     OLOGICO = 283,
     DIVIDIDOIGUAL = 284,
     PORIGUAL = 285,
     MENOSIGUAL = 286,
     MASIGUAL = 287
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 46 "TP5.y"

	 char* cadena;



/* Line 214 of yacc.c  */
#line 193 "TP5.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 205 "TP5.tab.c"

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
# if YYENABLE_NLS
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
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   460

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  112
/* YYNRULES -- Number of states.  */
#define YYNSTATES  175

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   287

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      43,    44,    25,    23,    41,    24,     2,    26,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    45,    42,
      28,    36,    29,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    27,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    46,     2,    47,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    30,    31,
      32,    33,    34,    35,    37,    38,    39,    40
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     7,    10,    12,    14,    15,    18,
      20,    22,    24,    26,    28,    30,    32,    34,    37,    40,
      41,    45,    46,    50,    52,    58,    66,    72,    74,    79,
      83,    85,    89,    91,    93,   103,   109,   117,   119,   121,
     126,   127,   129,   130,   132,   137,   139,   141,   142,   149,
     151,   153,   155,   159,   161,   163,   164,   165,   171,   174,
     176,   180,   182,   185,   187,   188,   190,   192,   194,   196,
     198,   201,   203,   205,   207,   211,   213,   215,   217,   219,
     223,   225,   227,   228,   233,   235,   237,   239,   241,   243,
     247,   251,   255,   259,   261,   265,   269,   271,   273,   275,
     277,   281,   285,   289,   293,   297,   301,   303,   305,   308,
     311,   314,   317
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      49,     0,    -1,    -1,    49,    51,    -1,    49,     1,    -1,
       4,    -1,     8,    -1,    -1,    52,    54,    -1,    71,    -1,
      74,    -1,    61,    -1,    58,    -1,    57,    -1,    59,    -1,
      53,    -1,    42,    -1,    19,    42,    -1,    20,    42,    -1,
      -1,     7,    55,    64,    -1,    -1,     9,    56,    65,    -1,
       1,    -1,    11,    43,    81,    44,    51,    -1,    11,    43,
      81,    44,    51,    17,    51,    -1,    16,    43,    81,    44,
      51,    -1,     1,    -1,    14,    60,    45,    51,    -1,    15,
      45,    51,    -1,     1,    -1,    18,    81,    42,    -1,    50,
      -1,     3,    -1,    10,    43,    62,    42,    63,    42,    63,
      44,    51,    -1,    12,    43,    81,    44,    51,    -1,    13,
      51,    12,    43,    81,    44,    42,    -1,     1,    -1,    81,
      -1,     7,     6,    36,    81,    -1,    -1,    81,    -1,    -1,
      78,    -1,    78,    41,    68,    42,    -1,    65,    -1,     1,
      -1,    -1,     6,    66,    43,    69,    44,    67,    -1,     1,
      -1,    42,    -1,    71,    -1,    78,    41,    68,    -1,    78,
      -1,     1,    -1,    -1,    -1,     7,     6,    70,    41,    69,
      -1,     7,     6,    -1,     1,    -1,    46,    72,    47,    -1,
       1,    -1,    51,    72,    -1,    51,    -1,    -1,     1,    -1,
      39,    -1,    40,    -1,    38,    -1,    37,    -1,    79,    42,
      -1,     1,    -1,     6,    -1,     1,    -1,     6,    77,    79,
      -1,     1,    -1,    36,    -1,    73,    -1,     6,    -1,     6,
      36,    81,    -1,     1,    -1,    81,    -1,    -1,    81,    80,
      41,    79,    -1,     1,    -1,    60,    -1,     5,    -1,     6,
      -1,    76,    -1,    81,    23,    81,    -1,    81,    24,    81,
      -1,    81,    25,    81,    -1,    81,    26,    81,    -1,    86,
      -1,    81,    27,    81,    -1,    43,    81,    44,    -1,    83,
      -1,    85,    -1,    82,    -1,    84,    -1,    81,    34,    81,
      -1,    81,    35,    81,    -1,    81,    28,    81,    -1,    81,
      29,    81,    -1,    81,    31,    81,    -1,    81,    30,    81,
      -1,    75,    -1,     1,    -1,    81,    21,    -1,    21,     6,
      -1,     6,    22,    -1,    22,     6,    -1,    24,    81,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    92,    92,    93,    94,    97,    98,   100,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   111,   112,   115,
     115,   116,   116,   117,   120,   121,   122,   123,   126,   127,
     128,   131,   134,   134,   137,   138,   139,   140,   144,   144,
     144,   147,   147,   150,   151,   152,   153,   156,   156,   157,
     160,   161,   164,   165,   166,   169,   170,   170,   171,   173,
     176,   177,   180,   181,   182,   183,   186,   187,   188,   189,
     192,   193,   196,   197,   203,   204,   207,   208,   211,   212,
     213,   216,   217,   217,   218,   221,   222,   223,   224,   225,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   253,   255,
     257,   259,   261
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CCHAR", "NUM", "LITERALCADENA", "ID",
  "TIPO_DATO", "REAL", "TOKEN_VOID", "FOR", "IF", "WHILE", "DO", "CASE",
  "DEFAULT", "SWITCH", "ELSE", "RETURN", "BREAK", "CONTINUE",
  "OP_DECREMENTO", "OP_INCREMENTO", "'+'", "'-'", "'*'", "'/'", "'^'",
  "'<'", "'>'", "MAYORIGUAL", "MENORIGUAL", "NOIGUAL", "IGUALIGUAL",
  "YLOGICO", "OLOGICO", "'='", "DIVIDIDOIGUAL", "PORIGUAL", "MENOSIGUAL",
  "MASIGUAL", "','", "';'", "'('", "')'", "':'", "'{'", "'}'", "$accept",
  "input", "numero", "sentencia", "$@1", "sentenciaSalto",
  "sentenciaDeclaracion", "$@2", "$@3", "sentenciaSeleccion",
  "sentenciaEtiquetada", "sentenciaRetorno", "constante",
  "sentenciaIteracion", "primeraExpresionFor", "expresionOpcional",
  "parteFinalDeclaracion", "sentenciaFuncion", "$@4",
  "declaracionODefFuncion", "listaIdentificadores", "listaDeParametros",
  "$@5", "sentenciaCompuesta", "listaDeSentencias", "opAsignacion",
  "sentenciaExpresion", "invocacionFuncion", "expresionDeAsignacion",
  "opAsignacionGeneral", "declaraId", "listaDeExpresiones", "$@7",
  "expresion", "opPostDecremento", "opPreDecremento", "opPostIncremento",
  "opPreIncremento", "expresionUnaria", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,    43,    45,    42,    47,    94,    60,    62,
     278,   279,   280,   281,   282,   283,    61,   284,   285,   286,
     287,    44,    59,    40,    41,    58,   123,   125
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    48,    49,    49,    49,    50,    50,    52,    51,    51,
      51,    51,    51,    51,    51,    51,    51,    53,    53,    55,
      54,    56,    54,    54,    57,    57,    57,    57,    58,    58,
      58,    59,    60,    60,    61,    61,    61,    61,    62,    62,
      62,    63,    63,    64,    64,    64,    64,    66,    65,    65,
      67,    67,    68,    68,    68,    69,    70,    69,    69,    69,
      71,    71,    72,    72,    72,    72,    73,    73,    73,    73,
      74,    74,    75,    75,    76,    76,    77,    77,    78,    78,
      78,    79,    80,    79,    79,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    82,    83,
      84,    85,    86
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     2,     1,     1,     0,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     0,
       3,     0,     3,     1,     5,     7,     5,     1,     4,     3,
       1,     3,     1,     1,     9,     5,     7,     1,     1,     4,
       0,     1,     0,     1,     4,     1,     1,     0,     6,     1,
       1,     1,     3,     1,     1,     0,     0,     5,     2,     1,
       3,     1,     2,     1,     0,     1,     1,     1,     1,     1,
       2,     1,     1,     1,     3,     1,     1,     1,     1,     3,
       1,     1,     0,     4,     1,     1,     1,     1,     1,     3,
       3,     3,     3,     1,     3,     3,     1,     1,     1,     1,
       3,     3,     3,     3,     3,     3,     1,     1,     2,     2,
       2,     2,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,     4,    33,     5,    86,    72,     6,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    16,     0,     0,    32,     3,     0,    15,    13,
      12,    14,    85,    11,     9,    10,   106,    88,     0,    81,
      98,    96,    99,    97,    93,   110,    76,    69,    68,    66,
      67,    77,     0,     0,     0,     0,    27,     0,     0,     0,
       0,    73,     0,    17,    18,   109,   111,   112,     0,    27,
       0,     0,    23,    19,    21,     8,    70,   108,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      73,    74,     0,     0,    38,     0,     0,     0,     0,    29,
       0,    31,    95,    62,    60,     0,     0,    89,    90,    91,
      92,    94,   102,   103,   105,   104,   100,   101,     0,     0,
       0,     0,     0,     0,    28,     0,    46,    78,    20,    45,
      43,    49,    47,    22,    83,     0,     0,    41,    24,    35,
       0,    26,     0,     0,     0,    39,     0,     0,     0,    79,
       0,    54,    78,     0,    53,     0,    25,    36,    59,     0,
       0,    44,     0,     0,    56,     0,    52,    34,     0,    61,
      50,    48,    51,     0,    57
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    25,    70,    27,    28,    75,   105,   106,    29,
      30,    31,    32,    33,    93,   136,   128,   129,   143,   171,
     153,   160,   168,    34,    71,    51,    35,    36,    37,    52,
     154,    38,    89,    39,    40,    41,    42,    43,    44
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -41
static const yytype_int16 yypact[] =
{
     -41,    13,   -41,   374,   -41,   -41,   -41,    14,   -41,   -28,
       5,    17,   254,    35,   -15,    18,   134,     4,    21,    58,
      71,   134,   -41,   134,   160,   -41,   -41,    75,   -41,   -41,
     -41,   -41,   -41,   -41,   -41,   -41,   -41,   -41,    37,   393,
     -41,   -41,   -41,   -41,   -41,   -41,   -41,   -41,   -41,   -41,
     -41,   -41,   286,   110,   134,   134,   374,    68,    36,   254,
     134,   -41,   356,   -41,   -41,   -41,   -41,   417,   165,   374,
     207,    42,   -41,   -41,   -41,   -41,   -41,   -41,   134,   134,
     134,   134,   134,   134,   134,   134,   134,   134,   134,    61,
     -41,   -41,   102,    67,   393,   212,   290,    69,   254,   -41,
     312,   -41,   -41,   -41,   -41,    56,    95,   417,   417,    64,
      64,   425,   -29,   -29,   -29,   -29,    84,   -41,   286,    87,
     280,   254,   254,   134,   -41,   254,    86,   -34,   -41,   -41,
      89,   -41,   -41,   -41,   -41,   134,    94,   393,   111,   -41,
     334,   -41,   134,    98,    99,   393,    82,   254,   101,   406,
       0,    86,   108,   103,   106,   104,   -41,   -41,   -41,   143,
     107,   -41,    99,   254,   113,     3,   -41,   -41,   109,   -41,
     -41,   -41,   -41,     0,   -41
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -41,   -41,   -41,    -1,   -41,   -41,   -41,   -41,   -41,   -41,
     -41,   -41,   141,   -41,   -41,    39,   -41,    53,   -41,   -41,
      -2,    10,   -41,    22,   127,   -41,   -41,   -41,   -41,   -41,
      93,   -40,   -41,   -13,   -41,   -41,   -41,   -41,   -41
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -81
static const yytype_int16 yytable[] =
{
      26,   158,   142,    62,   169,    87,    88,   159,    67,   -47,
      68,    57,    91,     2,     3,    53,     4,     5,     6,     7,
      -7,     8,    -7,     9,    10,    11,    12,    13,    14,    15,
      59,    16,    17,    18,    19,    20,    45,    21,     4,     5,
      94,    95,    96,     8,   -55,   170,    63,   100,    54,    24,
      46,    47,    48,    49,    50,    22,    23,   126,    99,    24,
      55,    60,   127,    64,    65,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,    72,    66,   134,    76,
      97,    98,    73,    61,    74,     4,     5,     6,     7,   104,
       8,    82,    83,    84,    85,    86,   131,   124,    87,    88,
     151,   132,   118,    19,    20,   152,    21,   137,   119,   120,
     140,    61,   123,     4,     5,     6,     7,    92,     8,    88,
     138,   139,   145,   135,   141,    23,   -42,   -80,   147,   149,
     144,    19,    20,   137,    21,    61,   146,     4,     5,     6,
       7,   150,     8,   157,   142,   161,   156,   162,   163,   164,
     173,   165,   -40,    23,    58,    19,    20,   -58,    21,   133,
     166,    69,   167,     4,     5,     6,     7,    -7,     8,    -7,
       9,    10,    11,    12,    13,    14,    15,    23,    16,    17,
      18,    19,    20,   174,    21,   155,    77,   172,    78,    79,
      80,    81,    82,    83,    84,    85,    86,   103,   130,    87,
      88,     0,    22,    23,     0,     0,    24,   -64,    69,   102,
       4,     5,     6,     7,    -7,     8,    -7,     9,    10,    11,
      12,    13,    14,    15,     0,    16,    17,    18,    19,    20,
       0,    21,     0,    77,     0,    78,    79,    80,    81,    82,
      83,    84,    85,    86,     0,     0,    87,    88,     0,    22,
      23,     0,     0,    24,   -63,    56,   121,     4,     5,     6,
       7,    -7,     8,    -7,     9,    10,    11,    12,    13,    14,
      15,     0,    16,    17,    18,    19,    20,     0,    21,     0,
       0,    61,     0,     4,     5,     6,     7,    90,     8,     4,
       5,     6,     7,     0,     8,     0,    22,    23,     0,     0,
      24,    19,    20,     0,    21,     0,     0,    19,    20,     0,
      21,    77,     0,    78,    79,    80,    81,    82,    83,    84,
      85,    86,   -42,    23,    87,    88,     0,     0,     0,    23,
       0,     0,     0,    77,   122,    78,    79,    80,    81,    82,
      83,    84,    85,    86,     0,     0,    87,    88,     0,     0,
       0,     0,     0,     0,     0,    77,   125,    78,    79,    80,
      81,    82,    83,    84,    85,    86,     0,     0,    87,    88,
       0,     0,     0,     0,     0,     0,     0,    77,   148,    78,
      79,    80,    81,    82,    83,    84,    85,    86,     0,     0,
      87,    88,     0,     0,     0,     0,     0,   -73,   101,   -73,
     -73,   -73,   -73,   -73,   -73,   -73,     0,     0,   -73,   -73,
       0,     0,     0,     0,    77,   -73,    78,    79,    80,    81,
      82,    83,    84,    85,    86,     0,     0,    87,    88,    78,
       0,    80,    81,    82,    83,    84,    85,    86,     0,     0,
      87,    88,    80,    81,    82,    83,    84,    85,    86,     0,
       0,    87,    88,    83,    84,    85,    86,     0,     0,    87,
      88
};

static const yytype_int16 yycheck[] =
{
       1,     1,    36,    16,     1,    34,    35,     7,    21,    43,
      23,    12,    52,     0,     1,    43,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      45,    18,    19,    20,    21,    22,    22,    24,     3,     4,
      53,    54,    55,     8,    44,    42,    42,    60,    43,    46,
      36,    37,    38,    39,    40,    42,    43,     1,    59,    46,
      43,    43,     6,    42,     6,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,     1,     6,   118,    42,
      12,    45,     7,     1,     9,     3,     4,     5,     6,    47,
       8,    27,    28,    29,    30,    31,     1,    98,    34,    35,
       1,     6,    41,    21,    22,     6,    24,   120,     6,    42,
     123,     1,    43,     3,     4,     5,     6,     7,     8,    35,
     121,   122,   135,    36,   125,    43,    44,    41,    17,   142,
      41,    21,    22,   146,    24,     1,    42,     3,     4,     5,
       6,    43,     8,    42,    36,    42,   147,    41,    44,     6,
      41,    44,    42,    43,    13,    21,    22,    44,    24,   106,
     162,     1,   163,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    43,    18,    19,
      20,    21,    22,   173,    24,   146,    21,   165,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    70,   105,    34,
      35,    -1,    42,    43,    -1,    -1,    46,    47,     1,    44,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    -1,    18,    19,    20,    21,    22,
      -1,    24,    -1,    21,    -1,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    -1,    -1,    34,    35,    -1,    42,
      43,    -1,    -1,    46,    47,     1,    44,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    -1,    18,    19,    20,    21,    22,    -1,    24,    -1,
      -1,     1,    -1,     3,     4,     5,     6,     1,     8,     3,
       4,     5,     6,    -1,     8,    -1,    42,    43,    -1,    -1,
      46,    21,    22,    -1,    24,    -1,    -1,    21,    22,    -1,
      24,    21,    -1,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    42,    43,    34,    35,    -1,    -1,    -1,    43,
      -1,    -1,    -1,    21,    44,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    -1,    -1,    34,    35,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    21,    44,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    -1,    -1,    34,    35,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,    44,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    -1,    -1,
      34,    35,    -1,    -1,    -1,    -1,    -1,    23,    42,    25,
      26,    27,    28,    29,    30,    31,    -1,    -1,    34,    35,
      -1,    -1,    -1,    -1,    21,    41,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    -1,    -1,    34,    35,    23,
      -1,    25,    26,    27,    28,    29,    30,    31,    -1,    -1,
      34,    35,    25,    26,    27,    28,    29,    30,    31,    -1,
      -1,    34,    35,    28,    29,    30,    31,    -1,    -1,    34,
      35
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    49,     0,     1,     3,     4,     5,     6,     8,    10,
      11,    12,    13,    14,    15,    16,    18,    19,    20,    21,
      22,    24,    42,    43,    46,    50,    51,    52,    53,    57,
      58,    59,    60,    61,    71,    74,    75,    76,    79,    81,
      82,    83,    84,    85,    86,    22,    36,    37,    38,    39,
      40,    73,    77,    43,    43,    43,     1,    51,    60,    45,
      43,     1,    81,    42,    42,     6,     6,    81,    81,     1,
      51,    72,     1,     7,     9,    54,    42,    21,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    34,    35,    80,
       1,    79,     7,    62,    81,    81,    81,    12,    45,    51,
      81,    42,    44,    72,    47,    55,    56,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    41,     6,
      42,    44,    44,    43,    51,    44,     1,     6,    64,    65,
      78,     1,     6,    65,    79,    36,    63,    81,    51,    51,
      81,    51,    36,    66,    41,    81,    42,    17,    44,    81,
      43,     1,     6,    68,    78,    63,    51,    42,     1,     7,
      69,    42,    41,    44,     6,    44,    68,    51,    70,     1,
      42,    67,    71,    41,    69
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
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
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
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
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


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

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
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

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
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
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

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
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

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
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
        case 7:

/* Line 1455 of yacc.c  */
#line 100 "TP5.y"
    {tNodoTablaDeSimb* nodo = (tNodoTablaDeSimb*) malloc(sizeof(tNodoTablaDeSimb));;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 100 "TP5.y"
    {agregarATS(&nodo);;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 115 "TP5.y"
    {nodo->tipo = strdup((yyvsp[(1) - (1)].cadena));;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 116 "TP5.y"
    {nodo->tipo = strdup((yyvsp[(1) - (1)].cadena));;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 120 "TP5.y"
    {printf("\nSe define una sentencia IF\n");;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 121 "TP5.y"
    {printf("\nSe define una sentencia IF seguida de un ELSE\n");;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 122 "TP5.y"
    {printf("\nSe define una sentencia de tipo SWITCH\n");;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 137 "TP5.y"
    {printf("\nSe define una sentencia FOR\n");;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 138 "TP5.y"
    {printf("\nSe define una sentencia WHILE\n");;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 139 "TP5.y"
    {printf("\nSe define una sentencia DO WHILE\n");;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 150 "TP5.y"
    {;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 151 "TP5.y"
    {;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 156 "TP5.y"
    {nodo->validar = 1; nodo->identificador = strdup((yyvsp[(1) - (1)].cadena));}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 170 "TP5.y"
    {encolarParametro((yyvsp[(1) - (2)].cadena), &(nodo->principioParametros), &(nodo->finalParametros));;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 171 "TP5.y"
    {encolarParametro((yyvsp[(1) - (2)].cadena), nodo->principioParametros, nodo->finalParametros)
									agregarATS(&nodo);}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 196 "TP5.y"
    { tNodoTablaDeSimb* nodoActual = encontrarEnTablaDeSimb((yyvsp[(1) - (1)].cadena)); validarTipo(1,nodoActual);}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 203 "TP5.y"
    {printf("\n-->Expresion de asignacion.\n");;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 211 "TP5.y"
    {nodo->identificador = strdup((yyvsp[(1) - (1)].cadena));;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 212 "TP5.y"
    {nodo->identificador = strdup((yyvsp[(1) - (3)].cadena);;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 216 "TP5.y"
    {if(indice->sgte == NULL) compararConParametro((yyvsp[(1) - (1)].cadena), nodoActual->principioDeCola, nodoActual->finalDeCola, indice); else printf ("La invocacion no cumple con la cantidad de parametros de: %s", nodoActual->identificador);}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 217 "TP5.y"
    {/* se compara con los parametros que hay en la cola de parametros*/;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 223 "TP5.y"
    {tNodoTablaDeSimb* nodoActual2 = encontrarEnTablaDeSimb(ID); validarTipo(0,nodoActual2);;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 225 "TP5.y"
    {if(strcmp((yyvsp[(1) - (3)].cadena), (yyvsp[(3) - (3)].cadena))){
											/*error*/
										}
										else
										{
											strcpy((yyval.cadena), (yyvsp[(1) - (3)].cadena));
										}
										;}
    break;



/* Line 1455 of yacc.c  */
#line 1798 "TP5.tab.c"
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
      /* If just tried and failed to reuse lookahead token after an
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

  /* Else will try to reuse lookahead token after shifting the error
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

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
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



/* Line 1675 of yacc.c  */
#line 264 "TP5.y"


void validarTipo(int a,tNodoTablaDeSimb* nodoActual){
	if(a != nodoActual->validar){
		printf("El identificador no corresponde con su uso") //que rompa y no siga analizando
	}
}

tNodoTablaDeSimb* encontrarEnTablaDeSimb(char* identificador)
{
	tNodoTablaDeSimb* pAct = tablaDeSimb;
	while(pAct && strcmp(pAct->identificador, identificador))
	{
		pAct = pAct->sgte;
	}
	return pAct;
}


void encolarParametro(char* tipoParametro, tColaParametro* colaParametroInicio, tColaParametro* colaParametroFinal)
{
	tColaParametro p = (tColaParametro) malloc(sizeof(tColaParametro));
	p->tipo = strdup(tipoParametro);
	p->sgte = NULL;

	if(*colaParametroInicio == NULL){
		*colaParametroInicio = p;
	}
	(*colaParametroFinal)->sgte = p;
	*colaParametroFinal = p;
}

void compararConParametro(char* tipoParametroEncontrado, tColaParametro* colaParametroInicio, tColaParametro* colaParametroFinal, tColaParametro* indice)
{
	if(strcmp(indice->tipo, tipoParametroEncontrado) || indice == NULL){
		printf("** ERROR: La invocacion no corresponde con la cant o tipo de parametros que hay en la declaracion de la funcion %s ** \n\n", nodo->identificador);
		return;
	}
	else {
		indice = indice->sgte
	}

}


void agregarATS(tNodoTablaDeSimb* nodo)
{
	if(encontrarEnTablaDeSimb(nodo->identificador))
	{
		printf("** ERROR: Doble declaracion de la variable %s ** \n\n", nodo->identificador);
		free(nodo);
		return;
	}
	nodo->sgte = tablaDeSimb;
	tablaDeSimb = nodo
}


void imprimirListaVariables()
{
	printf("IDENTIFICADOR	TIPO\n\n");
	
	
	while(listaVariables)
	{
		tNodoVariable* pActivo = listaVariables;
		printf(pActivo->identificador);printf("	");printf(strcat(pActivo->tipoDato,"\n"));
		free(pActivo);
		listaVariables = listaVariables -> sgte;
	}

	free(listaVariables);
}


void yyerror (char const *s)
{
  fprintf(stderr, "Error Sintactico en la linea %d \n", lineno);
  exit(1);
}

int main ()
{
#ifdef BISON_DEBUG
        yydebug = 1;
# endif
  yyin=fopen("entrada.txt","r");
  yyparse ();

  imprimirListaVariables();
}

