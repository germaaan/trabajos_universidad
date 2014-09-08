#include "Lista.h"
#include <stdexcept>
#include <iostream>
#include <cstdlib>

using namespace std;

Lista::Lista() {
    try {
        this->inicio = new celda;
    } catch (runtime_error excepcion) {
        cout << "Error de memoria: " << excepcion.what();
    }

    this->inicio->siguiente = 0;
    this->_size = 0;
}

Lista::Lista(const unsigned int &n) {
    celda *q;

    try {
        this->inicio = new celda;
    } catch (runtime_error excepcion) {
        cout << "Error de memoria: " << excepcion.what();
    }

    q = this->inicio;
    q->siguiente = 0;

    for (int i = 1; i <= n; i++) {
        try {
            q->siguiente = new celda;
        } catch (runtime_error excepcion) {
            cout << "Error de memoria: " << excepcion.what();
        }

        q->siguiente->valor = 0;
        q->siguiente->siguiente = 0;

        q = q->siguiente;
    }

    this->_size = n;
}

Lista::Lista(const unsigned int &n, const TipoBase &x) {
    celda *q;

    try {
        this->inicio = new celda;
    } catch (runtime_error excepcion) {
        cout << "Error de memoria: " << excepcion.what();
    }

    q = this->inicio;
    q->siguiente = 0;

    for (int i = 1; i <= n; i++) {
        try {
            q->siguiente = new celda;
        } catch (runtime_error excepcion) {
            cout << "Error de memoria: " << excepcion.what();
        }

        q->siguiente->valor = x;
        q->siguiente->siguiente = 0;

        q = q->siguiente;
    }

    this->_size = n;
}

Lista::Lista(const Lista &otro) {
    this->Copia(otro);
}

Lista::~Lista() {
    this->LiberaMemoria();
}

bool Lista::estaVacia() {
    return this->inicio->siguiente == 0;
}

unsigned int Lista::size() {
    return this->_size;
}

void Lista::escribeLista() {
    celda *q = this->inicio;

    while (q->siguiente != 0) {
        cout << q->siguiente->valor << " ";

        q = q->siguiente;
    }

    cout << endl;
}

void Lista::Insertar(const TipoBase &val, const unsigned int &pos) {
    celda *q, *r;

    if (pos <= this->_size) {
        q = this->inicio;

        for (int i = 1; ((i <= pos) && (q->siguiente != 0)); i++)
            q = q->siguiente;

        try {
            r = new celda;
        } catch (runtime_error excepcion) {
            cout << "Error de memoria: " << excepcion.what();
        }

        r->valor = val;
        r->siguiente = q->siguiente;
        q->siguiente = r;

        this->_size++;
    }
}

void Lista::Borrar(const unsigned int &pos) {
    celda *q, *r;

    if ((pos > 0) && (pos <= this->_size)) {
        q = this->inicio;

        for (int i = 1; ((i <= pos) && (q->siguiente != 0)); i++) {
            r = q;

            q = q->siguiente;
        }

        r->siguiente = q->siguiente;

        delete q;

        this->_size--;
    }
}

TipoBase Lista::ObtenerValor(const unsigned int &pos) {
    celda *q = this->inicio;

    if ((pos > 0) && (pos < this->_size)) {
        for (int i = 1; ((i <= pos) && (q->siguiente != 0)); i++)
            q = q->siguiente;
    }

    return q->valor;
}

void Lista::PonerValor(const unsigned int &pos, const TipoBase &val) {
    celda *q;

    if ((pos > 0) && (pos <= this->_size)) {

        q = this->inicio;

        for (int i = 1; ((i <= pos) && (q->siguiente != 0)); i++)
            q = q->siguiente;

        q->valor = val;
    }
}

Lista& Lista::operator =(const Lista &otro) {
    if (this != &otro) {
        this->LiberaMemoria();
        this->Copia(otro);
    }

    return (*this);
}

TipoBase& Lista::operator [](const unsigned int &indice) {
    celda *q = this->inicio;

    if ((indice > 0) && (indice < this->_size)) {
        for (int i = 1; ((i <= indice) && (q->siguiente != 0)); i++)
            q = q->siguiente;
    }

    return q->valor;
}

ostream & operator <<(ostream &out, const Lista &l) {
    Lista::celda *q = l.inicio;

    while (q->siguiente != 0) {
        out << q->siguiente->valor << " ";

        q = q->siguiente;
    }

    return out;
}

istream & operator >>(istream &in, Lista &l) {
    TipoBase valor;
    int cont = l.size();

    do {
        in >> valor;

        if (valor != '*') {
            l.Insertar(valor, cont);

            cont++;
        }

    } while (valor != '*');

    return in;
}

void Lista::Copia(const Lista &otro) {
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

void Lista::LiberaMemoria() {
    celda *q, *r;

    q = this->inicio;

    while (q->siguiente != 0) {
        r = q->siguiente;

        delete q;

        q = r;
    }
}
