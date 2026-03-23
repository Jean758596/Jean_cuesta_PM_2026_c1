#include <stdio.h>
#include <string.h>

int main(void)
{
    char cad1[50], cad2[50];
    char *cad0;
    int i = 0;

    printf("\nIngrese la primera cadena: ");
    fgets(cad1, 50, stdin);

    printf("\nIngrese la cadena a buscar: ");
    fgets(cad2, 50, stdin);

    // eliminar salto de línea
    cad1[strcspn(cad1, "\n")] = '\0';
    cad2[strcspn(cad2, "\n")] = '\0';

    cad0 = cad1; // apuntar al inicio

    cad0 = strstr(cad0, cad2);

    while (cad0 != NULL)
    {
        i++;
        cad0 = strstr(cad0 + 1, cad2);
    }

    printf("\nEl numero de veces que aparece la cadena es: %d\n", i);

    return 0;
}
