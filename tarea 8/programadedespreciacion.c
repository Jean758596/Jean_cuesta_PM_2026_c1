#include <stdio.h>
#include <stdlib.h>

/* Función para generar tabla */
void generarTabla(float inicial, float final, int meses, const char *archivo)
{
    FILE *f = fopen(archivo, "w");

    float depreciacion = (inicial - final) / meses;
    float valor = inicial;

    fprintf(f, "Mes\tValor Inicial\tDepreciacion\tValor Final\n");

    for (int i = 1; i <= meses; i++)
    {
        float valor_inicial = valor;
        valor -= depreciacion;

        fprintf(f, "%d\t%.2f\t\t%.2f\t\t%.2f\n",
                i, valor_inicial, depreciacion, valor);
    }

    fclose(f);
}

/* Opción 1 */
void modo1()
{
    float inicial, final;
    int meses;

    printf("Valor inicial: ");
    scanf("%f", &inicial);

    printf("Valor final: ");
    scanf("%f", &final);

    printf("Tiempo (meses): ");
    scanf("%d", &meses);

    generarTabla(inicial, final, meses, "tabla1.txt");
}

/* Opción 2 */
void modo2()
{
    float inicial;
    int meses;

    printf("Valor inicial: ");
    scanf("%f", &inicial);

    printf("Tiempo (meses): ");
    scanf("%d", &meses);

    float final = 0; // depreciación total

    generarTabla(inicial, final, meses, "tabla2.txt");
}

int main()
{
    int opcion;

    printf("1. Con valor final\n");
    printf("2. Solo valor inicial\n");
    printf("Seleccione: ");
    scanf("%d", &opcion);

    if (opcion == 1)
        modo1();
    else if (opcion == 2)
        modo2();
    else
        printf("Opcion invalida\n");

    printf("Tabla generada en archivo.\n");

    return 0;
}
