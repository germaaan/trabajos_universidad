#include "Racional.h"
#include <iostream>

using namespace std;

Racional::Racional() : numerador(0), denominador(0) {
}

Racional::Racional(const int &valor) : numerador(valor), denominador(1) {
}

Racional::Racional(const int &a, const int &b) : numerador(a), denominador(b) {
}

Racional::~Racional() {
}

int Racional::getNumerador() {
    return this->numerador;
}

int Racional::getDenominador() {
    return this->denominador;
}

void Racional::setNumerador(const int &valor) {
    this->numerador = valor;
}

void Racional::setDenominador(const int &valor) {
    this->denominador = valor;
}

void Racional::mostrar() {
    cout << this->numerador << "/" << this->denominador << endl;
}

Racional operator +(const Racional &r) {
    Racional resultado(+(r.numerador), r.denominador);

    return resultado;
}

Racional operator -(const Racional &r) {
    Racional resultado(-(r.numerador), r.denominador);

    return resultado;
}

Racional operator +(const Racional &r1, const Racional &r2) {
    Racional resultado;

    int comun;

    int numerador1 = r1.numerador;
    int denominador1 = r1.denominador;

    int numerador2 = r2.numerador;
    int denominador2 = r2.denominador;

    if (denominador1 != denominador2) {
        comun = Racional::mcd(denominador1, denominador2);

        numerador1 = (numerador1 * comun) / denominador1;
        numerador2 = (numerador2 * comun) / denominador2;

        denominador1 = denominador2 = comun;
    }

    resultado.numerador = numerador1 + numerador2;
    resultado.denominador = denominador1;

    return resultado;
}

Racional operator +(const Racional &r, const int entero) {
    return r + Racional(entero);
}

Racional operator +(const int entero, const Racional &r) {
    return Racional(entero) + r;
}

Racional operator -(const Racional &r1, const Racional &r2) {
    Racional resultado;

    int comun;

    int numerador1 = r1.numerador;
    int denominador1 = r1.denominador;

    int numerador2 = r2.numerador;
    int denominador2 = r2.denominador;

    if (denominador1 != denominador2) {
        comun = Racional::mcd(denominador1, denominador2);

        numerador1 = (numerador1 * comun) / denominador1;
        numerador2 = (numerador2 * comun) / denominador2;

        denominador1 = denominador2 = comun;
    }

    resultado.numerador = numerador1 - numerador2;
    resultado.denominador = denominador1;

    return resultado;
}

Racional operator -(const Racional &r, const int entero) {
    return r - Racional(entero);
}

Racional operator -(const int entero, const Racional &r) {
    return Racional(entero) - r;
}

Racional operator *(const Racional &r1, const Racional &r2) {
    Racional resultado;

    resultado.numerador = r1.numerador * r2.numerador;
    resultado.denominador = r1.denominador * r2.numerador;

    return resultado;
}

Racional operator *(const Racional &r, const int entero) {
    return r * Racional(entero);
}

Racional operator *(const int entero, const Racional &r) {
    return Racional(entero) * r;
}

Racional operator /(const Racional &r1, const Racional &r2) {
    Racional resultado;

    resultado.numerador = r1.numerador * r2.denominador;
    resultado.denominador = r1.denominador * r2.numerador;

    return resultado;
}

Racional operator /(const Racional &r, const int entero) {
    return r / Racional(entero);
}

Racional operator /(const int entero, const Racional &r) {
    return Racional(entero) / r;
}

Racional Racional::operator +=(const Racional &r) {
    return (*this)+r;
}

Racional Racional::operator -=(const Racional &r) {
    return (*this)-r;
}

Racional Racional::operator *=(const Racional &r) {
    return (*this)*r;
}

Racional Racional::operator /=(const Racional &r) {
    return (*this) / r;
}

bool operator ==(const Racional &r1, const Racional &r2) {
    int comun;

    int numerador1 = r1.numerador;
    int denominador1 = r1.denominador;

    int numerador2 = r2.numerador;
    int denominador2 = r2.denominador;

    if (denominador1 != denominador2) {
        comun = Racional::mcd(denominador1, denominador2);

        numerador1 = (numerador1 * comun) / denominador1;
        numerador2 = (numerador2 * comun) / denominador2;

        denominador1 = denominador2 = comun;
    }

    return numerador1 == numerador2;
}

bool operator ==(const Racional &r, const int entero) {
    return r == Racional(entero);
}

bool operator ==(const int entero, const Racional &r) {
    return Racional(entero) == r;
}

bool operator !=(const Racional &r1, const Racional &r2) {
    return !(r1 == r2);
}

bool operator !=(const Racional &r, const int entero) {
    return !(Racional(entero) == r);
}

bool operator !=(const int entero, const Racional &r) {
    return !(Racional(entero) == r);
}

bool operator>(const Racional &r1, const Racional &r2) {
    int comun;

    int numerador1 = r1.numerador;
    int denominador1 = r1.denominador;

    int numerador2 = r2.numerador;
    int denominador2 = r2.denominador;

    if (denominador1 != denominador2) {
        comun = Racional::mcd(denominador1, denominador2);

        numerador1 = (numerador1 * comun) / denominador1;
        numerador2 = (numerador2 * comun) / denominador2;

        denominador1 = denominador2 = comun;
    }

    return numerador1 > numerador2;
}

bool operator>(const Racional &r, const int entero) {
    return r > Racional(entero);
}

bool operator>(const int entero, const Racional &r) {
    return Racional(entero) > r;
}

bool operator<(const Racional &r1, const Racional &r2) {
    return !(r1 > r2);
}

bool operator<(const Racional &r, const int entero) {
    return !(r > Racional(entero));
}

bool operator<(const int entero, const Racional &r) {
    return !(Racional(entero) > r);
}

bool operator >=(const Racional &r1, const Racional &r2) {
    int comun;

    int numerador1 = r1.numerador;
    int denominador1 = r1.denominador;

    int numerador2 = r2.numerador;
    int denominador2 = r2.denominador;

    if (denominador1 != denominador2) {
        comun = Racional::mcd(denominador1, denominador2);

        numerador1 = (numerador1 * comun) / denominador1;
        numerador2 = (numerador2 * comun) / denominador2;

        denominador1 = denominador2 = comun;
    }

    return numerador1 >= numerador2;
}

bool operator >=(const Racional &r, const int entero) {
    return r >= Racional(entero);
}

bool operator >=(const int entero, const Racional &r) {
    return Racional(entero) >= r;
}

bool operator <=(const Racional &r1, const Racional &r2) {
    return !(r1 >= r2);
}

bool operator <=(const Racional &r, const int entero) {
    return !(r >= Racional(entero));
}

bool operator <=(const int entero, const Racional &r) {
    return !(Racional(entero) >= r);
}

ostream & operator <<(ostream &out, const Racional &r) {
    return out << r.numerador << "/" << r.denominador;
}

istream & operator >>(istream &in, Racional &r) {
    r.numerador = static_cast<int> (in.get());
    in.get();
    r.denominador = static_cast<int> (in.get());

    return in;
}

int Racional::mcd(int a, int b) {
    int min, max, r;

    r = a * b;

    while (a != b) {
        if (a > b)
            a = a - b;
        else
            b = b - a;
    }

    max = a;

    min = r / max;

    return min;
}
