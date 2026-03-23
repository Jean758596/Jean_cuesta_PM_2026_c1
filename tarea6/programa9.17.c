#include <stdio.h>
#include <string.h>

/* Prototipo */
void cambia(FILE *ap1, FILE *ap2);

int main(void)
{
    FILE *ar;
    FILE *ap;

    ar = fopen("arc.txt", "r");
    ap = fopen("arc1.txt", "w");

    if ((ar != NULL) && (ap != NULL))
    {
        cambia(ar, ap);
        fclose(ar);
        fclose(ap);
    }
    else
    {
        printf("No se pueden abrir los archivos");
    }

    return 0;
}

/* Función */
void cambia(FILE *ap1, FILE *ap2)
{
    char cad[100];

    while (fgets(cad, sizeof(cad), ap1) != NULL)
    {
        char *pos = strstr(cad, "méxico");

        while (pos != NULL)
        {
            pos[0] = 'M';  // reemplaza la primera letra

            pos = strstr(pos + 1, "méxico");  // sigue buscando
        }

        fputs(cad, ap2);
    }
}
