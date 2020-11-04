
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
#line 1 "TP4.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define YYDEBUG 1

extern int lineno;
extern FILE * yyin;

char* tipoDato;
char* idFuncion;
char* tipoFuncion;

int flag_error=0;
int contador=0;

int yylex();
int yywrap(){
	return(1);
}

void yyerror (char const *s);



/* Line 189 of yacc.c  */
#line 100 "TP4.tab.c"

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
#line 27 "TP4.y"

char* cadena;          
int entero;                     
int tipo;
double real;
char caracter;




/* Line 214 of yacc.c  */
#line 179 "TP4.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 191 "TP4.tab.c"

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
#define YYLAST   492

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  36
/* YYNRULES -- Number of rules.  */
#define YYNRULES  110
/* YYNRULES -- Number of states.  */
#define YYNSTATES  176

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
       0,     0,     3,     4,     7,    10,    12,    14,    16,    18,
      20,    22,    24,    26,    28,    30,    32,    35,    38,    39,
      43,    44,    48,    50,    56,    64,    70,    72,    77,    81,
      83,    87,    89,    91,   101,   107,   115,   117,   119,   124,
     125,   127,   128,   131,   136,   138,   140,   141,   148,   150,
     152,   154,   158,   160,   162,   163,   168,   171,   173,   177,
     179,   182,   184,   185,   187,   189,   191,   193,   195,   198,
     200,   205,   209,   211,   215,   217,   219,   221,   223,   227,
     229,   231,   235,   237,   239,   241,   243,   245,   249,   253,
     257,   261,   263,   267,   271,   273,   275,   277,   279,   283,
     287,   291,   295,   299,   303,   305,   307,   310,   313,   316,
     319
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      49,     0,    -1,    -1,    49,    51,    -1,    49,     1,    -1,
       4,    -1,     8,    -1,    53,    -1,    69,    -1,    72,    -1,
      60,    -1,    57,    -1,    56,    -1,    58,    -1,    52,    -1,
      42,    -1,    19,    42,    -1,    20,    42,    -1,    -1,     7,
      54,    63,    -1,    -1,     9,    55,    64,    -1,     1,    -1,
      11,    43,    78,    44,    51,    -1,    11,    43,    78,    44,
      51,    17,    51,    -1,    16,    43,    78,    44,    51,    -1,
       1,    -1,    14,    59,    45,    51,    -1,    15,    45,    51,
      -1,     1,    -1,    18,    78,    42,    -1,    50,    -1,     3,
      -1,    10,    43,    61,    42,    62,    42,    62,    44,    51,
      -1,    12,    43,    78,    44,    51,    -1,    13,    51,    12,
      43,    78,    44,    42,    -1,     1,    -1,    78,    -1,     7,
       6,    36,    78,    -1,    -1,    78,    -1,    -1,    76,    42,
      -1,    76,    41,    67,    42,    -1,    64,    -1,     1,    -1,
      -1,     6,    65,    43,    68,    44,    66,    -1,     1,    -1,
      42,    -1,    69,    -1,    76,    41,    67,    -1,    76,    -1,
       1,    -1,    -1,     7,     6,    41,    68,    -1,     7,     6,
      -1,     1,    -1,    46,    70,    47,    -1,     1,    -1,    51,
      70,    -1,    51,    -1,    -1,     1,    -1,    39,    -1,    40,
      -1,    38,    -1,    37,    -1,    77,    42,    -1,     1,    -1,
       6,    43,    77,    44,    -1,     6,    43,    44,    -1,     1,
      -1,     6,    75,    77,    -1,     1,    -1,    36,    -1,    71,
      -1,     6,    -1,     6,    36,    78,    -1,     1,    -1,    78,
      -1,    78,    41,    77,    -1,     1,    -1,    59,    -1,     5,
      -1,     6,    -1,    74,    -1,    78,    23,    78,    -1,    78,
      24,    78,    -1,    78,    25,    78,    -1,    78,    26,    78,
      -1,    83,    -1,    78,    27,    78,    -1,    43,    78,    44,
      -1,    80,    -1,    82,    -1,    79,    -1,    81,    -1,    78,
      34,    78,    -1,    78,    35,    78,    -1,    78,    28,    78,
      -1,    78,    29,    78,    -1,    78,    31,    78,    -1,    78,
      30,    78,    -1,    73,    -1,     1,    -1,    78,    21,    -1,
      21,     6,    -1,     6,    22,    -1,    22,     6,    -1,    24,
      78,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    76,    76,    77,    78,    81,    82,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    95,    96,    99,    99,
     100,   100,   101,   104,   105,   106,   107,   110,   111,   112,
     115,   118,   118,   121,   122,   123,   124,   128,   128,   128,
     131,   131,   134,   135,   136,   137,   140,   140,   141,   144,
     145,   148,   149,   150,   153,   154,   155,   156,   159,   160,
     163,   164,   165,   166,   169,   170,   171,   172,   175,   176,
     179,   180,   181,   184,   185,   188,   189,   192,   193,   194,
     197,   198,   199,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   226,   228,   230,   232,
     234
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
  "input", "numero", "sentencia", "sentenciaSalto", "sentenciaDeclaracion",
  "$@1", "$@2", "sentenciaSeleccion", "sentenciaEtiquetada",
  "sentenciaRetorno", "constante", "sentenciaIteracion",
  "primeraExpresionFor", "expresionOpcional", "parteFinalDeclaracion",
  "sentenciaFuncion", "$@3", "declaracionODefFuncion",
  "listaIdentificadores", "listaDeParametros", "sentenciaCompuesta",
  "listaDeSentencias", "opAsignacion", "sentenciaExpresion",
  "invocacionFuncion", "expresionDeAsignacion", "opAsignacionGeneral",
  "declaraId", "listaDeExpresiones", "expresion", "opPostDecremento",
  "opPreDecremento", "opPostIncremento", "opPreIncremento",
  "expresionUnaria", 0
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
       0,    48,    49,    49,    49,    50,    50,    51,    51,    51,
      51,    51,    51,    51,    51,    51,    52,    52,    54,    53,
      55,    53,    53,    56,    56,    56,    56,    57,    57,    57,
      58,    59,    59,    60,    60,    60,    60,    61,    61,    61,
      62,    62,    63,    63,    63,    63,    65,    64,    64,    66,
      66,    67,    67,    67,    68,    68,    68,    68,    69,    69,
      70,    70,    70,    70,    71,    71,    71,    71,    72,    72,
      73,    73,    73,    74,    74,    75,    75,    76,    76,    76,
      77,    77,    77,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    79,    80,    81,    82,
      83
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     0,     3,
       0,     3,     1,     5,     7,     5,     1,     4,     3,     1,
       3,     1,     1,     9,     5,     7,     1,     1,     4,     0,
       1,     0,     2,     4,     1,     1,     0,     6,     1,     1,
       1,     3,     1,     1,     0,     4,     2,     1,     3,     1,
       2,     1,     0,     1,     1,     1,     1,     1,     2,     1,
       4,     3,     1,     3,     1,     1,     1,     1,     3,     1,
       1,     3,     1,     1,     1,     1,     1,     3,     3,     3,
       3,     1,     3,     3,     1,     1,     1,     1,     3,     3,
       3,     3,     3,     3,     1,     1,     2,     2,     2,     2,
       2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,     4,    32,     5,    84,    85,    18,     6,
      20,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    15,     0,     0,    31,     3,    14,
       7,    12,    11,    13,    83,    10,     8,     9,   104,    86,
       0,    80,    96,    94,    97,    95,    91,   108,    75,    67,
      66,    64,    65,     0,    76,     0,     0,     0,     0,     0,
       0,    22,     0,     0,     0,     0,    72,     0,    16,    17,
     107,   109,   110,     0,    22,     0,     0,    68,   106,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    72,    71,     0,    73,    45,    77,    19,    44,     0,
      48,    46,    21,     0,     0,    37,     0,     0,     0,     0,
      28,     0,    30,    93,    60,    58,    87,    88,    89,    90,
      92,   100,   101,   103,   102,    98,    99,    81,    70,     0,
       0,     0,    42,     0,     0,     0,     0,     0,    27,     0,
      78,     0,    53,    77,     0,    52,     0,     0,    40,    23,
      34,     0,    25,    57,     0,     0,    43,     0,    38,     0,
       0,     0,    56,     0,    51,     0,    24,    35,     0,    59,
      49,    47,    50,     0,    55,    33
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    27,    75,    29,    30,    56,    57,    31,    32,
      33,    34,    35,   104,   147,    97,    98,   130,   171,   144,
     155,    36,    76,    54,    37,    38,    39,    55,   145,    40,
      41,    42,    43,    44,    45,    46
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -52
static const yytype_int16 yypact[] =
{
     -52,    11,   -52,   448,   -52,   -52,   -52,    87,   -52,   -52,
     -52,   -34,    -5,    -3,   189,    44,   -38,     6,   275,   -14,
       9,    52,    53,   275,   -52,   275,    74,   -52,   -52,   -52,
     -52,   -52,   -52,   -52,   -52,   -52,   -52,   -52,   -52,   -52,
      19,   431,   -52,   -52,   -52,   -52,   -52,   -52,   -52,   -52,
     -52,   -52,   -52,   215,   -52,   299,    54,   112,   245,   275,
     275,   448,    64,    46,   189,   275,   -52,   411,   -52,   -52,
     -52,   -52,    76,   301,   448,   142,    50,   -52,   -52,   275,
     275,   275,   275,   275,   275,   275,   275,   275,   275,   275,
     299,   -52,   -52,    56,   -52,    71,    -2,   -52,   -52,   -36,
     -52,   -52,   -52,   109,    90,   152,   323,   345,    86,   189,
     -52,   367,   -52,   -52,   -52,   -52,    76,    76,   457,   457,
     226,     2,     2,     2,     2,   101,   -52,   -52,   -52,   275,
      94,   127,   -52,   103,   269,   189,   189,   275,   -52,   189,
     152,    55,    71,   104,    99,   124,   275,   100,   152,   150,
     -52,   389,   -52,   -52,   162,   125,   -52,   127,   152,   221,
     189,   128,   130,     0,   -52,   147,   -52,   -52,    55,   -52,
     -52,   -52,   -52,   189,   -52,   -52
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -52,   -52,   -52,    -1,   -52,   -52,   -52,   -52,   -52,   -52,
     -52,   159,   -52,   -52,    47,   -52,   155,   -52,   -52,    57,
      49,    65,   140,   -52,   -52,   -52,   -52,   -52,   174,   -51,
     -15,   -52,   -52,   -52,   -52,   -52
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -80
static const yytype_int16 yytable[] =
{
      28,   169,    93,    67,    94,   131,   132,    64,    72,    58,
      73,     2,     3,    62,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    68,    18,
      19,    20,    21,    22,   129,    23,    88,    89,    59,   127,
      60,   -46,   170,   105,   106,   107,    26,     4,     5,    65,
     111,    69,     9,    24,    25,    95,   153,    26,    70,    71,
      96,    77,   154,   110,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,    74,   108,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,   109,    18,    19,    20,    21,    22,   115,    23,   -54,
     128,    81,    82,    83,    84,    85,    86,    87,   138,    47,
      88,    89,   -79,   100,   140,   133,    24,    25,   101,   148,
      26,   -62,   151,    48,    49,    50,    51,    52,   142,   137,
      53,   158,   134,   143,   149,   150,    89,   141,   152,   146,
     129,   156,   159,    74,   148,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,   166,
      18,    19,    20,    21,    22,   157,    23,   160,   162,   163,
     167,   168,   175,    78,    63,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    24,    25,    88,    89,    26,   -61,
      61,   173,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,   165,    18,    19,    20,
      21,    22,   102,    23,   164,   114,    91,   174,     4,     5,
       6,     7,    66,     9,     4,     5,     6,     7,   172,     9,
      99,    24,    25,     0,     0,    26,    21,    22,     0,    23,
       0,     0,    21,    22,     0,    23,    66,     0,     4,     5,
       6,     7,   103,     9,    84,    85,    86,    87,    25,    92,
      88,    89,     0,     0,    25,   -41,    21,    22,     0,    23,
      66,     0,     4,     5,     6,     7,    66,     9,     4,     5,
       6,     7,     0,     9,     0,     0,     0,   -39,    25,     0,
      21,    22,     0,    23,     0,     0,    21,    22,     0,    23,
      91,     0,     4,     5,     6,     7,     0,     9,     0,     0,
       0,   -41,    25,     0,     0,     0,     0,     0,    25,     0,
      21,    22,    78,    23,    79,    80,    81,    82,    83,    84,
      85,    86,    87,     0,     0,    88,    89,     0,     0,     0,
       0,     0,    25,     0,    78,   113,    79,    80,    81,    82,
      83,    84,    85,    86,    87,     0,     0,    88,    89,     0,
       0,     0,     0,     0,     0,     0,    78,   135,    79,    80,
      81,    82,    83,    84,    85,    86,    87,     0,     0,    88,
      89,     0,     0,     0,     0,     0,     0,     0,    78,   136,
      79,    80,    81,    82,    83,    84,    85,    86,    87,     0,
       0,    88,    89,     0,     0,     0,     0,     0,     0,     0,
      78,   139,    79,    80,    81,    82,    83,    84,    85,    86,
      87,     0,     0,    88,    89,     0,     0,     0,     0,     0,
       0,     0,    78,   161,    79,    80,    81,    82,    83,    84,
      85,    86,    87,     0,     0,    88,    89,     0,     0,     0,
       0,     0,    78,   112,    79,    80,    81,    82,    83,    84,
      85,    86,    87,     0,     0,    88,    89,     0,     0,     0,
       0,   -72,    90,   -72,   -72,   -72,   -72,   -72,   -72,   -72,
       0,     0,   -72,   -72,    83,    84,    85,    86,    87,   -72,
       0,    88,    89
};

static const yytype_int16 yycheck[] =
{
       1,     1,    53,    18,    55,    41,    42,    45,    23,    43,
      25,     0,     1,    14,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    42,    18,
      19,    20,    21,    22,    36,    24,    34,    35,    43,    90,
      43,    43,    42,    58,    59,    60,    46,     3,     4,    43,
      65,    42,     8,    42,    43,     1,     1,    46,     6,     6,
       6,    42,     7,    64,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,     1,    12,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    45,    18,    19,    20,    21,    22,    47,    24,    44,
      44,    25,    26,    27,    28,    29,    30,    31,   109,    22,
      34,    35,    41,     1,   129,     6,    42,    43,     6,   134,
      46,    47,   137,    36,    37,    38,    39,    40,     1,    43,
      43,   146,    42,     6,   135,   136,    35,    43,   139,    36,
      36,    42,    42,     1,   159,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,   160,
      18,    19,    20,    21,    22,    41,    24,    17,     6,    44,
      42,    41,   173,    21,    15,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    42,    43,    34,    35,    46,    47,
       1,    44,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,   159,    18,    19,    20,
      21,    22,    57,    24,   157,    75,     1,   168,     3,     4,
       5,     6,     1,     8,     3,     4,     5,     6,   163,     8,
      56,    42,    43,    -1,    -1,    46,    21,    22,    -1,    24,
      -1,    -1,    21,    22,    -1,    24,     1,    -1,     3,     4,
       5,     6,     7,     8,    28,    29,    30,    31,    43,    44,
      34,    35,    -1,    -1,    43,    44,    21,    22,    -1,    24,
       1,    -1,     3,     4,     5,     6,     1,     8,     3,     4,
       5,     6,    -1,     8,    -1,    -1,    -1,    42,    43,    -1,
      21,    22,    -1,    24,    -1,    -1,    21,    22,    -1,    24,
       1,    -1,     3,     4,     5,     6,    -1,     8,    -1,    -1,
      -1,    42,    43,    -1,    -1,    -1,    -1,    -1,    43,    -1,
      21,    22,    21,    24,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    -1,    -1,    34,    35,    -1,    -1,    -1,
      -1,    -1,    43,    -1,    21,    44,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    -1,    -1,    34,    35,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    21,    44,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    -1,    -1,    34,
      35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,    44,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    -1,
      -1,    34,    35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      21,    44,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    -1,    -1,    34,    35,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    21,    44,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    -1,    -1,    34,    35,    -1,    -1,    -1,
      -1,    -1,    21,    42,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    -1,    -1,    34,    35,    -1,    -1,    -1,
      -1,    23,    41,    25,    26,    27,    28,    29,    30,    31,
      -1,    -1,    34,    35,    27,    28,    29,    30,    31,    41,
      -1,    34,    35
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    49,     0,     1,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    18,    19,
      20,    21,    22,    24,    42,    43,    46,    50,    51,    52,
      53,    56,    57,    58,    59,    60,    69,    72,    73,    74,
      77,    78,    79,    80,    81,    82,    83,    22,    36,    37,
      38,    39,    40,    43,    71,    75,    54,    55,    43,    43,
      43,     1,    51,    59,    45,    43,     1,    78,    42,    42,
       6,     6,    78,    78,     1,    51,    70,    42,    21,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    34,    35,
      41,     1,    44,    77,    77,     1,     6,    63,    64,    76,
       1,     6,    64,     7,    61,    78,    78,    78,    12,    45,
      51,    78,    42,    44,    70,    47,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    77,    44,    36,
      65,    41,    42,     6,    42,    44,    44,    43,    51,    44,
      78,    43,     1,     6,    67,    76,    36,    62,    78,    51,
      51,    78,    51,     1,     7,    68,    42,    41,    78,    42,
      17,    44,     6,    44,    67,    62,    51,    42,    41,     1,
      42,    66,    69,    44,    68,    51
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
        case 18:

/* Line 1455 of yacc.c  */
#line 99 "TP4.y"
    {tipoDato = strdup((yyvsp[(1) - (1)].cadena));;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 100 "TP4.y"
    {tipoFuncion = strdup((yyvsp[(1) - (1)].cadena));;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 104 "TP4.y"
    {printf("\nSe define una sentencia IF\n");;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 105 "TP4.y"
    {printf("\nSe define una sentencia IF seguida de un ELSE\n");;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 106 "TP4.y"
    {printf("\nSe define una sentencia de tipo SWITCH\n");;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 121 "TP4.y"
    {printf("\nSe define una sentencia FOR\n");;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 122 "TP4.y"
    {printf("\nSe define una sentencia WHILE\n");;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 123 "TP4.y"
    {printf("\nSe define una sentencia DO WHILE\n");;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 134 "TP4.y"
    {;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 135 "TP4.y"
    {printf("\nSe declaro lista de variables\n");;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 136 "TP4.y"
    {tipoFuncion = strdup(tipoDato);;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 140 "TP4.y"
    {idFuncion =strdup((yyvsp[(1) - (1)].cadena));;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 140 "TP4.y"
    {;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 144 "TP4.y"
    {printf("\nSe declara la funcion %s de tipo %s \n",idFuncion,tipoFuncion);;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 145 "TP4.y"
    {printf("\nSe define la funcion %s de tipo %s\n",idFuncion,tipoFuncion);;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 179 "TP4.y"
    {printf("\nSe invoca la funcion %s con parametros\n",(yyvsp[(1) - (4)].cadena));;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 180 "TP4.y"
    {printf("\nSe invoca la funcion %s\n",(yyvsp[(1) - (3)].cadena));}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 184 "TP4.y"
    {printf("\n-->Expresion de asignacion.\n");;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 192 "TP4.y"
    {printf("\n-->Se declara el identificador %s de tipo %s sin asignacion: .\n", (yyvsp[(1) - (1)].cadena),tipoDato);;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 193 "TP4.y"
    {printf("\n-->Se declara el identificador %s de tipo %s con asignacion \n", (yyvsp[(1) - (3)].cadena),tipoDato);;}
    break;



/* Line 1455 of yacc.c  */
#line 1762 "TP4.tab.c"
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
#line 237 "TP4.y"


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
}

