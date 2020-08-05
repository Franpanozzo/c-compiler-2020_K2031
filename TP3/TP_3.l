%option noyywrap

%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//---IDENTIFICADORES
typedef struct tInfo
{
    char* identificador;
    int contador;
}tInfo;

typedef struct nodo
{
    tInfo info;
    struct nodo*  siguiente;
}nodo;

//---CADENAS
typedef struct tInfoCadena
{
    char* cadena;
    int contador;
}tInfoCadena;

typedef struct nodoCadena
{
    tInfoCadena info;
    struct nodoCadena*  siguiente;
}nodoCadena;

//---PALABRAS RESERVADAS

typedef struct nodoPalRes
{
    char* palRes;
    struct nodoPalRes* siguiente;
}nodoPalRes;

// Constantes
typedef struct tInfoConstantes
{
    char tipo;
    char* constante;
}tInfoConstantes;

typedef struct nodoConstantes
{
    tInfoConstantes info;
    struct nodoConstantes* siguiente;
}nodoConstantes;

typedef nodoConstantes* tListaConstantes; 
typedef nodo* tLista;
typedef nodoCadena* tPilaCadena;
typedef nodoPalRes* tColaPalRes;

tColaPalRes listaPalRes = NULL;
tColaPalRes listaPalResUltimo = NULL;
tPilaCadena pilaCadenas = NULL;
tLista listaDeIdentificadores = NULL;
tListaConstantes listaDeConstantes = NULL;

void procesarLiteralCadena (char* id, int longitud)
{
    tPilaCadena p = (tPilaCadena) malloc(sizeof(nodoCadena));
    p->info.cadena = strdup(id);
    p -> info.contador = longitud;
    p -> siguiente = pilaCadenas;
    pilaCadenas = p;
    tPilaCadena nodoActivo = pilaCadenas;

    while(nodoActivo){
        printf("Se encontra la cadena: %s , de longitud %i\n",p->info.cadena,p->info.contador);
        nodoActivo = nodoActivo -> siguiente;
    }
}
void insertarOrdenado(char* id)
{
    tLista nodoActivo = listaDeIdentificadores;
    tLista pNuevoNodo = (tLista) malloc(sizeof(nodo));
    tInfo informacion = {};
    pNuevoNodo->info.identificador = strdup(id);
    pNuevoNodo->info.contador = 1;



    if(listaDeIdentificadores)
    {
        while(nodoActivo->siguiente && strcmp(nodoActivo->siguiente->info.identificador, id) < 0)
        {
            nodoActivo = nodoActivo -> siguiente;
        }
        if(nodoActivo->siguiente)
        {
            pNuevoNodo->siguiente = nodoActivo->siguiente;
            nodoActivo->siguiente = pNuevoNodo;
        }
        else
        {
            nodoActivo->siguiente = pNuevoNodo;
            pNuevoNodo->siguiente = NULL;
        }
    }
    else
    {
        pNuevoNodo->siguiente = NULL;
        listaDeIdentificadores = pNuevoNodo;
    }
}
void buscarYContar (char* id)
{
    tLista nodoActivo = listaDeIdentificadores;

    if(listaDeIdentificadores)
    {
        while (nodoActivo -> siguiente && strcmp(nodoActivo->info.identificador, id) != 0)
        {
            nodoActivo = nodoActivo->siguiente;
        }

        if(strcmp(nodoActivo->info.identificador, id) == 0)
        {
            nodoActivo->info.contador++;
        }
        else
        {
            insertarOrdenado(id);
        }
    }
    else
    {
        insertarOrdenado(id);
    }
}
void procesarIdentificador(char* id)
{
    printf("Encontre un identificador: %s\n", id);

    buscarYContar(id);

    tLista nodoActivo = listaDeIdentificadores;
}

void procesarPalabraReservada(char* pr)
{
    tColaPalRes p = (tColaPalRes) malloc(sizeof(nodoPalRes));
     p->palRes = strdup(pr);

    if(listaPalRes)
    {
        listaPalResUltimo->siguiente = p;
        listaPalResUltimo = p;
        p->siguiente = NULL;
    }
    else
    {
        listaPalResUltimo = p;
        p->siguiente = NULL;
        listaPalRes = p;
    }
}

char* desencolarNodoPalabraReservada()
{
    tColaPalRes p = listaPalRes;
    listaPalRes = listaPalRes->siguiente;
    char* id = strdup(p->palRes);
    free(p);
    return id;
}

tInfoConstantes desencolarNodoConstante()
{
    tListaConstantes p = listaDeConstantes;
    listaDeConstantes = listaDeConstantes->siguiente;
    tInfoConstantes informacion = p->info;
    free(p);
    return informacion;
}

