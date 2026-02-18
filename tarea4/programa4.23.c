#include <stdio.h>

void trueque(int *x, int *y)
{
    int tem;
    tem = *x;
    *x = *y;
    *y = tem;
}

int suma(int x)
{
    return (x + x);
}

int main(void)
{
    int a = 5;
    int b = 8;

    printf("\nAntes del trueque: a = %d, b = %d", a, b);

    trueque(&a, &b);

    printf("\nDespués del trueque: a = %d, b = %d", a, b);

    a = suma(a);

    printf("\nDespués de suma: a = %d, b = %d", a, b);

    return 0;
}
