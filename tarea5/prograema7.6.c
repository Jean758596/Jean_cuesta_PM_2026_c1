#include <stdio.h>
#include <string.h>

int main(void)
{
    char cad0[50] = "Hola Mexico";
    char cad1[20], cad2[20], cad3[20] = ", buenos dias!!!";

    strcpy(cad1, cad0);
    printf("\nPrueba strcpy (cad0 -> cad1): %s\n", cad1);

    strcpy(cad1, cad3);
    printf("\nPrueba strcpy (cad3 -> cad1): %s\n", cad1);

    strcpy(cad1, "XX");
    printf("\nPrueba strcpy (XX -> cad1): %s\n", cad1);

    strncpy(cad2, cad0, 4);
    cad2[4] = '\0';
    printf("\nPrueba strncpy (4 de cad0 -> cad2): %s\n", cad2);

    strncpy(cad2, cad3, 3);
    cad2[3] = '\0';
    printf("\nPrueba strncpy (3 de cad3 -> cad2): %s\n", cad2);

    strcat(cad0, cad3);
    printf("\nPrueba strcat (cad3 a cad0): %s\n", cad0);

    strcat(cad1, " YY");
    printf("\nPrueba strcat (YY a cad1): %s\n", cad1);

    strcat(cad2, " ");
    strncat(cad2, cad0, 4);
    printf("\nPrueba strncat (4 de cad0 a cad2): %s\n", cad2);

    char *ptr;

    ptr = strstr(cad0, "Mexico");
    printf("\nPrueba strstr (Mexico en cad0): %s\n", ptr);

    ptr = strstr(cad0, "Guatemala");
    if (ptr != NULL)
        printf("\nPrueba strstr (Guatemala en cad0): %s\n", ptr);
    else
        printf("\nGuatemala no encontrada\n");

    return 0;
}
