#include <stdio.h>
/* Búsqueda binaria */

const int MAX = 100;

/* Prototipos */
void Lectura(int[], int);
int Binaria(int[], int, int);

int main(void)
{
    int RES, ELE, TAM, VEC[MAX];

    /* Validar tamaño del arreglo */
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

    RES = Binaria(VEC, TAM, ELE);

    if (RES)
        printf("\nEl elemento se encuentra en la posición: %d\n", RES);
    else
        printf("\nEl elemento no se encuentra en el arreglo\n");

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

/* Función de búsqueda binaria */
int Binaria(int A[], int T, int E)
{
    int IZQ = 0, DER = T - 1, CEN;

    while (IZQ <= DER)
    {
        CEN = (IZQ + DER) / 2;

        if (A[CEN] == E)
            return CEN + 1;  // Posición desde 1
        else if (E > A[CEN])
            IZQ = CEN + 1;
        else
            DER = CEN - 1;
    }

    return 0;  // No encontrado
}
