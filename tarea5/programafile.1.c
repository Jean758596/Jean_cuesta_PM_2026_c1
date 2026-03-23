#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Prototipos */
void crearArchivo(const char *nombre, int n);
int* leerArchivo(const char *nombre, int *n);
void ordenar(int *arr, int n);
void guardarArchivo(const char *nombre, int *arr, int n);

int main()
{
    int n = 10;  // cantidad de números
    int *numeros;

    /* 1. Crear archivo con números aleatorios */
    crearArchivo("numeros.txt", n);

    /* 2. Leer archivo con memoria dinámica */
    numeros = leerArchivo("numeros.txt", &n);

    /* 3. Ordenar */
    ordenar(numeros, n);

    /* 4. Guardar ordenados */
    guardarArchivo("ordenados.txt", numeros, n);

    /* Liberar memoria */
    free(numeros);

    printf("Proceso completado.\n");

    return 0;
}

/* 1. Crear archivo */
void crearArchivo(const char *nombre, int n)
{
    FILE *f = fopen(nombre, "w");
    int i;

    srand(time(NULL));

    for (i = 0; i < n; i++)
    {
        int num = rand() % 100; // números de 0 a 99
        fprintf(f, "%d\n", num);
    }

    fclose(f);
}

/* 2. Leer archivo con memoria dinámica */
int* leerArchivo(const char *nombre, int *n)
{
    FILE *f = fopen(nombre, "r");
    int *arr = NULL;
    int num, count = 0;

    /* Contar cuántos números hay */
    while (fscanf(f, "%d", &num) == 1)
        count++;

    rewind(f);

    /* Reservar memoria */
    arr = (int*)malloc(count * sizeof(int));

    /* Leer datos */
    for (int i = 0; i < count; i++)
        fscanf(f, "%d", &arr[i]);

    fclose(f);

    *n = count;
    return arr;
}

/* 3. Ordenar (burbuja) */
void ordenar(int *arr, int n)
{
    int i, j, temp;

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

/* 4. Guardar archivo ordenado */
void guardarArchivo(const char *nombre, int *arr, int n)
{
    FILE *f = fopen(nombre, "w");

    for (int i = 0; i < n; i++)
        fprintf(f, "%d\n", arr[i]);

    fclose(f);
}
