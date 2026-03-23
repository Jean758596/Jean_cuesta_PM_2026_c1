#include <stdio.h>
#include <string.h>

char *inverso(char *cadena);

int main(void)
{
    char fra[50], aux[50];

    printf("\nIngrese la linea de texto: ");
    fgets(fra, 50, stdin);

    // eliminar salto de línea
    fra[strcspn(fra, "\n")] = '\0';

    strcpy(aux, inverso(fra));

    printf("\nCadena invertida: ");
    puts(aux);

    return 0;
}

char *inverso(char *cadena)
{
    int i = 0, j, lon;
    char temp;

    lon = strlen(cadena);
    j = lon - 1;

    while (i < j)
    {
        temp = cadena[i];
        cadena[i] = cadena[j];
        cadena[j] = temp;

        i++;
        j--;
    }

    return cadena;
}
