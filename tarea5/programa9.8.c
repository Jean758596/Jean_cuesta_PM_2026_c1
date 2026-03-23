#include <stdio.h>

/* Alumnos.
El programa almacena variables de tipo estructura alumno en un archivo. */

typedef struct
{
    int matricula;
    char nombre[20];
    int carrera;
    float promedio;
} alumno;

/* Prototipo de función */
void escribe(FILE *ar);

int main(void)
{
    FILE *ar;

    if ((ar = fopen("alumnos.dat", "wb")) != NULL)
    {
        escribe(ar);
        fclose(ar);
    }
    else
    {
        printf("No se puede abrir el archivo");
    }

    return 0;
}

/* Función que escribe los datos en el archivo */
void escribe(FILE *ar)
{
    alumno a;
    int res;

    printf("¿Desea ingresar un alumno? Sí-1 No-0: ");
    scanf("%d", &res);

    while (res)
    {
        printf("\nMatrícula: ");
        scanf("%d", &a.matricula);

        printf("Nombre: ");
        scanf("%s", a.nombre);

        printf("Carrera: ");
        scanf("%d", &a.carrera);

        printf("Promedio: ");
        scanf("%f", &a.promedio);

        fwrite(&a, sizeof(alumno), 1, ar);

        printf("\n¿Desea ingresar otro alumno? Sí-1 No-0: ");
        scanf("%d", &res);
    }
}
