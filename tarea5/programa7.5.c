#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i;
    double d;
    long l;
    char cad0[20];
    char *cad1;

    printf("\nIngrese una cadena de caracteres: ");
    fgets(cad0, sizeof(cad0), stdin);

    i = atoi(cad0);
    printf("\n%s \t %d", cad0, i + 3);

    printf("\nIngrese una cadena de caracteres: ");
    fgets(cad0, sizeof(cad0), stdin);

    d = atof(cad0);
    printf("\n%s \t %.2lf", cad0, d + 1.50);

    d = strtod(cad0, &cad1);
    printf("\n%s \t %.2lf", cad0, d + 1.50);
    printf("\nResto: %s", cad1);

    l = atol(cad0);
    printf("\n%s \t %ld", cad0, l + 10);

    l = strtol(cad0, &cad1, 10);
    printf("\n%s \t %ld", cad0, l + 10);
    printf("\nResto: %s", cad1);

    return 0;
}
