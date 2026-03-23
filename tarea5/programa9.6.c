#include <stdio.h>

/* Archivos con variables enteras y reales.
El programa lee datos de alumnos almacenados en un archivo y escribe
la matrícula y el promedio de cada alumno. */

int main(void)
{
    int i, j, n, mat;
    float cal, pro;
    FILE *ar;

    if ((ar = fopen("arc9.txt", "r")) != NULL)
    {
        fscanf(ar, "%d", &n);  // número de alumnos

        for (i = 0; i < n; i++)
        {
            fscanf(ar, "%d", &mat);  // matrícula
            printf("%d\t", mat);

            pro = 0;

            for (j = 0; j < 5; j++)
            {
                fscanf(ar, "%f", &cal);  // calificaciones
                pro += cal;
            }

            printf("\t%.2f", pro / 5);  // promedio
            printf("\n");
        }

        fclose(ar);
    }
    else
    {
        printf("No se puede abrir el archivo");
    }

    return 0;
}
