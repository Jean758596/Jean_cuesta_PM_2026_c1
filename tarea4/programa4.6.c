#include <stdio.h>

/* Prueba de parámetros por referencia.  */

void f1(int *);
/* Prototipo de función. El parámetro es de tipo entero y por referencia
   —observa el uso del operador de indirección. */

int main(void)
{
    int I, K = 4;

    for (I = 1; I <= 3; I++)
    {
        printf("\n\nValor de K antes de llamar a la función: %d", ++K);

        f1(&K);   /* Se pasa la dirección de la variable K */

        printf("\nValor de K después de llamar a la función: %d", K);
    }

    return 0;
}

void f1(int *R)
/* La función recibe un parámetro por referencia.
   Cada vez que el parámetro se usa debe ir precedido por el operador de
   indirección. */
{
    *R += *R;
}
