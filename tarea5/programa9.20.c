#include <stdio.h>

/* Estructura materia-calificación */
typedef struct
{
    char materia[20];
    int calificacion;
} matcal;

/* Estructura alumno */
typedef struct
{
    int matricula;
    char nombre[20];
    matcal cal[5];
} alumno;

/* Prototipos */
void F1(FILE *ap);
void F2(FILE *ap);
float F3(FILE *ap);

int main(void)
{
    FILE *ap;
    float pro;

    if ((ap = fopen("esc.dat", "rb")) != NULL)
    {
        F1(ap);

        rewind(ap);
        F2(ap);

        rewind(ap);
        pro = F3(ap);

        printf("\n\nPROMEDIO GENERAL MATERIA 4: %.2f\n", pro);

        fclose(ap);
    }
    else
    {
        printf("\nEl archivo no se puede abrir");
    }

    return 0;
}

/* F1: matrícula y promedio por alumno */
void F1(FILE *ap)
{
    alumno alu;
    int j;
    float sum, pro;

    printf("\nMATRÍCULA y PROMEDIOS\n");

    while (fread(&alu, sizeof(alumno), 1, ap) == 1)
    {
        printf("\nMatrícula: %d", alu.matricula);

        sum = 0.0;
        for (j = 0; j < 5; j++)
            sum += alu.cal[j].calificacion;

        pro = sum / 5;
        printf("\tPromedio: %.2f", pro);
    }
}

/* F2: alumnos con nota > 9 en materia 3 */
void F2(FILE *ap)
{
    alumno alu;

    rewind(ap);

    printf("\n\nALUMNOS CON CALIFICACIÓN > 9 EN MATERIA 3\n");

    while (fread(&alu, sizeof(alumno), 1, ap) == 1)
    {
        if (alu.cal[2].calificacion > 9)
            printf("Matrícula del alumno: %d\n", alu.matricula);
    }
}

/* F3: promedio general de materia 4 */
float F3(FILE *ap)
{
    alumno alu;
    int i = 0;
    float sum = 0, pro;

    rewind(ap);

    while (fread(&alu, sizeof(alumno), 1, ap) == 1)
    {
        i++;
        sum += alu.cal[3].calificacion;
    }

    if (i != 0)
        pro = sum / i;
    else
        pro = 0;

    return pro;
}
