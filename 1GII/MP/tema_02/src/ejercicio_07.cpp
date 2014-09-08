// Considere el problema 6. Resuelva el problema almacenando los elementos en un vector dinamico que ahora va
// creciendo en bloques de tamaño n cuando no haya espacio para almacernar un nuevo valor. Reservar inicialmente
// 10 casillas.


#include <iostream>
#include <stdexcept>
using namespace std;

double* AumentarMemoriaReservada(double *vectorPequenio, int tamanio, int aumento) {
    double *vectorGrande;

    try {
        vectorGrande = new double[tamanio + aumento];
    } catch (runtime_error excepcion) {
        cout << "Error de memoria: " << excepcion.what();
    }

    vectorGrande = vectorPequenio;

    return vectorGrande;
}

void MostrarValores(double *vector, int tamanio) {

    cout << "\nValores en el vector dinamico: ";

    for (int i = 0; i < tamanio; i++)
        cout << vector[i] << " ";
}

int main() {
    double *vector, valor = 0;
    int contador = 0, tamanio = 10, n = 0;

    try {
        vector = new double[tamanio];
    } catch (runtime_error excepcion) {
        cout << "Error de memoria: " << excepcion.what();
    }

    while (valor >= 0) {

        if (contador >= tamanio) {
            do {
                cout << "\nIntroduzca en cuantos bloques se va a aumentar el vector dinamico (tiene que ser positivo y mayor que 0): ";
                cin >> n;
            } while (n <= 0);

            vector = AumentarMemoriaReservada(vector, tamanio, n);
            tamanio = tamanio + n;
            n = 0;

            cout << endl;
        }

        cout << "Introduzca un valor double (introducir un valor negativo para finalizar): ";
        cin >> valor;

        if (valor >= 0)
            vector[contador] = valor;

        contador++;
    }

    MostrarValores(vector, contador - 1);

    delete [] vector;

    cout << "\n\n";

    return (0);
}
