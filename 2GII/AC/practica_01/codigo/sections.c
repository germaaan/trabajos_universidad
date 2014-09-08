#include <stdio.h>
#include <omp.h>

void funcA() {
    printf("En funcA: esta sectión la ejecuta el thread %d\n",
            omp_get_thread_num());
}

void funcB() {
    printf("En funcB: esta sectión la ejecuta el thread %d\n",
            omp_get_thread_num());
}

main() {

#pragma omp parallel
    {
#pragma omp sections
        {
#pragma omp section
            {
                sleep(3);
                (void) funcA();
            }
#pragma omp section 
            {
                sleep(3);
                (void) funcB();
            }
        }
    }
}
