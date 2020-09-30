%{
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define YYDEBUG 1

int flag_error=0;
int contador=0;
char* tipo;

int yylex();
int yywrap(){
	return(1);
}

void yyerror (char const *s) {
   fprintf (stderr, "%s\n", s);
}

%}

%union {
char* cadena;          
int entero;                     
int tipo;
double real;
char caracter;
}

%token <caracter> CCHAR
%token <entero> NUM
%token <cadena> LITERALCADENA
%token <cadena> ID
%token <cadena> PALRESERVADA
%token <cadena> TIPO_DATO
%token <entero> ERROR
%token <real> REAL
%token TOKEN_VOID

%type <entero> expresion

%left OP_INCREMENTO OP_DECREMENTO
%left '+' '-'
%left '*' '/'
%left '^'
%left '<' '>' MENORIGUAL MAYORIGUAL
%left IGUALIGUAL NOIGUAL
%left YLOGICO
%left OLOGICO
%left '=' MASIGUAL MENOSIGUAL PORIGUAL DIVIDIDOIGUAL
%left ','

%start sentencia

%% /* A continuacion las reglas gramaticales y las acciones */

// Cambiar el axioma por una lista de sentencias
input:    /* vacio */
        | input sentencia
;

numero: NUM
		| REAL
;
sentencia:  sentenciaDeclaracion
			| sentenciaCompuesta
			| sentenciaDeAsignacion
			| sentenciaExpresion
			| sentencia
			| /* vacio */  ';'
;

sentenciaDeclaracion: TIPO_DATO declaraId parteFinalDeclaracion 
;

parteFinalDeclaracion: ';' {}
				| ',' listaIdentificadores';' {printf("\nSe declaro lista de variables\n");}
				| '(' listaDeParametros ')' declaracionODefFuncion {}
;

declaracionODefFuncion:  ';' {printf("\nSe declara una funcion\n");}
						| sentenciaCompuesta  {printf("\nSe define una funcion\n");}
;

listaIdentificadores: declaraId ',' listaIdentificadores
                    | declaraId
;

declaraId: 	ID {}
			| ID '=' expresion  {}
;

listaDeParametros: /* vacio */
					|TIPO_DATO ID ',' listaDeParametros
					| TIPO_DATO ID
;

sentenciaCompuesta: '{'listaDeSentencias'}' {}
;

listaDeSentencias: sentencia listaDeSentencias {}
					| sentencia {}
;

sentenciaDeAsignacion: ID opAsignacion expresion ';'
;

opAsignacion:  '='
			   | MENOSIGUAL
			   | MASIGUAL
			   | PORIGUAL
			   | DIVIDIDOIGUAL
;
sentenciaExpresion: expresion';'	{}
;	

invocacionFuncion: ID '(' listaDeExpresiones ')'
					| ID '('')'
;

listaDeExpresiones: expresion ',' listaDeExpresiones
					| expresion
;


expresion:	 numero
			| ID
			| ID  '='  expresion
			| ID '(' expresion  ')'
			| expresion '+' expresion
			| expresion '-' expresion
			| expresion '*' expresion
			| expresion '/' expresion
			| expresionUnaria
			| expresion '^' expresion
			| '(' expresion ')'
			| opPreDecremento
			| opPreIncremento
			| opPostDecremento
			| opPostIncremento 
			| expresion YLOGICO expresion
			| expresion OLOGICO expresion
			| expresion '<' expresion
			| expresion '>' expresion
			| expresion MENORIGUAL expresion
			| expresion MAYORIGUAL expresion
			| invocacionFuncion
;

opPostDecremento: expresion OP_DECREMENTO
;
opPreDecremento: OP_DECREMENTO ID
;
opPostIncremento: ID OP_INCREMENTO
;
opPreIncremento: OP_INCREMENTO ID
;
expresionUnaria: '-' expresion
;

%%

int main ()
{
#ifdef BISON_DEBUG
        yydebug = 1;
#endif
  printf("Ingrese la declaracion: ");
  yyparse ();
}