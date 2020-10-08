%{
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
%token <cadena> TIPO_DATO
%token <real> REAL
%token <cadena> TOKEN_VOID
%token <entero> error
%token FOR
%token IF
%token WHILE
%token DO
%token CASE
%token DEFAULT
%token SWITCH
%token ELSE
%token RETURN
%token BREAK
%token CONTINUE

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

%start input

%% /* A continuacion las reglas gramaticales y las acciones */

// Cambiar el axioma por una lista de sentencias
input:    /* vacio */
        | input sentencia
		| input error 
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
			| sentenciaRetorno
			| sentenciaSalto
			| /* vacio */  ';'
;

sentenciaSalto: BREAK ';'
				| CONTINUE ';'
;

sentenciaDeclaracion: TIPO_DATO {tipoDato = strdup($<cadena>1);} parteFinalDeclaracion 
					  | TOKEN_VOID {tipoFuncion = strdup($<cadena>1);} sentenciaFuncion
					  | error 
; 

sentenciaSeleccion: IF '(' expresion ')' sentencia {printf("\nSe define una sentencia IF\n");}
					| IF '(' expresion ')' sentencia ELSE sentencia {printf("\nSe define una sentencia IF seguida de un ELSE\n");}
					| SWITCH '(' expresion ')' sentencia {printf("\nSe define una sentencia de tipo SWITCH\n");}
					| error 
;

sentenciaEtiquetada: CASE constante ':' sentencia 
					| DEFAULT ':' sentencia
					| error
;

sentenciaRetorno: RETURN expresion ';'
;

constante: numero | CCHAR		
;

sentenciaIteracion: FOR '(' primeraExpresionFor ';' expresionOpcional ';' expresionOpcional ')' sentencia {printf("\nSe define una sentencia FOR\n");}
					| WHILE '(' expresion ')' sentencia {printf("\nSe define una sentencia WHILE\n");}
					| DO sentencia WHILE '(' expresion ')'';' {printf("\nSe define una sentencia DO WHILE\n");}
					| error
;


primeraExpresionFor: expresion | TIPO_DATO ID '=' expresion | /*vacio*/
;

expresionOpcional: expresion | /*vacio*/
;

parteFinalDeclaracion: declaraId';' {}
				| declaraId ',' listaIdentificadores';' {printf("\nSe declaro lista de variables\n");}
				| sentenciaFuncion {tipoFuncion = strdup(tipoDato);}
				| error
;

sentenciaFuncion: ID {idFuncion =strdup($<cadena>1);} '(' listaDeParametros ')' declaracionODefFuncion {}
				  | error
;

declaracionODefFuncion:  ';' {printf("\nSe declara la funcion %s de tipo %s \n",idFuncion,tipoFuncion);}
						| sentenciaCompuesta  {printf("\nSe define la funcion %s de tipo %s\n",idFuncion,tipoFuncion);}
;

listaIdentificadores: declaraId ',' listaIdentificadores
                    | declaraId
					| error
;

listaDeParametros: /* vacio */
					|TIPO_DATO ID ',' listaDeParametros
					| TIPO_DATO ID
					| error
;

sentenciaCompuesta: '{'listaDeSentencias'}'
					| error
;

listaDeSentencias: sentencia listaDeSentencias 
					| sentencia 
					| /*vacio*/
					| error
;

opAsignacion:	MENOSIGUAL
			   | MASIGUAL
			   | PORIGUAL
			   | DIVIDIDOIGUAL
;

sentenciaExpresion: listaDeExpresiones';'
					| error
;

invocacionFuncion: ID '(' listaDeExpresiones ')' {printf("\nSe invoca la funcion %s con parametros\n",$<cadena>1);}
				   |ID '('')' {printf("\nSe invoca la funcion %s\n",$<cadena>1)}
				   | error
;

expresionDeAsignacion: ID opAsignacionGeneral listaDeExpresiones {printf("\n-->Expresion de asignacion.\n");}
						| error
;

opAsignacionGeneral: '='
    				| opAsignacion
;

declaraId: 	ID {printf("\n-->Se declara el identificador %s de tipo %s sin asignacion: .\n", $<cadena>1,tipoDato);}
			| ID '=' expresion {printf("\n-->Se declara el identificador %s de tipo %s con asignacion \n", $<cadena>1,tipoDato);}
			| error
;

listaDeExpresiones: expresion
			 	    | expresion ',' listaDeExpresiones
					| error 
;
expresion:	 constante
			| LITERALCADENA
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
			| error 
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
