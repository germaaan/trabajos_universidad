#ifndef _MATRIZ2D_1
#define _MATRIZ2D_1
#include <iostream>

using namespace std;

typedef unsigned int** TipoBase;

class Matriz2D_1 {
private:
    TipoBase datos;
    int unsigned filas;
    int unsigned columnas;

public:
    Matriz2D_1();
    Matriz2D_1(const unsigned int &fils, const unsigned int &cols);
    Matriz2D_1(const unsigned int &fils, const unsigned int &cols, const unsigned int &val);
    Matriz2D_1(const Matriz2D_1 &otro);
    ~Matriz2D_1();
    bool estaVacia();
    void PonValor(const unsigned int &fil, const unsigned int &col, const unsigned int &val);
    int LeeValor(const unsigned int &fil, const unsigned int &col);

    Matriz2D_1& operator =(const Matriz2D_1 &otro);

    int& operator()(int, int);
    int operator()(int, int) const;

    friend Matriz2D_1 operator +(const Matriz2D_1 &otro);
    friend Matriz2D_1 operator -(const Matriz2D_1 &otro);

    bool operator ==(const Matriz2D_1 &otro);
    bool operator !=(const Matriz2D_1 &otro);

    friend ostream & operator <<(ostream &out, const Matriz2D_1 &m);

private:
    void Copia(const Matriz2D_1 &otro);
    void PideMemoria(const unsigned int &fils, const unsigned int &cols);
    void LiberaMemoria();
};

#endif
