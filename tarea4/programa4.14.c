#include <stdio.h>

/* Rango de calificaciones.
El programa, al recibir como dato una serie de calificaciones, obtiene
el rango en el que se encuentran.
*/

void Rango(float);     /* Prototipo corregido (debe ser float) */

int RA1 = 0;
int RA2 = 0;
int RA3 = 0;
int RA4 = 0;
int RA5 = 0;
/* Variables globales (no recomendado en proyectos grandes) */

int main(void)
{
    float CAL;

    printf("Ingresa la primera calificación del alumno (-1 para salir): ");
    scanf("%f", &CAL);

    while (CAL != -1)
    {
        Rango(CAL);   /* Paso por valor */

        printf("Ingresa la siguiente calificación del alumno (-1 para salir): ");
        scanf("%f", &CAL);
    }

    printf("\n0..3.99 = %d", RA1);
    printf("\n4..5.99 = %d", RA2)
