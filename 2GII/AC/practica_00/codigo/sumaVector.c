/*
 * sumaVector.c
 *
 *	Created on: 05/03/2012
 *		Author: German Martinez Maldonado
 */


#include <stdio.h>

int main() {
    int vector_a[32] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19,
        20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32};

    int vector_b[32] = {32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16,
        15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    int i = 0;
    int resultado = 0;

    while (i < 32) {
        resultado += vector_a[i] + vector_b[i];
        i++;
    }

    printf("El resultado de sumar los dos vectores es: %d", resultado);

    return (0);
}
