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
void modifica(FILE *ap);

int main(void)
{
    FILE *ar;

    if ((ar = fopen("ad1.dat", "rb+")) != NULL)
    {
        modifica(ar);
        fclose(ar);
    }
    else
    {
        printf("\nEl archivo no se puede abrir");
    }

    return 0;
}

/* Función para modificar un registro */
void modifica(FILE *ap)
{
    int d;
    alumno alu;

    printf("\nIngrese el número de registro que desea modificar: ");
    scanf("%d", &d);

    /* Posicionarse en el registro (d-1) */
    fseek(ap, (d - 1) * sizeof(alumno), SEEK_SET);

    /* Leer registro */
    fread(&alu, sizeof(alumno), 1, ap);

    printf("\nAlumno encontrado:");
    printf("\nMatrícula: %d", alu.matricula);
    printf("\nNombre: %s", alu.nombre);
    printf("\nCarrera: %d", alu.carrera);
    printf("\nPromedio actual: %.2f\n", alu.promedio);

    /* Modificar promedio */
    printf("\nIngrese el nuevo promedio: ");
    scanf("%f", &alu.promedio);

    /* Volver a posicionarse */
    fseek(ap, (d - 1) * sizeof(alumno), SEEK_SET);

    /* Escribir el registro modificado */
    fwrite(&alu, sizeof(alumno), 1, ap);

    printf("\nRegistro actualizado correctamente.\n");
}
