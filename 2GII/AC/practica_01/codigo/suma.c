#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(int argc, char **argv) {

    if (argc < 2) {
        fprintf(stderr, "\n[ERROR] - Falta tamaño vector. \n");
        exit(-1);
    }

    int i, N = atoi(argv[1]);

    if (N > 4094) {
        fprintf(stderr, "\n[ERROR] - El tamaño maximo permitido para el vector es 4094. \n");
        exit(-1);
    }

    int VR[N], V1[N], V2[N];

    for (i = 0; i < N; i++) {
        VR[i] = 0;
        V1[i] = i;
        V2[i] = i + 1;
    }

    for (i = 0; i < N; i++) {
        VR[i] = V1[i] + V2[i];

        if (i == 0) printf("\nValor primera componente resultado: %d", VR[i]);
        if (i == N - 1) printf("\nValor ultima componente resultado: %d", VR[i]);
    }

    printf("\n");
    return (0);
}
