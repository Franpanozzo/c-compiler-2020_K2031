
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

char* tipoDato;
char* idFuncion;
char* tipoFuncion;

//NODOS

typedef struct tNodoVariable
{
	char* tipoDato;
	char* identificador;
	struct tNodoVariable* sgte;
} tNodoVariable;


typedef struct tNodoParametro
{
	char* tipo;
	struct tNodoParametro* sgte;
} tNodoParametro;


typedef tNodoParametro* tColaParametro;


typedef struct tNodoFuncion
{
	char* tipoDato;
	char* identificador;
	tColaParametro parametros;
	struct tNodoFuncion* sgte;
} tNodoFuncion;

tNodoFuncion* listaFunciones = NULL;

tNodoVariable* listaVariables = NULL;

//FUNCIONES

tNodoVariable* encontrarEnListaVariable(char* identificador)
{
	tNodoVariable* pAct = listaVariables;
	while(pAct && strcmp(pAct->identificador, identificador))
	{
		pAct = pAct->sgte;
	}
	return pAct;
}
tNodoFuncion* encontrarEnListaFuncion(char* identificador)
{
	tNodoFuncion* pAct = listaFunciones;
	while(pAct && strcmp(pAct->identificador, identificador))
	{
		pAct = pAct->sgte;
	}
	return pAct;
}
/*
int funcion(c,b,a)
     A
a -> b -> c

     B
a -> b -> c

int funcion(c,b,a,d,e)

NA
P           F 
c > b > a > d
FIFO 
*/

int suma(int a; int b)


void encolarParametro(char* tipo, tColaParametro colaParametro)
{

}

int suma(int a, int b)


void agregarFuncion(char* identificador, char* tipo, tColaParametro colaParametro)
{
	if(encontrarEnListaDeFunciones(identificador))
	{
		printf("** ERROR: Doble declaracion de la variable %s ** \n\n", identificador);
		return;
	}
	tNodoFuncion* p = (tNodoFuncion*) malloc(sizeof(tNodoFuncion));
	p->tipoDato = strdup(tipo);
	p->identificador = strdup(identificador);
	p->parametros = strdup(colaParametro);

	p->sgte = listaFunciones;
	listaFunciones = p;
}



