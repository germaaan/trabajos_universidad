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

    if ((N < 4) || (N > 4094)) {
        fprintf(stderr, "\n[ERROR] - El tamaño de filas y columnas tiene que ser un valor entre 4 y 4094. \n");
        exit(-1);
    }

    for (i = 0; i < N; i++) {
        for (k = 0; k < N; k += 4) {
            A[i][k] = 0;
            A[i][k + 1] = 0;
            A[i][k + 2] = 0;
            A[i][k + 3] = 0;
        }
    }

    for (i = 0; i < N; i++) {
        for (k = 0; k < N; k += 4) {
            B[i][k] = valorB++;
            B[i][k + 1] = valorB++;
            B[i][k + 2] = valorB++;
            B[i][k + 3] = valorB++;
        }
    }

    for (i = 0; i < N; i++) {
        for (k = 0; k < N; k += 4) {
            C[i][k] = valorC++;
            C[i][k + 1] = valorC++;
            C[i][k + 2] = valorC++;
            C[i][k + 3] = valorC++;
        }
    }

    clock_gettime(CLOCK_REALTIME, &cgt1);

    printf("INICIO\n");

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            for (k = 0; k < N; k += 4) {
                A[i][j] += B[i][k] * C[k][j];
                A[i][j] += B[i][k + 1] * C[k + 1][j];
                A[i][j] += B[i][k + 2] * C[k + 2][j];
                A[i][j] += B[i][k + 3] * C[k + 3][j];
            }
        }
    }

    printf("FIN\n");

    clock_gettime(CLOCK_REALTIME, &cgt2);
    ncgt = (double) (cgt2.tv_sec - cgt1.tv_sec) + (double) ((cgt2.tv_nsec - cgt1.tv_nsec) / (1.e+9));

    printf("\tTiempo:\t%8.6f\n", ncgt);
}
