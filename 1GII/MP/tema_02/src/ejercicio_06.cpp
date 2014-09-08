// Deseamos guardar un numero indefinido de valores double y procesarlos (exactamente como en el problema 4).
// 
// Resuelva el problema almacenando los elementos en un vector dinamico que va creciendo de uno en uno cuando
// no haya espacio para almacernar un nuevo valor. Reservar inicialmente 10 casillas.


#include <iostream>
#include <stdexcept>
using namespace std;

double* AumentarMemoriaReservada(double *vectorPequenio, int tamanio) {
    double *vectorGrande;

    try {
        vectorGrande = new double[tamanio + 1];
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
    int contador = 0;

    try {
        vector = new double[10];
    } catch (runtime_error excepcion) {
        cout << "Error de memoria: " << excepcion.what();
    }

    while (valor >= 0) {

        if (contador >= 10) {
            vector = AumentarMemoriaReservada(vector, contador);
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
