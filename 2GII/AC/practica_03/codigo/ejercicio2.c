#include <stdio.h>
#include <stdlib.h>
#ifdef _OPENMP
#include <omp.h>
#else
#define omp_get_thread_num() 0
#endif

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

    omp_set_num_threads(4);
    omp_set_schedule(omp_sched_guided, 5);

    printf("\nInicializando matriz resultado (hebra en ejecución):\n");		
    for (i = 0; i < N; i++) {
#pragma omp parallel for lastprivate(k)
        for (k = 0; k < N; k++) {
            printf("%d ", omp_get_thread_num());
            A[i][k] = 0;
        }
        printf("\n");
    }

    printf("\nValores matriz A:\n");		
    for (i = 0; i < N; i++){
                    for (k = 0; k < N; k++){
                            printf("[%d]", A[i][k]);
                    }
                    printf("\n");
    }

    printf("\nAsignando valores de matriz B (hebra en ejecución):\n");		
    for (i = 0; i < N; i++) {
#pragma omp parallel for lastprivate(k)
        for (k = 0; k < N; k++) {
            printf("%d ", omp_get_thread_num());
            B[i][k] = i + k + 1;
        }
        printf("\n");
    }

    printf("\nValores matriz B:\n");		
    for (i = 0; i < N; i++){
                    for (k = 0; k < N; k++){
                            printf("[%d]", B[i][k]);
                    }
                    printf("\n");
    }

    printf("\nAsignando valores de matriz C (hebra en ejecución):\n");		
    for (i = 0; i < N; i++) {
#pragma omp parallel for lastprivate(k)
        for (k = 0; k < N; k++) {
            printf("%d ", omp_get_thread_num());
            C[i][k] = i + k + 2;
        }
        printf("\n");
    }

    printf("\nValores matriz C:\n");		
    for (i = 0; i < N; i++){
                    for (k = 0; k < N; k++){
                            printf("[%d]", C[i][k]);
                    }
                    printf("\n");
    }

    printf("\n\nCalculando multiplicación de matrices...");
    t = omp_get_wtime();
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
#pragma omp parallel for lastprivate(k)
            for (k = 0; k < N; k++) {
                A[i][j] += B[i][k] * C[k][j];
            }
        }
    }

    printf("\nValor componente [0][0] del resultado: %d", A[0][0]);
    printf("\nValor componente [%d][%d] del resultado: %d", N-1, N-1, A[N-1][N-1]);

    printf("\n\n");
    return (0);
}
