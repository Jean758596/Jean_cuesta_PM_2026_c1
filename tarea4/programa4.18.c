#include <stdio.h>

/* Expresión.
El programa escribe los valores de T, P y Q que satisfacen
la expresión mientras el resultado sea menor que 5500.
*/

int Expresion(int, int, int);

int main(void)
{
    int EXP;
    int T = 0, P = 0, Q = 0;

    EXP = Expresion(T, P, Q);

    while (EXP < 5500)
    {
        while (EXP < 5500)
        {
            while (EXP < 5500)
            {
                printf("\nT: %d, P: %d, Q: %d, Resultado: %d", T, P, Q, EXP);

                Q++;
                EXP = Expresion(T, P, Q);
            }

            P++;
            Q = 0;
            EXP = Expresion(T, P, Q);
        }

        T++;
        P = 0;
        Q = 0;
        EXP = Expresion(T, P, Q);
    }

    return 0;
}

int Expresion(int T, int P, int Q)
{
    int RES;

    RES = 15 * (T*T*T*T)
        + 12 * (P*P*P*P*P)
        + 9  * (Q*Q*Q*Q*Q*Q);

    return RES;
}
