%option noyywrap

%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//---IDENTIFICADORES Y CARACTERES DE PUNTUACION
typedef struct tInfo
{
    char* identificador;
    int contador;
}tInfo;

typedef enum{
    OCTAL,
    HEXADECIMAL,
    REAL,
    DECIMAL,
    CARACTER,
    UNICA,
    MULTIPLE
} ETIPO;


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

// CONSTANTES Y COMENTARIOS
typedef struct tInfoConstanteYComentario
{
    ETIPO tipo;
    char* contenido;
}tInfoConstanteYComentario;

typedef struct nodoConstanteYComentario
{
    tInfoConstanteYComentario info;
    struct nodoConstanteYComentario* siguiente;
}nodoConstanteYComentario;

typedef nodoConstanteYComentario* tListaConstantesYComentario;
typedef nodo* tLista;
typedef nodoCadena* tPilaCadena;
typedef nodoPalRes* tColaPalRes;

tColaPalRes colaPalRes = NULL;
tColaPalRes colaPalResUltimo = NULL;
tLista colaNoReconocidas = NULL;
tLista colaNoReconocidasUltimo = NULL;
tPilaCadena pilaCadenas = NULL;
tLista listaDeIdentificadores = NULL;
tListaConstantesYComentario listaDeConstantes = NULL;
tListaConstantesYComentario listaDeConstantesUltimo = NULL;
tListaConstantesYComentario listaDeComentarios = NULL;
tListaConstantesYComentario listaDeComentariosUltimo = NULL;
tLista listaCarDePun = NULL;
int contadorCaracteres = 0;
int contadorLinea = 0;

void procesarLiteralCadena (char* id, int longitud)
{
    tPilaCadena p = (tPilaCadena) malloc(sizeof(nodoCadena));
    p->info.cadena = strdup(id);
    p -> info.contador = longitud;
    p -> siguiente = pilaCadenas;
    pilaCadenas = p;
    tPilaCadena nodoActivo = pilaCadenas;
}
void insertarOrdenado(char* id, tLista* lista)
{
    tLista nodoActivo = *lista;
    tLista pNuevoNodo = (tLista) malloc(sizeof(nodo));
    pNuevoNodo->info.identificador = strdup(id);
    pNuevoNodo->info.contador = 1;

    if(*lista)
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
        *lista = pNuevoNodo;
    }
}

void buscarYContar (char* id, tLista* lista)
{
    tLista nodoActivo = *lista;
    if(*lista)
    {
        while (nodoActivo->siguiente && strcmp(nodoActivo->info.identificador, id) != 0)
        {
            nodoActivo = nodoActivo->siguiente;
        }

        if(strcmp(nodoActivo->info.identificador, id) == 0)
        {
            nodoActivo->info.contador++;
        }
        else
        {
            insertarOrdenado(id,lista);
        }
    }
    else
    {
        insertarOrdenado(id,lista);
    }
}

void procesarPalabraReservada(char* pr)
{
    tColaPalRes p = (tColaPalRes) malloc(sizeof(nodoPalRes));
     p->palRes = strdup(pr);

    if(colaPalRes)
    {
        colaPalResUltimo->siguiente = p;
        colaPalResUltimo = p;
        p->siguiente = NULL;
    }
    else
    {
        colaPalResUltimo = p;
        p->siguiente = NULL;
        colaPalRes = p;
    }
}

char* desencolarNodoPalabraReservada()
{
    tColaPalRes p = colaPalRes;
    colaPalRes = colaPalRes->siguiente;
    char* id = strdup(p->palRes);
    if(!(colaPalRes))
    {
        colaPalResUltimo = NULL;
    }
    free(p);
    return id;
}

tInfoConstanteYComentario desencolarNodoConstantesYComentarios(tListaConstantesYComentario* lista)
{
    tListaConstantesYComentario p = *lista;
    *lista = (*lista)->siguiente;
    tInfoConstanteYComentario informacion = p->info;
    free(p);
    return informacion;
}

