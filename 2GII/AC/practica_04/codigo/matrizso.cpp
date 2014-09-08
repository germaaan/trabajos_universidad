#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv) {

    if (argc < 2) {
        fprintf(stderr, "\n[ERROR] - Debe introducir introducir dimension. \n");
        exit(-1);
    }

    int i, k, j, N = atoi(argv[1]), A[N][N], B[N][N], C[N][N], valorB = 1, valorC = 2;

    struct timespec cgt1, cgt2;
    double ncgt;

    if ((N <= 0) || (N > 4094)) {
        fprintf(stderr, "\n[ERROR] - El tamaño de filas y columnas tiene que ser un valor entre 1 y 4094. \n");
        exit(-1);
    }

    for (i = 0; i < N; i++)
        for (k = 0; k < N; k++)
            A[i][k] = 0;

    for (i = 0; i < N; i++)
        for (k = 0; k < N; k++)
            B[i][k] = valorB++;

    for (i = 0; i < N; i++)
        for (k = 0; k < N; k++)
            C[i][k] = valorC++;

    clock_gettime(CLOCK_REALTIME, &cgt1);

    printf("INICIO\n");

    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            for (k = 0; k < N; k++)
                A[i][j] += B[i][k] * C[k][j];

    printf("FIN\n");

    clock_gettime(CLOCK_REALTIME, &cgt2);
    ncgt = (double) (cgt2.tv_sec - cgt1.tv_sec) + (double) ((cgt2.tv_nsec - cgt1.tv_nsec) / (1.e+9));

    printf("\tTiempo:\t%8.6f\n", ncgt);

    return 0;
}
