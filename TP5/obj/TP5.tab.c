
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
#line 1 "../src/TP5.y"

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
	tColaParametro principioParametros;
	tColaParametro finalParametros;
	struct tNodoTablaDeSimb* sgte;
} tNodoTablaDeSimb;
tNodoTablaDeSimb* inicializarTablaDeSimbolos();
tNodoTablaDeSimb* encontrarEnTablaDeSimb(char*);
void compararConParametro(char* tipoParametroEncontrado, tColaParametro* indice);
void encolarParametro(char* tipoParametro, tColaParametro* colaParametroInicio, tColaParametro* colaParametroFinal);
void agregarATS(tNodoTablaDeSimb** nodo);
void imprimirListaVariables();
void imprimirListaParametros(tNodoParametro** principio, tNodoParametro** final);

tNodoTablaDeSimb* tablaDeSimb = NULL;
tNodoTablaDeSimb* nodo;
tNodoTablaDeSimb* nodoActual;
tNodoTablaDeSimb* nodoActual2;
tColaParametro indice;
void validarExistenciaYTipo(int a,tNodoTablaDeSimb* nodoActual, char* identificador);
int flag_error=0;
int contador=0;

int yylex();
int yywrap(){
	return(1);
}

void yyerror (char const *s);



/* Line 189 of yacc.c  */
#line 129 "TP5.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
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
#line 56 "../src/TP5.y"

	 char* cadena;



