#include <stdio.h>
#include <math.h>

/* Función para calcular la media */
float Media(int A[], int T)
{
    int I;
    float SUM = 0.0;
    for (I = 0; I < T; I++)
        SUM += A[I];
    return SUM / T;
}

/* Función para calcular la varianza */
float Varianza(int A[], int T, float M)
{
    int I;
    float SUM = 0.0;
    for (I = 0; I < T; I++)
        SUM += pow((A[I] - M), 2);
    return SUM / T;
}

/* Función para calcular la desviación estándar */
float Desviacion(float V)
{
    return sqrt(V);
}

/* Función para calcular la frecuencia de calificaciones */
void Frecuencia(int A[], int P, int B[])
{
    int I;
    for (I = 0; I < P; I++)
        B[A[I]]++;
}

/* Función para calcular la moda */
int Moda(int A[], int T)
{
    int I, MOD = 0, VAL = A[0];
    for (I = 1; I < T; I++)
    {
        if (A[I] > VAL)
        {
            VAL = A[I];
            MOD = I;
        }
    }
    return MOD;
}
