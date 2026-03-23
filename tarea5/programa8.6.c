#include <stdio.h>
#include <string.h>

typedef struct
{
    int clave;
    char nombre[15];
    float precio;
    int existencia;
} producto;

void Lectura(producto A[], int T);
void Ventas(producto A[], int T);
void Reabastecimiento(producto A[], int T);
void Nuevos_Productos(producto A[], int *T);
void Inventario(producto A[], int T);

int main(void)
{
    producto INV[100];
    int TAM, OPE;

    do
    {
        printf("Ingrese el numero de productos: ");
        scanf("%d", &TAM);
    } while (TAM > 100 || TAM < 1);

    Lectura(INV, TAM);

    printf("\nMenu:\n1-Ventas\n2-Reabastecimiento\n3-Nuevos Productos\n4-Inventario\n0-Salir\n");
    scanf("%d", &OPE);

    while (OPE)
    {
        switch (OPE)
        {
            case 1: Ventas(INV, TAM); break;
            case 2: Reabastecimiento(INV, TAM); break;
            case 3: Nuevos_Productos(INV, &TAM); break;
            case 4: Inventario(INV, TAM); break;
        }

        printf("\nMenu:\n1-Ventas\n2-Reabastecimiento\n3-Nuevos Productos\n4-Inventario\n0-Salir\n");
        scanf("%d", &OPE);
    }

    return 0;
}

void Lectura(producto A[], int T)
{
    int i;

    for (i = 0; i < T; i++)
    {
        printf("\nProducto %d\n", i + 1);

        printf("Clave: ");
        scanf("%d", &A[i].clave);
        getchar();

        printf("Nombre: ");
        fgets(A[i].nombre, 15, stdin);
        A[i].nombre[strcspn(A[i].nombre, "\n")] = '\0';

        printf("Precio: ");
        scanf("%f", &A[i].precio);

        printf("Existencia: ");
        scanf("%d", &A[i].existencia);
    }
}

void Ventas(producto A[], int T)
{
    int CLA, CAN, i, RES;
    float TOT = 0, PAR;

    printf("\nIngrese clave del producto (0 para salir): ");
    scanf("%d", &CLA);

    while (CLA)
    {
        printf("Cantidad: ");
        scanf("%d", &CAN);

        i = 0;
        while (i < T && A[i].clave != CLA)
            i++;

        if (i == T)
        {
            printf("Clave incorrecta\n");
        }
        else if (A[i].existencia >= CAN)
        {
            A[i].existencia -= CAN;
            PAR = A[i].precio * CAN;
            TOT += PAR;
        }
        else
        {
            printf("Stock insuficiente (%d disponibles)\n", A[i].existencia);
            printf("Desea comprarlos? 1-Si 0-No: ");
            scanf("%d", &RES);

            if (RES)
            {
                PAR = A[i].precio * A[i].existencia;
                TOT += PAR;
                A[i].existencia = 0;
            }
        }

        printf("\nIngrese otra clave (0 para salir): ");
        scanf("%d", &CLA);
    }

    printf("\nTotal de la venta: %.2f\n", TOT);
}

void Reabastecimiento(producto A[], int T)
{
    int CLA, CAN, i;

    printf("\nIngrese clave (0 para salir): ");
    scanf("%d", &CLA);

    while (CLA)
    {
        i = 0;
        while (i < T && A[i].clave != CLA)
            i++;

        if (i == T)
        {
            printf("Clave incorrecta\n");
        }
        else
        {
            printf("Cantidad: ");
            scanf("%d", &CAN);
            A[i].existencia += CAN;
        }

        printf("\nIngrese otra clave (0 para salir): ");
        scanf("%d", &CLA);
    }
}

void Nuevos_Productos(producto A[], int *T)
{
    int CLA, i, j;

    printf("\nIngrese clave (0 para salir): ");
    scanf("%d", &CLA);

    while (*T < 100 && CLA)
    {
        i = 0;
        while (i < *T && A[i].clave < CLA)
            i++;

        if (i < *T && A[i].clave == CLA)
        {
            printf("Producto ya existe\n");
        }
        else
        {
            for (j = *T; j > i; j--)
                A[j] = A[j - 1];

            A[i].clave = CLA;
            getchar();

            printf("Nombre: ");
            fgets(A[i].nombre, 15, stdin);
            A[i].nombre[strcspn(A[i].nombre, "\n")] = '\0';

            printf("Precio: ");
            scanf("%f", &A[i].precio);

            printf("Cantidad: ");
            scanf("%d", &A[i].existencia);

            (*T)++;
        }

        printf("\nIngrese otra clave (0 para salir): ");
        scanf("%d", &CLA);
    }

    if (*T == 100)
        printf("Inventario lleno\n");
}

void Inventario(producto A[], int T)
{
    int i;

    printf("\n--- INVENTARIO ---\n");

    for (i = 0; i < T; i++)
    {
        printf("\nClave: %d", A[i].clave);
        printf("\tNombre: %s", A[i].nombre);
        printf("\tPrecio: %.2f", A[i].precio);
        printf("\tExistencia: %d\n", A[i].existencia);
    }
}
