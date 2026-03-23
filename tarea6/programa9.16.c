#include <stdio.h>
#include <stdlib.h>

/* Prototipo */
void sumypro(FILE *ap1);

int main(void)
{
    FILE *ap;

    if ((ap = fopen("arc2.txt", "r")) != NULL)
    {
        sumypro(ap);
        fclose(ap);
    }
    else
    {
        printf("No se puede abrir el archivo");
    }

    return 0;
}

/* Función */
void sumypro(FILE *ap1)
{
    char cad[30];
    int i = 0;
    float sum = 0.0, r;

    while (fgets(cad, sizeof(cad), ap1) != NULL)
    {
        r = atof(cad);  // convierte cadena a número

        if (r != 0.0)   // solo si realmente hay número válido
        {
            i++;
            sum += r;
        }
    }

    printf("\nSuma: %.2f", sum);

    if (i != 0)
        printf("\nPromedio: %.2f", sum / i);
}
