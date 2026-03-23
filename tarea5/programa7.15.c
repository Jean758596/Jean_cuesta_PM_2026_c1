#include <stdio.h>
#include <ctype.h>

void interpreta(char *cadena);

int main(void)
{
    char cad[50];

    printf("\nIngrese la cadena de caracteres: ");
    fgets(cad, 50, stdin);

    interpreta(cad);

    return 0;
}

void interpreta(char *cadena)
{
    int i = 0, j, k;

    while (cadena[i] != '\0')
    {
        if (isalpha(cadena[i]))
        {
            k = cadena[i - 1] - '0';  // convertir carácter a número

            for (j = 0; j < k; j++)
                putchar(cadena[i]);
        }
        i++;
    }
}
