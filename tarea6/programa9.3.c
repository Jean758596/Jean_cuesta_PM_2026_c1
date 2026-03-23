#include <stdio.h>

/* Archivos y cadenas de caracteres.
El programa escribe cadenas en un archivo. */

int main(void)
{
    char cad[50];
    int res;
    FILE *ar;

    if ((ar = fopen("arc.txt", "w")) != NULL)
    {
        printf("\n¿Desea ingresar una cadena de caracteres?  Sí-1 No-0: ");
        scanf("%d", &res);
        getchar();  // limpiar el ENTER del buffer

        while (res)
        {
            printf("Ingrese la cadena: ");
            fgets(cad, sizeof(cad), stdin);

            fputs(cad, ar);  // escribe la cadena

            printf("\n¿Desea ingresar otra cadena?  Sí-1 No-0: ");
            scanf("%d", &res);
            getchar();  // limpiar buffer
        }

        fclose(ar);
    }
    else
    {
        printf("No se puede abrir el archivo");
    }

    return 0;
}