void imprimirListaPalabrasReservadas()
{
    char* informacion;

    printf("\n>>>LISTADO DE PALABRAS RESERVADAS<<<\n\n");
    while(colaPalRes)
    {
        informacion = desencolarNodoPalabraReservada();
        printf("Palabra reservada: %s \n",informacion);
    }
    
}

tInfo desencolarNoReconocidas()
{
    tLista p = colaNoReconocidas;
    colaNoReconocidas = colaNoReconocidas->siguiente;
    tInfo informacion = p->info;
    if(!(colaNoReconocidas))
    {
        colaNoReconocidasUltimo = NULL;
    }
    free(p);
    return informacion;
}

void imprimirListaNoReconocidas()
{
    tInfo informacion;

    printf("\n>>>LISTADO DE CARACTERES NO RECONOCIDOS<<<\n\n");
    while(colaNoReconocidas)
    {
        informacion = desencolarNoReconocidas();
        printf("%s - Esta en la linea: %i\n",informacion.identificador,informacion.contador);
    }
    
}

void procesarConstanteYComentario(char* id, ETIPO cTipo, tListaConstantesYComentario* listaInicio,tListaConstantesYComentario* listaFin )
{
    tListaConstantesYComentario p = (tListaConstantesYComentario) malloc(sizeof(nodoConstanteYComentario));
    p->info.tipo = cTipo;
    p->info.contenido = strdup(id);

    if(*listaInicio)
    {
        (*listaFin)->siguiente = p;
        *listaFin = p;
        p->siguiente = NULL;
    }
    else
    {
        *listaFin = p;
        p->siguiente = NULL;
        *listaInicio = p;
    }
}

void imprimirListaDeConstantes()
{
    tInfoConstanteYComentario informacion;
    double parteEntera = 0;
    double mantisa = 0;
    double numeroReal = 0;

    printf("\n>>>LISTADO DE CONSTANTES<<<\n\n");
    while(listaDeConstantes)
    { 
        informacion = desencolarNodoConstantesYComentarios(&listaDeConstantes);
        switch(informacion.tipo)
        {
            case OCTAL:
                printf("Constante octal: %s - Valor decimal: %li\n", informacion.contenido, strtol(informacion.contenido, NULL, 8));
                break;
            case HEXADECIMAL:
                printf("Constante hexa: %s - Valor decimal: %li\n", informacion.contenido, strtol(informacion.contenido, NULL, 16));
                break;
            case REAL: 
                numeroReal = atof(informacion.contenido);
                //int parteEntera = (int) numeroReal;
                mantisa = modf(numeroReal, &parteEntera);
                
                // "-12.456E-2L" parteEntera = 0 mantisa =12456

                printf("Constante real: %s - Mantisa: %f - Parte entera: %i\n",informacion.contenido , mantisa, (int) parteEntera);
                break;
            case DECIMAL:
                printf("Constante decimal: %s\n", informacion.contenido);
                break;
            case CARACTER:
                printf("Constante caracter: %s - orden de aparicion: %i\n" , informacion.contenido, ++contadorCaracteres);
                break;
                

        }
    }
}

tInfo obtenerDeLista(tLista* lista)
{
    tLista p = *lista;
    tInfo informacion= p->info;
    *lista = p->siguiente;
    free(p);
    return informacion;
}

void imprimirLista(tLista* lista, char* titulo)
{
    printf("\n%s\n\n", titulo);
    tInfo id;
    if(titulo == ">>>LISTADO DE CARACTERES NO RECONOCIDOS<<<")
    {
        
    }
    else
    {
    while(*lista)
    {
        id = obtenerDeLista(lista);
        printf("%s - cantidad: %i\n", id.identificador, id.contador);
    }
    }
    
}

tInfoCadena popCadena()
{
    tPilaCadena p = pilaCadenas;
    pilaCadenas = pilaCadenas->siguiente;
    tInfoCadena informacion = p->info;
    free(p);
    return informacion;
}

