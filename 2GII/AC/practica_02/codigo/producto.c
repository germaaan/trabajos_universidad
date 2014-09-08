#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {

    if (argc < 2) {
        fprintf(stderr, "\n[ERROR] - Debe introducir introducir dimension. \n");
        exit(-1);
    }

    int i, k, N = atoi(argv[1]), VR[N], M[N][N], V[N];

    if (N > 4094) {
        fprintf(stderr, "\n[ERROR] - El tamaño maximo permitido para filas y columnas es 4094. \n");
        exit(-1);
    }

    printf("\nValores vector: ");
    for (i = 0; i < N; i++) {
        VR[i] = 0;
        V[i] = i + 2;
        printf("[%d]", V[i]);
    }

    printf("\n\nValores matriz:");
    for (i = 0; i < N; i++) {
        printf("\n");
        for (k = 0; k < N; k++) {
            M[i][k] = i + k + 1;
            printf("[%d]", M[i][k]);
        }
    }

    printf("\n\nCalculando producto...");
    for (i = 0; i < N; i++) {
        printf("\n%d: ", i);

        for (k = 0; k < N; k++) {
            VR[i] += M[i][k] * V[k];
            printf("->[%d]", VR[i]);
        }
    }

    printf("\n\nValor primera componente resultado: %d", VR[0]);
    printf("\nValor ultima componente resultado: %d", VR[N - 1]);

    printf("\n\n");
    return (0);
}
