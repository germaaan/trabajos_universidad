#include "Cola.h"
#include <stdexcept>
#include <iostream>

using namespace std;

Cola::Cola() {
    try {
        this->inicio = new celda;
    } catch (runtime_error excepcion) {
        cout << "Error de memoria: " << excepcion.what();
    }

    this->inicio->siguiente = 0;
    this->_size = 0;
}

Cola::Cola(const Cola &otra) {
    this->Copia(otra);
}

Cola::~Cola() {
    this->LiberaMemoria();
}

bool Cola::estaVacia() {
    return this->inicio->siguiente == 0;
}

void Cola::push(const TipoBase &x) {
    celda *q = this->inicio;

    while (q->siguiente != 0)
        q = q->siguiente;

    try {
        q->siguiente = new celda;
    } catch (runtime_error excepcion) {
        cout << "Error de memoria: " << excepcion.what();
    }

    q->siguiente->valor = x;
    q->siguiente->siguiente = 0;

    this->_size++;
}

TipoBase Cola::sacar() {
    TipoBase elemento;
    celda *q;

    q = this->inicio->siguiente;

    elemento = q->valor;

    this->inicio->siguiente = q->siguiente;

    delete q;

    this->_size--;

    return elemento;
}

TipoBase Cola::cabecera() {
    return this->inicio->siguiente->valor;
}

Cola& Cola::operator =(const Cola &otro) {
    if (this != &otro) {
        this->LiberaMemoria();
        this->Copia(otro);
    }

    return (*this);
}

ostream & operator <<(ostream &out, const Cola &otra) {
    Cola::celda *q = otra.inicio;

    while (q->siguiente != 0) {
        out << q->siguiente->valor << " ";

        q = q->siguiente;
    }

    return out;
}

void Cola::Copia(const Cola &otro) {
    celda *q, *r;

    this->_size = otro._size;

    q = otro.inicio->siguiente;
    inicio = new celda;
    r = inicio;

    while (q != 0) {
        r->siguiente = new celda;
        r->siguiente->valor = q->valor;
        r->siguiente->siguiente = 0;
        q = q->siguiente;
        r = r->siguiente;
    }
}

void Cola::LiberaMemoria() {
    celda *q, *r;

    q = this->inicio;

    while (q->siguiente != 0) {
        r = q->siguiente;

        delete q;

        q = r;
    }
}
