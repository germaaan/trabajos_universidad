// Deseamos guardar un numero indefinido de valores double y procesarlos (exactamente como en el problema 4).
// 
// Resuelva el problema almacenando los elementos en un vector dinamico que va creciendo de uno en uno cuando
// no haya espacio para almacernar un nuevo valor. Reservar inicialmente 10 casillas.


#include <iostream>
#include "vector.h"
using namespace std;

int main() {
    vector miVector;
    int valor, ampliacion;

    do {
        cout << "\nIntroduzca un valor double para almacenarlo en el vector (introduzca un numero negativo para salir): ";
        cin >> valor;

        if (valor >= 0)
            miVector.push_back(valor);

    } while (valor >= 0);

    cout << "\nValores almacenados en el vector: " << endl;
    miVector.print();

    return (0);
}
