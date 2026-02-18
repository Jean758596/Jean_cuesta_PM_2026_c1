#include <stdio.h>

/* Prototipos de funciones */
void Lectura(int *, int);
void Imprime(int *, int);
void Elimina(int *, int *);

int main(void)
{
    int TAM, ARRE[100];

    /* Validar tamaño */
    do
    {
        printf("Ingrese el tamaño del arreglo: ");
        scanf("%d", &TAM);
    }
    while (TAM > 100 || TAM < 1);

    Lectura(ARRE, TAM);

    /* Se pasa TAM por referencia */
    Elimina(ARRE, &TAM);

    Imprime(ARRE, TAM);

    return 0;
}

/* Función para leer el arreglo */
void Lectura(int A[], int T)
{
    int I;

    printf("\n");

    for (I = 0; I < T; I++)
    {
        printf("Ingrese el elemento %d: ", I + 1);
        scanf("%d", &A[I]);
    }
}

/* Función para imprimir el arreglo */
void Imprime(int A[], int T)
{
    int I;

    printf("\nArreglo sin elementos repetidos:\n");

    for (I = 0; I < T; I++)
        printf("A[%d]: %d\n", I, A[I]);
}

/* Función que elimina repetidos */
void Elimina(int A[], int *T)
{
    int I = 0, K, L;

    while (I < (*T - 1))
    {
        K = I + 1;

        while (K <= (*T - 1))
        {
            if (A[I] == A[K])
            {
                /* Desplazar elementos */
                for (L = K; L < (*T - 1); L++)
                    A[L] = A[L + 1];

                *T = *T - 1;   /* Reducir tamaño */
            }
            else
                K++;
        }

        I++;
    }
}
