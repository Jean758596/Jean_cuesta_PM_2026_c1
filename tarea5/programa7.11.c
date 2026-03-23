#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
    char p, cad[50];
    int n;

    printf("\nIngrese la cadena de caracteres (maximo 50): ");
    fgets(cad, 50, stdin);

    printf("\nIngrese la posicion en la cadena que desea verificar: ");
    scanf("%d", &n);

    int len = strlen(cad);

    if (n >= 1 && n <= len)
    {
        p = cad[n - 1];

        if (islower(p))
            printf("\n%c es una letra minuscula", p);
        else
            printf("\n%c no es una letra minuscula", p);
    }
    else
    {
        printf("\nEl valor ingresado de n es incorrecto");
    }

    return 0;
}
