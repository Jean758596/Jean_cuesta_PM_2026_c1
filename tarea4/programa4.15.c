#include <stdio.h>

/* Productoria.
El programa calcula la productoria de los N primeros números naturales. */

int Productoria(int);   /* Prototipo */

int main(void)
{
    int NUM;

    /* Validar que el número esté entre 1 y 100 */
    do
    {
        printf("Ingresa el número del cual quieres calcular la productoria (1-100): ");
        scanf("%d", &NUM);
    }
    while (NUM > 100 || NUM < 1);

    printf("\nLa productoria de %d es: %d\n", NUM, Productoria(NUM));

    return 0;
}

int Productoria(int N)
{
    int I, PRO = 1;

    for (I = 1; I <= N; I++)
        PRO *= I;

    return PRO;
}
