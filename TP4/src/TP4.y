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
struct{int tipo, char* nombre} tipoYNombre;
}

%token <caracter> CCHAR
%token <entero> NUM
%token <cadena> LITERALCADENA
%token <cadena> ID
%token <cadena> TIPO_DATO
%token <entero> ERROR
%token <real> REAL
%token TOKEN_VOID
%token FOR
%token IF
%token WHILE
%token DO
%token CASE
%token DEFAULT
%token SWITCH
%token ELSE

%type <entero> expresion
%type <entero> numero
%type <entero> constante
%type <tipoYNombre> declaraId

%left OP_INCREMENTO OP_DECREMENTO
%left '+' '-'
%left '*' '/'
%left '^'
%left '<' '>' MENORIGUAL MAYORIGUAL
%left IGUALIGUAL NOIGUAL
%left YLOGICO
%left OLOGICO
%right '=' MASIGUAL MENOSIGUAL PORIGUAL DIVIDIDOIGUAL
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
			| sentenciaExpresion
			| sentenciaIteracion
			| sentenciaEtiquetada
			| sentenciaSeleccion
			| /* vacio */  ';'
;

sentenciaDeclaracion: TIPO_DATO parteFinalDeclaracion 
;

sentenciaSeleccion: IF '(' expresion ')' sentencia 
					| IF '(' expresion ')' sentencia ELSE sentencia 
					| SWITCH '(' expresion ')' sentencia
;

sentenciaEtiquetada: CASE constante ':' sentencia
					| DEFAULT ':' sentencia
;

constante: numero | CCHAR
;

sentenciaIteracion: FOR '(' expresionOpcional ';' expresionOpcional ';' expresionOpcional ')' sentencia
					| WHILE '(' expresion ')' sentencia
					| DO sentencia WHILE '(' expresion ')'';'
;

expresionOpcional: expresion | /*vacio*/ ;

parteFinalDeclaracion: declaraId';' {}
				| declaraId ',' listaIdentificadores';' {printf("\nSe declaro lista de variables\n");}
				| ID '(' listaDeParametros ')' declaracionODefFuncion {}
;

declaracionODefFuncion:  ';' {printf("\nSe declara una funcion\n");}
						| sentenciaCompuesta  {printf("\nSe define una funcion\n");}
;

listaIdentificadores: declaraId ',' listaIdentificadores
                    | declaraId
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

opAsignacion:	MENOSIGUAL
			   | MASIGUAL
			   | PORIGUAL
			   | DIVIDIDOIGUAL
;

sentenciaExpresion: listaDeExpresiones';'	{}
;

invocacionFuncion: ID '(' listaDeExpresiones ')'
					| '('')'
;

expresionDeAsignacion: ID opAsignacionGeneral listaDeExpresiones {printf("\n-->Expresion de asignacion.\n");}
;

opAsignacionGeneral: '='
    				| opAsignacion
;

declaraId: 	ID {printf("\n-->Declaracion sin asignacion: $s.\n", $<cadena>1);}
			| ID '=' expresion {printf("\n-->Declaracion con asignacion: %s.\n", $<cadena>1);}
;

listaDeExpresiones: expresion
			 	    | expresion ',' listaDeExpresiones

expresion:	 numero
			| ID
			| expresionDeAsignacion
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