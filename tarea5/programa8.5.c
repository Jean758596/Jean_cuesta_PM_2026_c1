#include <stdio.h>
#include <string.h>

union datos
{
    char celular[15];
    char correo[20];
};

typedef struct
{
    int matricula;
    char nombre[20];
    char carrera[20];
    float promedio;
    union datos personales;
} alumno;

void Lectura(alumno *a);

int main(void)
{
    alumno a1 = {120, "Maria", "Contabilidad", 8.9, "5-158-40-50"};
    alumno a2, a3;

    // ===== ALUMNO 2 =====
    printf("Alumno 2\n");

    printf("Ingrese la matricula: ");
    scanf("%d", &a2.matricula);
    getchar();

    printf("Ingrese el nombre: ");
    fgets(a2.nombre, 20, stdin);
    a2.nombre[strcspn(a2.nombre, "\n")] = '\0';

    printf("Ingrese la carrera: ");
    fgets(a2.carrera, 20, stdin);
    a2.carrera[strcspn(a2.carrera, "\n")] = '\0';

    printf("Ingrese el promedio: ");
    scanf("%f", &a2.promedio);
    getchar();

    printf("Ingrese el correo: ");
    fgets(a2.personales.correo, 20, stdin);
    a2.personales.correo[strcspn(a2.personales.correo, "\n")] = '\0';

    // ===== ALUMNO 3 =====
    printf("\nAlumno 3\n");
    Lectura(&a3);

    // ===== IMPRESION =====
    printf("\nDatos del alumno 1\n");
    printf("%d\n", a1.matricula);
    puts(a1.nombre);
    puts(a1.carrera);
    printf("%.2f\n", a1.promedio);
    puts(a1.personales.celular);
    puts(a1.personales.correo); // basura

    printf("\nDatos del alumno 2\n");
    printf("%d\n", a2.matricula);
    puts(a2.nombre);
    puts(a2.carrera);
    printf("%.2f\n", a2.promedio);
    puts(a2.personales.celular); // basura
    puts(a2.personales.correo);

    printf("\nIngrese el telefono celular del alumno 2: ");
    fgets(a2.personales.celular, 15, stdin);
    a2.personales.celular[strcspn(a2.personales.celular, "\n")] = '\0';

    puts(a2.personales.celular);
    puts(a2.personales.correo); // ahora basura

    printf("\nDatos del alumno 3\n");
    printf("%d\n", a3.matricula);
    puts(a3.nombre);
    puts(a3.carrera);
    printf("%.2f\n", a3.promedio);
    puts(a3.personales.celular);
    puts(a3.personales.correo); // basura

    return 0;
}

void Lectura(alumno *a)
{
    printf("\nIngrese la matricula: ");
    scanf("%d", &a->matricula);
    getchar();

    printf("Ingrese el nombre: ");
    fgets(a->nombre, 20, stdin);
    a->nombre[strcspn(a->nombre, "\n")] = '\0';

    printf("Ingrese la carrera: ");
    fgets(a->carrera, 20, stdin);
    a->carrera[strcspn(a->carrera, "\n")] = '\0';

    printf("Ingrese el promedio: ");
    scanf("%f", &a->promedio);
    getchar();

    printf("Ingrese el telefono celular: ");
    fgets(a->personales.celular, 15, stdin);
    a->personales.celular[strcspn(a->personales.celular, "\n")] = '\0';
}
