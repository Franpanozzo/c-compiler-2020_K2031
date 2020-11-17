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
        | input inicializarNodo
		| input error 
;

numero: NUM {$<cadena>$ = strdup($<cadena>1);}
		| REAL {$<cadena>$ = strdup($<cadena>1);}
;

inicializarNodo: {nodo = inicializarTablaDeSimbolos();} sentencia

sentencia:  sentenciaDeclaracion{agregarATS(&nodo);}
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

constante: numero {$<cadena>$ = strdup($<cadena>1);}
		   | CCHAR	{$<cadena>$ = strdup($<cadena>1);}
;

sentenciaIteracion: FOR '(' primeraExpresionFor ';' expresionOpcional ';' expresionOpcional ')' sentencia {printf("\nSe define una sentencia FOR\n");}
					| WHILE '(' expresion ')' sentencia {printf("\nSe define una sentencia WHILE\n");}
					| DO sentencia WHILE '(' expresion ')'';' {printf("\nSe define una sentencia DO WHILE\n");}
					| error
;


primeraExpresionFor: expresion | TIPO_DATO ID {nodo->identificador = strdup($<cadena>2); agregarATS(&nodo);} '=' expresion | /*vacio*/
;

expresionOpcional: expresion | /*vacio*/
;

parteFinalDeclaracion: declaraId
				| declaraId ',' listaIdentificadores';'
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
					| TIPO_DATO ID {encolarParametro($<cadena>1, &(nodo->principioParametros), &(nodo->finalParametros));}
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

invocacionFuncion: ID {nodoActual = encontrarEnTablaDeSimb($<cadena>1); validarExistenciaYTipo(1,nodoActual,$<cadena>1);} segundaParteInvocacion
				   | error
;

segundaParteInvocacion: {if(nodoActual) indice = nodoActual->principioParametros;} '(' conOSinParametros ')'

conOSinParametros: listaDeExpresionesInvocacion
				   | /* blank */

//int sumar(int a, int b){}; sumar(2,3);

expresionDeAsignacion: ID opAsignacionGeneral listaDeExpresiones {printf("\n-->Expresion de asignacion.\n");}
						| error
;

opAsignacionGeneral: '='
    				| opAsignacion
;

declaraId: 	ID {nodo->identificador = strdup($<cadena>1);}
			| ID '=' expresion {nodo->identificador = strdup($<cadena>1);}
			| error
;

listaDeExpresionesInvocacion: expresion {if(nodoActual && indice){if(indice->sgte == NULL) compararConParametro($<cadena>1, &indice); else printf ("La invocacion no cumple con la cantidad de parametros de %s", nodoActual->identificador);indice = NULL;}}
			 	    | expresion {if(nodoActual && indice){if(indice->sgte != NULL) compararConParametro($<cadena>1, &indice); else printf ("La invocacion no cumple con la cantidad de parametros de %s", nodoActual->identificador);indice = NULL;}} ',' listaDeExpresionesInvocacion
					| error 
;

listaDeExpresiones: expresion
			 	    | expresion ',' listaDeExpresiones
					| error 
;

expresion:	 constante {$<cadena>$ = strdup($<cadena>1);}
			| LITERALCADENA {$<cadena>$ = strdup($<cadena>1);}
			| ID {nodoActual2 = encontrarEnTablaDeSimb($<cadena>1); validarExistenciaYTipo(0,nodoActual2, $<cadena>1);}
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

void validarExistenciaYTipo(int a,tNodoTablaDeSimb* nodoActual, char* identificador){
	if(nodoActual){
		if(a != nodoActual->validar){
			printf("El identificador no corresponde con su uso"); //que rompa y no siga analizando
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
	printf("SE INICIA LA BUSQUEDA...\n");
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
}

void compararConParametro(char* tipoParametroEncontrado, tColaParametro* indice)
{
	if(strcmp((*indice)->tipo, tipoParametroEncontrado)){
		printf("** ERROR: La invocacion no corresponde con los tipos de parametros que hay en la declaracion de la funcion %s ** \n\n", nodo->identificador);
	}
	*indice = (*indice)->sgte;
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
	printf("IDENTIFICADOR	RETORNO	PARAMETROS\n\n");
	
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
  imprimirListaFunciones();
}
