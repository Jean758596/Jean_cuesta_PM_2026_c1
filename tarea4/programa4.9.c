#include <stdio.h>

/* Paso de una función como parámetro por referencia. */

int Suma(int X, int Y)
/* La función Suma regresa la suma de los parámetros X y Y. */
{
    return (X + Y);
}

int Resta(int X, int Y)
/* Esta función regresa la resta de los parámetros X y Y. */
{
    return (X - Y);
}

int Control(int (*apf)(int, int), int X, int Y)
/* Esta función recibe como parámetro la dirección de otra función */
{
    int RES;

    RES = (*apf)(X, Y);   /* Llama a Suma o Resta */

    return RES;
}

int main(void)
{
    int R1, R2;

    R1 = Control(Suma, 15, 5);
    R2 = Control(Resta, 10, 4);

    printf("\nResultado 1: %d", R1);
    printf("\nResultado 2: %d", R2);

    return 0;
}
