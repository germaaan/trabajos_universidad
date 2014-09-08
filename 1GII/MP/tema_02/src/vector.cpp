#include <iostream>
#include "vector.h"
using namespace std;

vector::vector() {
    _m = new double[10];
    _size = 0;
    _capacity = 10;
}

int vector::size() {
    return _size;
}

int vector::capacity() {
    return _capacity;
}

void vector::ampliar(int n) {
    double *aux;

    aux = new double[_capacity + n];

    _capacity = _capacity + n;

    for (int i = 0; i < _size; i++)
        aux[i] = _m[i];

    delete [] _m;

    _m = aux;
}

void vector::push_back(const double &x) {
    if (_size == _capacity)
        ampliar(10);

    _m[_size] = x;
    _size++;
}

void vector::push_back_7(const double &x) {
	_m[_size] = x;
	_size++;
}

void vector::print() {

    for (int i = 0; i < _size; i++)
        cout << _m[i] << " ";

    cout << endl;
}
