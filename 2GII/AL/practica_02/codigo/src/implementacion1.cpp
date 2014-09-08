#include "include/bigint.h"

#define UMBRAL 8

bigint elevar10(int ceros) {
    string pot = "1";
    for (int i = 0; i < ceros; i++)
        pot = pot + "0";
    bigint potencia = pot;

    return potencia;
}

bigint producto1(const bigint &x, const bigint &y) {
    int n;
    bigint a, b, c, d;

    if (x.size() > y.size())
        n = x.size();
    else
        n = y.size();

    if (n < UMBRAL)
        return x * y;
    else {

        a = x.digits(x.size() / 2, x.size() - 1);
        b = x.digits(0, x.size() / 2 - 1);

        c = y.digits(y.size() / 2, y.size() - 1);
        d = y.digits(0, y.size() / 2 - 1);

        return (producto1(a, c) * elevar10(n)) + ((producto1(a, d) + producto1(b, c)) * elevar10(n / 2)) + producto1(b, d);
    }
}