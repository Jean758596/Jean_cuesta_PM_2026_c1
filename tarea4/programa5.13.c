#include <stdio.h>
/* Ordenación por selección directa */

const int MAX = 100;

/* Prototipos de funciones */
void Lectura(int[], int);
void Ordena(int[], int);
void Imprime(int[], int);

int main(void)
{
    int TAM, VEC[MAX];

    /* Validar tamaño del arreglo */
    do
    {
        printf("Ingrese el tamaño del arreglo: ");
        scanf("%d", &TAM);
    }
    while (TAM > MAX || TAM < 1);

    Lectura(VEC, TAM);
    Ordena(VEC, TAM);
    Imprime(VEC, TAM);

    return 0;
}

/* Función para leer el arreglo */
void Lectura(int A[], int T)
{
    for (int I = 0; I < T; I++)
    {
        printf("Ingrese el elemento %d: ", I + 1);
        scanf("%d", &A[I]);
    }
}

/* Función para imprimir el arreglo */
void Imprime(int A[], int T)
{
    for (int I = 0; I < T; I++)
        printf("\nA[%d]: %d", I, A[I]);
}

/* Función que ordena por selección directa */
void Ordena(int A[], int T)
{
    int I, J, MEN, L;

    for (I = 0; I < T - 1; I++)
    {
        MEN = A[I];
        L = I;

        for (J = I + 1; J < T; J++)
        {
            if (A[J] < MEN)
            {
                MEN = A[J];
                L = J;
            }
        }

        /* Intercambio de valores */
        A[L] = A[I];
        A[I] = MEN;
    }
}