void imprimirListaPalabrasReservadas()
{
    char* informacion;

    printf("\n>>>LISTADO DE PALABRAS RESERVADAS<<<\n\n");
    while(listaPalRes)
    {
        informacion = desencolarNodoPalabraReservada();
        printf("Palabra reservada: %s \n",informacion);
    }
}

void procesarConstante(char* id, char tipo)
{
    tListaConstantes p = (tListaConstantes) malloc(sizeof(nodoConstantes));
    p->tipo = tipo;
    p->constante = strdup(id);

    if(listaDeConstantes)
    {
        listaDeConstantesUltimo->siguiente = p;
        listaDeConstantesUltimo = p;
        p->siguiente = NULL;
    }
    else
    {
        listaDeConstantesUltimo = p;
        p->siguiente = NULL;
        listaDeConstantes = p;
    }
}

void imprimirListaDeConstantes()
{
    char* informacion;
    int parteEntera;
    printf("\n>>>LISTADO DE CONSTANTES<<<\n\n");
    while(listaDeConstantes)
    {
        informacion = desencolarNodoConstante();
        switch(informacion.tipo)
        {
            case 'o':
                printf("Constante octal: %s - Valor decimal: %s", informacion.constante, strol(informacion.constante, NULL, 8));
            case 'h':
                printf("Constante hexa: %s - Valor decimal: %s", informacion.constante, strol(informacion.constante, NULL, 16));
            case 'r': 
            "-12.456E-2" parteEntera = 0 mantisa =12456
                parteEntera = (int) strol(informacion.constante, NULL, 10);
                printf("Constante real: %s - Mantisa: %i - Parte entera: %i", mantisa, parteEntera);
            case 'd':
                printf("Constante hexa: %s - Valor decimal: %s", informacion.constante, strol(informacion.constante, NULL, 16));

        }
    }
}

%}

DIGITO_DECIMAL [0-9] 
DIGITO_OCTAL [0-7] 
DIGITO_HEXADECIMAL [a-fA-F0-9] 
LETRA [a-zA-Z]
SIGNO [+-]

PARTE_EXPONENTE [Ee]{SIGNO}?{DIGITO_DECIMAL}+
SUFIJO_REAL [lLfF]
SUFIJO_ENTERO [uULl]
PALABRA_RESERVADA "auto"|"case"|"default"|"do"|"double"|"else"|"enum"|"extern"|"float"|"for"|"goto"|"if"|"int"|"long"|"register"|"return"|"short"|"signed"|"sizeof"|"static"|"struct"|"switch"|"typedef"|"union"|"unsigned"|"void"|"volatile"|"while"|"char"
CARACTER_C [^\\]
SECUENCIA_DE_ESCAPE "\\'"|"\\?"|"\\\\"|"\\a"|"\\b"|"\\f"|"\\n"|"\\r"|"\\t"|"\\v"



%%
[1-9]{DIGITO_DECIMAL}*{SUFIJO_ENTERO}? {procesarConstante(yytext, 'd'); printf("Encontre una constante entera decimal: %s \n", yytext);}
0{DIGITO_OCTAL}*{SUFIJO_ENTERO}? {procesarConstante(yytext, 'o');printf("Encontre una constante entera octal: %s \n", yytext);}
0[xX][0-9a-fA-F]+{SUFIJO_ENTERO}? {procesarConstante(yytext), 'h'); printf("Encontre una constante entera hexadecimal: %s\n", yytext);}
{DIGITO_DECIMAL}+(\.{DIGITO_DECIMAL}*)?{PARTE_EXPONENTE}?{SUFIJO_REAL}? {procesarConstante(yytext. 'r');printf("Encontre una constante real: %s \n", yytext);}
{PALABRA_RESERVADA} {procesarPalabraReservada(yytext); printf("---->Encontre una palabra reservada: %s \n", yytext);}
\'({CARACTER_C}|{SECUENCIA_DE_ESCAPE})\' {printf("Encontre una constante caracter: %s \n", yytext);}
[a-zA-Z_][a-zA-Z0-9_]* {procesarIdentificador(yytext); printf("Se encontro un identificador: %s\n", yytext);}
"++"|[*+&!,;/%<:=]|"<="|"=="|"!="|"&&"|"||"|"?"|"+="|"{"|"}"|"["|"]"|"("|")" {printf("Encontre un caracter de puntuacion: %s\n", yytext);}
\"([^\"]*)\" {procesarLiteralCadena(yytext,yyleng);}
"/*"([^*]|\*+[^/])*\*+\/ {printf("Se encontro un comentario de multiple linea.\n");}

%%

int main() {
    yyin = fopen("entrada.txt", "r");
    yyout = fopen("salida.txt", "w");
    yylex();
	
    imprimirListaPalabrasReservadas();
    imprimirListaDeConstantes();
    return 0;
}

