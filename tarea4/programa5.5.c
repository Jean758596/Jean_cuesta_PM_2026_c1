#include <stdio.h>

/* Frecuencia de calificaciones.
El programa recibe 50 calificaciones (0 a 5)
y calcula la frecuencia de cada una.
Además muestra cuál es la frecuencia más alta.
*/

const int TAM = 50;

/* Prototipos */
void Lectura(int *, int);
void Frecuencia(int *, int, int *, int);
void Impresion(int *, int);
void Mayor(int *, int);

int main(void)
{
    int CAL[TAM];
    int FRE[6] = {0};   /* 0,1,2,3,4,5 */

    Lectura(CAL, TAM);
    Frecuencia(CAL, TAM, FRE, 6);

    printf("\nFrecuencia de Calificaciones\n");
    Impresion(FRE, 6);

    Mayor(FRE, 6);

    return 0;
}

void Lectura(int VEC[], int T)
{
    int I;
    for (I = 0; I < T; I++)
    {
        printf("Ingrese la calificación (0-5) del alumno %d: ", I + 1);
        scanf("%d", &VEC[I]);
    }
}

void Impresion(int VEC[], int T)
{
    int I;
    for (I = 0; I < T; I++)
        printf("\nCalificación %d: %d alumnos", I, VEC[I]);
}

void Frecuencia(int A[], int P, int B[], int T)
{
    int I;
    for (I = 0; I < P; I++)
    {
        if ((A[I] >= 0) && (A[I] < T))
            B[A[I]]++;
    }
}

void Mayor(int X[], int T)
{
    int I;
    int MFRE = 0;
    int MVAL = X[0];

    for (I = 1; I < T; I++)
    {
        if (MVAL < X[I])
        {
            MFRE = I;
            MVAL = X[I];
        }
    }

    printf("\n\nMayor frecuencia:");
    printf("\nCalificación: %d", MFRE);
    printf("\nCantidad de alumnos: %d\n", MVAL);
}
