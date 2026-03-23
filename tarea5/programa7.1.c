#include<stdio.h>

/* funciones para el manejo de caracteres de ;a biblioteca stdio.h*/
void main(void)
{
char p1, p2, p3 = '$';
\* delcaracion de las variables tipo caracter p1, p2 y p3. observa que a p3 se le asigna el simbolo $.*/
printf("\n ingrese un caracter:");
p1= getchar();          /* se utiliza para la funcion getchar para leer un caracter. */
putchar(p1);            \* se utiliza la funcion putchar para escribir un caracter. */
printf("\n");
fflush(stdin);
/ luego de ller un carater siempre es conveniente escribir la funcion fflush para limpiar el bufer, porque generalmente queda con basura y genera un error en la ejecucion del programa. el error se produce con basura y genera un error en la ejecucion del programa. el error se produce cuando se ingrea un dato se oprime el retunr y luego volvemos a leer un caracter o una cadena de caracteres se toma a ese retunr como el nuevo dato ingresado. */

printf("/n el caracter p3 es: ");
putchar(p3);

\* se utiliza la funcion putchar para escribir el caracter almacenado en p3. */
printf("/n*");

printf("/n ingrese otro carcter: ");
fflsh(stdin);
scanf("%c*, p2);

/* se puede utlizar scanf con el formato de variable %c para leer un caracter. */



















}
