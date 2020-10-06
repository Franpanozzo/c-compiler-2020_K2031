%{
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define YYDEBUG 1

extern FILE * yyin;

int flag_error=0;
int contador=0;
char* tipoDato;
char* idFuncion;

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
//struct{int tipo, char* nombre} tipoYNombre;
}
%token <caracter> CCHAR
%token <entero> NUM
%token <cadena> LITERALCADENA
%token <cadena> ID
%token <cadena> TIPO_DATO
%token <entero> ERROR
%token <real> REAL
%token <cadena> TOKEN_VOID
%token FOR
%token IF
%token WHILE
%token DO
%token CASE
%token DEFAULT
%token SWITCH
%token ELSE
%token RETURN

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
			| /* vacio */  ';'
;

sentenciaDeclaracion: TIPO_DATO {tipoDato = $<cadena>1} parteFinalDeclaracion 
					  | TOKEN_VOID {tipoDato = $<cadena>1} sentenciaFuncion
; 

sentenciaSeleccion: IF '(' expresion ')' sentencia {printf("\nSe define una sentencia IF\n");}
					| IF '(' expresion ')' sentencia ELSE sentencia {printf("\nSe define una sentencia IF seguida de un ELSE\n");}
					| SWITCH '(' expresion ')' sentencia {printf("\nSe define una sentencia de tipo SWITCH\n");}
;

sentenciaEtiquetada: CASE constante ':' sentencia 
					| DEFAULT ':' sentencia
;

sentenciaRetorno: RETURN expresion ';'
;

constante: numero | CCHAR
;

sentenciaIteracion: FOR '(' expresionOpcional ';' expresionOpcional ';' expresionOpcional ')' sentencia {printf("Se define una sentencia FOR");}
					| WHILE '(' expresion ')' sentencia {printf("Se define una sentencia WHILE");}
					| DO sentencia WHILE '(' expresion ')'';' {printf("Se define una sentencia DO WHILE");}
;

expresionOpcional: expresion | /*vacio*/ ;

parteFinalDeclaracion: declaraId';' {}
				| declaraId ',' listaIdentificadores';' {printf("\nSe declaro lista de variables\n");}
				| sentenciaFuncion
;

sentenciaFuncion: ID {idFuncion = $<cadena>1} '(' listaDeParametros ')' declaracionODefFuncion {}
;

declaracionODefFuncion:  ';' {printf("\nSe declara la funcion %s de tipo %s \n",idFuncion,tipoDato);}
						| sentenciaCompuesta  {printf("\nSe define la funcion %s de tipo %s\n",idFuncion,tipoDato);}
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

invocacionFuncion: ID '(' listaDeExpresiones ')' {printf("\nSe invoca la funcion %s con parametros\n",$<cadena>1);}
				   |ID '('')' {printf("\nSe invoca la funcion %s\n",$<cadena>1)}
;

expresionDeAsignacion: ID opAsignacionGeneral listaDeExpresiones {printf("\n-->Expresion de asignacion.\n");}
;

opAsignacionGeneral: '='
    				| opAsignacion
;

declaraId: 	ID {printf("\n-->Se declara el identificador %s de tipo %s sin asignacion: .\n", $<cadena>1,tipoDato);}
			| ID '=' expresion {printf("\n-->Se declara el identificador %s de tipo %s con asignacion : %s.\n", $<cadena>1,tipoDato);}
;

listaDeExpresiones: expresion
			 	    | expresion ',' listaDeExpresiones
;
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
# endif
  printf("Ingrese la declaracion: ");
  yyparse ();
}
