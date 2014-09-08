#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
using namespace std;

void manejador(int sig_num) {
    cout << "Atrapada la señal: " << sig_num << endl;
}

int main(int argc, char* argv[]) {
    sigset_t sigmask;
    struct sigaction accion, vieja_accion;
    sigemptyset(&sigmask);

    /* inicializamos la máscara */
    if (sigaddset(&sigmask, SIGTERM) == -1 || sigprocmask(SIG_SETMASK, &sigmask, 0) == -1)
        perror("Al establecer la máscara");

    sigemptyset(&accion.sa_mask);
    sigaddset(&accion.sa_mask, SIGSEGV);

    if (sigismember(&sigmask, SIGINT)) {
        accion.sa_handler = manejador;
        accion.sa_flags = SA_NODEFER | SA_RESETHAND;
        if (sigaction(SIGINT, &accion, &vieja_accion) == -1)
            perror("Sigaction");
    }

    pause();

    return 0;
}

