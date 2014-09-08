#ifndef _CONJUNTO
#define _CONJUNTO
#include <iostream>
#include "VectorDinamico.h"

using namespace std;

typedef int TipoBase;

class Conjunto {
private:

    struct celda {
        TipoBase valor;
        celda *siguiente;
    };

    celda *inicio;
    int _size;

public:
    Conjunto();
    Conjunto(const TipoBase &x);
    Conjunto(const Conjunto &otro);
    ~Conjunto();
    bool estaVacio();
    Conjunto& operator =(const Conjunto &otro);
    int size();
    bool buscarElemento(const TipoBase &x);
    void push(const TipoBase &x);

    friend ostream & operator <<(ostream &out, const Conjunto &otro);
    friend istream & operator >>(istream &in, Conjunto &otro);

    bool operator ==(const Conjunto &otro);
    bool operator !=(const Conjunto &otro);

    friend Conjunto operator +(const Conjunto &c1, const Conjunto &c2);
    friend Conjunto operator +(const Conjunto &c, const TipoBase &x);
    friend Conjunto operator +(const TipoBase &x, const Conjunto &c);

    friend Conjunto operator -(const Conjunto &c1, Conjunto &c2);
    friend Conjunto operator -(const Conjunto &c, const TipoBase &x);

    friend Conjunto operator *(Conjunto &c1, Conjunto &c2);
    friend Conjunto operator *(Conjunto &c, const TipoBase &x);
    friend Conjunto operator *(const TipoBase &x, Conjunto &c);
};
#endif
