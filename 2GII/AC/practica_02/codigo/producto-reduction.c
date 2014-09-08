#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {

    if (argc < 2) {
        fprintf(stderr, "\n[ERROR] - Debe introducir introducir dimension. \n");
        exit(-1);
    }

    int i, k, N = atoi(argv[1]), VR[N], M[N][N], V[N], producto = 0;

    if (N > 4094) {
        fprintf(stderr, "\n[ERROR] - El tamaño maximo permitido para filas y columnas es 4094. \n");
        exit(-1);
    }

    printf("\nInicializando vector...");
#pragma omp parallel for
    for (i = 0; i < N; i++) {
        printf("\nHebra %d: VR[%d], V[%d]", omp_get_thread_num(), i, i);
        VR[i] = 0;
        V[i] = i + 2;
    }

    printf("\n\nValores vector: ");
    for (i = 0; i < N; i++) printf("[%d]", V[i]);


    printf("\n\nInicializando matriz...");
#pragma omp parallel for
    for (i = 0; i < N; i++) {
        printf("\nHebra %d, fila %d: ", omp_get_thread_num(), i);

        for (k = 0; k < N; k++) {
            M[i][k] = i + k + 1;
            printf("[%d]", M[i][k]);
        }
    }

    printf("\n\nCalculando producto...");
#pragma omp parallel for reduction(+:producto)
    for (i = 0; i < N; i++) {
        producto = 0;
        printf("\nHebra %d calcula componente %d: ", omp_get_thread_num(), i);

        for (k = 0; k < N; k++) {
            producto += M[i][k] * V[k];
            printf("->[%d]", producto);
        }

        VR[i] = producto;
    }

    printf("\n\nValor primera componente resultado: %d", VR[0]);
    printf("\nValor ultima componente resultado: %d", VR[N - 1]);

    printf("\n\n");

    return (0);
}
