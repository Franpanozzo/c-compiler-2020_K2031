%option noyywrap

%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "TP4.tab.h"
%}



DIGITO_DECIMAL [0-9] 
DIGITO_OCTAL [0-7] 
DIGITO_HEXADECIMAL [a-fA-F0-9] 
LETRA [a-zA-Z]
SIGNO [+-]

PARTE_EXPONENTE [Ee]{SIGNO}?{DIGITO_DECIMAL}+
SUFIJO_REAL [lLfF]
SUFIJO_ENTERO [uULl]
PALABRA_RESERVADA_TIPO "int"|"long"|"double"|"float"|"char"|"short"
PALABRA_RESERVADA_BLOQUE  "while" | "for" | "if" | "do"
PALABRA_RESERVADA "auto"|"case"|"default"|"do"|"else"|"enum"|"extern"|"for"|"goto"|"if"|"register"|"return"|"signed"|"sizeof"|"static"|"struct"|"switch"|"typedef"|"union"|"unsigned"|"void"|"volatile"|"while"
CARACTER_C [^\\]
SECUENCIA_DE_ESCAPE "\\'"|"\\?"|"\\\\"|"\\a"|"\\b"|"\\f"|"\\n"|"\\r"|"\\t"|"\\v"

%%

[1-9]{DIGITO_DECIMAL}*{SUFIJO_ENTERO}? {yylval.entero = atoi(yytext); return NUM;}
0{DIGITO_OCTAL}*{SUFIJO_ENTERO}? {yylval.entero = strtol(yytext, NULL, 0); return NUM;} 
0[xX][0-9a-fA-F]+{SUFIJO_ENTERO}? {yylval.entero = strtol(yytext, NULL, 0); return NUM;}
{SIGNO}?{DIGITO_DECIMAL}+(\.{DIGITO_DECIMAL}*)?{PARTE_EXPONENTE}?{SUFIJO_REAL}? {yylval.real = atof(yytext); return REAL;}
{PALABRA_RESERVADA} {strcpy(yylval.cadena,yytext); return PALRESERVADA;}
{PALABRA_RESERVADA_TIPO} {strcpy(yylval.cadena, yytext); return TIPO_DATO;}
\'({CARACTER_C}|{SECUENCIA_DE_ESCAPE})\' {yylval.caracter = yytext[1];return CCHAR;}
[a-zA-Z_][a-zA-Z0-9_]* {strcpy(yylval.cadena,yytext); return ID;}
"//"[^\n]*$ {}
[ + - / * =: \ n () ^ ] {return yytext[0];}
\"([^\"]*)\" {strcpy(yylval.cadena, yytext);return LITERALCADENA;}
"/*"([^*]|\*+[^/])*\*+\/ {}
[^ ] {return ERROR;}

%%

/*
int main() 
{
    freopen("reporte.txt", "w", stdout);
    yyin = fopen("entrada.txt", "r");
    yyout = fopen("salida.txt", "w");
    yylex();

    return 0;
}
*/