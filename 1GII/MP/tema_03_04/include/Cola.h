#ifndef _COLA
#define _COLA
#include <iostream>

using namespace std;

typedef int TipoBase;

class Cola {
private:

    struct celda {
        TipoBase valor;
        celda *siguiente;
    };

    celda *inicio;
    int unsigned _size;

public:
    Cola();
    Cola(const Cola &otra);
    ~Cola();
    bool estaVacia();
    void push(const TipoBase &x);
    TipoBase sacar();
    TipoBase cabecera();

    Cola& operator =(const Cola &otro);

    friend ostream & operator <<(ostream &out, const Cola &l);

private:
    void Copia(const Cola &otro);
    void LiberaMemoria();
};

#endif
