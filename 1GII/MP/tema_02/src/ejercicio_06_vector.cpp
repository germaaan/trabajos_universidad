// Deseamos guardar un numero indefinido de valores double y procesarlos (exactamente como en el problema 4).
// 
// Resuelva el problema almacenando los elementos en un vector dinamico que va creciendo de uno en uno cuando
// no haya espacio para almacernar un nuevo valor. Reservar inicialmente 10 casillas.


#include <iostream>
#include "vector_v2.h"

using namespace std;

void leeVector(vector * v) {

    TipoBase valor;

    cout << "Introducir un valor (para finalizar, introducir un negativo): ";
    cin >> valor;
    while (valor >= 0) {
        push_back(v, valor);
        cout << "Introducir un valor (para finalizar, introducir un negativo): ";
        cin >> valor;
    }
}

void pintarVector(const vector *v) {
    for (int i = 0; i < size(v); i++)
        cout << at(v, i) << " ";
    cout << endl;
}

int main(void) {
    vector X;
    //cout << "Esta en " << &X << endl;

    //X = inicializar(3);
    //cout << X.datos << endl;
    reservar(&X, 3);
    //cout << X.datos << endl;
    leeVector(&X);
    pintarVector(&X);
    liberar(&X);
}
