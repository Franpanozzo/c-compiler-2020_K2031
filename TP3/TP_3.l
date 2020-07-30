%option noyywrap

%{
#include <stdio.h>
%}

DIGITO_DECIMAL [0-9] 
DIGITO_OCTAL [0-7] 
DIGITO_HEXADECIMAL [a-fA-F0-9] 
LETRA [a-zA-Z]
SIGNO [+-]

PARTE_EXPONENTE [Ee]{SIGNO}?{DIGITO_DECIMAL}+
SUFIJO_REAL [lLfF]
SUFIJO_ENTERO [uULl]

PALABRAS_RESERVADAS "auto" | "break" | "case" | "char" | "const" | "continue" | "default" | "do" | "double" | "else" | " enum" | "extern" | "float" | "for" | "goto" | "if"

%%

({DIGITO_DECIMAL}*.)?{DIGITO_DECIMAL}+{PARTE_EXPONENTE}?{SUFIJO_REAL}? {printf("Encontre una constante real.");}
[1-9]{DIGITO_DECIMAL}*{SUFIJO_ENTERO}? {printf("Encontre una constante entera decimal \n");}
0{DIGITO_OCTAL}*{SUFIJO_ENTERO}? {printf("Encontre una constante entera octal \n");}
0[xX][0-9a-fA-F]+{SUFIJO_ENTERO}? {printf("Encontre una constante entera hexadecimal \n");}
[a-zA-Z_][a-zA-Z0-9_]* {printf("Encontre un identificador \n");}

"++" | [*+&!/%<:=] | "sizeof" | "<=" | "==" | "!=" | "&&" | "||" | "?" | "+=" {printf("Encontre un caracter de puntuacion. \n");}
{PALABRAS_RESERVADAS} {printf("Encontre una palabra reservada. \n");}

%%

int main() {
   
    yyin = fopen("entrada.txt", "r");
    yyout = fopen("salida.txt", "w");
    yylex();
	
    return 0;
}