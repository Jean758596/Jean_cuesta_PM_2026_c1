#include <stdio.h>

void inverso(char *cadena);

int main(void)
{
    char fra[50];

    printf("\nIngrese la linea de texto: ");
    fgets(fra, 50, stdin);

    printf("\nCadena invertida: ");
    inverso(fra);

    return 0;
}

void inverso(char *cadena)
{
    if (cadena[0] != '\0')
    {
        inverso(&cadena[1]);
        putchar(cadena[0]);
    }
}
