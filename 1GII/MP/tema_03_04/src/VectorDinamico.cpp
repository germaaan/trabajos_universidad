#include "VectorDinamico.h"
#include "Conjunto.h"
#include <stdexcept>
#include <iostream>
#include <cstdlib>

using namespace std;

VectorDinamico::VectorDinamico() {
    this->PideMemoria(0);

    this->_size = 0;
    this->_capacity = 0;
}

VectorDinamico::VectorDinamico(const unsigned int &n) {
    this->PideMemoria(n);

    for (int i = 0; i < n; i++)
        this->datos[i] = 0;

    this->_size = n;
    this->_capacity = n;
}

VectorDinamico::VectorDinamico(const unsigned int &n, const int &valor) {
    this->PideMemoria(n);

    for (int i = 0; i < n; i++)
        this->datos[i] = valor;

    this->_size = n;
    this->_capacity = n;
}

VectorDinamico::VectorDinamico(const VectorDinamico &otro) {
    this->Copia(otro);
}

VectorDinamico::~VectorDinamico() {
    this->LiberaMemoria();
}

bool VectorDinamico::estaVacio() {
    return (this->_size == 0);
}

unsigned int VectorDinamico::size() {
    return this->_size;
}

unsigned int VectorDinamico::capacity() {
    return this->_capacity;
}

int VectorDinamico::at(const unsigned int &i) {
    if (i < this->_size) return this->datos[i];
}

void VectorDinamico::push(const int &valor) {
    if (this->_size == this->_capacity)
        this->redimensionar(this->_capacity + 1);

    this->datos[this->_size] = valor;

    this->_size++;
}

void VectorDinamico::escribirVector() {
    for (int i = 0; i < this->_size; i++)
        cout << this->datos[i] << " ";
}

VectorDinamico& VectorDinamico::operator =(const VectorDinamico &otro) {
    if (this != &otro) {
        this->LiberaMemoria();
        this->Copia(otro);
    }

    return (*this);
}

int& VectorDinamico::operator [](const unsigned int &indice) {
    if (indice > this->_size) {
        cerr << "Error: indice fuera del rango de casillas accesible." << endl;
        exit(1);
    }

    return this->datos[indice];
}

bool VectorDinamico::operator ==(const VectorDinamico &otro) {
    bool igual = false;

    if (this->_size == otro._size) {

        for (int i = 0; ((i < this->_size) || !igual); i++) {
            if (this->datos[0] == otro.datos[0])
                igual = true;
        }
    }

    return igual;
}

bool VectorDinamico::operator !=(const VectorDinamico &otro) {
    return !((*this) == otro);
}

bool VectorDinamico::operator>(const VectorDinamico &otro) {
    bool mayor = false;
    int tamanio;

    if (this->_size < otro._size)
        tamanio = this->_size;
    else
        tamanio = otro._size;

    for (int i = 0; ((i < tamanio) && !mayor); i++) {

        if (this->datos[0] > otro.datos[0])
            mayor = true;
    }

    return mayor;
}

bool VectorDinamico::operator<(const VectorDinamico &otro) {
    return !((*this) > otro);
}

bool VectorDinamico::operator >=(const VectorDinamico &otro) {
    bool mayorIgual = false;
    int tamanio;

    if (this->_size < otro._size)
        tamanio = this->_size;
    else
        tamanio = otro._size;

    for (int i = 0; ((i < tamanio) && !mayorIgual); i++) {
        if (this->datos[0] > otro.datos[0])
            mayorIgual = true;
    }

    return mayorIgual;
}

bool VectorDinamico::operator <=(const VectorDinamico &otro) {
    return !((*this) >= otro);
}

VectorDinamico VectorDinamico::operator +(const int &n) {
    VectorDinamico nuevo((*this));

    nuevo.redimensionar(nuevo._capacity + n);

    return nuevo;
}

VectorDinamico VectorDinamico::operator -(const int &n) {
    int tope;

    VectorDinamico nuevo(this->_capacity - n);

    if (this->_size < (this->_capacity - n))
        tope = this->_size;
    else
        tope = this->_capacity - n;

    for (int i = 0; i < tope; i++)
        nuevo.datos[i] = this->datos[i];

    return nuevo;
}

VectorDinamico VectorDinamico::operator +=(const int &n) {
    return (*this)+n;
}

VectorDinamico VectorDinamico::operator -=(const int &n) {
    return (*this)-n;
}

ostream & operator <<(ostream &out, const VectorDinamico &r) {
    for (int i = 0; i < r._size; i++)
        out << r.datos[i] << " ";

    return out;
}

istream & operator >>(istream &in, VectorDinamico &r) {
    int valor;

    do {
        in >> valor;

        if (valor != '*')
            r.push(valor);
    } while (valor != '*');

    return in;
}

void VectorDinamico::redimensionar(const unsigned int &n) {
    int *aux;

    try {
        aux = new int[n];
    } catch (runtime_error excepcion) {
        cout << "Error de memoria: " << excepcion.what() << endl;
    }

    for (int i = 0; i < this->_size; i++)
        aux[i] = this->datos[i];

    this->LiberaMemoria();

    this->datos = aux;
    this->_capacity = n;
}

void VectorDinamico::Copia(const VectorDinamico &otro) {
    this->_size = otro._size;
    this->_capacity = otro._capacity;

    this->PideMemoria(this->_capacity);

    for (int i = 0; i < this->_size; i++)
        this->datos[i] = otro.datos[i];
}

void VectorDinamico::PideMemoria(const unsigned int &n) {
    try {
        this->datos = new int[n];
    } catch (runtime_error excepcion) {
        cout << "Error de memoria: " << excepcion.what() << endl;
    }
}

void VectorDinamico::LiberaMemoria() {
    delete [] this->datos;
}
