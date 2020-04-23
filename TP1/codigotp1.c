#include <stdio.h>

int determinarColumna(char caracter);

void escribirTipoEnArchivo (char * s, FILE * archivo);

char * determinarTipo (int estado);

int main()
{
    int trans [7][5] = {
       {2,1,1,6,6},
       {1,1,1,6,6},
       {5,5,6,3,6},
       {4,4,4,6,4},
       {4,4,4,6,4},
       {5,5,6,6,6},
       {6,6,6,6,6}
    };

    
    FILE* fe = fopen("entrada.txt", "r");
    FILE* fs = fopen("salida.txt","w");
    
    int columna;
    int estadoActual = 0;
    while (!feof(fe)){
       char caracter = fgetc(fe);
       
       while(caracter != ',')
       {
           if(estadoActual != 6)
           {
                columna = determinarColumna(caracter);
                if(columna == -1)
                {
                    estadoActual = 6;
                    continue;
                }

                estadoActual = trans[estadoActual][columna];
           }
            
            caracter = fgetc(fe);
       }
       
        char * tipo = determinarTipo(estadoActual);
        escribirTipoEnArchivo(tipo, fs);
        estadoActual = 0;
    }

    fclose(fs);
    fclose(fe);
    
}

int determinarColumna(char caracter){
    if(caracter=='0') return 0;
    else if('1' <= caracter <= '7') return 1;
    else if(caracter == '8' || caracter =='9') return 2;
    else if ( caracter == 'x' || caracter =='X') return 3;
    else if('a' <= caracter <= 'f' || 'A' <= caracter <= 'F') return 4;
    else return -1;
}

void escribirTipoEnArchivo(char * s , FILE * archivo)
{
    fputs( s , archivo);
    //char  nombreTipo [] = determinarTipo(estado);
}
char * determinarTipo (int estado)
{
    if(estado == 4) return "hexadecimal,";
    if(estado == 2 || estado == 5) return "octal,";
    if(estado == 1) return "decimal,";
    
    return "VALOR NO RECONOCIDO,";
}


//asdas