#ifndef _VECTOR_DINAMICO
#define _VECTOR_DINAMICO
#include "Conjunto.h"
#include <iostream>

using namespace std;

class VectorDinamico {
private:
    int *datos;
    unsigned int _size;
    unsigned int _capacity;

public:
    VectorDinamico();
    VectorDinamico(const unsigned int &n);
    VectorDinamico(const unsigned int &n, const int &valor);
    VectorDinamico(const VectorDinamico &otro);
    ~VectorDinamico();
    bool estaVacio();
    unsigned int size();
    unsigned int capacity();
    int at(const unsigned int &i);
    void push(const int &valor);
    void escribirVector();
    VectorDinamico& operator =(const VectorDinamico &otro);
    int& operator [](const unsigned int &indice);

    bool operator ==(const VectorDinamico &otro);
    bool operator !=(const VectorDinamico &otro);

    bool operator>(const VectorDinamico &otro);
    bool operator<(const VectorDinamico &otro);
    bool operator >=(const VectorDinamico &otro);
    bool operator <=(const VectorDinamico &otro);

    VectorDinamico operator +(const int &n);
    VectorDinamico operator -(const int &n);
    VectorDinamico operator +=(const int &n);
    VectorDinamico operator -=(const int &n);

    friend ostream & operator <<(ostream &out, const VectorDinamico &r);
    friend istream & operator >>(istream &in, VectorDinamico &r);

private:
    void redimensionar(const unsigned int &n);
    void Copia(const VectorDinamico &otro);
    void PideMemoria(const unsigned int &n);
    void LiberaMemoria();
};

#endif
