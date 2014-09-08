#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

using namespace std;

void abortar(int) {
}

int main(int argc, char** argv) {
    struct sigaction accion;

    accion.sa_handler = abortar;
    accion.sa_flags = 0;
    sigemptyset(&accion.sa_mask);

    if (sigaction(SIGABRT, &accion, 0) == -1) {
        perror("Sigaction");
    }

    (void) abort();

    return 0;
}
