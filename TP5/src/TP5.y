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

numero: NUM {$<cadena>$ = strdup($<cadena>1);}
		| REAL {$<cadena>$ = strdup($<cadena>1);}
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
			| error PuntoYComaOBarraN
;

puntoYComaOBarraN: ';'
			     | '\n'

sentenciaSalto: BREAK ';'
				| CONTINUE ';'
;

sentenciaDeclaracion: TIPO_DATO {inicializarNodoConTipo($<cadena>1, &nodo);} parteFinalDeclaracion 
					  | TOKEN_VOID {inicializarNodoConTipo($<cadena>1, &nodo);} sentenciaFuncion
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


primeraExpresionFor: expresion 
					 | TIPO_DATO ID {nodo-> validar = 0;nodo->identificador = strdup($<cadena>2); agregarATS(&nodo);} '=' expresion 
					 | /*vacio*/
;

expresionOpcional: expresion | /*vacio*/
;

parteFinalDeclaracion: declaraId ';'
				| declaraId ',' {inicializarNodoConTipo(nodo->tipo, &nodo);} listaIdentificadores
				| sentenciaFuncion
				| error
;

sentenciaFuncion: ID {inicializarNodoConTipo(nodo->tipo, &nodo2);nodo2->validar = 1; nodo2->identificador = strdup($<cadena>1);} '(' listaDeParametros ')' declaracionODefFuncion {printf("Se va a agregar %s de tipo %s\n", nodo2->identificador,nodo2->tipo);agregarATS(&nodo2);}
				  | error
;

declaracionODefFuncion:  ';'
						| sentenciaCompuesta
						| error
;

listaIdentificadores: declaraId ',' {inicializarNodoConTipo(nodo->tipo, &nodo);} listaIdentificadores
                    | declaraId ';'
					| error
;

listaDeParametros: /* vacio */ 
					|TIPO_DATO ID {encolarParametro($<cadena>1, &(nodo2->principioParametros), &(nodo2->finalParametros));} ',' listaDeParametros 
					| TIPO_DATO ID {encolarParametro($<cadena>1, &(nodo2->principioParametros), &(nodo2->finalParametros));}
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

declaraId: 	ID {nodo->identificador = strdup($<cadena>1);agregarATS(&nodo);}
			| ID '=' expresion {nodo->identificador = strdup($<cadena>1);agregarATS(&nodo);}
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
