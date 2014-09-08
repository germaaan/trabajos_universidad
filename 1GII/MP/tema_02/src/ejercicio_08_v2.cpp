// Considere el problema 6. Resuelva el problema almacenando los elementos en un vector dinamico que ahora va
// duplicando su tamaño cuando no haya espacio para almacernar un nuevo valor. Reservar inicialmente 10 casillas.


#include <iostream>
#include "vector.h"
using namespace std;

int main() {
    vector miVector;
    int valor;

    do {
        cout << "\nIntroduzca un valor double para almacenarlo en el vector (introduzca un numero negativo para salir): ";
        cin >> valor;

        if (valor >= 0) {
            miVector.push_back_7(valor);

            if (miVector.size() == miVector.capacity()) {
                cout << "\nVector dinanico completo. Doblando los bloques de memoria disponibles.";
                miVector.ampliar((miVector.size())*2);
            }
        }

    } while (valor >= 0);

    cout << "\nValores almacenados en el vector: " << endl;
    miVector.print();

    return (0);
}
