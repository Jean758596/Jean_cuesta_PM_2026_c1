#include <stdio.h>

/* Suma pagos.
El programa, al recibir como datos un conjunto de pagos realizados en el último
mes, obtiene la suma de los mismos.
PAG y SPA: variables de tipo real. */

int main(void)
{
    float PAG, SPA;

    SPA = 0;

    printf("Ingrese el primer pago:\t");
    scanf("%f", &PAG);

    while (PAG != 0.0)    /* La condición es verdadera mientras el pago sea diferente de cero */
    {
        SPA += PAG;  /* Suma acumulativa */
        printf("Ingrese el siguiente pago (0 para terminar):\t");
        scanf("%f", &PAG);  /* Leer el siguiente pago */
    }

    printf("\nEl total de pagos del mes es: %.2f\n", SPA);

    return 0;
}
