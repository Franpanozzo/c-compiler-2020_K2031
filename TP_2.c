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

char pop (nodo** pila);

int main()
{

    est trans [6][6] = {
        {{3, "$"},{1, "$"}, {3, "$"}, {0, "R$"}, {3, "$"}, {3, "$"}},  // q0 $
        {{1, "$"}, {1, "$"}, {0, "$"}, {3, "$"}, {3, "$"}, {3, "$"}},  // q1 $
        {{3, "R"}, {1, "R"}, {3, "$"}, {0, "RR"}, {3, "R"}, {3, "R"}}, // q0 R
        {{1, "R"}, {1, "R"}, {0, "R"}, {3, "R"}, {2, ""}, {3, "R"}},   // q1 R
        {{3, "R"}, {3, "R"}, {0, "R"}, {3, "R"}, {2, ""}, {3, "R"}},   // q2 R
        {{3, "$"}, {3, "$"}, {0, "$"}, {3, "$"}, {3, "$"}, {3, "$"}},  // q2 $
        };

    char exp [20];
    int columna;
    int fila;
    int estadoActual;
    est estadoDeTabla;
    int i , j;
    char caracterActual;
    nodo* pila = NULL;

    char cimaDePila;
    char charControl = 's';

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
        else
        {
            printf("La expresion no es sintacticamente correcta D:\n");
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