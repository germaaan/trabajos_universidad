#include <iostream>
#include <stdlib.h>
#include "vector_v3.h"

using namespace std;

vector::vector(int n) {
    if (n == 0) _datos = 0;
    else {
        _datos = new TipoBase [n];
        if (_datos == 0) {
            cout << "Error de Memoria" << endl;
            exit(1);
        }
    }
    _capacity = n;
    _size = 0;

}

int vector::size() {
    return _size;
}

int vector::capacity() {
    return _capacity;
}

void vector::realojar(int n) {
    TipoBase * aux;
    if (n <= _capacity) return;

    aux = new TipoBase [ n];
    if (aux == 0) {
        cout << "Error de Memoria" << endl;
        exit(1);
    }
    for (int i = 0; i < _size; i++)
        aux[i] = _datos[i];
    delete [] _datos;
    _datos = aux;
    _capacity = n;
}

void vector::push_back(TipoBase x) {
    if (_size == _capacity)
        realojar(_capacity + 10);
    _datos[_size] = x;
    _size++;
}

TipoBase vector::at(int i) {
    if (i < _size)
        return _datos[i];
}

void vector::liberar() {
    delete [] _datos;
    _datos = 0;
    _capacity = _size = 0;
}
