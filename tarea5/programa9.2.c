#include <stdio.h>

/* Archivos y caracteres.
El programa lee caracteres de un archivo. */

int main(void)
{
    char p1;
    FILE *ar;

    if ((ar = fopen("arc.txt", "r")) != NULL)  /* Se abre el archivo */
    {
        while ((p1 = fgetc(ar)) != EOF)
        {
            putchar(p1);  /* Muestra el caracter en pantalla */
        }
        fclose(ar);
    }
    else
    {
        printf("No se puede abrir el archivo");
    }

    return 0;
}
