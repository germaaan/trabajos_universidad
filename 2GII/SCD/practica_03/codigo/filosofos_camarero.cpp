#include "mpi.h"
#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

void Filosofo(int id, int nprocesos); // Codigo proc. Filosofo
void Tenedor(int id, int nprocesos); // Codigo proc. Tenedor
void Camarero(int id, int nprocesos); // Codigo proc. Camarero

int main(int argc, char** argv) {
    int rank, size;
    srand(time(0));

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (size != 11) {
        if (rank == 0)
            cout << "El numero de procesos debe ser 11." << endl << flush;

        MPI_Finalize();

        return 0;
    }

    if ((rank % 2) == 0) {
        if (rank == 10)
            Camarero(rank, size); // El proceso 10 es el Camarero

        Filosofo(rank, size); // Los pares son Filosofos
    } else Tenedor(rank, size); // Los impares son Tenedores

    //	cout << "Camarero" <<rank<<endl<<flush;
    //	Camarero(rank,size);

    MPI_Finalize();

    return 0;
}

void Filosofo(int id, int nprocesos) {
    int izq = (id - 1 + nprocesos) % nprocesos;
    int der = (id + 1) % nprocesos;

    while (1) {
        cout << "El filosofo " << id << " esta PENSANDO..." << endl << flush;
        sleep((rand() % 3) + 1);

        // Solicitar poder sentarse a la mesa
        MPI_Ssend(&id, 1, MPI_INT, 10, id, MPI_COMM_WORLD);
        cout << "El filosofo " << id << " se sienta a la mesa." << endl << flush;

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

        // Solicitar poder levantarse de la mesa
        cout << "El filosofo " << id << " se levanta de la mesa." << endl << flush;
        MPI_Ssend(&id, 1, MPI_INT, 10, id, MPI_COMM_WORLD);
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

void Camarero(int id, int nprocesos) {
    MPI_Status status;
    int max = 4, num = 0, buf, Filo, flag;

    while (1) {
        // Espera una peticion desde cualquier filosofo para sentarse o levantarse...
        MPI_Iprobe(MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &flag, &status);

        if (num < max) {
            // Recibe la peticion de filosofo...
            MPI_Recv(&buf, 1, MPI_INT, MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &status);
            Filo = status.MPI_SOURCE;
            cout << "El camarero recibe una peticion del filosofo " << Filo << "." << endl << flush;
            num++;

            // Espera a que el filosofo se levante...
            MPI_Recv(&buf, 1, MPI_INT, MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &status);
            cout << "El camarero le da permiso al filosofo " << Filo << " para levantarse de la mesa." << endl << flush;
            num--;
        } else {
            Filo = status.MPI_SOURCE;
            cout << "El filosofo " << Filo << " no puede sentarse a la mesa porque esta llena." << endl << flush;
        }
    }
}
