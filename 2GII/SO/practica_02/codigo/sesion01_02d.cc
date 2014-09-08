#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/syscall.h>

using namespace std;

int i;
char c;

int imp_c(void *p) {
    int tid = syscall(SYS_gettid);

    cout << "\nProceso hijo 1 (PID: " << getpid() << ", TID: " << tid << ", PID Padre: " << getppid() << ")." << endl;

    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {

        for (int i = 0; i < 30; i++)
            cout << c << " ";
    } else {
        cout << "Error: se esperaba un carácter alfabético.";
    }

    cout << endl << flush;
    _exit(1);
}

int imp_i(void *p) {
    int *i = (int*) p;
    int tid = syscall(SYS_gettid);

    cout << "\nProceso hijo 2 (PID: " << getpid() << ", TID: " << tid << ", PID Padre: " << getppid() << ")." << endl;

    if (*i >= 0 && *i <= 9) {

        for (int j = 0; j < 30; j++)
            cout << *i << " ";
    } else {
        cout << "Error: se esperaba un valor numérico.";
    }

    cout << endl << flush;
    _exit(2);
}

int main(int argc, char **argv) {
    unsigned char pila[6144];
    int ejecucion1, ejecucion2;

    if (argc != 3) {
        cerr << "Error: Numero de parametros erroneo.\n";
        cerr << "Uso: " << argv[0] << " <caracter> <entero>\n";
        exit(1);
    }

    c = *argv[1];
    i = atoi(argv[2]);

    cout << "\nProceso padre (PID: " << getpid() << ")." << endl;

    ejecucion1 = clone(imp_c, (void **) pila + 2048, CLONE_VM | CLONE_FILES | CLONE_FS | CLONE_THREAD | CLONE_SIGHAND, NULL);
    ejecucion2 = clone(imp_i, (void **) pila + 4096, CLONE_VM | CLONE_FILES | CLONE_FS | CLONE_THREAD | CLONE_SIGHAND, NULL);

    return 0;
}
