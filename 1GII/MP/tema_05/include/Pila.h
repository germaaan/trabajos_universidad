#ifndef _PILA
#define _PILA
#include <iostream>

using namespace std;

typedef char TipoBase;

class Pila {
private:

    struct celda {
        TipoBase valor;
        celda *siguiente;
    };

    celda *inicio;
    int unsigned _size;

public:
    Pila();
    Pila(const Pila &otra);
    ~Pila();
    bool estaVacia();
    void push(const TipoBase &x);
    TipoBase sacar();
    TipoBase tope();

    Pila& operator =(const Pila &otro);

    friend ostream & operator <<(ostream &out, const Pila &l);

private:
    void Copia(const Pila &otro);
    void LiberaMemoria();
};

#endif
