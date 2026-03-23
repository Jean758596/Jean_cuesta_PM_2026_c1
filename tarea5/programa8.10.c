#include <stdio.h>
#include <string.h>

/* Vendedores */

typedef struct
{
    char noba[20];   /* Nombre del banco */
    char nucu[20];   /* Número de cuenta */
} banco;

typedef union
{
    banco che;
    banco nomi;
    char venta;
} fpago;

typedef struct
{
    char cnu[50];
    char col[30];
    char cp[10];
    char ciu[30];
} domicilio;

typedef struct
{
    int num;
    char nom[50];
    float ven[12];
    domicilio domi;
    float sal;
    fpago pago;
    int cla;
} vendedor;

/* Prototipos */
void Lectura(vendedor *, int);
void F1(vendedor *, int);
void F2(vendedor *, int);
void F3(vendedor *, int);
void F4(vendedor *, int);

int main(void)
{
    vendedor VENDEDORES[100];
    int TAM;

    do
    {
        printf("Ingrese el número de vendedores: ");
        scanf("%d", &TAM);
    }
    while(TAM > 100 || TAM < 1);

    Lectura(VENDEDORES, TAM);
    F1(VENDEDORES, TAM);
    F2(VENDEDORES, TAM);
    F3(VENDEDORES, TAM);
    F4(VENDEDORES, TAM);

    printf("\n\tFIN DEL PROGRAMA");

    return 0;
}

void Lectura(vendedor A[], int T)
{
    int I, J;

    for (I = 0; I < T; I++)
    {
        printf("\n\tIngrese datos del vendedor %d\n", I + 1);

        printf("Número de vendedor: ");
        scanf("%d", &A[I].num);

        printf("Nombre del vendedor: ");
        scanf(" %[^\n]", A[I].nom);

        printf("Ventas del año:\n");
        for (J = 0; J < 12; J++)
        {
            printf("\tMes %d: ", J + 1);
            scanf("%f", &A[I].ven[J]);
        }

        printf("Domicilio del vendedor:\n");

        printf("\tCalle y número: ");
        scanf(" %[^\n]", A[I].domi.cnu);

        printf("\tColonia: ");
        scanf(" %[^\n]", A[I].domi.col);

        printf("\tCódigo Postal: ");
        scanf(" %[^\n]", A[I].domi.cp);

        printf("\tCiudad: ");
        scanf(" %[^\n]", A[I].domi.ciu);

        printf("Salario del vendedor: ");
        scanf("%f", &A[I].sal);

        printf("Forma de pago (1=Banco, 2=Nómina, 3=Ventanilla): ");
        scanf("%d", &A[I].cla);

        switch(A[I].cla)
        {
            case 1:
                printf("\tNombre del banco: ");
                scanf(" %[^\n]", A[I].pago.che.noba);

                printf("\tNúmero de cuenta: ");
                scanf(" %[^\n]", A[I].pago.che.nucu);
                break;

            case 2:
                printf("\tNombre del banco: ");
                scanf(" %[^\n]", A[I].pago.nomi.noba);

                printf("\tNúmero de cuenta: ");
                scanf(" %[^\n]", A[I].pago.nomi.nucu);
                break;

            case 3:
                A[I].pago.venta = 'S';
                break;
        }
    }
}

void F1(vendedor A[], int T)
{
    int I, J;
    float SUM;

    printf("\n\t\tVentas Totales de los Vendedores");

    for (I = 0; I < T; I++)
    {
        SUM = 0.0;

        for (J = 0; J < 12; J++)
            SUM += A[I].ven[J];

        printf("\nVendedor: %d", A[I].num);
        printf("\nVentas: %.2f\n", SUM);
    }
}

void F2(vendedor A[], int T)
{
    int I, J;
    float SUM;

    printf("\n\t\tIncremento a vendedores con ventas > 1,500,000");

    for (I = 0; I < T; I++)
    {
        SUM = 0.0;

        for (J = 0; J < 12; J++)
            SUM += A[I].ven[J];

        if (SUM > 1500000.0)
        {
            A[I].sal *= 1.05;

            printf("\nNúmero: %d\nVentas: %.2f\nNuevo salario: %.2f",
                   A[I].num, SUM, A[I].sal);
        }
    }
}

void F3(vendedor A[], int T)
{
    int I, J;
    float SUM;

    printf("\n\t\tVendedores con ventas < 300,000");

    for (I = 0; I < T; I++)
    {
        SUM = 0.0;

        for (J = 0; J < 12; J++)
            SUM += A[I].ven[J];

        if (SUM < 300000.0)
        {
            printf("\nNúmero: %d\nNombre: %s\nVentas: %.2f",
                   A[I].num, A[I].nom, SUM);
        }
    }
}

void F4(vendedor A[], int T)
{
    int I;

    printf("\n\t\tVendedores con cuenta bancaria");

    for (I = 0; I < T; I++)
    {
        if (A[I].cla == 1)
        {
            printf("\nNúmero: %d\nBanco: %s\nCuenta: %s",
                   A[I].num,
                   A[I].pago.che.noba,
                   A[I].pago.che.nucu);
        }
    }
}
