#include <stdio.h>

/* Conflicto de variables con el mismo nombre. */

void f1(void);        /* Prototipo de función. */
int K = 5;            /* Variable global. */

int main(void)
{
    int I;

    for (I = 1; I <= 3; I++)
        f1();

    return 0;
}

void f1(void)   /* La función utiliza tanto la variable local como la global */
{
    int K = 2;   /* Variable local */

    K += K;   /* K = 2 + 2 = 4 */
    printf("\n\nEl valor de la variable local es: %d", K);

    /* En C no existe :: como en C++.
       La variable global K está oculta por la local.
       Para usar la global, no debe existir una local con el mismo nombre.
       Por eso usamos otro nombre auxiliar. */

    {
        extern int K;   /* Hace referencia a la variable global */
        K = K + 4;
        printf("\nEl valor de la variable global es: %d", K);
    }
}