void imprimirCadenas()
{
    tInfoCadena cad;
    printf("\n>>>LISTADO DE LITERALES CADENA<<<\n\n");
    
    while(pilaCadenas)
    {
        cad = popCadena();
        printf("%s - Longitud: %i \n", cad.cadena, cad.contador);
    }
}

void imprimirComentarios()
{
    tInfoConstanteYComentario informacion;
    printf("\n>>>LISTADO DE COMENTARIOS<<<\n\n");
    while(listaDeComentarios)
    { 
        informacion = desencolarNodoConstantesYComentarios(&listaDeComentarios);
        switch(informacion.tipo)
        {
            case UNICA:
                printf("%s - Comentario de una linea \n",informacion.contenido);
                break;
            case MULTIPLE:
                printf("%s - Comentario de multiples lineas \n",informacion.contenido);
                break;
        }
    }
}

void procesarNoReconocido(char* caracter)
{
    if(caracter[0] == '\n')
    {
        contadorLinea++;
        return;
    }

    tLista p = (tLista) malloc(sizeof(nodo));
    p->info.identificador = strdup(caracter);
    p->info.contador = contadorLinea;

    if(colaNoReconocidas)
    {
        colaNoReconocidasUltimo->siguiente = p;
        p->siguiente = NULL;
        colaNoReconocidasUltimo = p;
    }
    else
    {
        p->siguiente = NULL;
        colaNoReconocidas = p;
        colaNoReconocidasUltimo = p;
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

[1-9]{DIGITO_DECIMAL}*{SUFIJO_ENTERO}? {procesarConstanteYComentario(yytext, DECIMAL, &listaDeConstantes, &listaDeConstantesUltimo);}
0{DIGITO_OCTAL}*{SUFIJO_ENTERO}? {procesarConstanteYComentario(yytext, OCTAL, &listaDeConstantes, &listaDeConstantesUltimo);}
0[xX][0-9a-fA-F]+{SUFIJO_ENTERO}? {procesarConstanteYComentario(yytext, HEXADECIMAL, &listaDeConstantes, &listaDeConstantesUltimo);}
{SIGNO}?{DIGITO_DECIMAL}+(\.{DIGITO_DECIMAL}*)?{PARTE_EXPONENTE}?{SUFIJO_REAL}? {procesarConstanteYComentario(yytext, REAL, &listaDeConstantes, &listaDeConstantesUltimo);}
{PALABRA_RESERVADA} {procesarPalabraReservada(yytext);}
\'({CARACTER_C}|{SECUENCIA_DE_ESCAPE})\' {procesarConstanteYComentario(yytext, CARACTER, &listaDeConstantes, &listaDeConstantesUltimo);}
[a-zA-Z_][a-zA-Z0-9_]* {buscarYContar(yytext, &listaDeIdentificadores);}
"//"[^\n]*$ {procesarConstanteYComentario(yytext, UNICA, &listaDeComentarios, &listaDeComentariosUltimo);}
"++"|[*+&!,;/%<:=-]|"<="|"=="|"!="|"&&"|"||"|"?"|"+="|"{"|"}"|"["|"]"|"("|")"|"--" {buscarYContar(yytext,&listaCarDePun);}
\"([^\"]*)\" {procesarLiteralCadena(yytext,yyleng);}
"/*"([^*]|\*+[^/])*\*+\/ {procesarConstanteYComentario(yytext, MULTIPLE, &listaDeComentarios, &listaDeComentariosUltimo);}
[^ ] {procesarNoReconocido(yytext);}

%%

int main() 
{
    freopen("reporte.txt", "w", stdout);
    yyin = fopen("entrada.txt", "r");
    yyout = fopen("salida.txt", "w");
    yylex();

    imprimirLista(&listaDeIdentificadores,">>>LISTADO DE IDENTIFICADORES<<<");
    imprimirCadenas();
    imprimirListaPalabrasReservadas();
    imprimirListaDeConstantes();
    imprimirLista(&listaCarDePun,">>>LISTADO DE CARACTERES DE PUNTUACION<<<");
    imprimirComentarios();
    imprimirListaNoReconocidas();

    return 0;
}

