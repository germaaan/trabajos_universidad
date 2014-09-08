#include "Matriz2D-2.h"
#include <stdexcept>
#include <iostream>
#include <cstdlib>

using namespace std;

Matriz2D_2::Matriz2D_2() {
    this->PideMemoria(0, 0);

    this->filas = 0;
    this->columnas = 0;
}

Matriz2D_2::Matriz2D_2(const unsigned int &fils, const unsigned int &cols) {
    this->PideMemoria(fils, cols);

    for (int i = 0; i < fils; i++)
        for (int j = 0; j < cols; j++)
            this->datos[i][j] = 0;

    this->filas = fils;
    this->columnas = cols;
}

Matriz2D_2::Matriz2D_2(const unsigned int &fils, const unsigned int &cols, const unsigned int &val) {
    this->PideMemoria(fils, cols);

    for (int i = 0; i < fils; i++)
        for (int j = 0; j < cols; j++)
            this->datos[i][j] = val;

    this->filas = fils;
    this->columnas = cols;
}

Matriz2D_2::Matriz2D_2(const Matriz2D_2 &otro) {
    this->Copia(otro);
}

Matriz2D_2::~Matriz2D_2() {
    this->LiberaMemoria();
}

bool Matriz2D_2::estaVacia() {
    bool estado = true;

    for (int i = 0; i < this->filas; i++)
        for (int j = 0; (j < this->columnas) && estado; j++)
            if (this->datos[i][j] >= 0)
                estado = false;

    return estado;
}

void Matriz2D_2::PonValor(const unsigned int &fil, const unsigned int &col, const unsigned int &val) {
    if ((fil < this->filas) && (col < this->columnas))
        this->datos[fil][col] = val;
}

int Matriz2D_2::LeeValor(const unsigned int &fil, const unsigned int &col) {
    if ((fil < this->filas) && (col < this->columnas))
        return this->datos[fil][col];
}

Matriz2D_2& Matriz2D_2::operator =(const Matriz2D_2 &otro) {
    if (this != &otro) {
        this->LiberaMemoria();
        this->Copia(otro);
    }

    return (*this);
}

int& Matriz2D_2::operator()(int fil, int col) {
    if ((fil < 0) || (fil > this->filas) || (col < 0) || (col > this->columnas)) {
        cerr << "Error: indice fuera del rango de casillas accesible." << endl;
        exit(1);
    }

    return (*this)(fil, col);
}

int Matriz2D_2::operator()(int fil, int col) const {
    if ((fil < 0) || (fil > this->filas) || (col < 0) || (col > this->columnas)) {
        cerr << "Error: indice fuera del rango de casillas accesible." << endl;
        exit(1);
    }

    return (*this).datos[fil][col];
}

Matriz2D_2 operator +(const Matriz2D_2 &otro) {
    Matriz2D_2 nuevo(otro);

    for (int i = 0; i < nuevo.filas; i++)
        for (int j = 0; j < nuevo.columnas; j++)
            nuevo.datos[i][j] = +(otro.datos[i][j]);

    return nuevo;
}

Matriz2D_2 operator -(const Matriz2D_2 &otro) {
    Matriz2D_2 nuevo(otro);

    for (int i = 0; i < nuevo.filas; i++)
        for (int j = 0; j < nuevo.columnas; j++)
            nuevo.datos[i][j] = -(otro.datos[i][j]);

    return nuevo;
}

bool Matriz2D_2::operator ==(const Matriz2D_2 &otro) {
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

bool Matriz2D_2::operator !=(const Matriz2D_2 &otro) {
    return !((*this) == otro);
}

ostream & operator <<(ostream &out, const Matriz2D_2 &m) {
    for (int i = 0; i < m.filas; i++) {
        for (int j = 0; j < m.columnas; j++)
            out << "[" << m.datos[i][j] << "]";

        out << endl;
    }

    return out;
}

void Matriz2D_2::Copia(const Matriz2D_2 &otro) {
    this->filas = otro.filas;
    this->columnas = otro.columnas;

    this->PideMemoria(this->filas, this->columnas);

    for (int i = 0; i < this->filas; i++)
        for (int j = 0; j < this->columnas; j++)
            this->datos[i][j] = otro.datos[i][j];
}

void Matriz2D_2::PideMemoria(const unsigned int &fils, const unsigned int &cols) {
    try {
        this->datos = new unsigned int *[fils];
    } catch (runtime_error excepcion) {
        cout << "Error de memoria: " << excepcion.what();
    }

    this->datos[0] = new unsigned int [fils * cols];

    for (int i = 1; i < fils; i++)
        this->datos[i] = this->datos[i - 1] + cols;
}

void Matriz2D_2::LiberaMemoria() {
    delete [] this->datos[0];

    delete [] this->datos;
}
