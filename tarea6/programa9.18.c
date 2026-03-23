#include <stdio.h>

/* Prototipo */
void mezcla(FILE *ar, FILE *ar1, FILE *ar2);

int main(void)
{
    FILE *ar, *ar1, *ar2;

    ar  = fopen("arc9.dat", "r");
    ar1 = fopen("arc10.dat", "r");
    ar2 = fopen("arc11.dat", "w");

    if ((ar != NULL) && (ar1 != NULL) && (ar2 != NULL))
    {
        mezcla(ar, ar1, ar2);

        fclose(ar);
        fclose(ar1);
        fclose(ar2);
    }
    else
    {
        printf("No se pueden abrir los archivos");
    }

    return 0;
}

/* Función de mezcla */
void mezcla(FILE *ar, FILE *ar1, FILE *ar2)
{
    int mat, mat1;
    float ca[3], ca1[3];
    int i;

    /* Leer primer registro de ambos archivos */
    int ok  = fscanf(ar, "%d %f %f %f", &mat, &ca[0], &ca[1], &ca[2]);
    int ok1 = fscanf(ar1,"%d %f %f %f", &mat1,&ca1[0],&ca1[1],&ca1[2]);

    while (ok == 4 && ok1 == 4)
    {
        if (mat < mat1)
        {
            fprintf(ar2, "%d\t%f\t%f\t%f\n", mat, ca[0], ca[1], ca[2]);
            ok = fscanf(ar, "%d %f %f %f", &mat, &ca[0], &ca[1], &ca[2]);
        }
        else
        {
            fprintf(ar2, "%d\t%f\t%f\t%f\n", mat1, ca1[0], ca1[1], ca1[2]);
            ok1 = fscanf(ar1, "%d %f %f %f", &mat1, &ca1[0], &ca1[1], &ca1[2]);
        }
    }

    /* Copiar lo que queda del primer archivo */
    while (ok == 4)
    {
        fprintf(ar2, "%d\t%f\t%f\t%f\n", mat, ca[0], ca[1], ca[2]);
        ok = fscanf(ar, "%d %f %f %f", &mat, &ca[0], &ca[1], &ca[2]);
    }

    /* Copiar lo que queda del segundo archivo */
    while (ok1 == 4)
    {
        fprintf(ar2, "%d\t%f\t%f\t%f\n", mat1, ca1[0], ca1[1], ca1[2]);
        ok1 = fscanf(ar1, "%d %f %f %f", &mat1, &ca1[0], &ca1[1], &ca1[2]);
    }
}
