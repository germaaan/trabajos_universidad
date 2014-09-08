#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct s {
    int a;
    int b;
};

main() {
    struct s p[5000];

    clock_t cgt1, cgt2;
    double ncgt;

    int ii, i, X1, X2, R[40000];

    cgt1 = clock();

    printf("INICIO\n");

    for (ii = 1; ii <= 40000; ii++) {

        for (i = 0; i < 5000; i++)
            X1 = 2 * p[i].a + ii;

        for (i = 0; i < 5000; i++)
            X2 = 3 * p[i].b - ii;

        if (X1 < X2)
            R[ii] = X1;
        else
            R[ii] = X2;
    }

    printf("FIN\n");

    cgt2 = clock();
    ncgt = (double) (cgt2 - cgt1) / CLOCKS_PER_SEC;

    printf("\tTiempo:\t%8.6f\n", ncgt);
}
