ma#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Crear matriz dinámica */
int** crearMatriz(int filas, int cols)
{
    int **m = (int**)malloc(filas * sizeof(int*));
    for (int i = 0; i < filas; i++)
        m[i] = (int*)malloc(cols * sizeof(int));
    return m;
}

/* Liberar memoria */
void liberarMatriz(int **m, int filas)
{
    for (int i = 0; i < filas; i++)
        free(m[i]);
    free(m);
}

/* Mostrar matriz */
void mostrar(int **m, int filas, int cols)
{
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < cols; j++)
            printf("%d ", m[i][j]);
        printf("\n");
    }
}

/* Leer desde teclado */
void leerTeclado(int **m, int filas, int cols)
{
    for (int i = 0; i < filas; i++)
        for (int j = 0; j < cols; j++)
        {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &m[i][j]);
        }
}

/* Leer matriz desde archivo CSV */
int** leerArchivo(const char *nombre, int *filas, int *cols)
{
    FILE *f = fopen(nombre, "r");
    char linea[200];
    int **m = NULL;

    int fcount = 0, ccount = 0;

    while (fgets(linea, sizeof(linea), f))
    {
        fcount++;
        if (fcount == 1)
        {
            char *token = strtok(linea, ",");
            while (token)
            {
                ccount++;
                token = strtok(NULL, ",");
            }
        }
    }

    rewind(f);

    m = crearMatriz(fcount, ccount);

    int i = 0;
    while (fgets(linea, sizeof(linea), f))
    {
        char *token = strtok(linea, ",");
        int j = 0;
        while (token)
        {
            m[i][j] = atoi(token);
            token = strtok(NULL, ",");
            j++;
        }
        i++;
    }

    fclose(f);

    *filas = fcount;
    *cols = ccount;

    return m;
}

/* Suma */
int** suma(int **a, int **b, int f, int c)
{
    int **r = crearMatriz(f, c);

    for (int i = 0; i < f; i++)
        for (int j = 0; j < c; j++)
            r[i][j] = a[i][j] + b[i][j];

    return r;
}

/* Resta */
int** resta(int **a, int **b, int f, int c)
{
    int **r = crearMatriz(f, c);

    for (int i = 0; i < f; i++)
        for (int j = 0; j < c; j++)
            r[i][j] = a[i][j] - b[i][j];

    return r;
}

/* Multiplicación */
int** multiplicar(int **a, int **b, int f1, int c1, int c2)
{
    int **r = crearMatriz(f1, c2);

    for (int i = 0; i < f1; i++)
        for (int j = 0; j < c2; j++)
        {
            r[i][j] = 0;
            for (int k = 0; k < c1; k++)
                r[i][j] += a[i][k] * b[k][j];
        }

    return r;
}

int main()
{
    int **A, **B, **R;
    int f1, c1, f2, c2;
    int opcion;

    printf("1. Ingresar matrices por teclado\n");
    printf("2. Leer matrices desde archivo\n");
    scanf("%d", &opcion);

    if (opcion == 1)
    {
        printf("Filas y columnas de A: ");
        scanf("%d %d", &f1, &c1);

        printf("Filas y columnas de B: ");
        scanf("%d %d", &f2, &c2);

        A = crearMatriz(f1, c1);
        B = crearMatriz(f2, c2);

        printf("Matriz A:\n");
        leerTeclado(A, f1, c1);

        printf("Matriz B:\n");
        leerTeclado(B, f2, c2);
    }
    else
    {
        A = leerArchivo("A.txt", &f1, &c1);
        B = leerArchivo("B.txt", &f2, &c2);
    }

    printf("\n1. Suma\n2. Resta\n3. Multiplicacion\n");
    scanf("%d", &opcion);

    if (opcion == 1 && f1 == f2 && c1 == c2)
        R = suma(A, B, f1, c1);
    else if (opcion == 2 && f1 == f2 && c1 == c2)
        R = resta(A, B, f1, c1);
    else if (opcion == 3 && c1 == f2)
        R = multiplicar(A, B, f1, c1, c2);
    else
    {
        printf("Dimensiones incompatibles\n");
        return 0;
    }

    printf("\nResultado:\n");
    mostrar(R, f1, (opcion == 3) ? c2 : c1);

    liberarMatriz(A, f1);
    liberarMatriz(B, f2);
    liberarMatriz(R, f1);

    return 0;
}
