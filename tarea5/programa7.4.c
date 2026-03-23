#include <stdio.h>

int main(void)
{
    // Puntero a cadena (solo lectura)
    char *cad0;

    cad0 = "Argentina";
    puts(cad0);

    cad0 = "Brasil";
    puts(cad0);

    // ⚠️ Forma correcta para leer texto
    char cad1[20];  // Reservamos memoria
    printf("\nIngrese una cadena: ");
    fgets(cad1, sizeof(cad1), stdin);
    puts(cad1);

    // Arreglo de caracteres modificable
    char cad2[20] = "Mexico";
    puts(cad2);

    printf("\nIngrese otra cadena: ");
    fgets(cad2, sizeof(cad2), stdin);
    puts(cad2);

    return 0;
}
