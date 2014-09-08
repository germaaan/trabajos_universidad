#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct s {
    int a;
    int b;
    long int pad;
};

main() {
    struct s *p, *new_p;

    clock_t cgt1, cgt2;
    double ncgt;

    int ii, i, X1, X2, R[40000];

    p = (struct s*) malloc(sizeof (struct s) * 5000);
    new_p = (struct s*) (((long int) p + 63) & (-64));

    cgt1 = clock();

    printf("INICIO\n");

    for (ii = 1; ii <= 40000; ii++) {

        for (i = 0; i < 5000; i += 4) {
            X1 = 2 * p[i].a + ii;
            X1 = 2 * p[i + 1].a + ii;
            X1 = 2 * p[i + 2].a + ii;
            X1 = 2 * p[i + 3].a + ii;
            X2 = 3 * p[i].b - ii;
            X2 = 3 * p[i + 1].b - ii;
            X2 = 3 * p[i + 2].b - ii;
            X2 = 3 * p[i + 3].b - ii;
        }

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
