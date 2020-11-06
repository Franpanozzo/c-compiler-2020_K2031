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
	tColaParametro principioParametros;
	tColaParametro finalParametros;
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

%}



%union {
	 struct yylval_struct {
		char* cadena;          
		int entero;                     
		int tipo;
		double real;
		char caracter;
	}estructuraDeTipos;
}

/*
	tipo:
		1 = int
		2 = float
		3 = char
		5 = void
*/


%token <estructuraDeTipos> CCHAR
%token <estructuraDeTipos> NUM
%token <estructuraDeTipos> LITERALCADENA
%token <estructuraDeTipos> ID
%token <estructuraDeTipos> TIPO_DATO
%token <estructuraDeTipos> REAL
%token <estructuraDeTipos> TOKEN_VOID
%token <estructuraDeTipos> error
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

%type <estructuraDeTipos> expresion
%type <estructuraDeTipos> numero
%type <estructuraDeTipos> constante
%type <estructuraDeTipos> declaraId

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

sentenciaDeclaracion: TIPO_DATO {tipoDato = strdup($<estructuraDeTipos>1.cadena);} parteFinalDeclaracion 
					  | TOKEN_VOID {tipoFuncion = strdup($<estructuraDeTipos>1.cadena);} sentenciaFuncion
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
				| sentenciaFuncion {tipoFuncion = strdup(tipoDato);} 
				| error
;
// new nodoDeListaDeFunciones, nodoDeListaDeFunciones.pParametros = new pColaParametros, new fColaParametros = pColaParametros
sentenciaFuncion: ID /*{crear nodo de funcion, asignarle el tipo y el identificador}*/ '(' listaDeParametros ')' declaracionODefFuncion
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
					|TIPO_DATO ID ',' listaDeParametros {/*encolarParametro($<estructuraDeTipos>1.cadena, &nodoDeListaDeFunciones.principioParametros, &nodoDeListaDeFunciones.principioParametros);*/}
					| TIPO_DATO ID {/*encolarParametro($<estructuraDeTipos>1.cadena, &nodoDeListaDeFunciones.principioParametros, &nodoDeListaDeFunciones.principioParametros);
									agregarFuncion*/}
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

invocacionFuncion: ID '(' listaDeExpresiones ')' {printf("\nSe invoca la funcion %s con parametros\n",$<estructuraDeTipos>1.cadena);}
				   |ID '('')' {printf("\nSe invoca la funcion %s\n",$<estructuraDeTipos>1.cadena)}
				   | error
;

expresionDeAsignacion: ID opAsignacionGeneral listaDeExpresiones {printf("\n-->Expresion de asignacion.\n");}
						| error
;

opAsignacionGeneral: '='
    				| opAsignacion
;

declaraId: 	ID {agregarDeclaracion($<estructuraDeTipos>1.tipo,tipoDato);}
			| ID '=' expresion {agregarDeclaracion($<estructuraDeTipos>1.cadena,tipoDato);}
			| error
;

listaDeExpresiones: expresion
			 	    | expresion ',' listaDeExpresiones
					| error 
;

expresion:	 constante
			| LITERALCADENA 
			| ID {/*$<estructuraDeTipos>$.tipo = retornarTipoVariable(),$<estructuraDeTipos>$ = ret*/}  
			| expresionDeAsignacion
			| expresion '+'expresion	{if($<estructuraDeTipos>1.tipo == $<estructuraDeTipos>3.tipo) {
											switch($<estructuraDeTipos>$.tipo)
											{
											case 1:
												$<estructuraDeTipos>$.entero = $<estructuraDeTipos>1.entero + $<estructuraDeTipos>3.entero
											case 2:
												$<estructuraDeTipos>$.real = $<estructuraDeTipos>1.real + $<estructuraDeTipos>3.real
											case 3:
												$<estructuraDeTipos>$.entero = $<estructuraDeTipos>1.caracter + $<estructuraDeTipos>3.caracter	 
											} } }
			| expresion '-' expresion	{}
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

  imprimirListaVariables();
}
