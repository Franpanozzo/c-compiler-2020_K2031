%{
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
	int validar = 0;
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

%}

%union {
	 char* cadena;
}

%token <cadena> CCHAR
%token <cadena> NUM
%token <cadena> LITERALCADENA
%token <cadecna> ID
%token <cadena> TIPO_DATO
%token <cadena> REAL
%token <cadena> TOKEN_VOID
%token <cadena> error
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

%type <cadena> expresion
%type <cadena> numero
%type <cadena> constante
%type <cadena> declaraId

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
sentencia:  {tNodoTablaDeSimb* nodo = (tNodoTablaDeSimb*) malloc(sizeof(tNodoTablaDeSimb));} sentenciaDeclaracion {agregarATS(&nodo);}
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

sentenciaDeclaracion: TIPO_DATO {nodo->tipo = strdup($<cadena>1);} parteFinalDeclaracion 
					  | TOKEN_VOID {nodo->tipo = strdup($<cadena>1);} sentenciaFuncion
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

parteFinalDeclaracion: declaraId {}
				| declaraId ',' listaIdentificadores';' {}
				| sentenciaFuncion 
				| error
;

sentenciaFuncion: ID {nodo->validar = 1; nodo->identificador = strdup($<cadena>1)} '(' listaDeParametros ')' declaracionODefFuncion
				  | error
;

declaracionODefFuncion:  ';'
						| sentenciaCompuesta  
;

listaIdentificadores: declaraId ',' listaIdentificadores
                    | declaraId
					| error
;

listaDeParametros: /* vacio */ 
					|TIPO_DATO ID {encolarParametro($<cadena>1, &(nodo->principioParametros), &(nodo->finalParametros));} ',' listaDeParametros 
					| TIPO_DATO ID {encolarParametro($<cadena>1, nodo->principioParametros, nodo->finalParametros)
									agregarATS(&nodo)}
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

invocacionFuncion: ID { tNodoTablaDeSimb* nodoActual = encontrarEnTablaDeSimb($<cadena>1); validarTipo(1,nodoActual)}
				   | error
;

segundaParteInvocacion: '('')' 
						| {tColaParametro indice = nodoActual->principioDeCola;} '(' listaDeExpresiones ')' 

expresionDeAsignacion: ID opAsignacionGeneral listaDeExpresiones {printf("\n-->Expresion de asignacion.\n");}
						| error
;

opAsignacionGeneral: '='
    				| opAsignacion
;

declaraId: 	ID {nodo->identificador = strdup($<cadena>1);}
			| ID '=' expresion {nodo->identificador = strdup($<cadena>1;}
			| error
;

listaDeExpresiones: expresion {if(indice->sgte == NULL) compararConParametro($<cadena>1, nodoActual->principioDeCola, nodoActual->finalDeCola, indice); else printf ("La invocacion no cumple con la cantidad de parametros de: %s", nodoActual->identificador)}
			 	    | expresion {/* se compara con los parametros que hay en la cola de parametros*/} ',' listaDeExpresiones
					| error 
;

expresion:	 constante
			| LITERALCADENA 
			| ID {tNodoTablaDeSimb* nodoActual2 = encontrarEnTablaDeSimb(ID); validarTipo(0,nodoActual2);}  
			| expresionDeAsignacion
			| expresion '+' expresion	{if(strcmp($<cadena>1, $<cadena>3)){
											/*error*/
										}
										else
										{
											strcpy($<cadena>$, $<cadena>1);
										}
										}
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
