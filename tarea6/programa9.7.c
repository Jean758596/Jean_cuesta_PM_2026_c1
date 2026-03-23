#include <stdio.h>

/* Prototipo de función */
void promedio(FILE *ar1);

/* Programa principal */
int main(void)
{
    FILE *ar;

    if ((ar = fopen("arc9.txt", "r")) != NULL)
    {
        promedio(ar);  // se pasa el archivo como parámetro
        fclose(ar);
    }
    else
    {
        printf("No se puede abrir el archivo");
    }

    return 0;
}

/* Función que procesa el archivo */
void promedio(FILE *ar1)
{
    int i, j, n, mat;
    float pro, cal;

    fscanf(ar1, "%d", &n);

    for (i = 0; i < n; i++)
    {
        fscanf(ar1, "%d", &mat);
        printf("%d\t", mat);

        pro = 0;

        for (j = 0; j < 5; j++)
        {
            fscanf(ar1, "%f", &cal);
            pro += cal;
        }

        printf("\t%.2f", pro / 5);
        printf("\n");
    }
}
