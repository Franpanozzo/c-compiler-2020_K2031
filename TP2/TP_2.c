#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//codigo final

typedef struct {
    int estadoSiguiente;
    char cadenaPush[2+1];
} est;

typedef struct _nodo{
    struct _nodo* sgte;
    char info;
} nodo;

int determinarColumna(char caracter);

int determinarFila (int estadoActual, char cimaDePila);

int esEstadoFinal (int estado, char cimaDePila);

void push (nodo** pila, char x);

void vaciarPila(nodo ** pila);

char pop (nodo** pila);

int main()
{

    est trans [6][6] = {
        {{3, "$"}, {1, "$"}, {3, "$"}, {0, "R$"}, {3, "$"}, {3, "$"}}, // q0 $
        {{1, "$"}, {1, "$"}, {0, "$"}, {3, "$"}, {3, "$"}, {3, "$"}},  // q1 $
        {{3, "R"}, {1, "R"}, {3, "$"}, {0, "RR"}, {3, "R"}, {3, "R"}}, // q0 R
        {{1, "R"}, {1, "R"}, {0, "R"}, {3, "R"}, {2, ""}, {3, "R"}},   // q1 R
        {{3, "R"}, {3, "R"}, {0, "R"}, {3, "R"}, {2, ""}, {3, "R"}},   // q2 R
        {{3, "$"}, {3, "$"}, {0, "$"}, {3, "$"}, {3, "$"}, {3, "$"}},  // q2 $
        };

    char exp [50];
    int columna;
    int fila;
    int estadoActual;
    est estadoDeTabla;
    int i , j;
    char caracterActual;
    nodo* pila = NULL;

    char cimaDePila;
    char charControl = 's';
     est pos;
    while (charControl != 'n' && charControl != 'N')
    {
        i = j = estadoActual = 0;
        vaciarPila (&pila);
        push (&pila, '$');

        system("cls");
        printf("Ingrese la expresion a evaluar: ");
        scanf("%s",exp);
        caracterActual = exp[i];

        while (caracterActual != '\0' && estadoActual != 3)
        {
            cimaDePila = pop(&pila);
            columna = determinarColumna(caracterActual);
            fila = determinarFila(estadoActual , cimaDePila);

            estadoDeTabla = trans[fila][columna];
            estadoActual = estadoDeTabla.estadoSiguiente;

            if (estadoDeTabla.estadoSiguiente == 3)
            {
                printf("Hubo un error de sintaxis en la posicion %d\n", j);
                determinarError(caracterActual, fila);
            }

            for(int h = strlen(estadoDeTabla.cadenaPush) - 1; h >= 0 ; h--)
            {
                push(&pila, estadoDeTabla.cadenaPush[h]);
            }

            j++;
            caracterActual = exp[++i];
        }

        cimaDePila = pop(&pila);

        if(esEstadoFinal(estadoActual, cimaDePila))
        {
            printf("La expresion es sintacticamente correcta :D\n");
        }
        else if (estadoActual != 3)
        {
            fila = determinarFila(estadoActual, cimaDePila);
            printf("La expresion no es sintacticamente correcta D:\n");
            int m=0;
            printf("Se esperaba alguno:\n");   
            while(m<6)
            {
               pos=trans [fila][m];
               if(pos.estadoSiguiente!=3 ){   //((2+3)+
                  switch (m)
                  {
                       case 0:
                          printf(" 0\n");
                          break;
                        case 1:
                          printf("1 al 9\n");
                          break;
                       case 2:
                          printf(" + ,- ,* o /\n");
                          break;
                       case 3:
                          printf("(\n");
                          break;
                       case 4:
                          printf(" )\n");
                          break;
                    }
               }
               m++;
           }
        }

        printf("Quiere ingresar otra expresion? (s/n): ");
        fflush(stdin);
        charControl = getc(stdin);
    }

    return 0;
}

int esEstadoFinal(int estado, char cimaDePila)
{
    return (estado == 1 || estado == 2) && cimaDePila == '$';
}

void determinarError(char c, int fila)
{
    switch(fila)
    {
        case 0: //05
            if(c == '0') printf ("La expresion no puede empezar con 0\n");
            if(c == '+' || c == '-' || c == '*' || c == '/')  printf ("La expresion no puede empezar con una operacion\n");  
            if(c == ')') printf ("La expresion necesita un ( antes\n");     
            break;
        case 1: //2()
            if(c == '(') printf ("No se puede abrir un parentesis despues de un numero\n");
            if(c == ')') printf ("No se puede cerrar un parentesis despues de un numero\n");
            break;
        case 2: //5+05  5+-  5+)
            if(c == '0') printf ("La expresion no puede empezar con 0\n");
            if(c == '+' || c == '-' || c == '*' || c == '/')  printf ("La expresion no puede empezar con una operacion\n");  
            if(c == ')') printf ("No puede haber parentesis vacios\n");
            break;
        case 3: //(2()
            printf ("No se puede abrir un parentesis despues de un numero\n");
            break;
        case 4://(2+2)0   (2+2)1  (2+2)(
        case 5:
            if(c >= '0' && '9' >= c) printf ("No puede haber un numero despues de un parentesis de cierre\n");
            if(c == '(') printf ("No puede venir un parentesis de apertura despues de uno de cierre\n");
            if (c == ')') printf ("Cerraste parentesis de mas\n");
            break;
    }
}

void vaciarPila(nodo ** pila)
{
    while (*pila != NULL)
    {
        pop(pila);
    }
}

int determinarColumna(char caracter){
    if(caracter=='0') return 0;
    else if('1' <= caracter && caracter <= '9') return 1;
    else if(caracter == '+' || caracter =='-' || caracter == '*' || caracter == '/') return 2;
    else if ( caracter == '(') return 3;
    else if(caracter == ')') return 4;
    else return 5;
}

void push (nodo** pila, char x)
{
    nodo* p = (nodo*) malloc(sizeof(nodo));
    p -> info = x;
    p -> sgte = *pila ;
    *pila = p;
}

char pop (nodo** pila)
{
    nodo*p = *pila;
    char x = p->info;
    *pila = p->sgte;
    free (p);
    return x;
}

int determinarFila (int estadoActual, char cimaDePila)
{
    int ret;

    switch (estadoActual)
    {
        case 0:
            ret = cimaDePila == '$' ? 0 : 2;
            break;
        case 1:
            ret = cimaDePila == '$' ? 1 : 3;
            break;
        case 2:
            ret = cimaDePila == '$' ? 5 : 4;
            break;
    }

    return ret;
}