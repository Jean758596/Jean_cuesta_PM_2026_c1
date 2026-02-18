#include <stdio.h>

/* Apuntadores y arreglos */
int main(void) {
    int V1[4] = {1, 3, 5, 7};
    int V2[4] = {2, 4, 0, 0}; // inicializar todo el arreglo
    int *AX, *AY;

    AX = &V1[2];  // AX apunta a V1[2] = 5
    AY = &V2[2];  // AY apunta a V2[2] = 0

    V2[2] = *(AX+1); // V2[2] = V1[3] = 7
    V2[3] = *AX;     // V2[3] = V1[2] = 5
    AX = AX + 1;     // AX apunta a V1[3] = 7
    V1[0] = *AX;     // V1[0] = 7

    printf("\nV1[0]=%d V1[1]=%d V1[2]=%d V1[3]=%d \tV2[0]=%d V2[1]=%d V2[2]=%d V2[3]=%d\n",
           V1[0], V1[1], V1[2], V1[3], V2[0], V2[1], V2[2], V2[3]);

    V1[2] = *AY;     // V1[2] = V2[2] = 7
    V1[1] = --*AY;   // V2[2] = 6, V1[1] = 6
    AX = AX + 1;     // AX apunta fuera del arreglo → peligro, lo eliminamos
    V1[3] = *(&V1[3]); // simplemente asignamos V1[3] = 7 (sin moverse AX)

    printf("\nV1[0]=%d V1[1]=%d V1[2]=%d V1[3]=%d \tV2[0]=%d V2[1]=%d V2[2]=%d V2[3]=%d\n",
           V1[0], V1[1], V1[2], V1[3], V2[0], V2[1], V2[2], V2[3]);

    return 0;
}
