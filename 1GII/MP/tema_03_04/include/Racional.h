#ifndef _RACIONAL
#define _RACIONAL
#include <iostream>

using namespace std;

class Racional {
private:
    int numerador;
    int denominador;

public:
    Racional();
    Racional(const int &valor);
    Racional(const int &a, const int &b);
    ~Racional();
    int getNumerador();
    int getDenominador();
    void setNumerador(const int &valor);
    void setDenominador(const int &valor);
    void mostrar();

    friend Racional operator +(const Racional &r);
    friend Racional operator -(const Racional &r);

    friend Racional operator +(const Racional &r1, const Racional &r2);
    friend Racional operator +(const Racional &r, const int entero);
    friend Racional operator +(const int entero, const Racional &r);

    friend Racional operator -(const Racional &r1, const Racional &r2);
    friend Racional operator -(const Racional &r, const int entero);
    friend Racional operator -(const int entero, const Racional &r);

    friend Racional operator *(const Racional &r1, const Racional &r2);
    friend Racional operator *(const Racional &r, const int entero);
    friend Racional operator *(const int entero, const Racional &r);

    friend Racional operator /(const Racional &r1, const Racional &r2);
    friend Racional operator /(const Racional &r, const int entero);
    friend Racional operator /(const int entero, const Racional &r);

    Racional operator +=(const Racional &r);
    Racional operator -=(const Racional &r);
    Racional operator *=(const Racional &r);
    Racional operator /=(const Racional &r);

    friend bool operator ==(const Racional &r1, const Racional &r2);
    friend bool operator ==(const Racional &r, const int entero);
    friend bool operator ==(const int entero, const Racional &r);

    friend bool operator !=(const Racional &r1, const Racional &r2);
    friend bool operator !=(const Racional &r, const int entero);
    friend bool operator !=(const int entero, const Racional &r);

    friend bool operator>(const Racional &r1, const Racional &r2);
    friend bool operator>(const Racional &r, const int entero);
    friend bool operator>(const int entero, const Racional &r);

    friend bool operator<(const Racional &r1, const Racional &r2);
    friend bool operator<(const Racional &r, const int entero);
    friend bool operator<(const int entero, const Racional &r);

    friend bool operator >=(const Racional &r1, const Racional &r2);
    friend bool operator >=(const Racional &r, const int entero);
    friend bool operator >=(const int entero, const Racional &r);

    friend bool operator <=(const Racional &r1, const Racional &r2);
    friend bool operator <=(const Racional &r, const int entero);
    friend bool operator <=(const int entero, const Racional &r);

    friend ostream & operator <<(ostream &out, const Racional &r);
    friend istream & operator >>(istream &in, Racional &r);

private:
    static int mcd(int a, int b);
};

#endif
