// Deseamos guardar un numero indefinido de valores double y procesarlos (exactamente como en el problema 4).
// 
// Resuelva el problema almacenando los elementos en un vector dinamico que va creciendo de uno en uno cuando
// no haya espacio para almacernar un nuevo valor. Reservar inicialmente 10 casillas.


#include <iostream>
#include "celda.h"

using namespace std;

void leeCeldas(celdasEnlazadas * c) {
    TipoBase valor;
    cout << "Introducir un valor (para finalizar, introducir un negativo): ";
    cin >> valor;
    while (valor >= 0) {
        push_back(c, valor);
        cout << "Introducir un valor (para finalizar, introducir un negativo): ";
        cin >> valor;
    }
}

void pintarCeldas(const celdasEnlazadas *c) {
    for (int i = 0; i < size(c); i++)
        cout << at(c, i) << " ";
    cout << endl;
}

int main(void) {

    celdasEnlazadas X;
    X = inicializar();
    leeCeldas(&X);
    pintarCeldas(&X);
    liberar(&X);
}
