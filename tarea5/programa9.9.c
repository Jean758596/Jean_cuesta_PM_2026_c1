#include <stdio.h>

/* Alumnos.
El programa lee bloques (estructuras alumno) de un archivo binario. */

typedef struct
{
    int matricula;
    char nombre[20];
    int carrera;
    float promedio;
} alumno;

/* Prototipo */
void lee(FILE *ap);

int main(void)
{
    FILE *ar;

    if ((ar = fopen("ad1.dat", "rb")) != NULL)
    {
        lee(ar);   // ← aquí estaba el error
        fclose(ar);
    }
    else
    {
        printf("\nEl archivo no se puede abrir");
    }

    return 0;
}

/* Función que lee el archivo */
void lee(FILE *ap)
{
    alumno alu;

    /* Primera lectura */
    fread(&alu, sizeof(alumno), 1, ap);

    while (!feof(ap))
    {
        printf("\nMatrícula: %d", alu.matricula);
        printf("\tCarrera: %d", alu.carrera);
        printf("\tPromedio: %.2f\t", alu.promedio);
        printf("\tNombre: %s", alu.nombre);

        /* Siguiente lectura */
        fread(&alu, sizeof(alumno), 1, ap);
    }
}
