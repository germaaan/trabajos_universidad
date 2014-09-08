#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/syscall.h>

using namespace std;

int main(int argc, char **argv) {
    pid_t pid, pid1, pid2;
    int estado1, estado2, ejecucion1, ejecucion2;
    char c, i;

    if (argc != 3) {
        cerr << "Error: Numero de parametros erroneo.\n";
        cerr << "Uso: " << argv[0] << " <caracter> <entero>\n";
        exit(1);
    }

    c = *argv[1];
    i = *argv[2];

    switch (pid1 = fork()) {
        case (pid_t) - 1:
            perror("fork fallo");
            return -1;

        case (pid_t) 0:
            cout << "\nProceso hijo 1 (PID: " << getpid() << ", PID Padre: " << getppid() << ")." << endl;
            cout << "Imprimiendo carácter alfabético recibido..." << endl;
            ejecucion1 = execl("./imp_c", "imp_c", &c, 0);

            if (ejecucion1 == -1) {
                perror("execl fallo");
                return -1;
            } else
                _exit(1);

        default:
            pid = waitpid(pid1, &estado1, WUNTRACED);
    }

    switch (pid2 = fork()) {
        case (pid_t) - 1:
            perror("fork fallo");
            return -1;

        case (pid_t) 0:
            cout << "\nProceso hijo 2 (PID: " << getpid() << ", PID Padre: " << getppid() << ")." << endl;
            cout << "Imprimiendo valor numérico recibido..." << endl;
            ejecucion2 = execl("./imp_i", "imp_i", &i, 0);

            if (ejecucion2 == -1) {
                perror("execl fallo");
                return -1;
            } else
                _exit(2);

        default:
            pid = waitpid(pid2, &estado2, WUNTRACED);
    }

    cout << "\nProceso padre (PID: " << getpid() << ")." << endl;

    if (WIFEXITED(estado1))
        cerr << pid1 << " finalizó: " << WEXITSTATUS(estado1) << endl;
    else if (WIFSTOPPED(estado1))
        cerr << pid1 << " parado por " << WSTOPSIG(estado1) << endl;
    else if (WIFSIGNALED(estado1))
        cerr << pid1 << " matado por " << WTERMSIG(estado1) << endl;
    else perror("En waitpid");

    if (WIFEXITED(estado2))
        cerr << pid2 << " finalizó: " << WEXITSTATUS(estado2) << endl;
    else if (WIFSTOPPED(estado2))
        cerr << pid2 << " parado por " << WSTOPSIG(estado2) << endl;
    else if (WIFSIGNALED(estado2))
        cerr << pid2 << " matado por " << WTERMSIG(estado2) << endl;
    else perror("En waitpid");

    return 0;
}
