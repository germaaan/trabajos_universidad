#include <iostream>
#include <stdlib.h>
#include "vector_v2.h"

using namespace std;

vector inicializar(int n) {
    vector salida;
    if (n == 0) salida.datos = 0;
    else {
        salida.datos = new TipoBase [ n];
        if (salida.datos == 0) {
            cout << "Error de Memoria" << endl;
            exit(1);
        }
    }
    salida._capacity = n;
    salida._size = 0;
    return salida;
}

int size(const vector *v) {
    return v->_size;
}

int capacity(const vector *v) {
    return v->_capacity;
}

void realojar(vector *v, int n) {
    TipoBase * aux;
    if (n <= v->_capacity) return;

    aux = new TipoBase [ n];
    if (aux == 0) {
        cout << "Error de Memoria" << endl;
        exit(1);
    }
    for (int i = 0; i < v->_size; i++)
        aux[i] = v->datos[i];
    delete [] v->datos;
    v->datos = aux;
    v->_capacity = n;
}

void push_back(vector *v, TipoBase x) {
    if (v->_size == v->_capacity)
        realojar(v, v->_capacity + 10);
    v->datos[v->_size] = x;
    v->_size++;
}

TipoBase at(const vector *v, int i) {
    if (i < v->_size)
        return v->datos[i];
}

void liberar(vector *v) {
    delete [] v->datos;
    v->_capacity = v->_size = 0;
}

void reservar(vector *v, int n) {
    (*v).datos = new TipoBase[n];
    (*v)._size = 0;
    (*v)._capacity = 0;
}
