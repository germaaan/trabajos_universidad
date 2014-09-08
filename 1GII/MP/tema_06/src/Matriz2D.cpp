#include "Matriz2D.h"
#include <stdexcept>
#include <iostream>
#include <cstdlib>

using namespace std;

Matriz2D::Matriz2D() {
    this->PideMemoria(0, 0);

    this->filas = 0;
    this->columnas = 0;
}

Matriz2D::Matriz2D(const unsigned int &fils, const unsigned int &cols) {
    this->PideMemoria(fils, cols);

    for (int i = 0; i < fils; i++)
        for (int j = 0; j < cols; j++)
            this->datos[i][j] = 0;

    this->filas = fils;
    this->columnas = cols;
}

Matriz2D::Matriz2D(const unsigned int &fils, const unsigned int &cols, const unsigned int &val) {
    this->PideMemoria(fils, cols);

    for (int i = 0; i < fils; i++)
        for (int j = 0; j < cols; j++)
            this->datos[i][j] = val;

    this->filas = fils;
    this->columnas = cols;
}

Matriz2D::Matriz2D(const Matriz2D &otro) {
    this->Copia(otro);
}

Matriz2D::~Matriz2D() {
    this->LiberaMemoria();
}

bool Matriz2D::estaVacia() {
    bool estado = true;

    for (int i = 0; i < this->filas; i++)
        for (int j = 0; (j < this->columnas) && estado; j++)
            if (this->datos[i][j] >= 0)
                estado = false;

    return estado;
}

void Matriz2D::PonValor(const unsigned int &fil, const unsigned int &col, const unsigned int &val) {
    if ((fil < this->filas) && (col < this->columnas))
        this->datos[fil][col] = val;
}

int Matriz2D::LeeValor(const unsigned int &fil, const unsigned int &col) {
    if ((fil < this->filas) && (col < this->columnas))
        return this->datos[fil][col];
}

Matriz2D& Matriz2D::operator =(const Matriz2D &otro) {
    if (this != &otro) {
        this->LiberaMemoria();
        this->Copia(otro);
    }

    return (*this);
}

int& Matriz2D::operator()(int fil, int col) {
    if ((fil < 0) || (fil > this->filas) || (col < 0) || (col > this->columnas)) {
        cerr << "Error: indice fuera del rango de casillas accesible." << endl;
        exit(1);
    }

    return (*this)(fil, col);
}

int Matriz2D::operator()(int fil, int col) const {
    if ((fil < 0) || (fil > this->filas) || (col < 0) || (col > this->columnas)) {
        cerr << "Error: indice fuera del rango de casillas accesible." << endl;
        exit(1);
    }

    return (*this).datos[fil][col];
}

Matriz2D operator +(const Matriz2D &otro) {
    Matriz2D nuevo(otro);

    for (int i = 0; i < nuevo.filas; i++)
        for (int j = 0; j < nuevo.columnas; j++)
            nuevo.datos[i][j] = +(otro.datos[i][j]);

    return nuevo;
}

Matriz2D operator -(const Matriz2D &otro) {
    Matriz2D nuevo(otro);

    for (int i = 0; i < nuevo.filas; i++)
        for (int j = 0; j < nuevo.columnas; j++)
            nuevo.datos[i][j] = -(otro.datos[i][j]);

    return nuevo;
}

bool Matriz2D::operator ==(const Matriz2D &otro) {
    bool igual = true;

    if ((this->filas == otro.filas) && (this->columnas == otro.columnas)) {

        for (int i = 0; (i < this->filas) && igual; i++)
            for (int j = 0; (j < this->columnas) && igual; j++)
                if (this->datos[i][j] != otro.datos[i][j])
                    igual = false;
    } else
        igual = false;

    return igual;
}

bool Matriz2D::operator !=(const Matriz2D &otro) {
    return !((*this) == otro);
}

ostream & operator <<(ostream &out, const Matriz2D &m) {
    for (int i = 0; i < m.filas; i++) {
        for (int j = 0; j < m.columnas; j++)
            out << "[" << m.datos[i][j] << "]";

        out << endl;
    }

    return out;
}

void Matriz2D::aumentarFilas() {
    Matriz2D otra(this->filas + 1, this->columnas);

    for (int i = 0; i < this->filas; i++)
        for (int j = 0; j < this->columnas; j++)
            otra.datos[i][j] = this->datos[i][j];

    *(this) = otra;
}

void Matriz2D::Copia(const Matriz2D &otro) {
    this->filas = otro.filas;
    this->columnas = otro.columnas;

    this->PideMemoria(this->filas, this->columnas);

    for (int i = 0; i < this->filas; i++)
        for (int j = 0; j < this->columnas; j++)
            this->datos[i][j] = otro.datos[i][j];
}

void Matriz2D::PideMemoria(const unsigned int &fils, const unsigned int &cols) {
    try {
        this->datos = new unsigned int *[fils];
    } catch (runtime_error excepcion) {
        cout << "Error de memoria: " << excepcion.what();
    }

    for (int i = 0; i < fils; i++) {
        try {
            this->datos[i] = new unsigned int [cols];
        } catch (runtime_error excepcion) {
            cout << "Error de memoria: " << excepcion.what();
        }
    }
}

void Matriz2D::LiberaMemoria() {
    for (int i = 0; i < this->filas; i++)
        delete [] this->datos[i];

    delete [] this->datos;
}
