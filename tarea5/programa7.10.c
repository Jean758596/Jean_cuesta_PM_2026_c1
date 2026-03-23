#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char c;
    char cad[50];
    int i = 0;
    float sum = 0.0;

    printf("\nDesea ingresar una cadena (S/N)? ");
    c = getchar();
    getchar(); // limpia el ENTER

    while (c == 'S' || c == 's')
    {
        printf("\nIngrese la cadena de caracteres: ");
        fgets(cad, 50, stdin);

        cad[strcspn(cad, "\n")] = '\0'; // eliminar salto de línea

        i++;
        sum += atof(cad);

        printf("\nDesea ingresar otra cadena (S/N)? ");
        c = getchar();
        getchar(); // limpia el ENTER
    }

    if (i > 0)
    {
        printf("\nSuma: %.2f", sum);
        printf("\nPromedio: %.2f", sum / i);
    }
    else
    {
        printf("\nNo se ingresaron datos.");
    }

    return 0;
}