/* Line 214 of yacc.c  */
#line 203 "TP5.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 215 "TP5.tab.c"

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
#define YYLAST   538

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  43
/* YYNRULES -- Number of rules.  */
#define YYNRULES  119
/* YYNRULES -- Number of states.  */
#define YYNSTATES  188

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
     151,   153,   156,   160,   162,   164,   165,   166,   172,   175,
     177,   181,   183,   186,   188,   189,   191,   193,   195,   197,
     199,   202,   204,   205,   209,   211,   214,   215,   220,   224,
     226,   228,   230,   232,   236,   238,   240,   241,   246,   248,
     250,   254,   256,   258,   260,   262,   264,   268,   272,   276,
     280,   282,   286,   290,   292,   294,   296,   298,   302,   306,
     310,   314,   318,   322,   324,   326,   329,   332,   335,   338
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      49,     0,    -1,    -1,    49,    51,    -1,    49,     1,    -1,
       4,    -1,     8,    -1,    -1,    52,    54,    -1,    71,    -1,
      74,    -1,    61,    -1,    58,    -1,    57,    -1,    59,    -1,
      53,    -1,    42,    -1,    19,    42,    -1,    20,    42,    -1,
      -1,     7,    55,    64,    -1,    -1,     9,    56,    65,    -1,
       1,    -1,    11,    43,    85,    44,    51,    -1,    11,    43,
      85,    44,    51,    17,    51,    -1,    16,    43,    85,    44,
      51,    -1,     1,    -1,    14,    60,    45,    51,    -1,    15,
      45,    51,    -1,     1,    -1,    18,    85,    42,    -1,    50,
      -1,     3,    -1,    10,    43,    62,    42,    63,    42,    63,
      44,    51,    -1,    12,    43,    85,    44,    51,    -1,    13,
      51,    12,    43,    85,    44,    42,    -1,     1,    -1,    85,
      -1,     7,     6,    36,    85,    -1,    -1,    85,    -1,    -1,
      81,    -1,    81,    41,    68,    42,    -1,    65,    -1,     1,
      -1,    -1,     6,    66,    43,    69,    44,    67,    -1,     1,
      -1,    42,    -1,    71,    42,    -1,    81,    41,    68,    -1,
      81,    -1,     1,    -1,    -1,    -1,     7,     6,    70,    41,
      69,    -1,     7,     6,    -1,     1,    -1,    46,    72,    47,
      -1,     1,    -1,    51,    72,    -1,    51,    -1,    -1,     1,
      -1,    39,    -1,    40,    -1,    38,    -1,    37,    -1,    84,
      42,    -1,     1,    -1,    -1,     6,    76,    77,    -1,     1,
      -1,    43,    44,    -1,    -1,    78,    43,    82,    44,    -1,
       6,    80,    84,    -1,     1,    -1,    36,    -1,    73,    -1,
       6,    -1,     6,    36,    85,    -1,     1,    -1,    85,    -1,
      -1,    85,    83,    41,    82,    -1,     1,    -1,    85,    -1,
      85,    41,    84,    -1,     1,    -1,    60,    -1,     5,    -1,
       6,    -1,    79,    -1,    85,    23,    85,    -1,    85,    24,
      85,    -1,    85,    25,    85,    -1,    85,    26,    85,    -1,
      90,    -1,    85,    27,    85,    -1,    43,    85,    44,    -1,
      87,    -1,    89,    -1,    86,    -1,    88,    -1,    85,    34,
      85,    -1,    85,    35,    85,    -1,    85,    28,    85,    -1,
      85,    29,    85,    -1,    85,    31,    85,    -1,    85,    30,
      85,    -1,    75,    -1,     1,    -1,    85,    21,    -1,    21,
       6,    -1,     6,    22,    -1,    22,     6,    -1,    24,    85,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   102,   102,   103,   104,   107,   108,   110,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   121,   122,   125,
     125,   126,   126,   127,   130,   131,   132,   133,   136,   137,
     138,   141,   144,   144,   147,   148,   149,   150,   154,   154,
     154,   157,   157,   160,   161,   162,   163,   166,   166,   167,
     170,   171,   174,   175,   176,   179,   180,   180,   181,   182,
     185,   186,   189,   190,   191,   192,   195,   196,   197,   198,
     201,   202,   205,   205,   206,   209,   210,   210,   214,   215,
     218,   219,   222,   223,   224,   227,   228,   228,   229,   232,
     233,   234,   237,   238,   239,   240,   241,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   265,   266,   269,   271,   273,   275,   277
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
  "sentenciaExpresion", "invocacionFuncion", "$@6",
  "segundaParteInvocacion", "$@7", "expresionDeAsignacion",
  "opAsignacionGeneral", "declaraId", "listaDeExpresionesInvocacion",
  "$@8", "listaDeExpresiones", "expresion", "opPostDecremento",
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
       0,    48,    49,    49,    49,    50,    50,    52,    51,    51,
      51,    51,    51,    51,    51,    51,    51,    53,    53,    55,
      54,    56,    54,    54,    57,    57,    57,    57,    58,    58,
      58,    59,    60,    60,    61,    61,    61,    61,    62,    62,
      62,    63,    63,    64,    64,    64,    64,    66,    65,    65,
      67,    67,    68,    68,    68,    69,    70,    69,    69,    69,
      71,    71,    72,    72,    72,    72,    73,    73,    73,    73,
      74,    74,    76,    75,    75,    77,    78,    77,    79,    79,
      80,    80,    81,    81,    81,    82,    83,    82,    82,    84,
      84,    84,    85,    85,    85,    85,    85,    85,    85,    85,
      85,    85,    85,    85,    85,    85,    85,    85,    85,    85,
      85,    85,    85,    85,    85,    86,    87,    88,    89,    90
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     2,     1,     1,     0,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     0,
       3,     0,     3,     1,     5,     7,     5,     1,     4,     3,
       1,     3,     1,     1,     9,     5,     7,     1,     1,     4,
       0,     1,     0,     1,     4,     1,     1,     0,     6,     1,
       1,     2,     3,     1,     1,     0,     0,     5,     2,     1,
       3,     1,     2,     1,     0,     1,     1,     1,     1,     1,
       2,     1,     0,     3,     1,     2,     0,     4,     3,     1,
       1,     1,     1,     3,     1,     1,     0,     4,     1,     1,
       3,     1,     1,     1,     1,     1,     3,     3,     3,     3,
       1,     3,     3,     1,     1,     1,     1,     3,     3,     3,
       3,     3,     3,     1,     1,     2,     2,     2,     2,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,     4,    33,     5,    93,    94,     6,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    16,     0,     0,    32,     3,     0,    15,    13,
      12,    14,    92,    11,     9,    10,   113,    95,     0,    89,
     105,   103,   106,   104,   100,   117,    80,    69,    68,    66,
      67,    81,     0,     0,     0,     0,     0,    27,     0,     0,
       0,     0,    74,     0,    17,    18,   116,   118,   119,     0,
      27,     0,     0,    23,    19,    21,     8,    70,   115,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    73,     0,    74,    78,     0,     0,    38,     0,
       0,     0,     0,    29,     0,    31,   102,    62,    60,     0,
       0,    96,    97,    98,    99,   101,   109,   110,   112,   111,
     107,   108,    90,    75,     0,     0,     0,     0,     0,     0,
      28,     0,    46,    82,    20,    45,    43,    49,    47,    22,
      74,     0,    85,     0,     0,    41,    24,    35,     0,    26,
       0,     0,     0,    77,     0,    39,     0,     0,     0,    83,
       0,    54,    82,     0,    53,     0,     0,    25,    36,    59,
       0,     0,    44,     0,    87,     0,    56,     0,    52,    34,
       0,    61,    50,    48,     0,     0,    51,    57
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    25,    71,    27,    28,    76,   109,   110,    29,
      30,    31,    32,    33,    97,   144,   134,   135,   151,   183,
     163,   171,   180,    34,    72,    51,    35,    36,    52,    92,
      93,    37,    53,   164,   141,   154,    38,    39,    40,    41,
      42,    43,    44
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -49
static const yytype_int16 yypact[] =
{
     -49,     9,   -49,   460,   -49,   -49,   -49,   100,   -49,   -36,
      -8,    -7,   204,    53,     5,    -6,   284,    18,    20,    57,
      70,   284,   -49,   284,    74,   -49,   -49,    25,   -49,   -49,
     -49,   -49,   -49,   -49,   -49,   -49,   -49,   -49,    58,   424,
     -49,   -49,   -49,   -49,   -49,   -49,   -49,   -49,   -49,   -49,
     -49,   -49,    56,   290,   236,   284,   284,   460,    91,    59,
     204,   284,   -49,   404,   -49,   -49,   -49,   -49,   503,   162,
     460,   157,    60,   -49,   -49,   -49,   -49,   -49,   -49,   284,
     284,   284,   284,   284,   284,   284,   284,   284,   284,   284,
     290,    61,   -49,    63,   -49,   -49,   102,    68,   479,   316,
     338,    69,   204,   -49,   360,   -49,   -49,   -49,   -49,    43,
      52,   503,   503,   117,   117,   241,   -31,   -31,   -31,   -31,
      78,   -49,   -49,   -49,   314,    79,   260,   204,   204,   284,
     -49,   204,    77,     2,   -49,   -49,    82,   -49,   -49,   -49,
     -49,    75,   443,   284,    83,   479,   107,   -49,   382,   -49,
     284,    86,    96,   -49,    90,   479,   230,   204,    92,   492,
      47,    77,    97,   111,   101,   314,    88,   -49,   -49,   -49,
     143,   110,   -49,    96,   -49,   204,   113,     1,   -49,   -49,
     114,   -49,   -49,   -49,   138,    47,   -49,   -49
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -49,   -49,   -49,    -1,   -49,   -49,   -49,   -49,   -49,   -49,
     -49,   -49,   146,   -49,   -49,    26,   -49,    84,   -49,   -49,
      11,    10,   -49,    21,   130,   -49,   -49,   -49,   -49,   -49,
     -49,   -49,   -49,    93,    62,   -49,   -48,   -15,   -49,   -49,
     -49,   -49,   -49
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -87
static const yytype_int16 yytable[] =
{
      26,    63,   181,    88,    89,    95,    68,    54,    69,     2,
       3,    58,     4,     5,     6,     7,    -7,     8,    -7,     9,
      10,    11,    12,    13,    14,    15,    73,    16,    17,    18,
      19,    20,    74,    21,    75,    55,    56,    61,   150,    98,
      99,   100,   122,   182,   132,   -47,   104,    24,   169,   133,
      60,    22,    23,   137,   170,    24,     4,     5,   138,   103,
      64,     8,    65,    66,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,    70,    67,     4,     5,     6,
       7,    -7,     8,    -7,     9,    10,    11,    12,    13,    14,
      15,   -55,    16,    17,    18,    19,    20,   161,    21,    91,
      77,   130,   162,   101,   102,   123,   124,   108,   125,   142,
     126,   145,   129,    89,   148,   143,    22,    23,   -84,   153,
      24,   -64,    45,   152,   157,   156,   146,   147,   155,   160,
     149,   165,   175,   150,   168,   159,    46,    47,    48,    49,
      50,   145,   173,   -72,    83,    84,    85,    86,    87,   176,
     142,    88,    89,   172,   177,   185,   167,   -58,    70,    59,
       4,     5,     6,     7,    -7,     8,    -7,     9,    10,    11,
      12,    13,    14,    15,   179,    16,    17,    18,    19,    20,
     186,    21,   166,    78,   178,    79,    80,    81,    82,    83,
      84,    85,    86,    87,   139,   187,    88,    89,   184,    22,
      23,   107,   136,    24,   -63,    57,   106,     4,     5,     6,
       7,    -7,     8,    -7,     9,    10,    11,    12,    13,    14,
      15,     0,    16,    17,    18,    19,    20,   174,    21,     0,
       0,    62,     0,     4,     5,     6,     7,    62,     8,     4,
       5,     6,     7,    96,     8,     0,    22,    23,     0,     0,
      24,    19,    20,     0,    21,     0,     0,    19,    20,     0,
      21,    62,     0,     4,     5,     6,     7,     0,     8,    84,
      85,    86,    87,    23,   -42,    88,    89,     0,   -40,    23,
       0,    19,    20,     0,    21,    62,     0,     4,     5,     6,
       7,    94,     8,     4,     5,     6,     7,     0,     8,     0,
       0,     0,   -42,    23,     0,    19,    20,     0,    21,     0,
       0,    19,    20,     0,    21,   140,     0,     4,     5,     6,
       7,     0,     8,     0,     0,     0,     0,    23,     0,     0,
       0,     0,     0,    23,     0,    19,    20,    78,    21,    79,
      80,    81,    82,    83,    84,    85,    86,    87,     0,     0,
      88,    89,     0,     0,     0,     0,     0,    23,     0,    78,
     127,    79,    80,    81,    82,    83,    84,    85,    86,    87,
       0,     0,    88,    89,     0,     0,     0,     0,     0,     0,
       0,    78,   128,    79,    80,    81,    82,    83,    84,    85,
      86,    87,     0,     0,    88,    89,     0,     0,     0,     0,
       0,     0,     0,    78,   131,    79,    80,    81,    82,    83,
      84,    85,    86,    87,     0,     0,    88,    89,     0,     0,
       0,     0,     0,     0,     0,    78,   158,    79,    80,    81,
      82,    83,    84,    85,    86,    87,     0,     0,    88,    89,
       0,     0,     0,     0,     0,    78,   105,    79,    80,    81,
      82,    83,    84,    85,    86,    87,     0,     0,    88,    89,
       0,     0,     0,     0,    78,    90,    79,    80,    81,    82,
      83,    84,    85,    86,    87,     0,     0,    88,    89,     0,
       0,     0,     0,   -74,   -86,   -74,   -74,   -74,   -74,   -74,
     -74,   -74,     0,     0,   -74,   -74,     0,     0,     0,     0,
      78,   -74,    79,    80,    81,    82,    83,    84,    85,    86,
      87,     0,     0,    88,    89,    79,     0,    81,    82,    83,
      84,    85,    86,    87,     0,     0,    88,    89,    81,    82,
      83,    84,    85,    86,    87,     0,     0,    88,    89
};

static const yytype_int16 yycheck[] =
{
       1,    16,     1,    34,    35,    53,    21,    43,    23,     0,
       1,    12,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,     1,    18,    19,    20,
      21,    22,     7,    24,     9,    43,    43,    43,    36,    54,
      55,    56,    90,    42,     1,    43,    61,    46,     1,     6,
      45,    42,    43,     1,     7,    46,     3,     4,     6,    60,
      42,     8,    42,     6,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,     1,     6,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    44,    18,    19,    20,    21,    22,     1,    24,    43,
      42,   102,     6,    12,    45,    44,    43,    47,     6,   124,
      42,   126,    43,    35,   129,    36,    42,    43,    41,    44,
      46,    47,    22,    41,    17,    42,   127,   128,   143,    43,
     131,    41,    44,    36,    42,   150,    36,    37,    38,    39,
      40,   156,    41,    43,    27,    28,    29,    30,    31,     6,
     165,    34,    35,    42,    44,    41,   157,    44,     1,    13,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,   175,    18,    19,    20,    21,    22,
      42,    24,   156,    21,   173,    23,    24,    25,    26,    27,
      28,    29,    30,    31,   110,   185,    34,    35,   177,    42,
      43,    71,   109,    46,    47,     1,    44,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    -1,    18,    19,    20,    21,    22,   165,    24,    -1,
      -1,     1,    -1,     3,     4,     5,     6,     1,     8,     3,
       4,     5,     6,     7,     8,    -1,    42,    43,    -1,    -1,
      46,    21,    22,    -1,    24,    -1,    -1,    21,    22,    -1,
      24,     1,    -1,     3,     4,     5,     6,    -1,     8,    28,
      29,    30,    31,    43,    44,    34,    35,    -1,    42,    43,
      -1,    21,    22,    -1,    24,     1,    -1,     3,     4,     5,
       6,     1,     8,     3,     4,     5,     6,    -1,     8,    -1,
      -1,    -1,    42,    43,    -1,    21,    22,    -1,    24,    -1,
      -1,    21,    22,    -1,    24,     1,    -1,     3,     4,     5,
       6,    -1,     8,    -1,    -1,    -1,    -1,    43,    -1,    -1,
      -1,    -1,    -1,    43,    -1,    21,    22,    21,    24,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    -1,    -1,
      34,    35,    -1,    -1,    -1,    -1,    -1,    43,    -1,    21,
      44,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      -1,    -1,    34,    35,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    21,    44,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    -1,    -1,    34,    35,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    21,    44,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    -1,    -1,    34,    35,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    21,    44,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    -1,    -1,    34,    35,
      -1,    -1,    -1,    -1,    -1,    21,    42,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    -1,    -1,    34,    35,
      -1,    -1,    -1,    -1,    21,    41,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    -1,    -1,    34,    35,    -1,
      -1,    -1,    -1,    23,    41,    25,    26,    27,    28,    29,
      30,    31,    -1,    -1,    34,    35,    -1,    -1,    -1,    -1,
      21,    41,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    -1,    -1,    34,    35,    23,    -1,    25,    26,    27,
      28,    29,    30,    31,    -1,    -1,    34,    35,    25,    26,
      27,    28,    29,    30,    31,    -1,    -1,    34,    35
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    49,     0,     1,     3,     4,     5,     6,     8,    10,
      11,    12,    13,    14,    15,    16,    18,    19,    20,    21,
      22,    24,    42,    43,    46,    50,    51,    52,    53,    57,
      58,    59,    60,    61,    71,    74,    75,    79,    84,    85,
      86,    87,    88,    89,    90,    22,    36,    37,    38,    39,
      40,    73,    76,    80,    43,    43,    43,     1,    51,    60,
      45,    43,     1,    85,    42,    42,     6,     6,    85,    85,
       1,    51,    72,     1,     7,     9,    54,    42,    21,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    34,    35,
      41,    43,    77,    78,     1,    84,     7,    62,    85,    85,
      85,    12,    45,    51,    85,    42,    44,    72,    47,    55,
      56,    85,    85,    85,    85,    85,    85,    85,    85,    85,
      85,    85,    84,    44,    43,     6,    42,    44,    44,    43,
      51,    44,     1,     6,    64,    65,    81,     1,     6,    65,
       1,    82,    85,    36,    63,    85,    51,    51,    85,    51,
      36,    66,    41,    44,    83,    85,    42,    17,    44,    85,
      43,     1,     6,    68,    81,    41,    63,    51,    42,     1,
       7,    69,    42,    41,    82,    44,     6,    44,    68,    51,
      70,     1,    42,    67,    71,    41,    42,    69
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
#line 110 "../src/TP5.y"
    { nodo = inicializarTablaDeSimbolos();;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 110 "../src/TP5.y"
    {agregarATS(&nodo);;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 125 "../src/TP5.y"
    {nodo->tipo = strdup((yyvsp[(1) - (1)].cadena));;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 126 "../src/TP5.y"
    {nodo->tipo = strdup((yyvsp[(1) - (1)].cadena));;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 130 "../src/TP5.y"
    {printf("\nSe define una sentencia IF\n");;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 131 "../src/TP5.y"
    {printf("\nSe define una sentencia IF seguida de un ELSE\n");;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 132 "../src/TP5.y"
    {printf("\nSe define una sentencia de tipo SWITCH\n");;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 147 "../src/TP5.y"
    {printf("\nSe define una sentencia FOR\n");;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 148 "../src/TP5.y"
    {printf("\nSe define una sentencia WHILE\n");;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 149 "../src/TP5.y"
    {printf("\nSe define una sentencia DO WHILE\n");;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 166 "../src/TP5.y"
    {nodo->validar = 1; nodo->identificador = strdup((yyvsp[(1) - (1)].cadena));}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 180 "../src/TP5.y"
    {encolarParametro((yyvsp[(1) - (2)].cadena), &(nodo->principioParametros), &(nodo->finalParametros));;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 181 "../src/TP5.y"
    {encolarParametro((yyvsp[(1) - (2)].cadena), &(nodo->principioParametros), &(nodo->finalParametros));;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 205 "../src/TP5.y"
    {nodoActual = encontrarEnTablaDeSimb((yyvsp[(1) - (1)].cadena)); validarExistenciaYTipo(1,nodoActual,(yyvsp[(1) - (1)].cadena));;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 210 "../src/TP5.y"
    {indice = nodoActual->principioParametros;;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 214 "../src/TP5.y"
    {printf("\n-->Expresion de asignacion.\n");;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 222 "../src/TP5.y"
    {nodo->identificador = strdup((yyvsp[(1) - (1)].cadena));;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 223 "../src/TP5.y"
    {nodo->identificador = strdup((yyvsp[(1) - (3)].cadena));;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 227 "../src/TP5.y"
    {if(indice->sgte == NULL) compararConParametro((yyvsp[(1) - (1)].cadena), &indice); else printf ("La invocacion no cumple con la cantidad de parametros de %s", nodoActual->identificador);indice = NULL;;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 228 "../src/TP5.y"
    {if(indice->sgte != NULL) compararConParametro((yyvsp[(1) - (1)].cadena), &indice); else printf ("La invocacion no cumple con la cantidad de parametros de %s", nodoActual->identificador);indice = NULL;;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 239 "../src/TP5.y"
    {nodoActual2 = encontrarEnTablaDeSimb((yyvsp[(1) - (1)].cadena)); validarExistenciaYTipo(0,nodoActual2, (yyvsp[(1) - (1)].cadena));;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 241 "../src/TP5.y"
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
#line 1824 "TP5.tab.c"
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
#line 280 "../src/TP5.y"


void validarExistenciaYTipo(int a,tNodoTablaDeSimb* nodoActual, char* identificador){
	if(nodoActual){
		if(a != nodoActual->validar){
			printf("El identificador no corresponde con su uso"); //que rompa y no siga analizando
		}
	}
	else if(a)
	{
		printf("No se encuentra la función declarada con el indentificador %s\n", identificador);
	}
	else printf("No existe una variable declarada con ese identificador %s\n", identificador);
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
	tColaParametro p = (tColaParametro) malloc(sizeof(tNodoParametro));
	p->tipo = strdup(tipoParametro);
	p->sgte = NULL;

	if(*colaParametroInicio == NULL){
		*colaParametroInicio = p;
		*colaParametroFinal = p;
	}
	else {
		(*colaParametroFinal)->sgte = p;
		*colaParametroFinal = p;
	}
}

void compararConParametro(char* tipoParametroEncontrado, tColaParametro* indice)
{
	if(strcmp((*indice)->tipo, tipoParametroEncontrado)){
		printf("** ERROR: La invocacion no corresponde con los tipos de parametros que hay en la declaracion de la funcion %s ** \n\n", nodo->identificador);
	}
	else {
		*indice = (*indice)->sgte;
	}

}


void agregarATS(tNodoTablaDeSimb** nodo)
{
	if(encontrarEnTablaDeSimb((*nodo)->identificador))
	{
		printf("** ERROR: Doble declaracion de la variable %s ** \n\n", (*nodo)->identificador);
		//llamar a yyerror();
		free(*nodo);
		free(nodo);
		return;
	}
	(*nodo)->sgte = tablaDeSimb;
	tablaDeSimb = *nodo;
}


void imprimirListaVariables()
{
	printf("IDENTIFICADOR	TIPO\n\n");
	
	tNodoTablaDeSimb* pActivo = tablaDeSimb;
	while(tablaDeSimb)
	{
		if(pActivo->validar == 0)
			printf(pActivo->identificador);printf("	");printf(strcat(pActivo->tipo,"\n"));
		tablaDeSimb = tablaDeSimb -> sgte;
		free(pActivo);
	}
}

void imprimirListaFunciones()
{
	printf("IDENTIFICADOR	RETORNO	PARÁMETROS\n\n");
	
	tNodoTablaDeSimb* pActivo = tablaDeSimb;
	while(tablaDeSimb)
	{
		if(pActivo->validar == 1)
			printf(pActivo->identificador);printf("	");printf(pActivo->tipo); printf("	"); imprimirListaParametros(&(pActivo->principioParametros), &(pActivo->finalParametros)); printf("\n");
		tablaDeSimb = tablaDeSimb -> sgte;
		free(pActivo);
	}
}

void imprimirListaParametros(tNodoParametro** principio, tNodoParametro** final)
{
	tNodoParametro* pAct = *principio;
	while(*principio){
		pAct = *principio;
		printf((*principio)->tipo);

		*principio = (*principio)->sgte;

		if((*principio) == NULL)
			*final = NULL;
		else
			printf(", ");

		free(pAct);
	}

	free(principio);
	free(final);
}

tNodoTablaDeSimb* inicializarTablaDeSimbolos()
{
	tNodoTablaDeSimb* nodo = (tNodoTablaDeSimb*) malloc(sizeof(tNodoTablaDeSimb));

	nodo->principioParametros = NULL;
	nodo->finalParametros = NULL;
	nodo->validar = 0;
	
	return nodo;
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

