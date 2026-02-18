#include <stdio.h>

/* Temperaturas.
El programa recibe 24 temperaturas (una por hora),
calcula el promedio, la máxima y la mínima
junto con la hora en que ocurrieron.
*/

/* Prototipos */
void Acutem(float);
void Maxima(float, int);
void Minima(float, int);

/* Variables globales */
float ACT = 0.0;      // Acumulador
float MAX = -50.0;    // Inicializada baja para asegurar cambio
float MIN = 60.0;     // Inicializada alta para asegurar cambio
int HMAX;             // Hora de la máxima
int HMIN;             // Hora de la mínima

int main(void)
{
    float TEM;
    int I;

    for (I = 1; I <= 24; I++)
    {
        printf("Ingresa la temperatura de la hora %d: ", I);
        scanf("%f", &TEM);

        Acutem(TEM);
        Maxima(TEM, I);
        Minima(TEM, I);
    }

    printf("\nPromedio del día: %5.2f", (ACT / 24));
    printf("\nMáxima del día: %5.2f \tHora: %d", MAX, HMAX);
    printf("\nMínima del día: %5.2f \tHora: %d\n", MIN, HMIN);

    return 0;
}

void Acutem(float T)
{
    ACT += T;
}

void Maxima(float T, int H)
{
    if (MAX < T)
    {
        MAX = T;
        HMAX = H;
    }
}

void Minima(float T, int H)
{
    if (MIN > T)
    {
        MIN = T;
        HMIN = H;
    }
}
