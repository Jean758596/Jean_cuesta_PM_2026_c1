#include <stdio.h>

/* Estructura alumno */
typedef struct
{
    int clave;
    char nombre[20];
    int carrera;
    float promedio;
    float examen;
    char telefono[12];
} alumno;

/* Prototipos */
float F1(FILE *ap);
void F2(FILE *ap, FILE *c1, FILE *c2, FILE *c3, FILE *c4, FILE *c5);
void F3(FILE *c1, FILE *c2, FILE *c3, FILE *c4, FILE *c5);

int main(void)
{
    float pro;
    FILE *ap, *c1, *c2, *c3, *c4, *c5;

    ap = fopen("alu1.dat", "rb");

    c1 = fopen("car1.dat", "wb+");
    c2 = fopen("car2.dat", "wb+");
    c3 = fopen("car3.dat", "wb+");
    c4 = fopen("car4.dat", "wb+");
    c5 = fopen("car5.dat", "wb+");

    if ((ap != NULL) && (c1 != NULL) && (c2 != NULL) &&
        (c3 != NULL) && (c4 != NULL) && (c5 != NULL))
    {
        pro = F1(ap);
        printf("\nPROMEDIO EXAMEN DE ADMISION: %.2f", pro);

        F2(ap, c1, c2, c3, c4, c5);
        F3(c1, c2, c3, c4, c5);

        fclose(ap);
        fclose(c1);
        fclose(c2);
        fclose(c3);
        fclose(c4);
        fclose(c5);
    }
    else
    {
        printf("\nEl o los archivos no se pudieron abrir");
    }

    return 0;
}

/* F1: promedio del examen */
float F1(FILE *ap)
{
    alumno alu;
    float sum = 0;
    int i = 0;

    rewind(ap);

    while (fread(&alu, sizeof(alumno), 1, ap) == 1)
    {
        i++;
        sum += alu.examen;
    }

    if (i != 0)
        return sum / i;
    else
        return 0;
}

/* F2: separar alumnos admitidos por carrera */
void F2(FILE *ap, FILE *c1, FILE *c2, FILE *c3, FILE *c4, FILE *c5)
{
    alumno alu;

    rewind(ap);

    while (fread(&alu, sizeof(alumno), 1, ap) == 1)
    {
        /* Condición de admisión */
        if ((alu.examen >= 1300 && alu.promedio >= 8) ||
            (alu.examen >= 1400 && alu.promedio >= 7))
        {
            switch (alu.carrera)
            {
                case 1: fwrite(&alu, sizeof(alumno), 1, c1); break;
                case 2: fwrite(&alu, sizeof(alumno), 1, c2); break;
                case 3: fwrite(&alu, sizeof(alumno), 1, c3); break;
                case 4: fwrite(&alu, sizeof(alumno), 1, c4); break;
                case 5: fwrite(&alu, sizeof(alumno), 1, c5); break;
            }
        }
    }
}

/* F3: promedio por carrera */
void F3(FILE *c1, FILE *c2, FILE *c3, FILE *c4, FILE *c5)
{
    alumno alu;
    float cal[5] = {0};
    float sum;
    int i;

    FILE *archivos[5] = {c1, c2, c3, c4, c5};

    for (int k = 0; k < 5; k++)
    {
        rewind(archivos[k]);

        sum = 0;
        i = 0;

        while (fread(&alu, sizeof(alumno), 1, archivos[k]) == 1)
        {
            i++;
            sum += alu.examen;
        }

        if (i != 0)
            cal[k] = sum / i;
        else
            cal[k] = 0;
    }

    /* Mostrar resultados */
    for (i = 0; i < 5; i++)
    {
        printf("\nPromedio carrera %d: %.2f", i + 1, cal[i]);
    }
}
