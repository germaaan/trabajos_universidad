#include "Pila.h"
#include <stdexcept>
#include <iostream>

using namespace std;

Pila::Pila() {
    try {
        this->inicio = new celda;
    } catch (runtime_error excepcion) {
        cout << "Error de memoria: " << excepcion.what();
    }

    this->inicio->siguiente = 0;
    this->_size = 0;
}

Pila::Pila(const Pila & otra) {
    this->Copia(otra);
}

Pila::~Pila() {
    this->LiberaMemoria();
}

bool Pila::estaVacia() {
    return this->inicio->siguiente == 0;
}

void Pila::push(const TipoBase &x) {
    celda *q;

    try {
        q = new celda;
    } catch (runtime_error excepcion) {
        cout << "Error de memoria: " << excepcion.what();
    }

    q->valor = x;
    q->siguiente = this->inicio->siguiente;
    this->inicio->siguiente = q;

    this->_size++;
}

TipoBase Pila::sacar() {
    TipoBase elemento;
    celda *q;

    q = this->inicio->siguiente;

    elemento = q->valor;

    this->inicio->siguiente = q->siguiente;

    delete q;

    this->_size--;

    return elemento;
}

TipoBase Pila::tope() {
    return this->inicio->siguiente->valor;
}

Pila& Pila::operator =(const Pila &otra) {
    if (this != &otra) {
        this->LiberaMemoria();
        this->Copia(otra);
    }

    return (*this);
}

ostream & operator <<(ostream &out, const Pila &otra) {
    Pila::celda *q = otra.inicio;

    while (q->siguiente != 0) {
        out << q->siguiente->valor << " ";

        q = q->siguiente;
    }

    return out;
}

void Pila::Copia(const Pila &otro) {
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

void Pila::LiberaMemoria() {
    celda *q, *r;

    q = this->inicio;

    while (q->siguiente != 0) {
        r = q->siguiente;

        delete q;

        q = r;
    }
}
