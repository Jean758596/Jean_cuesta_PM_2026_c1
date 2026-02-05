#include <stdio.h>

/* Lanzamiento de martillo.
El programa, al recibir como dato N lanzamientos de martillo, calcula el promedio
de los lanzamientos de la atleta cubana.
I, N: variables de tipo entero.
LAN, SLA: variables de tipo real. */

int main(void)
{
    int I, N;
    float LAN, SLA = 0;

    /* Se utiliza do-while para verificar que N sea correcto (1-11) */
    do
    {
        printf("Ingrese el número de lanzamientos (1-11):\t");
        scanf("%d", &N);
    }
    while (N < 1 || N > 11);  /* operador OR lógico */

    for (I = 1; I <= N; I++)
    {
        printf("\nIngrese el lanzamiento %d: ", I);
        scanf("%f", &LAN);
        SLA += LAN;  /* suma acumulativa */
    }

    SLA = SLA / N;  /* cálculo del promedio */

    printf("\nEl promedio de lanzamientos es: %.2f\n", SLA);

    return 0;
}
