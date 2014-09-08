#ifndef _LISTA
#define _LISTA
#include <iostream>

using namespace std;

typedef int TipoBase;

class Lista {
private:

    struct celda {
        TipoBase valor;
        celda *siguiente;
    };

    celda *inicio;
    unsigned int _size;

public:
    Lista();
    Lista(const unsigned int &n);
    Lista(const unsigned int &n, const TipoBase &x);
    Lista(const Lista &otro);
    ~Lista();
    bool estaVacia();
    unsigned int size();
    void escribeLista();
    void Insertar(const TipoBase &val, const unsigned int &pos);
    void Borrar(const unsigned int &pos);
    TipoBase ObtenerValor(const unsigned int &pos);
    void PonerValor(const unsigned int &pos, const TipoBase &val);

    Lista& operator =(const Lista &otro);
    TipoBase& operator [](const unsigned int &indice);

    friend ostream & operator <<(ostream &out, const Lista &l);
    friend istream & operator >>(istream &in, Lista &l);

private:
    void Copia(const Lista &otro);
    void LiberaMemoria();
};

#endif
