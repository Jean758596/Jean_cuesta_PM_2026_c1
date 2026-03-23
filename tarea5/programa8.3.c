#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char calle[20];
    int numero;
    int cp;
    char localidad[20];
} domicilio;

struct empleado
{
    char nombre[20];
    char departamento[20];
    float sueldo;
    domicilio direccion;
};

void Lectura(struct empleado *a);

int main(void)
{
    struct empleado e0 = {"Arturo", "Compras", 15500.75,
                          {"San Jeronimo", 120, 3490, "Toluca"}};

    struct empleado *e1, *e2, e3, e4;

    // Reserva de memoria
    e1 = (struct empleado *)malloc(sizeof(struct empleado));

    printf("\nIngrese el nombre del empleado 1: ");
    fgets(e1->nombre, 20, stdin);
    e1->nombre[strcspn(e1->nombre, "\n")] = '\0';

    printf("Ingrese el departamento: ");
    fgets(e1->departamento, 20, stdin);
    e1->departamento[strcspn(e1->departamento, "\n")] = '\0';

    printf("Ingrese el sueldo: ");
    scanf("%f", &e1->sueldo);
    getchar();

    printf("---- Direccion ----\n");

    printf("Calle: ");
    fgets(e1->direccion.calle, 20, stdin);
    e1->direccion.calle[strcspn(e1->direccion.calle, "\n")] = '\0';

    printf("Numero: ");
    scanf("%d", &e1->direccion.numero);

    printf("CP: ");
    scanf("%d", &e1->direccion.cp);
    getchar();

    printf("Localidad: ");
    fgets(e1->direccion.localidad, 20, stdin);
    e1->direccion.localidad[strcspn(e1->direccion.localidad, "\n")] = '\0';

    // ===== EMPLEADO 3 =====
    printf("\nIngrese el nombre del empleado 3: ");
    fgets(e3.nombre, 20, stdin);
    e3.nombre[strcspn(e3.nombre, "\n")] = '\0';

    printf("Ingrese el departamento: ");
    fgets(e3.departamento, 20, stdin);
    e3.departamento[strcspn(e3.departamento, "\n")] = '\0';

    printf("Ingrese el sueldo: ");
    scanf("%f", &e3.sueldo);
    getchar();

    printf("---- Direccion ----\n");

    printf("Calle: ");
    fgets(e3.direccion.calle, 20, stdin);
    e3.direccion.calle[strcspn(e3.direccion.calle, "\n")] = '\0';

    printf("Numero: ");
    scanf("%d", &e3.direccion.numero);

    printf("CP: ");
    scanf("%d", &e3.direccion.cp);
    getchar();

    printf("Localidad: ");
    fgets(e3.direccion.localidad, 20, stdin);
    e3.direccion.localidad[strcspn(e3.direccion.localidad, "\n")] = '\0';

    // ===== USO DE FUNCION =====
    e2 = (struct empleado *)malloc(sizeof(struct empleado));
    Lectura(e2);
    Lectura(&e4);

    // ===== IMPRESION =====
    printf("\nDatos del empleado 1\n");
    printf("%s\t%s\t%.2f\t%s\t%d\t%d\t%s\n",
           e1->nombre, e1->departamento, e1->sueldo,
           e1->direccion.calle, e1->direccion.numero,
           e1->direccion.cp, e1->direccion.localidad);

    printf("\nDatos del empleado 4\n");
    printf("%s\t%s\t%.2f\t%s\t%d\t%d\t%s\n",
           e4.nombre, e4.departamento, e4.sueldo,
           e4.direccion.calle, e4.direccion.numero,
           e4.direccion.cp, e4.direccion.localidad);

    free(e1);
    free(e2);

    return 0;
}

void Lectura(struct empleado *a)
{
    printf("\nIngrese el nombre: ");
    fgets(a->nombre, 20, stdin);
    a->nombre[strcspn(a->nombre, "\n")] = '\0';

    printf("Ingrese el departamento: ");
    fgets(a->departamento, 20, stdin);
    a->departamento[strcspn(a->departamento, "\n")] = '\0';

    printf("Ingrese el sueldo: ");
    scanf("%f", &a->sueldo);
    getchar();

    printf("---- Direccion ----\n");

    printf("Calle: ");
    fgets(a->direccion.calle, 20, stdin);
    a->direccion.calle[strcspn(a->direccion.calle, "\n")] = '\0';

    printf("Numero: ");
    scanf("%d", &a->direccion.numero);

    printf("CP: ");
    scanf("%d", &a->direccion.cp);
    getchar();

    printf("Localidad: ");
    fgets(a->direccion.localidad, 20, stdin);
    a->direccion.localidad[strcspn(a->direccion.localidad, "\n")] = '\0';
}
