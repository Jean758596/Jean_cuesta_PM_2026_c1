#include <stdio.h>
#include <string.h>
#include <ctype.h>

int cuentap(char *cad);

int main(void)
{
    int i;
    char fra[50];

    printf("\nIngrese la linea de texto: ");
    fgets(fra, 50, stdin);

    // eliminar salto de línea
    fra[strcspn(fra, "\n")] = '\0';

    i = cuentap(fra);

    printf("\nLa linea de texto tiene %d palabras\n", i);

    return 0;
}

int cuentap(char *cad)
{
    int i = 0, palabras = 0;
    int en_palabra = 0;

    while (cad[i] != '\0')
    {
        if (!isspace(cad[i]) && en_palabra == 0)
        {
            palabras++;
            en_palabra = 1;
        }
        else if (isspace(cad[i]))
        {
            en_palabra = 0;
        }

        i++;
    }

    return palabras;
}
