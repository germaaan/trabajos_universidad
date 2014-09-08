#include "mpi.h"
#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

void Filosofo(int id, int nprocesos); // Codigo proc. Filosofo
void Tenedor(int id, int nprocesos); // Codigo proc. Tenedor

int main(int argc, char** argv) {
    int rank, size;
    srand(time(0));

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (size != 10) {
        if (rank == 0)
            cout << "El numero de procesos debe ser 10." << endl << flush;

        MPI_Finalize();

        return 0;
    }

    if ((rank % 2) == 0)
        Filosofo(rank, size); // Los pares son Filosofos
    else Tenedor(rank, size); // Los impares son Tenedores

    MPI_Finalize();

    return 0;
}

void Filosofo(int id, int nprocesos) {
    int izq = (id - 1 + nprocesos) % nprocesos;
    int der = (id + 1) % nprocesos;

    while (1) {

        if (id == 0) {
            // Solicitar tenedor derecho
            MPI_Ssend(&id, 1, MPI_INT, der, id, MPI_COMM_WORLD);
            cout << "El filosofo " << id << " coge el tenedor de su derecha (" << der << ")." << endl << flush;

            // Solicitar tenedor izquierda
            MPI_Ssend(&id, 1, MPI_INT, izq, id, MPI_COMM_WORLD);
            cout << "El filosofo " << id << " coge el tenedor de su izquierda (" << izq << ")." << endl << flush;
        } else {
            // Solicitar tenedor izquierda
            MPI_Ssend(&id, 1, MPI_INT, izq, id, MPI_COMM_WORLD);
            cout << "El filosofo " << id << " coge el tenedor de su izquierda (" << izq << ")." << endl << flush;

            // Solicitar tenedor derecho
            MPI_Ssend(&id, 1, MPI_INT, der, id, MPI_COMM_WORLD);
            cout << "El filosofo " << id << " coge el tenedor de su derecha (" << der << ")." << endl << flush;
        }

        cout << "El filosofo " << id << " esta COMIENDO..." << endl << flush;
        sleep((rand() % 3) + 1);

        // Suelta el tenedor izquierda
        MPI_Ssend(&id, 1, MPI_INT, izq, id, MPI_COMM_WORLD);
        cout << "El filosofo " << id << " suelta el tenedor de su izquierda " << izq << "." << endl << flush;

        // Suelta el tenedor derecha
        MPI_Ssend(&id, 1, MPI_INT, der, id, MPI_COMM_WORLD);
        cout << "El filosofo " << id << " suelta el tenedor de su derecha " << der << "." << endl << flush;

        cout << "El filosofo " << id << " esta PENSANDO..." << endl << flush;
        sleep((rand() % 3) + 1);
    }
}

void Tenedor(int id, int nprocesos) {
    int buf;
    int Filo;
    int flag;
    MPI_Status status;

    while (1) {
        // Espera una peticion desde cualquier filosofo vecino...
        MPI_Iprobe(MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &flag, &status);

        // Recibe la peticion de filosofo...
        MPI_Recv(&buf, 1, MPI_INT, MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &status);
        Filo = status.MPI_SOURCE;
        cout << "El tenedor " << id << " recibe una peticion del filosofo " << Filo << "." << endl << flush;

        // Espera a que el filosofo suelte el tenedor...
        MPI_Recv(&buf, 1, MPI_INT, Filo, MPI_ANY_TAG, MPI_COMM_WORLD, &status);
        cout << "El tenedor " << id << " recibe la liberacion del filosofo " << Filo << "." << endl << flush;
    }
}
