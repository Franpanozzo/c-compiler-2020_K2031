%option noyywrap

%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

typedef struct tInfoCadena
{
    char* identificador;
    int contador;
}tInfoCadena;

typedef struct nodoCadena
{
    tInfoCadena info;
    struct nodoCadena*  siguiente;
}nodoCadena;

typedef nodo* tLista;
typedef nodoCadena* tPilaCadena;

tPilaCadena pilaCadenas;
tLista listaDeIdentificadores = NULL;

void procesarLiteralCadena (char* id, int longitud)
{
    tPilaCadena p = (tPilaCadena) malloc(sizeof(nodoCadena));

    //tInfoCadena nuevaInformacion = malloc(sizeof(tInfoCadena));
    //nuevaInformacion -> 

    strcpy(p -> info.identificador, id);
    p -> info.contador = longitud;
    p -> siguiente = pilaCadenas ;
    pilaCadenas = p;
}
void insertarOrdenado(char* id)
{
    tLista nodoActivo = listaDeIdentificadores;
    tLista pNuevoNodo = (tLista) malloc(sizeof(nodo));
    tInfo informacion = {};
    informacion.identificador = (char*) malloc((strlen(id) + 1) * sizeof(char));

    strcpy(informacion.identificador, id);
    informacion.contador = 1;
    pNuevoNodo->info = informacion;

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
    while (nodoActivo)
    {
        printf("-> %s : %i\n", nodoActivo->info.identificador, nodoActivo->info.contador);
        nodoActivo = nodoActivo->siguiente;
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
PALABRA_RESERVADA "auto"|"case"|"default"|"do"|"double"|"else"|"enum"|"extern"|"float"|"for"|"goto"|"if"|"int"|"long"|"register"|"return"|"short"|"signed"|"sizeof"|"static"|"struct"|"switch"|"typedef"|"union"|"unsigned"|"void"|"volatile"|"while"
CARACTER_C [^\\]
SECUENCIA_DE_ESCAPE "\\'"|"\\?"|"\\\\"|"\\a"|"\\b"|"\\f"|"\\n"|"\\r"|"\\t"|"\\v"



%%
[1-9]{DIGITO_DECIMAL}*{SUFIJO_ENTERO}? {printf("Encontre una constante entera decimal \n");}
0{DIGITO_OCTAL}*{SUFIJO_ENTERO}? {printf("Encontre una constante entera octal \n");}
0[xX][0-9a-fA-F]+{SUFIJO_ENTERO}? {printf("Encontre una constante entera hexadecimal \n");}
{DIGITO_DECIMAL}+\.{DIGITO_DECIMAL}*{PARTE_EXPONENTE}?{SUFIJO_REAL}? {printf("Encontre una constante real. \n");}
{PALABRA_RESERVADA} {printf("Encontre una palabra reservada. \n");}
\'({CARACTER_C}|{SECUENCIA_DE_ESCAPE})\' {printf("Encontre una constante caracter: %s \n", yytext);}
[a-zA-Z_][a-zA-Z0-9_]* {procesarIdentificador(yytext);}
"++"|[*+&!/%<:=]|"<="|"=="|"!="|"&&"|"||"|"?"|"+=" {printf("Encontre un caracter de puntuacion. \n");}
\"([^\"]*)\" {procesarLiteralCadena(yytext,yyleng);}

%%

int main() {
   
    yyin = fopen("entrada.txt", "r");
    yyout = fopen("salida.txt", "w");
    yylex();
	
    return 0;
}

