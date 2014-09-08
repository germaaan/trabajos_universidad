// Deseamos guardar un numero indefinido de valores double y procesarlos (exactamente como en el problema 4).
// 
// Resuelva el problema almacenando los elementos en un vector dinamico que va creciendo de uno en uno cuando
// no haya espacio para almacernar un nuevo valor. Reservar inicialmente 10 casillas.


#include <iostream>
#include "vector_v3.h"

using namespace std;

void leeVector(vector * v) {

    TipoBase valor;

    cout << "Introducir un valor (para finalizar, introducir un negativo): ";
    cin >> valor;
    while (valor >= 0) {
        (*v).push_back(valor);
        cout << "Introducir un valor (para finalizar, introducir un negativo): ";
        cin >> valor;
    }
}

void pintarVector(vector *v) {
    for (int i = 0; i < (*v).size(); i++)
        cout << (*v).at(i) << " ";
    cout << endl;
}

int main(void) {

    vector X(3);
    leeVector(&X);
    pintarVector(&X);
    X.liberar();
}
