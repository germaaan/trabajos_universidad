#include "include/bigint.h"

#define UMBRAL 8

bigint elevar10(int ceros) {
    string pot = "1";
    for (int i = 0; i < ceros; i++)
        pot = pot + "0";
    bigint potencia = pot;

    return potencia;
}

bigint producto2(const bigint &x, const bigint &y) {
    int n;
    bigint a, b, c, d, r, p, q;

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

        r = producto2(a + b, c + d);
        p = producto2(a, c);
        q = producto2(b, d);

        return (p * elevar10(n)) + ((r - p - q) * elevar10(n / 2)) + q;
    }
}