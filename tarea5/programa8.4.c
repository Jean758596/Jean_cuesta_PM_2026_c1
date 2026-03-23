#include <stdio.h>
#include <string.h>

typedef struct
{
    int matricula;
    char nombre[30];
    float cal[5];
} alumno;

void Lectura(alumno A[], int T);
void F1(alumno A[], int T);
void F2(alumno A[], int T);
void F3(alumno A[], int T);

int main(void)
{
    alumno ARRE[50];
    int TAM;

    do
    {
        printf("Ingrese el tamaño del arreglo: ");
        scanf("%d", &TAM);
    } while (TAM > 50 || TAM < 1);

    Lectura(ARRE, TAM);
    F1(ARRE, TAM);
    F2(ARRE, TAM);
    F3(ARRE, TAM);

    return 0;
}

void Lectura(alumno A[], int T)
{
    int i, j;

    for (i = 0; i < T; i++)
    {
        printf("\nAlumno %d\n", i + 1);

        printf("Matricula: ");
        scanf("%d", &A[i].matricula);
        getchar();

        printf("Nombre: ");
        fgets(A[i].nombre, 30, stdin);
        A[i].nombre[strcspn(A[i].nombre, "\n")] = '\0';

        for (j = 0; j < 5; j++)
        {
            printf("Calificacion %d: ", j + 1);
            scanf("%f", &A[i].cal[j]);
        }
    }
}

void F1(alumno A[], int T)
/* Promedio de cada alumno */
{
    int i, j;
    float suma;

    printf("\n--- Promedio por alumno ---\n");

    for (i = 0; i < T; i++)
    {
        suma = 0;

        for (j = 0; j < 5; j++)
            suma += A[i].cal[j];

        printf("%s -> Promedio: %.2f\n", A[i].nombre, suma / 5);
    }
}

void F2(alumno A[], int T)
/* Promedio general del grupo */
{
    int i, j;
    float suma = 0;

    for (i = 0; i < T; i++)
        for (j = 0; j < 5; j++)
            suma += A[i].cal[j];

    printf("\nPromedio general del grupo: %.2f\n", suma / (T * 5));
}

void F3(alumno A[], int T)
/* Alumno con mejor promedio */
{
    int i, j, pos = 0;
    float suma, mejor = 0, prom;

    for (i = 0; i < T; i++)
    {
        suma = 0;

        for (j = 0; j < 5; j++)
            suma += A[i].cal[j];

        prom = suma / 5;

        if (i == 0 || prom > mejor)
        {
            mejor = prom;
            pos = i;
        }
    }

    printf("\nMejor alumno: %s (%.2f)\n", A[pos].nombre, mejor);
}
