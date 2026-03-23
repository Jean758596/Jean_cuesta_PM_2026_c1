#include <stdio.h>
#include <ctype.h>

/* Prototipo */
void minymay(FILE *arc);

int main(void)
{
    FILE *ar;

    if ((ar = fopen("arc5.txt", "r")) != NULL)
    {
        minymay(ar);
        fclose(ar);
    }
    else
    {
        printf("No se pudo abrir el archivo");
    }

    return 0;
}

/* Función */
void minymay(FILE *arc)
{
    int min = 0, may = 0;
    int p;  // IMPORTANTE: int para manejar EOF

    while ((p = fgetc(arc)) != EOF)
    {
        if (islower(p))
            min++;
        else if (isupper(p))
            may++;
    }

    printf("\nNúmero de minúsculas: %d", min);
    printf("\nNúmero de mayúsculas: %d", may);
}
