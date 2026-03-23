#include <stdio.h>
#include <string.h>

/* Hospital.
El programa genera información acerca de los pacientes de un hospital. */

typedef struct
{
    char cal[20];   /* Calle */
    int num;
    char col[20];
    char cp[10];
    char ciu[20];
} domicilio;

typedef struct
{
    char nom[50];
    int edad;
    char sexo;
    int con;
    domicilio dom;
    char tel[15];
} paciente;

/* Prototipos */
void Lectura(paciente *, int);
void F1(paciente *, int);
void F2(paciente *, int);
void F3(paciente *, int);

int main(void)
{
    paciente HOSPITAL[100];
    int TAM;

    do
    {
        printf("Ingrese el número de pacientes: ");
        scanf("%d", &TAM);
    }
    while(TAM > 100 || TAM < 1);

    Lectura(HOSPITAL, TAM);
    F1(HOSPITAL, TAM);
    F2(HOSPITAL, TAM);
    F3(HOSPITAL, TAM);

    return 0;
}

void Lectura(paciente A[], int T)
{
    int I;

    for (I = 0; I < T; I++)
    {
        printf("\n\t\tPaciente %d\n", I + 1);

        printf("Nombre: ");
        scanf(" %[^\n]", A[I].nom);

        printf("Edad: ");
        scanf("%d", &A[I].edad);

        printf("Sexo (F/M): ");
        scanf(" %c", &A[I].sexo);

        printf("Condición (1..5): ");
        scanf("%d", &A[I].con);

        printf("\tCalle: ");
        scanf(" %[^\n]", A[I].dom.cal);

        printf("\tNúmero: ");
        scanf("%d", &A[I].dom.num);

        printf("\tColonia: ");
        scanf(" %[^\n]", A[I].dom.col);

        printf("\tCódigo Postal: ");
        scanf(" %[^\n]", A[I].dom.cp);

        printf("\tCiudad: ");
        scanf(" %[^\n]", A[I].dom.ciu);

        printf("Teléfono: ");
        scanf(" %[^\n]", A[I].tel);
    }
}

void F1(paciente A[], int T)
{
    int I, FEM = 0, MAS = 0, TOT;

    for (I = 0; I < T; I++)
    {
        switch(A[I].sexo)
        {
            case 'F': FEM++; break;
            case 'M': MAS++; break;
        }
    }

    TOT = FEM + MAS;

    printf("\nPorcentaje de Hombres: %.2f%%", (float)MAS / TOT * 100);
    printf("\nPorcentaje de Mujeres: %.2f%%", (float)FEM / TOT * 100);
}

void F2(paciente A[], int T)
{
    int I, C1 = 0, C2 = 0, C3 = 0, C4 = 0, C5 = 0;

    for (I = 0; I < T; I++)
    {
        switch(A[I].con)
        {
            case 1: C1++; break;
            case 2: C2++; break;
            case 3: C3++; break;
            case 4: C4++; break;
            case 5: C5++; break;
        }
    }

    printf("\nNúmero pacientes en condición 1: %d", C1);
    printf("\nNúmero pacientes en condición 2: %d", C2);
    printf("\nNúmero pacientes en condición 3: %d", C3);
    printf("\nNúmero pacientes en condición 4: %d", C4);
    printf("\nNúmero pacientes en condición 5: %d", C5);
}

void F3(paciente A[], int T)
{
    int I;

    printf("\nPacientes en estado grave (condición 5):");

    for (I = 0; I < T; I++)
    {
        if (A[I].con == 5)
        {
            printf("\nNombre: %s\tTeléfono: %s", A[I].nom, A[I].tel);
        }
    }
}
