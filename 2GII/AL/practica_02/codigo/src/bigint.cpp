#include <cstring>
#include "../include/bigint.h"

bigint::bigint() {
    signo = 1;
}

bigint::bigint(const string &s) {
    if (s.length() < 1) return;

    int ultimo;

    if (s[0] == '-') {
        signo = -1;
        ultimo = 1;
    } else {
        signo = 1;
        ultimo = 0;
    }
    for (int i = s.length() - 1; i >= ultimo; i--)
        digitos.push_back(s[i] - '0');
}

bigint::bigint(const char *s) {
    if (strlen(s) < 1) return;

    int ultimo;

    if (s[0] == '-') {
        signo = -1;
        ultimo = 1;
    } else {
        signo = 1;
        ultimo = 0;
    }

    for (int i = strlen(s) - 1; i >= ultimo; i--)
        digitos.push_back(s[i] - '0');

}

bigint::bigint(int x) {
    if (x >= 0)
        signo = 1;
    else {
        signo = -1;
        x = -x;
    }

    int aux = x;
    while (aux >= 10) {
        digitos.push_back(aux % 10);
        aux /= 10;
    }
    digitos.push_back(aux);
}

bigint bigint::operator+(const bigint &x) const {
    unsigned int acum = 0;
    unsigned int i;
    bigint res;

    if (signo == -1 && x.signo == -1)
        return -(*this +x);
    else
        if (signo == -1 && x.signo == 1)
        return x - - * this;
    else
        if (signo == 1 && x.signo == -1)
        return *this - -x;

    for (i = 0; i < min(digitos.size(), x.digitos.size()); i++) {
        unsigned int aux = digitos[i] + x.digitos[i];
        res.digitos.push_back((aux + acum) % 10);
        acum = (aux + acum) / 10;
    }

    if (i < digitos.size())
        for (unsigned int j = i; j < digitos.size(); j++) {
            res.digitos.push_back((digitos[j] + acum) % 10);
            acum = (digitos[j] + acum) / 10;
        } else
        if (i < x.digitos.size())
        for (unsigned int j = i; j < x.digitos.size(); j++) {
            res.digitos.push_back(x.digitos[j] + acum);
            acum = (x.digitos[j] + acum) / 10;
        } else
        if (acum == 1)
        res.digitos.push_back(acum);
    return res;

}

/* Resta dos bigint considerando que el primero es mayor que el segundo y sin mirar signos */
bigint bigint::resta(const bigint &x) const {
    bigint res;
    unsigned int i;
    int acum = 0;

    for (i = 0; i < x.digitos.size(); i++) {
        int aux = digitos[i] - x.digitos[i] + acum;
        if (aux < 0) {
            acum = -1;
            res.digitos.push_back(aux + 10);
        } else {
            acum = 0;
            res.digitos.push_back(aux);
        }
    }

    for (unsigned int j = i; j < digitos.size(); j++) {
        res.digitos.push_back((digitos[i] + acum) % 10);
        acum = (digitos[i] + acum) / 10;
    }
    while (res.digitos.size() > 1 && res.digitos.back() == 0)
        res.digitos.pop_back();
    if (res.digitos.size() == 1 && res.digitos[0] == 0) res.signo = 1;

    return res;
}

bigint bigint::operator-(const bigint &x) const {
    bigint res;
    if (signo != x.signo) // Se suman
        if (signo == 1)
            res = *this + -x;
        else {
            res = - * this +x;
            res.signo = -1;
        } else {
        if (*this<x)
            res = -(x.resta(*this));
        else
            res = resta(x);
    }

    return res;
}

bigint bigint::operator*(const int x) const {
    bigint res;
    unsigned int i;
    unsigned int acum = 0;
    int xx;


    if (x == 0)
        return res;
    else
        if (x < 0) {
        res.signo = signo * (-1);
        xx = -x;
    } else xx = x;

    for (i = 0; i < digitos.size(); i++) {
        unsigned int aux = digitos[i] * xx;
        res.digitos.push_back((aux + acum) % 10);
        acum = (aux + acum) / 10;
    }
    while (acum > 0) {
        res.digitos.push_back(acum % 10);
        acum /= 10;
    }

    return res;
}

bigint bigint::operator*(const bigint &x) const {
    if (*this == 0 || x == 0)
        return bigint();

    bigint res;
    unsigned int ceros = 0;
    while (x.digitos[ceros] == 0)
        ceros++;

    res = *this * x.digitos[ceros];

    for (unsigned int i = ceros + 1; i < x.digitos.size(); i++) {
        if (x.digitos[i] != 0) {
            bigint aux = *this * x.digitos[i];
            for (unsigned int k = 0; k < i - ceros; k++)
                aux.digitos.insert(aux.digitos.begin(), 0);
            res = res + aux;
        }
    }

    for (unsigned int j = 0; j < ceros; j++)
        res.digitos.insert(res.digitos.begin(), 0);

    res.signo = signo * x.signo;

    return res;
}

bigint bigint::operator-() const {
    bigint res;
    res.digitos = (*this).digitos;
    if (digitos.size() == 1 && digitos[0] == 0)
        res.signo = 1;
    else
        res.signo = -signo;

    return res;
}

bool bigint::operator<(const bigint &x) const {
    if (signo != x.signo)
        return (signo == -1);

    // Igual signo
    if (digitos.size() < x.digitos.size())
        return true;
    else
        if (digitos.size() > x.digitos.size())
        return false;

    // Mismo número de dígitos
    int i = digitos.size() - 1;
    while (i >= 0 && digitos[i] == x.digitos[i]) {
        i--;
    }

    return (i >= 0 && digitos[i] < x.digitos[i]);
}

bool bigint::operator==(const bigint &x) const {
    if (signo != x.signo)
        if (digitos.size() == 1 && x.digitos.size() == 1 && digitos[0] == 0 && x.digitos[0] == 0)
            return true;
        else
            return false;

    // Igual signo
    if (digitos.size() != x.digitos.size())
        return false;

    // Mismo número de dígitos
    int i = digitos.size() - 1;
    while (i >= 0 && digitos[i] == x.digitos[i]) {
        i--;
    }

    return i < 0;
}

bigint bigint::digits(unsigned int a, unsigned int b) const {
    bigint res;
    int aux = min(b, (unsigned int) digitos.size() - 1);

    while (aux >= 0 && digitos[aux] == 0)
        aux--;

    for (int i = aux; i >= max((int) a, 0); i--)
        res.digitos.insert(res.digitos.begin(), digitos[i]);

    return res;
}

bigint::~bigint() {
}

ostream& operator<<(ostream &os, const bigint &x) {
    if (x.digitos.size() == 0)
        os << "0";
    else {
        if (x.signo == -1) cout << "-";

        for (int i = x.digitos.size() - 1; i >= 0; i--)
            os << (int) x.digitos[i];
    }

    return os;
}