#include <stdio.h>
#ifdef _OPENMP
#include <omp.h>
#endif

main() {
    int i, n = 7;
    int a[n];

    for (i = 0; i < n; i++)
        a[i] = i + 1;

#pragma omp parallel for shared(a) default(none) firstprivate(n)
    for (i = 0; i < n; i++) {
        a[i] += i;
        printf("Iteracion %d, Hebra %d, Valor de a[%d] = %d.\n", i, omp_get_thread_num(), i, a[i]);
    }

    printf("Después de parallel for:\n");

    for (i = 0; i < n; i++)
        printf("a[%d] = %d\n", i, a[i]);
}
