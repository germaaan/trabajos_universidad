#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv) {

    if (argc < 2) {
        fprintf(stderr, "\n[ERROR] - Debe introducir introducir dimension. \n");
        exit(-1);
    }

    int i, k, j, N = atoi(argv[1]), A[N][N], B[N][N], C[N][N];

    if (N > 4094) {
        fprintf(stderr, "\n[ERROR] - El tamaño maximo permitido para filas y columnas es 4094. \n");
        exit(-1);
    }

    printf("\nInicializando matriz resultado...");
    for (i = 0; i < N; i++)
        for (k = 0; k < N; k++)
            A[i][k] = 0;

    printf("\nValores matriz B:");
    for (i = 0; i < N; i++) {
        printf("\n");
        for (k = 0; k < N; k++) {
            B[i][k] = i + k + 1;
            printf("[%d]", B[i][k]);
        }
    }

    printf("\nValores matriz C:");
    for (i = 0; i < N; i++) {
        printf("\n");
        for (k = 0; k < N; k++) {
            C[i][k] = i + k + 2;
            printf("[%d]", C[i][k]);
        }
    }

    printf("\n\nCalculando multiplicación de matrices...");
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            for (k = 0; k < N; k++)
                A[i][j] += B[i][k] * C[k][j];

    printf("\n\nValor componente [0][0] del resultado: %d", A[0][0]);
    printf("\nValor componente [%d][%d] del resultado: %d", N - 1, N - 1, A[N - 1][N - 1]);

    printf("\n\n");
    return (0);
}
