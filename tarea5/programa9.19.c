#include <stdio.h>

/* Estructura alumno */
typedef struct
{
    int matricula;
    char nombre[20];
    int carrera;
    float promedio;
} alumno;

/* Prototipo */
void ordena(FILE *ap1, FILE *ap2);

int main(void)
{
    FILE *ar1, *ar2;

    ar1 = fopen("ad5.dat", "rb");  // lectura binaria
    ar2 = fopen("ad6.dat", "wb");  // escritura binaria

    if ((ar1 != NULL) && (ar2 != NULL))
    {
        ordena(ar1, ar2);
        fclose(ar1);
        fclose(ar2);
    }
    else
    {
        printf("\nEl o los archivos no se pudieron abrir");
    }

    return 0;
}

/* Función */
void ordena(FILE *ap1, FILE *ap2)
{
    alumno alu;
    int t, n, i;

    t = sizeof(alumno);

    /* Ir al final del archivo */
    fseek(ap1, 0, SEEK_END);

    /* Número de registros */
    n = ftell(ap1) / t;

    /* Volver al inicio */
    rewind(ap1);

    /* Recorrer en orden inverso */
    for (i = n - 1; i >= 0; i--)
    {
        fseek(ap1, i * t, SEEK_SET);
        fread(&alu, t, 1, ap1);
        fwrite(&alu, t, 1, ap2);
    }
}
