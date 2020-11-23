%option noyywrap

%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "TP5.tab.h"

int lineno = 1;

%}

DIGITO_DECIMAL [0-9] 
DIGITO_OCTAL [0-7] 
DIGITO_HEXADECIMAL [a-fA-F0-9] 
LETRA [a-zA-Z]
PARTE_EXPONENTE [Ee]{SIGNO}?{DIGITO_DECIMAL}+
SUFIJO_REAL [lLfF]
SUFIJO_ENTERO [uULl]
PALABRA_RESERVADA_TIPO "int"|"long"|"double"|"float"|"char"|"short"|"char*"
CARACTER_C [^\\]
SECUENCIA_DE_ESCAPE "\\'"|"\\?"|"\\\\"|"\\a"|"\\b"|"\\f"|"\\n"|"\\r"|"\\t"|"\\v"
CONSTANTE_REAL {DIGITO_DECIMAL}+\.{DIGITO_DECIMAL}*{SUFIJO_REAL}? 
%%


[1-9]{DIGITO_DECIMAL}*{SUFIJO_ENTERO}? {yylval.cadena = "int"; return NUM;}
0{DIGITO_OCTAL}*{SUFIJO_ENTERO}? {yylval.cadena = "int"; return NUM;} 
0[xX][0-9a-fA-F]+{SUFIJO_ENTERO}? {yylval.cadena = "int"; return NUM;}
{CONSTANTE_REAL} {yylval.cadena = "float"; return REAL;}
{PALABRA_RESERVADA_TIPO} {yylval.cadena = strdup(yytext); return TIPO_DATO;}
\'({CARACTER_C}|{SECUENCIA_DE_ESCAPE})\' {yylval.cadena = "char"; return CCHAR;}
"if" {return IF;}
"else" {return ELSE;}
"for" {return FOR;}
"while" {return WHILE;}
"break" {return BREAK;}
"case" {return CASE;}
"do" {return DO;}
"switch" {return SWITCH;}
"default" {return DEFAULT;}
"void" {yylval.cadena = strdup(yytext); return TOKEN_VOID;}
"return" {return RETURN;}
"//"[^\n]*$ {;}
"++" {return OP_INCREMENTO;}
"--" {return OP_DECREMENTO;}
"==" {return IGUALIGUAL;}
"!=" {return NOIGUAL;}
"&&" {return YLOGICO;}
"||" {return OLOGICO;}
"<=" {return MENORIGUAL;}
">=" {return MAYORIGUAL;}
"+=" {return MASIGUAL;}
"-=" {return MENOSIGUAL;}
"*=" {return PORIGUAL;}
"/=" {return DIVIDIDOIGUAL;}
[a-zA-Z_][a-zA-Z0-9_]* {yylval.cadena = strdup(yytext); return ID;}
[+-/*=:()^{};&<>] {return yytext[0];}
\"([^\"]*)\" {yylval.cadena = "char*";return LITERALCADENA;}
"/*"([^*]|\*+[^/])*\*+\/ {}
\n {lineno++;}
[^ ] {printf("\nHay un error lexico, la secuencia %s no es reconocida\n\n",yytext);}
%%