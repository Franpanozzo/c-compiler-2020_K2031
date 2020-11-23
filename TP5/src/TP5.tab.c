
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
	tColaParametro principioParametros;
	tColaParametro finalParametros;
	struct tNodoTablaDeSimb* sgte;
} tNodoTablaDeSimb;
tNodoTablaDeSimb* inicializarNodo();
void inicializarNodoConTipo(char* tipo,tNodoTablaDeSimb** nodo);
tNodoTablaDeSimb* encontrarEnTablaDeSimb(char*);
void compararConParametro(char* tipoParametroEncontrado, tColaParametro* indice);
void encolarParametro(char* tipoParametro, tColaParametro* colaParametroInicio, tColaParametro* colaParametroFinal);
void agregarATS(tNodoTablaDeSimb** nodo);
void imprimirListaVariables();
void imprimirListaParametros(tNodoParametro** principio, tNodoParametro** final);

tNodoTablaDeSimb* tablaDeSimb = NULL;
tNodoTablaDeSimb* nodo;
tNodoTablaDeSimb* nodo2;
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
#line 131 "TP5.tab.c"

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
#line 58 "TP5.y"

	 char* cadena;



/* Line 214 of yacc.c  */
#line 205 "TP5.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 217 "TP5.tab.c"

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
#define YYLAST   531

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  46
/* YYNRULES -- Number of rules.  */
#define YYNRULES  123
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
       0,     0,     3,     4,     7,    10,    12,    14,    16,    18,
      20,    22,    24,    26,    28,    30,    32,    35,    38,    39,
      43,    44,    48,    50,    56,    64,    70,    72,    77,    81,
      83,    87,    89,    91,   101,   107,   115,   117,   119,   120,
     126,   127,   129,   130,   133,   134,   139,   141,   143,   144,
     151,   153,   155,   157,   159,   160,   165,   168,   170,   171,
     172,   178,   181,   183,   187,   189,   192,   194,   195,   197,
     199,   201,   203,   205,   208,   210,   211,   215,   217,   218,
     223,   225,   226,   230,   232,   234,   236,   238,   242,   244,
     246,   247,   252,   254,   256,   260,   262,   264,   266,   268,
     270,   274,   278,   282,   286,   288,   292,   296,   298,   300,
     302,   304,   308,   312,   316,   320,   324,   328,   330,   332,
     335,   338,   341,   344
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      49,     0,    -1,    -1,    49,    51,    -1,    49,     1,    -1,
       4,    -1,     8,    -1,    53,    -1,    73,    -1,    76,    -1,
      60,    -1,    57,    -1,    56,    -1,    58,    -1,    52,    -1,
      42,    -1,    19,    42,    -1,    20,    42,    -1,    -1,     7,
      54,    64,    -1,    -1,     9,    55,    66,    -1,     1,    -1,
      11,    43,    88,    44,    51,    -1,    11,    43,    88,    44,
      51,    17,    51,    -1,    16,    43,    88,    44,    51,    -1,
       1,    -1,    14,    59,    45,    51,    -1,    15,    45,    51,
      -1,     1,    -1,    18,    88,    42,    -1,    50,    -1,     3,
      -1,    10,    43,    61,    42,    63,    42,    63,    44,    51,
      -1,    12,    43,    88,    44,    51,    -1,    13,    51,    12,
      43,    88,    44,    42,    -1,     1,    -1,    88,    -1,    -1,
       7,     6,    62,    36,    88,    -1,    -1,    88,    -1,    -1,
      84,    42,    -1,    -1,    84,    41,    65,    69,    -1,    66,
      -1,     1,    -1,    -1,     6,    67,    43,    71,    44,    68,
      -1,     1,    -1,    42,    -1,    73,    -1,     1,    -1,    -1,
      84,    41,    70,    69,    -1,    84,    42,    -1,     1,    -1,
      -1,    -1,     7,     6,    72,    41,    71,    -1,     7,     6,
      -1,     1,    -1,    46,    74,    47,    -1,     1,    -1,    51,
      74,    -1,    51,    -1,    -1,     1,    -1,    39,    -1,    40,
      -1,    38,    -1,    37,    -1,    87,    42,    -1,     1,    -1,
      -1,     6,    78,    79,    -1,     1,    -1,    -1,    80,    43,
      81,    44,    -1,    85,    -1,    -1,     6,    83,    87,    -1,
       1,    -1,    36,    -1,    75,    -1,     6,    -1,     6,    36,
      88,    -1,     1,    -1,    88,    -1,    -1,    88,    86,    41,
      85,    -1,     1,    -1,    88,    -1,    88,    41,    87,    -1,
       1,    -1,    59,    -1,     5,    -1,     6,    -1,    82,    -1,
      88,    23,    88,    -1,    88,    24,    88,    -1,    88,    25,
      88,    -1,    88,    26,    88,    -1,    93,    -1,    88,    27,
      88,    -1,    43,    88,    44,    -1,    90,    -1,    92,    -1,
      89,    -1,    91,    -1,    88,    34,    88,    -1,    88,    35,
      88,    -1,    88,    28,    88,    -1,    88,    29,    88,    -1,
      88,    31,    88,    -1,    88,    30,    88,    -1,    77,    -1,
       1,    -1,    88,    21,    -1,    21,     6,    -1,     6,    22,
      -1,    22,     6,    -1,    24,    88,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   104,   104,   105,   106,   109,   110,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   124,   125,   128,   128,
     129,   129,   130,   133,   134,   135,   136,   139,   140,   141,
     144,   147,   148,   151,   152,   153,   154,   158,   159,   159,
     160,   163,   163,   166,   167,   167,   168,   169,   172,   172,
     173,   176,   177,   178,   181,   181,   182,   183,   186,   187,
     187,   188,   189,   192,   193,   196,   197,   198,   199,   202,
     203,   204,   205,   208,   209,   212,   212,   213,   216,   216,
     218,   219,   223,   224,   227,   228,   231,   232,   233,   236,
     237,   237,   238,   241,   242,   243,   246,   247,   248,   249,
     250,   258,   259,   260,   261,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   278,
     280,   282,   284,   286
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
  "primeraExpresionFor", "$@3", "expresionOpcional",
  "parteFinalDeclaracion", "$@4", "sentenciaFuncion", "$@5",
  "declaracionODefFuncion", "listaIdentificadores", "$@6",
  "listaDeParametros", "$@7", "sentenciaCompuesta", "listaDeSentencias",
  "opAsignacion", "sentenciaExpresion", "invocacionFuncion", "$@8",
  "segundaParteInvocacion", "$@9", "conOSinParametros",
  "expresionDeAsignacion", "opAsignacionGeneral", "declaraId",
  "listaDeExpresionesInvocacion", "$@10", "listaDeExpresiones",
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
       0,    48,    49,    49,    49,    50,    50,    51,    51,    51,
      51,    51,    51,    51,    51,    51,    52,    52,    54,    53,
      55,    53,    53,    56,    56,    56,    56,    57,    57,    57,
      58,    59,    59,    60,    60,    60,    60,    61,    62,    61,
      61,    63,    63,    64,    65,    64,    64,    64,    67,    66,
      66,    68,    68,    68,    70,    69,    69,    69,    71,    72,
      71,    71,    71,    73,    73,    74,    74,    74,    74,    75,
      75,    75,    75,    76,    76,    78,    77,    77,    80,    79,
      81,    81,    82,    82,    83,    83,    84,    84,    84,    85,
      86,    85,    85,    87,    87,    87,    88,    88,    88,    88,
      88,    88,    88,    88,    88,    88,    88,    88,    88,    88,
      88,    88,    88,    88,    88,    88,    88,    88,    88,    89,
      90,    91,    92,    93
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     0,     3,
       0,     3,     1,     5,     7,     5,     1,     4,     3,     1,
       3,     1,     1,     9,     5,     7,     1,     1,     0,     5,
       0,     1,     0,     2,     0,     4,     1,     1,     0,     6,
       1,     1,     1,     1,     0,     4,     2,     1,     0,     0,
       5,     2,     1,     3,     1,     2,     1,     0,     1,     1,
       1,     1,     1,     2,     1,     0,     3,     1,     0,     4,
       1,     0,     3,     1,     1,     1,     1,     3,     1,     1,
       0,     4,     1,     1,     3,     1,     1,     1,     1,     1,
       3,     3,     3,     3,     1,     3,     3,     1,     1,     1,
       1,     3,     3,     3,     3,     3,     3,     1,     1,     2,
       2,     2,     2,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,     4,    32,     5,    97,    98,    18,     6,
      20,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    15,     0,     0,    31,     3,    14,
       7,    12,    11,    13,    96,    10,     8,     9,   117,    99,
       0,    93,   109,   107,   110,   108,   104,   121,    84,    72,
      71,    69,    70,    85,    78,     0,     0,     0,     0,     0,
       0,    22,     0,     0,     0,     0,    77,     0,    16,    17,
     120,   122,   123,     0,    22,     0,     0,    73,   119,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    76,     0,    77,    82,    47,    86,    19,    46,     0,
      50,    48,    21,     0,     0,    37,     0,     0,     0,     0,
      28,     0,    30,   106,    65,    63,   100,   101,   102,   103,
     105,   113,   114,   116,   115,   111,   112,    94,     0,     0,
       0,    44,    43,    38,     0,     0,     0,     0,    27,     0,
      77,     0,    80,    89,    87,     0,     0,     0,     0,    41,
      23,    34,     0,    25,    79,     0,    62,     0,     0,    57,
      86,    45,     0,     0,     0,     0,     0,     0,    59,     0,
      54,    56,    39,     0,    24,    35,    91,     0,    53,    51,
      49,    52,     0,     0,     0,    55,    33,    60
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    27,    75,    29,    30,    56,    57,    31,    32,
      33,    34,    35,   104,   147,   148,    97,   146,    98,   130,
     180,   161,   182,   158,   177,    36,    76,    53,    37,    38,
      54,    91,    92,   141,    39,    55,   162,   142,   155,    40,
      41,    42,    43,    44,    45,    46
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -54
static const yytype_int16 yypact[] =
{
     -54,    11,   -54,   468,   -54,   -54,   -54,   117,   -54,   -54,
     -54,    -7,    -3,     8,   212,     1,   -17,    15,   122,    17,
      19,    70,    85,   122,   -54,   122,    74,   -54,   -54,   -54,
     -54,   -54,   -54,   -54,   -54,   -54,   -54,   -54,   -54,   -54,
      69,   432,   -54,   -54,   -54,   -54,   -54,   -54,   -54,   -54,
     -54,   -54,   -54,   -54,   -54,   298,    46,    54,   268,   122,
     122,   468,   103,    52,   212,   122,   -54,   412,   -54,   -54,
     -54,   -54,    75,   170,   468,   165,    71,   -54,   -54,   122,
     122,   122,   122,   122,   122,   122,   122,   122,   122,   122,
     298,   -54,    81,   -54,   -54,    88,    -2,   -54,   -54,   -35,
     -54,   -54,   -54,   125,    90,   487,   324,   346,    93,   212,
     -54,   368,   -54,   -54,   -54,   -54,    75,    75,   496,   496,
     249,     4,     4,     4,     4,    98,   -54,   -54,   238,   122,
      94,   -54,   -54,   -54,   292,   212,   212,   122,   -54,   212,
     -54,    96,   -54,   451,   487,    55,   106,   105,   100,   487,
     128,   -54,   390,   -54,   -54,   109,   -54,   141,   107,    88,
     123,   -54,     7,   122,   244,   212,   116,   322,   118,     0,
     -54,   -54,   487,   119,   -54,   -54,   -54,   120,   -54,   -54,
     -54,   -54,   106,   212,    55,   -54,   -54,   -54
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -54,   -54,   -54,    -1,   -54,   -54,   -54,   -54,   -54,   -54,
     -54,   152,   -54,   -54,   -54,    24,   -54,   -54,   133,   -54,
     -54,    10,   -54,    18,   -54,    34,   131,   -54,   -54,   -54,
     -54,   -54,   -54,   -54,   -54,   -54,   153,    43,   -54,   -53,
     -15,   -54,   -54,   -54,   -54,   -54
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -91
static const yytype_int16 yytable[] =
{
      28,   178,    94,    67,     4,     5,   131,   132,    72,     9,
      73,     2,     3,    62,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    64,    18,
      19,    20,    21,    22,   129,    23,    58,   127,    88,    89,
      59,   -48,   179,   105,   106,   107,    26,    95,   170,   171,
     111,    60,    96,    24,    25,   100,   156,    26,    65,    68,
     101,    69,   157,   110,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,    74,    70,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    71,    18,    19,    20,    21,    22,   109,    23,   -58,
      81,    82,    83,    84,    85,    86,    87,   159,   138,    88,
      89,    77,   160,   143,   144,   108,    24,    25,   115,   149,
      26,   -67,   152,    66,   128,     4,     5,     6,     7,   -88,
       9,   133,   134,    89,   150,   151,   137,   145,   153,    47,
     154,   163,   164,    21,    22,   165,    23,   168,   172,   149,
     167,   169,   143,    48,    49,    50,    51,    52,   175,   129,
     -75,   184,   -61,   183,   174,    25,    74,    63,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,   186,    18,    19,    20,    21,    22,   173,    23,
     102,    78,   185,    79,    80,    81,    82,    83,    84,    85,
      86,    87,   187,   181,    88,    89,   114,    24,    25,    99,
     176,    26,   -66,    61,   113,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,     0,
      18,    19,    20,    21,    22,     0,    23,     0,     0,   140,
       0,     4,     5,     6,     7,    66,     9,     4,     5,     6,
       7,     0,     9,     0,    24,    25,     0,     0,    26,    21,
      22,     0,    23,     0,     0,    21,    22,     0,    23,    66,
       0,     4,     5,     6,     7,   103,     9,    84,    85,    86,
      87,    25,   -81,    88,    89,     0,     0,    25,   -42,    21,
      22,     0,    23,    66,     0,     4,     5,     6,     7,    93,
       9,     4,     5,     6,     7,     0,     9,     0,     0,     0,
     -40,    25,     0,    21,    22,     0,    23,     0,     0,    21,
      22,     0,    23,   140,     0,     4,     5,     6,     7,     0,
       9,     0,     0,     0,   -42,    25,     0,     0,     0,     0,
       0,    25,     0,    21,    22,    78,    23,    79,    80,    81,
      82,    83,    84,    85,    86,    87,     0,     0,    88,    89,
       0,     0,     0,     0,     0,    25,     0,    78,   135,    79,
      80,    81,    82,    83,    84,    85,    86,    87,     0,     0,
      88,    89,     0,     0,     0,     0,     0,     0,     0,    78,
     136,    79,    80,    81,    82,    83,    84,    85,    86,    87,
       0,     0,    88,    89,     0,     0,     0,     0,     0,     0,
       0,    78,   139,    79,    80,    81,    82,    83,    84,    85,
      86,    87,     0,     0,    88,    89,     0,     0,     0,     0,
       0,     0,     0,    78,   166,    79,    80,    81,    82,    83,
      84,    85,    86,    87,     0,     0,    88,    89,     0,     0,
       0,     0,     0,    78,   112,    79,    80,    81,    82,    83,
      84,    85,    86,    87,     0,     0,    88,    89,     0,     0,
       0,     0,    78,    90,    79,    80,    81,    82,    83,    84,
      85,    86,    87,     0,     0,    88,    89,     0,     0,     0,
       0,   -77,   -90,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
       0,     0,   -77,   -77,     0,     0,     0,     0,    78,   -77,
      79,    80,    81,    82,    83,    84,    85,    86,    87,     0,
       0,    88,    89,    83,    84,    85,    86,    87,     0,     0,
      88,    89
};

static const yytype_int16 yycheck[] =
{
       1,     1,    55,    18,     3,     4,    41,    42,    23,     8,
      25,     0,     1,    14,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    45,    18,
      19,    20,    21,    22,    36,    24,    43,    90,    34,    35,
      43,    43,    42,    58,    59,    60,    46,     1,    41,    42,
      65,    43,     6,    42,    43,     1,     1,    46,    43,    42,
       6,    42,     7,    64,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,     1,     6,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,     6,    18,    19,    20,    21,    22,    45,    24,    44,
      25,    26,    27,    28,    29,    30,    31,     1,   109,    34,
      35,    42,     6,   128,   129,    12,    42,    43,    47,   134,
      46,    47,   137,     1,    43,     3,     4,     5,     6,    41,
       8,     6,    42,    35,   135,   136,    43,    43,   139,    22,
      44,    36,    42,    21,    22,    17,    24,     6,   163,   164,
      41,    44,   167,    36,    37,    38,    39,    40,    42,    36,
      43,    41,    44,    44,   165,    43,     1,    15,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,   183,    18,    19,    20,    21,    22,   164,    24,
      57,    21,   182,    23,    24,    25,    26,    27,    28,    29,
      30,    31,   184,   169,    34,    35,    75,    42,    43,    56,
     167,    46,    47,     1,    44,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    -1,
      18,    19,    20,    21,    22,    -1,    24,    -1,    -1,     1,
      -1,     3,     4,     5,     6,     1,     8,     3,     4,     5,
       6,    -1,     8,    -1,    42,    43,    -1,    -1,    46,    21,
      22,    -1,    24,    -1,    -1,    21,    22,    -1,    24,     1,
      -1,     3,     4,     5,     6,     7,     8,    28,    29,    30,
      31,    43,    44,    34,    35,    -1,    -1,    43,    44,    21,
      22,    -1,    24,     1,    -1,     3,     4,     5,     6,     1,
       8,     3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,
      42,    43,    -1,    21,    22,    -1,    24,    -1,    -1,    21,
      22,    -1,    24,     1,    -1,     3,     4,     5,     6,    -1,
       8,    -1,    -1,    -1,    42,    43,    -1,    -1,    -1,    -1,
      -1,    43,    -1,    21,    22,    21,    24,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    -1,    -1,    34,    35,
      -1,    -1,    -1,    -1,    -1,    43,    -1,    21,    44,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    -1,    -1,
      34,    35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,
      44,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      -1,    -1,    34,    35,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    21,    44,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    -1,    -1,    34,    35,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    21,    44,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    -1,    -1,    34,    35,    -1,    -1,
      -1,    -1,    -1,    21,    42,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    -1,    -1,    34,    35,    -1,    -1,
      -1,    -1,    21,    41,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    -1,    -1,    34,    35,    -1,    -1,    -1,
      -1,    23,    41,    25,    26,    27,    28,    29,    30,    31,
      -1,    -1,    34,    35,    -1,    -1,    -1,    -1,    21,    41,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    -1,
      -1,    34,    35,    27,    28,    29,    30,    31,    -1,    -1,
      34,    35
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    49,     0,     1,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    18,    19,
      20,    21,    22,    24,    42,    43,    46,    50,    51,    52,
      53,    56,    57,    58,    59,    60,    73,    76,    77,    82,
      87,    88,    89,    90,    91,    92,    93,    22,    36,    37,
      38,    39,    40,    75,    78,    83,    54,    55,    43,    43,
      43,     1,    51,    59,    45,    43,     1,    88,    42,    42,
       6,     6,    88,    88,     1,    51,    74,    42,    21,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    34,    35,
      41,    79,    80,     1,    87,     1,     6,    64,    66,    84,
       1,     6,    66,     7,    61,    88,    88,    88,    12,    45,
      51,    88,    42,    44,    74,    47,    88,    88,    88,    88,
      88,    88,    88,    88,    88,    88,    88,    87,    43,    36,
      67,    41,    42,     6,    42,    44,    44,    43,    51,    44,
       1,    81,    85,    88,    88,    43,    65,    62,    63,    88,
      51,    51,    88,    51,    44,    86,     1,     7,    71,     1,
       6,    69,    84,    36,    42,    17,    44,    41,     6,    44,
      41,    42,    88,    63,    51,    42,    85,    72,     1,    42,
      68,    73,    70,    44,    41,    69,    51,    71
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
        case 5:

/* Line 1455 of yacc.c  */
#line 109 "TP5.y"
    {(yyval.cadena) = strdup((yyvsp[(1) - (1)].cadena));;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 110 "TP5.y"
    {(yyval.cadena) = strdup((yyvsp[(1) - (1)].cadena));;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 128 "TP5.y"
    {inicializarNodoConTipo((yyvsp[(1) - (1)].cadena), &nodo);;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 129 "TP5.y"
    {inicializarNodoConTipo((yyvsp[(1) - (1)].cadena), &nodo);;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 133 "TP5.y"
    {printf("\nSe define una sentencia IF\n");;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 134 "TP5.y"
    {printf("\nSe define una sentencia IF seguida de un ELSE\n");;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 135 "TP5.y"
    {printf("\nSe define una sentencia de tipo SWITCH\n");;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 147 "TP5.y"
    {(yyval.cadena) = strdup((yyvsp[(1) - (1)].cadena));;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 148 "TP5.y"
    {(yyval.cadena) = strdup((yyvsp[(1) - (1)].cadena));;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 151 "TP5.y"
    {printf("\nSe define una sentencia FOR\n");;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 152 "TP5.y"
    {printf("\nSe define una sentencia WHILE\n");;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 153 "TP5.y"
    {printf("\nSe define una sentencia DO WHILE\n");;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 159 "TP5.y"
    {nodo-> validar = 0;nodo->identificador = strdup((yyvsp[(2) - (2)].cadena)); agregarATS(&nodo);;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 167 "TP5.y"
    {inicializarNodoConTipo(nodo->tipo, &nodo);;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 172 "TP5.y"
    {inicializarNodoConTipo(nodo->tipo, &nodo2);nodo2->validar = 1; nodo2->identificador = strdup((yyvsp[(1) - (1)].cadena));;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 172 "TP5.y"
    {printf("Se va a agregar %s de tipo %s\n", nodo2->identificador,nodo2->tipo);agregarATS(&nodo2);;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 181 "TP5.y"
    {inicializarNodoConTipo(nodo->tipo, &nodo);;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 187 "TP5.y"
    {encolarParametro((yyvsp[(1) - (2)].cadena), &(nodo2->principioParametros), &(nodo2->finalParametros));;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 188 "TP5.y"
    {encolarParametro((yyvsp[(1) - (2)].cadena), &(nodo2->principioParametros), &(nodo2->finalParametros));;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 212 "TP5.y"
    {nodoActual = encontrarEnTablaDeSimb((yyvsp[(1) - (1)].cadena)); validarExistenciaYTipo(1,nodoActual,(yyvsp[(1) - (1)].cadena));;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 216 "TP5.y"
    {if(nodoActual) indice = nodoActual->principioParametros;;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 223 "TP5.y"
    {printf("\n-->Expresion de asignacion.\n");;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 231 "TP5.y"
    {nodo->identificador = strdup((yyvsp[(1) - (1)].cadena));agregarATS(&nodo);;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 232 "TP5.y"
    {nodo->identificador = strdup((yyvsp[(1) - (3)].cadena));agregarATS(&nodo);;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 236 "TP5.y"
    {if(nodoActual && indice){if(indice->sgte == NULL) compararConParametro((yyvsp[(1) - (1)].cadena), &indice); else printf ("La invocacion no cumple con la cantidad de parametros de %s", nodoActual->identificador);indice = NULL;};}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 237 "TP5.y"
    {if(nodoActual && indice){if(indice->sgte != NULL) compararConParametro((yyvsp[(1) - (1)].cadena), &indice); else printf ("La invocacion no cumple con la cantidad de parametros de %s", nodoActual->identificador);indice = NULL;};}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 246 "TP5.y"
    {(yyval.cadena) = strdup((yyvsp[(1) - (1)].cadena));;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 247 "TP5.y"
    {(yyval.cadena) = strdup((yyvsp[(1) - (1)].cadena));;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 248 "TP5.y"
    {nodoActual2 = encontrarEnTablaDeSimb((yyvsp[(1) - (1)].cadena)); validarExistenciaYTipo(0,nodoActual2, (yyvsp[(1) - (1)].cadena));;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 250 "TP5.y"
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
#line 1886 "TP5.tab.c"
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
#line 289 "TP5.y"


void validarExistenciaYTipo(int a,tNodoTablaDeSimb* nodoActual, char* identificador){
	if(nodoActual){
		if(a != nodoActual->validar){
			printf("El identificador %s no corresponde con su uso %i",identificador, nodoActual->validar); //que rompa y no siga analizando
		}
	}
	else if(a)
	{
		printf("No se encuentra la funcion declarada con el indentificador %s\n", identificador);
	}
	else printf("No existe una variable declarada con ese identificador %s\n", identificador);
}

tNodoTablaDeSimb* encontrarEnTablaDeSimb(char* identificador)
{
	printf("SE INICIA LA BUSQUEDA DE %s\n", identificador);
	tNodoTablaDeSimb* pAct = tablaDeSimb;

	while(pAct && strcmp(pAct->identificador, identificador))
	{
		printf("Leyendo TS: %s\n", pAct->identificador);
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
	printf("Se encolo el parametro %s\n",(*colaParametroFinal)->tipo);
}

void compararConParametro(char* tipoParametroEncontrado, tColaParametro* indice)
{
	if(strcmp((*indice)->tipo, tipoParametroEncontrado)){
		printf("** ERROR: La invocacion no corresponde con los tipos de parametros que hay en la declaracion de la funcion %s ** \n\n", nodo->identificador);
	}
	printf("El parametro %s coincide, esta bien :)\n",tipoParametroEncontrado);
	*indice = (*indice)->sgte;
}


void agregarATS(tNodoTablaDeSimb** nodo)
{
	tNodoTablaDeSimb* nodoCopia = (tNodoTablaDeSimb*) malloc(sizeof(tNodoTablaDeSimb));
	(*nodoCopia) = (**nodo);

	if(encontrarEnTablaDeSimb(nodoCopia->identificador))
	{
		printf("** ERROR: Doble declaracion de la variable %s ** \n\n", encontrarEnTablaDeSimb(nodoCopia->identificador));
		//llamar a yyerror();
		free(*nodo);
		free(nodo);
		return;
	}
	nodoCopia->sgte = tablaDeSimb;
	tablaDeSimb = nodoCopia;
	printf("Se agrego a la tabla: %s\n", nodoCopia->identificador);
}


void imprimirListaVariables()
{
	printf("IDENTIFICADOR	TIPO\n\n");
	
	tNodoTablaDeSimb* pActivo = tablaDeSimb;
	while(pActivo)
	{
		if(pActivo->validar == 0)
		{
			printf(pActivo->identificador);
			printf("	");
			printf(strcat(pActivo->tipo,"\n"));
		}
		
		pActivo = pActivo -> sgte;
	}
}

void imprimirListaFunciones()
{
	printf("IDENTIFICADOR	RETORNO	  PARAMETROS\n\n");
	
	tNodoTablaDeSimb* pActivo = tablaDeSimb;
	while(pActivo)
	{
		if(pActivo->validar == 1)
		{
			printf(pActivo->identificador);
			printf("	");
			printf(pActivo->tipo);
			printf("	");
			imprimirListaParametros(&(pActivo->principioParametros), &(pActivo->finalParametros));
			printf("\n");
		}
		pActivo = pActivo -> sgte;
	}
}

void imprimirListaParametros(tNodoParametro** principio, tNodoParametro** final)
{
	tNodoParametro* pAct = *principio;
	while(pAct){
		printf(pAct->tipo);
		*principio = (*principio)->sgte;

		if((*principio) == NULL)
			*final = NULL;
		else
			printf(", ");

		free(pAct);
		pAct = *principio;
	}
}

/*tNodoTablaDeSimb* inicializarNodo()
{
	tNodoTablaDeSimb* nodo = (tNodoTablaDeSimb*) malloc(sizeof(tNodoTablaDeSimb));

	nodo->principioParametros = NULL;
	nodo->finalParametros = NULL;
	nodo->sgte = NULL;
	nodo->validar = 0;
	
	return nodo;
}*/

void inicializarNodoConTipo(char* tipo, tNodoTablaDeSimb** nodo)
{
	(*nodo)->principioParametros = NULL;
	(*nodo)->finalParametros = NULL;
	(*nodo)->validar = 0;
	(*nodo)->sgte = NULL;
	(*nodo)->tipo = strdup(tipo);
	free(nodo);
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
  nodo = (tNodoTablaDeSimb*) malloc(sizeof(tNodoTablaDeSimb));
  nodo2 = (tNodoTablaDeSimb*) malloc(sizeof(tNodoTablaDeSimb));
  yyin=fopen("entrada.txt","r");
  yyparse ();

  imprimirListaVariables();
  imprimirListaFunciones();
}

