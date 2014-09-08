#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <cstdlib>

using namespace std;

int main(int argc, char **argv) {
    int n;
    pid_t pid_hijo, pid_padre;

    if (argc != 2) {
        cerr << "Error: Numero de parametros erroneo.\n";
        cerr << "Uso: " << argv[0] << " <numeroProcesosHijo>\n";
        exit(1);
    }

    n = atoi(argv[1]);
    pid_padre = getpid();

    cout << "PID del padre: " << pid_padre << endl;

    pid_hijo = fork();

    for (int i = 0; i < n; i++) {

        switch (pid_hijo) {
            case (pid_t) - 1:
                perror("fork fallo"); /* fork ha fallado */
                break;

            case (pid_t) 0: /* en el hijo pid_hijo == */
                break;

            default:
                pid_padre = getpid();
                pid_hijo = fork();
        }
    }

    cout << "Hijo creado con PID: " << getpid() << ", PID del padre " << pid_padre << endl;

    return 0;
}
