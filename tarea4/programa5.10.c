#include <stdio.h>

/* Búsqueda secuencial en arreglos ordenados en forma creciente */

const int MAX = 100;

/* Prototipos */
void Lectura(int[], int);
int Busca(int[], int, int);

int main(void)
{
    int RES, ELE, TAM, VEC[MAX];

    do
    {
        printf("Ingrese el tamaño del arreglo: ");
        scanf("%d", &TAM);
    }
    while (TAM > MAX || TAM < 1);

    printf("\n*** Recuerde ingresar los datos en orden creciente ***\n\n");

    Lectura(VEC, TAM);

    printf("\nIngrese el elemento a buscar: ");
    scanf("%d", &ELE);

    RES = Busca(VEC, TAM, ELE);

    if (RES)
        printf("\nEl elemento se encuentra en la posición: %d", RES);
    else
        printf("\nEl elemento no se encuentra en el arreglo");

    return 0;
}

/* Función para leer el arreglo */
void Lectura(int A[], int T)
{
    int I;

    for (I = 0; I < T; I++)
    {
        printf("Ingrese el elemento %d: ", I + 1);
        scanf("%d", &A[I]);
    }
}

/* Búsqueda secuencial optimizada */
int Busca(int A[], int T, int E)
{
    int I = 0;

    while (I < T && E >= A[I])
    {
        if (A[I] == E)
            return I + 1;   /* Posición desde 1 */
        I++;
    }

    return 0;   /* No encontrado */
}
