#include "Conjunto.h"
#include "VectorDinamico.h"
#include <stdexcept>
#include <iostream>

using namespace std;

Conjunto::Conjunto() {
    try {
        this->inicio = new celda;
    } catch (runtime_error excepcion) {
        cout << "Error de memoria: " << excepcion.what();
    }

    this->inicio->siguiente = 0;
    this->_size = 0;
}

Conjunto::Conjunto(const TipoBase &x) {
    try {
        this->inicio = new celda;
    } catch (runtime_error excepcion) {
        cout << "Error de memoria: " << excepcion.what();
    }

    try {
        this->inicio->siguiente = new celda;
    } catch (runtime_error excepcion) {
        cout << "Error de memoria: " << excepcion.what();
    }

    this->inicio->siguiente->valor = x;
    this->inicio->siguiente->siguiente = 0;

    this->_size = 1;
}

Conjunto::Conjunto(const Conjunto &origen) {
    celda *q, *r;

    this->_size = origen._size;

    q = origen.inicio->siguiente;

    try {
        this->inicio = new celda;
    } catch (runtime_error excepcion) {
        cout << "Error de memoria: " << excepcion.what();
    }

    r = inicio;

    while (q != 0) {
        try {
            r->siguiente = new celda;
        } catch (runtime_error excepcion) {
            cout << "Error de memoria: " << excepcion.what();
        }

        r->siguiente->valor = q->valor;
        r->siguiente->siguiente = 0;
        q = q->siguiente;
        r = r->siguiente;
    }
}

Conjunto::~Conjunto() {
    celda *q, *aux;

    q = this->inicio;

    while (q != 0) {
        aux = q->siguiente;

        delete q;

        q = aux;
    }
}

bool Conjunto::estaVacio() {
    return this->inicio->siguiente == 0;
}

Conjunto& Conjunto::operator =(const Conjunto &derecha) {
    celda *q, *aux;

    q = this->inicio->siguiente;

    while (q != 0) {
        aux = q->siguiente;
        delete q;
        q = aux;
    }

    this->inicio->siguiente = 0;
    this->_size = 0;

    q = derecha.inicio->siguiente;

    while (q != 0) {
        (*this).push(q->valor);
        q = q->siguiente;
    }

    return (*this);
}

int Conjunto::size() {
    return this->_size;
}

bool Conjunto::buscarElemento(const TipoBase &x) {
    bool encontrado = false;
    celda *q = this->inicio;

    while ((q->siguiente != 0) && !encontrado) {
        if (q->siguiente->valor == x)
            encontrado = true;

        q = q->siguiente;
    }

    return encontrado;
}

void Conjunto::push(const TipoBase &x) {
    celda *q, *r;

    q = inicio;

    while ((q->siguiente != 0) && (q->siguiente->valor < x))
        q = q->siguiente;

    try {
        r = new celda;
    } catch (runtime_error excepcion) {
        cout << "Error de memoria: " << excepcion.what();
    }

    r->valor = x;

    r->siguiente = q->siguiente;
    q->siguiente = r;

    this->_size++;
}

ostream & operator <<(ostream &out, const Conjunto &otro) {
    Conjunto::celda *q = otro.inicio;

    while (q->siguiente != 0) {
        out << q->siguiente->valor << " ";

        q = q->siguiente;
    }

    return out;
}

istream & operator >>(istream &in, Conjunto &otro) {
    TipoBase valor;

    do {
        in >> valor;

        if ((valor != '*') && (!otro.buscarElemento(valor)))
            otro.push(valor);

    } while (valor != '*');

    return in;
}

bool Conjunto::operator ==(const Conjunto &derecha) {
    celda *i, *d;

    i = this->inicio;
    d = derecha.inicio;

    if (this->_size == derecha._size) {
        while ((d->siguiente != 0) && (d->siguiente->valor == i->siguiente->valor)) {
            d = d->siguiente;
            i = i->siguiente;
        }
    } else
        return false;

    return (i->siguiente == 0);
}

bool Conjunto::operator !=(const Conjunto &otro) {
    return !((*this) == otro);
}

Conjunto operator +(const Conjunto &c1, const Conjunto &c2) {
    Conjunto salida(c1);

    Conjunto::celda *q;
    q = c2.inicio->siguiente;

    while (q != 0) {
        if (!(salida.buscarElemento(q->valor)))
            salida.push(q->valor);
        q = q->siguiente;
    }

    return salida;
}

Conjunto operator +(const Conjunto &c, const TipoBase &x) {
    return c + Conjunto(x);
}

Conjunto operator +(const TipoBase &x, const Conjunto &c) {
    return Conjunto(x) + c;
}

Conjunto operator -(const Conjunto &c1, Conjunto &c2) {
    Conjunto salida;

    Conjunto::celda *q;
    q = c1.inicio->siguiente;

    while (q != 0) {
        if (!(c2.buscarElemento(q->valor)))
            salida.push(q->valor);
        q = q->siguiente;
    }

    return salida;
}

Conjunto operator *(Conjunto &c1, Conjunto &c2) {
    Conjunto salida;

    Conjunto::celda *q;
    q = c1.inicio->siguiente;

    while (q != 0) {
        if ((c2.buscarElemento(q->valor)))
            salida.push(q->valor);
        q = q->siguiente;
    }

    return salida;
}