void agregarDeclaracion(char* identificador, char* tipo)
{
	if(encontrarEnListaVariable(identificador))
	{
		printf("** ERROR: Doble declaracion de la variable %s ** \n\n", identificador);
		return;
	}
	tNodoVariable* p = (tNodoVariable*) malloc(sizeof(tNodoVariable));
	p->tipoDato = strdup(tipo);
	p->identificador = strdup(identificador);

	p->sgte = listaVariables;
	listaVariables = p;
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


/*void validarTiposOperacionesBinarias(union primerParametro, union segundoParametro, char* operacion, union resultado)

if(primerParametro.tipo == sengundoParametro.tipo) {
	switch(operacion)
	{
		case SUMA:
		return primerParametro.
	} 
}*/



// BISON

int flag_error=0;
int contador=0;

int yylex();
int yywrap(){
	return(1);
}

void yyerror (char const *s);



/* Line 189 of yacc.c  */
#line 245 "TP5.tab.c"

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
#line 174 "TP5.y"

	typedef struct yylval_struct {
		char* cadena;          
		int entero;                     
		int tipo;
		double real;
		char caracter;
	}estructuraDeTipos;



/* Line 214 of yacc.c  */
#line 325 "TP5.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 337 "TP5.tab.c"

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
#define YYLAST   526

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  35
/* YYNRULES -- Number of rules.  */
#define YYNRULES  109
/* YYNRULES -- Number of states.  */
#define YYNSTATES  174

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
     125,   127,   128,   130,   135,   137,   139,   145,   147,   149,
     151,   155,   157,   159,   160,   165,   168,   170,   174,   176,
     179,   181,   182,   184,   186,   188,   190,   192,   195,   197,
     202,   206,   208,   212,   214,   216,   218,   220,   224,   226,
     228,   232,   234,   236,   238,   240,   242,   246,   250,   254,
     258,   260,   264,   268,   270,   272,   274,   276,   280,   284,
     288,   292,   296,   300,   302,   304,   307,   310,   313,   316
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      49,     0,    -1,    -1,    49,    51,    -1,    49,     1,    -1,
       4,    -1,     8,    -1,    53,    -1,    68,    -1,    71,    -1,
      60,    -1,    57,    -1,    56,    -1,    58,    -1,    52,    -1,
      42,    -1,    19,    42,    -1,    20,    42,    -1,    -1,     7,
      54,    63,    -1,    -1,     9,    55,    64,    -1,     1,    -1,
      11,    43,    77,    44,    51,    -1,    11,    43,    77,    44,
      51,    17,    51,    -1,    16,    43,    77,    44,    51,    -1,
       1,    -1,    14,    59,    45,    51,    -1,    15,    45,    51,
      -1,     1,    -1,    18,    77,    42,    -1,    50,    -1,     3,
      -1,    10,    43,    61,    42,    62,    42,    62,    44,    51,
      -1,    12,    43,    77,    44,    51,    -1,    13,    51,    12,
      43,    77,    44,    42,    -1,     1,    -1,    77,    -1,     7,
       6,    36,    77,    -1,    -1,    77,    -1,    -1,    75,    -1,
      75,    41,    66,    42,    -1,    64,    -1,     1,    -1,     6,
      43,    67,    44,    65,    -1,     1,    -1,    42,    -1,    68,
      -1,    75,    41,    66,    -1,    75,    -1,     1,    -1,    -1,
       7,     6,    41,    67,    -1,     7,     6,    -1,     1,    -1,
      46,    69,    47,    -1,     1,    -1,    51,    69,    -1,    51,
      -1,    -1,     1,    -1,    39,    -1,    40,    -1,    38,    -1,
      37,    -1,    76,    42,    -1,     1,    -1,     6,    43,    76,
      44,    -1,     6,    43,    44,    -1,     1,    -1,     6,    74,
      76,    -1,     1,    -1,    36,    -1,    70,    -1,     6,    -1,
       6,    36,    77,    -1,     1,    -1,    77,    -1,    77,    41,
      76,    -1,     1,    -1,    59,    -1,     5,    -1,     6,    -1,
      73,    -1,    77,    23,    77,    -1,    77,    24,    77,    -1,
      77,    25,    77,    -1,    77,    26,    77,    -1,    82,    -1,
      77,    27,    77,    -1,    43,    77,    44,    -1,    79,    -1,
      81,    -1,    78,    -1,    80,    -1,    77,    34,    77,    -1,
      77,    35,    77,    -1,    77,    28,    77,    -1,    77,    29,
      77,    -1,    77,    31,    77,    -1,    77,    30,    77,    -1,
      72,    -1,     1,    -1,    77,    21,    -1,    21,     6,    -1,
       6,    22,    -1,    22,     6,    -1,    24,    77,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   235,   235,   236,   237,   240,   241,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   254,   255,   258,   258,
     259,   259,   260,   263,   264,   265,   266,   269,   270,   271,
     274,   277,   277,   280,   281,   282,   283,   287,   287,   287,
     290,   290,   293,   294,   295,   296,   299,   300,   303,   304,
     307,   308,   309,   312,   313,   314,   315,   318,   319,   322,
     323,   324,   325,   328,   329,   330,   331,   334,   335,   338,
     339,   340,   343,   344,   347,   348,   351,   352,   353,   356,
     357,   358,   361,   362,   363,   364,   365,   375,   376,   377,
     378,   379,   380,   381,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   391,   392,   395,   397,   399,   401,   403
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
  "sentenciaFuncion", "declaracionODefFuncion", "listaIdentificadores",
  "listaDeParametros", "sentenciaCompuesta", "listaDeSentencias",
  "opAsignacion", "sentenciaExpresion", "invocacionFuncion",
  "expresionDeAsignacion", "opAsignacionGeneral", "declaraId",
  "listaDeExpresiones", "expresion", "opPostDecremento", "opPreDecremento",
  "opPostIncremento", "opPreIncremento", "expresionUnaria", 0
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
      62,    62,    63,    63,    63,    63,    64,    64,    65,    65,
      66,    66,    66,    67,    67,    67,    67,    68,    68,    69,
      69,    69,    69,    70,    70,    70,    70,    71,    71,    72,
      72,    72,    73,    73,    74,    74,    75,    75,    75,    76,
      76,    76,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    78,    79,    80,    81,    82
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     0,     3,
       0,     3,     1,     5,     7,     5,     1,     4,     3,     1,
       3,     1,     1,     9,     5,     7,     1,     1,     4,     0,
       1,     0,     1,     4,     1,     1,     5,     1,     1,     1,
       3,     1,     1,     0,     4,     2,     1,     3,     1,     2,
       1,     0,     1,     1,     1,     1,     1,     2,     1,     4,
       3,     1,     3,     1,     1,     1,     1,     3,     1,     1,
       3,     1,     1,     1,     1,     1,     3,     3,     3,     3,
       1,     3,     3,     1,     1,     1,     1,     3,     3,     3,
       3,     3,     3,     1,     1,     2,     2,     2,     2,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,     4,    32,     5,    83,    84,    18,     6,
      20,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    15,     0,     0,    31,     3,    14,
       7,    12,    11,    13,    82,    10,     8,     9,   103,    85,
       0,    79,    95,    93,    96,    94,    90,   107,    74,    66,
      65,    63,    64,     0,    75,     0,     0,     0,     0,     0,
       0,    22,     0,     0,     0,     0,    71,     0,    16,    17,
     106,   108,   109,     0,    22,     0,     0,    67,   105,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    71,    70,     0,    72,    45,    76,    19,    44,    42,
      47,     0,    21,     0,     0,    37,     0,     0,     0,     0,
      28,     0,    30,    92,    59,    57,    86,    87,    88,    89,
      91,    99,   100,   102,   101,    97,    98,    80,    69,     0,
       0,     0,     0,     0,     0,     0,     0,    27,     0,    77,
      56,     0,     0,    52,    76,     0,    51,     0,     0,    40,
      23,    34,     0,    25,    55,     0,    43,     0,    38,     0,
       0,     0,     0,    58,    48,    46,    49,    50,     0,    24,
      35,    54,     0,    33
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    27,    75,    29,    30,    56,    57,    31,    32,
      33,    34,    35,   104,   148,    97,    98,   165,   145,   142,
      36,    76,    54,    37,    38,    39,    55,   146,    40,    41,
      42,    43,    44,    45,    46
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -52
static const yytype_int16 yypact[] =
{
     -52,    11,   -52,   448,   -52,   -52,   -52,   143,   -52,   -52,
     -52,   -36,   -34,    -7,   189,    48,   -17,    -6,   275,    -4,
       7,    41,    52,   275,   -52,   275,    77,   -52,   -52,   -52,
     -52,   -52,   -52,   -52,   -52,   -52,   -52,   -52,   -52,   -52,
      17,   431,   -52,   -52,   -52,   -52,   -52,   -52,   -52,   -52,
     -52,   -52,   -52,   215,   -52,   299,    54,   106,   245,   275,
     275,   448,    49,    30,   189,   275,   -52,   411,   -52,   -52,
     -52,   -52,   491,   301,   448,   142,    15,   -52,   -52,   275,
     275,   275,   275,   275,   275,   275,   275,   275,   275,   275,
     299,   -52,   -52,    32,   -52,    38,     5,   -52,   -52,    53,
     -52,    57,   -52,   107,    73,   467,   323,   345,    74,   189,
     -52,   367,   -52,   -52,   -52,   -52,   491,   491,    75,    75,
     139,   -29,   -29,   -29,   -29,    87,   -52,   -52,   -52,   275,
      33,   110,    89,   269,   189,   189,   275,   -52,   189,   480,
     -52,   120,    83,    38,    92,    88,    90,   275,    93,   467,
     112,   -52,   389,   -52,    95,     0,   -52,   110,   467,   221,
     189,    96,    33,   -52,   -52,   -52,   -52,   -52,    97,   -52,
     -52,   -52,   189,   -52
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -52,   -52,   -52,    -1,   -52,   -52,   -52,   -52,   -52,   -52,
     -52,   124,   -52,   -52,   -19,   -52,    85,   -52,    18,    10,
      21,   102,   -52,   -52,   -52,   -52,   -52,   122,   -51,   -15,
     -52,   -52,   -52,   -52,   -52
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -79
static const yytype_int16 yytable[] =
{
      28,   163,    93,    67,    94,    88,    89,    58,    72,    59,
      73,     2,     3,    62,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    64,    18,
      19,    20,    21,    22,   140,    23,    60,    65,    68,   127,
     141,   129,   164,   105,   106,   107,    26,    70,   130,    69,
     111,     4,     5,    24,    25,    95,     9,    26,    71,    77,
      96,   108,   115,   110,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   109,   128,   -53,    74,   -78,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,   131,    18,    19,    20,    21,    22,
     130,    23,    83,    84,    85,    86,    87,   100,   137,    88,
      89,   143,   101,   132,   139,   133,   144,   136,   149,    24,
      25,   152,    89,    26,   -61,   147,   154,   155,   129,   160,
     156,   157,   158,   150,   151,   159,   162,   153,   170,    63,
     168,   172,   102,    74,   149,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,   169,
      18,    19,    20,    21,    22,    47,    23,    84,    85,    86,
      87,   173,   171,    88,    89,   167,   166,   114,    99,    48,
      49,    50,    51,    52,    24,    25,    53,     0,    26,   -60,
      61,     0,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,     0,    18,    19,    20,
      21,    22,     0,    23,     0,     0,    91,     0,     4,     5,
       6,     7,    66,     9,     4,     5,     6,     7,     0,     9,
       0,    24,    25,     0,     0,    26,    21,    22,     0,    23,
       0,     0,    21,    22,     0,    23,    66,     0,     4,     5,
       6,     7,   103,     9,     0,     0,     0,     0,    25,    92,
       0,     0,     0,     0,    25,   -41,    21,    22,     0,    23,
      66,     0,     4,     5,     6,     7,    66,     9,     4,     5,
       6,     7,     0,     9,     0,     0,     0,   -39,    25,     0,
      21,    22,     0,    23,     0,     0,    21,    22,     0,    23,
      91,     0,     4,     5,     6,     7,     0,     9,     0,     0,
       0,   -41,    25,     0,     0,     0,     0,     0,    25,     0,
      21,    22,    78,    23,    79,    80,    81,    82,    83,    84,
      85,    86,    87,     0,     0,    88,    89,     0,     0,     0,
       0,     0,    25,     0,    78,   113,    79,    80,    81,    82,
      83,    84,    85,    86,    87,     0,     0,    88,    89,     0,
       0,     0,     0,     0,     0,     0,    78,   134,    79,    80,
      81,    82,    83,    84,    85,    86,    87,     0,     0,    88,
      89,     0,     0,     0,     0,     0,     0,     0,    78,   135,
      79,    80,    81,    82,    83,    84,    85,    86,    87,     0,
       0,    88,    89,     0,     0,     0,     0,     0,     0,     0,
      78,   138,    79,    80,    81,    82,    83,    84,    85,    86,
      87,     0,     0,    88,    89,     0,     0,     0,     0,     0,
       0,     0,    78,   161,    79,    80,    81,    82,    83,    84,
      85,    86,    87,     0,     0,    88,    89,     0,     0,     0,
       0,     0,    78,   112,    79,    80,    81,    82,    83,    84,
      85,    86,    87,     0,     0,    88,    89,     0,     0,     0,
       0,   -71,    90,   -71,   -71,   -71,   -71,   -71,   -71,   -71,
       0,     0,   -71,   -71,     0,     0,     0,     0,    78,   -71,
      79,    80,    81,    82,    83,    84,    85,    86,    87,     0,
       0,    88,    89,    79,     0,    81,    82,    83,    84,    85,
      86,    87,     0,     0,    88,    89,    81,    82,    83,    84,
      85,    86,    87,     0,     0,    88,    89
};

static const yytype_int16 yycheck[] =
{
       1,     1,    53,    18,    55,    34,    35,    43,    23,    43,
      25,     0,     1,    14,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    45,    18,
      19,    20,    21,    22,     1,    24,    43,    43,    42,    90,
       7,    36,    42,    58,    59,    60,    46,     6,    43,    42,
      65,     3,     4,    42,    43,     1,     8,    46,     6,    42,
       6,    12,    47,    64,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    45,    44,    44,     1,    41,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    41,    18,    19,    20,    21,    22,
      43,    24,    27,    28,    29,    30,    31,     1,   109,    34,
      35,     1,     6,     6,   129,    42,     6,    43,   133,    42,
      43,   136,    35,    46,    47,    36,     6,    44,    36,    17,
      42,    41,   147,   134,   135,    42,    41,   138,    42,    15,
     159,    44,    57,     1,   159,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,   160,
      18,    19,    20,    21,    22,    22,    24,    28,    29,    30,
      31,   172,   162,    34,    35,   157,   155,    75,    56,    36,
      37,    38,    39,    40,    42,    43,    43,    -1,    46,    47,
       1,    -1,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    -1,    18,    19,    20,
      21,    22,    -1,    24,    -1,    -1,     1,    -1,     3,     4,
       5,     6,     1,     8,     3,     4,     5,     6,    -1,     8,
      -1,    42,    43,    -1,    -1,    46,    21,    22,    -1,    24,
      -1,    -1,    21,    22,    -1,    24,     1,    -1,     3,     4,
       5,     6,     7,     8,    -1,    -1,    -1,    -1,    43,    44,
      -1,    -1,    -1,    -1,    43,    44,    21,    22,    -1,    24,
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
      -1,    -1,    34,    35,    -1,    -1,    -1,    -1,    21,    41,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    -1,
      -1,    34,    35,    23,    -1,    25,    26,    27,    28,    29,
      30,    31,    -1,    -1,    34,    35,    25,    26,    27,    28,
      29,    30,    31,    -1,    -1,    34,    35
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    49,     0,     1,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    18,    19,
      20,    21,    22,    24,    42,    43,    46,    50,    51,    52,
      53,    56,    57,    58,    59,    60,    68,    71,    72,    73,
      76,    77,    78,    79,    80,    81,    82,    22,    36,    37,
      38,    39,    40,    43,    70,    74,    54,    55,    43,    43,
      43,     1,    51,    59,    45,    43,     1,    77,    42,    42,
       6,     6,    77,    77,     1,    51,    69,    42,    21,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    34,    35,
      41,     1,    44,    76,    76,     1,     6,    63,    64,    75,
       1,     6,    64,     7,    61,    77,    77,    77,    12,    45,
      51,    77,    42,    44,    69,    47,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    76,    44,    36,
      43,    41,     6,    42,    44,    44,    43,    51,    44,    77,
       1,     7,    67,     1,     6,    66,    75,    36,    62,    77,
      51,    51,    77,    51,     6,    44,    42,    41,    77,    42,
      17,    44,    41,     1,    42,    65,    68,    66,    62,    51,
      42,    67,    44,    51
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
#line 258 "TP5.y"
    {tipoDato = strdup((yyvsp[(1) - (1)].estructuraDeTipos).cadena);;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 259 "TP5.y"
    {tipoFuncion = strdup((yyvsp[(1) - (1)].estructuraDeTipos).cadena);;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 263 "TP5.y"
    {printf("\nSe define una sentencia IF\n");;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 264 "TP5.y"
    {printf("\nSe define una sentencia IF seguida de un ELSE\n");;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 265 "TP5.y"
    {printf("\nSe define una sentencia de tipo SWITCH\n");;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 280 "TP5.y"
    {printf("\nSe define una sentencia FOR\n");;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 281 "TP5.y"
    {printf("\nSe define una sentencia WHILE\n");;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 282 "TP5.y"
    {printf("\nSe define una sentencia DO WHILE\n");;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 293 "TP5.y"
    {;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 294 "TP5.y"
    {;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 295 "TP5.y"
    {tipoFuncion = strdup(tipoDato);;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 303 "TP5.y"
    {printf("\nSe declara la funcion %s de tipo %s \n",idFuncion,tipoFuncion);;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 304 "TP5.y"
    {printf("\nSe define la funcion %s de tipo %s\n",idFuncion,tipoFuncion);;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 313 "TP5.y"
    {/*encolarParametro($<estructuraDeTipos>1.cadena, &colaP, &colaF);*/;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 314 "TP5.y"
    {/*encolarParametro($<estructuraDeTipos>$.tipo,  &colaP, &colaF);*/;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 338 "TP5.y"
    {printf("\nSe invoca la funcion %s con parametros\n",(yyvsp[(1) - (4)].estructuraDeTipos).cadena);;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 339 "TP5.y"
    {printf("\nSe invoca la funcion %s\n",(yyvsp[(1) - (3)].estructuraDeTipos).cadena);}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 343 "TP5.y"
    {printf("\n-->Expresion de asignacion.\n");;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 351 "TP5.y"
    {agregarDeclaracion((yyvsp[(1) - (1)].estructuraDeTipos).tipo,tipoDato);;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 352 "TP5.y"
    {agregarDeclaracion((yyvsp[(1) - (3)].estructuraDeTipos).cadena,tipoDato);;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 363 "TP5.y"
    {/*$<estructuraDeTipos>$.tipo = retornarTipoVariable(),$<estructuraDeTipos>$ = ret*/;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 365 "TP5.y"
    {if((yyvsp[(1) - (3)].estructuraDeTipos).tipo == (yyvsp[(3) - (3)].estructuraDeTipos).tipo) {
											switch((yyval.estructuraDeTipos).tipo)
											{
											case 1:
												(yyval.estructuraDeTipos).entero = (yyvsp[(1) - (3)].estructuraDeTipos).entero + (yyvsp[(3) - (3)].estructuraDeTipos).entero
											case 2:
												(yyval.estructuraDeTipos).real = (yyvsp[(1) - (3)].estructuraDeTipos).real + (yyvsp[(3) - (3)].estructuraDeTipos).real
											case 3:
												(yyval.estructuraDeTipos).entero = (yyvsp[(1) - (3)].estructuraDeTipos).caracter + (yyvsp[(3) - (3)].estructuraDeTipos).caracter	 
											} } ;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 375 "TP5.y"
    {;}
    break;



/* Line 1455 of yacc.c  */
#line 1938 "TP5.tab.c"
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
#line 406 "TP5.y"


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

