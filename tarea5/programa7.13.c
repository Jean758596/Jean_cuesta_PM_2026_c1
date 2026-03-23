#include <stdio.h>

int cuenta(char *cadena);

int main(void)
{
    int i;
    char cad[50];

    printf("\nIngrese la cadena de caracteres: ");
    fgets(cad, 50, stdin);

    i = cuenta(cad);

    printf("\nLongitud de la cadena: %d", i);

    return 0;
}

int cuenta(char *cadena)
{
    int c = 0;

    while (cadena[c] != '\0')
        c++;

    return c;
}
