#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv) {

    if (argc < 2) {
        fprintf(stderr, "\n[ERROR] - Debe introducir introducir dimension. \n");
        exit(-1);
    }

    int a = 5, N = atoi(argv[1]), x[N], y[N], i;

    struct timespec cgt1, cgt2;
    double ncgt;

    if (N <= 0) {
        fprintf(stderr, "\n[ERROR] - El tamaño tiene que ser un valor mayor que 0. \n");
        exit(-1);
    }

    for (i = 0; i < N; i++) {
        x[i] = i;
        y[i] = i * 3;
    }

    clock_gettime(CLOCK_REALTIME, &cgt1);

    printf("INICIO\n");

    for (i = 0; i < N; i++)
        y[i] = a * x[i] + y[i];

    printf("FIN\n");

    clock_gettime(CLOCK_REALTIME, &cgt2);
    ncgt = (double) (cgt2.tv_sec - cgt1.tv_sec) + (double) ((cgt2.tv_nsec - cgt1.tv_nsec) / (1.e+9));

    printf("\tTiempo:\t%8.6f\n", ncgt);

    return 0;
}
