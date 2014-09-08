#include <iostream>
#include "include/bigint.h"
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <iomanip>

//#define UMBRAL 8

using namespace std;

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

int main(int argc, char **argv) {
    bigint bi[8], biMC, biR, biDV;
    clock_t tantes, tdespues;
    double tiempo_transcurrido;
    const int NUM_VECES = 10000;
    int j, i;

    bi[0] = "11";
    bi[1] = "2222";
    bi[2] = "33333333";
    bi[3] = "4444444444444444";
    bi[4] = "55555555555555555555555555555555";
    bi[5] = "6666666666666666666666666666666666666666666666666666666666666666";

    cout << "\nmultiplicacion_clasica.dat:" << endl;
    cout << "===========================" << endl;

    for (i = 0; i < 6; i++) {
        tantes = clock();

        for (j = 0; j < NUM_VECES; j++) biMC = bi[i] * bi[i];

        tdespues = clock();

        tiempo_transcurrido = ((double) (tdespues - tantes) / (CLOCKS_PER_SEC * (double) NUM_VECES));
        cout << " " << pow(2, i + 1) << " ";
        cout << setiosflags(ios::fixed);
        cout << tiempo_transcurrido * (double) NUM_VECES << endl;
        cout.unsetf(ios::fixed);
    }

    cout << "\nrecursividad.dat:" << endl;
    cout << "===========================" << endl;

    for (i = 0; i < 6; i++) {
        tantes = clock();

        for (j = 0; j < NUM_VECES; j++) biR = producto1(bi[i], bi[i]);

        tdespues = clock();

        tiempo_transcurrido = ((double) (tdespues - tantes) / (CLOCKS_PER_SEC * (double) NUM_VECES));
        cout << " " << pow(2, i + 1) << " ";
        cout << setiosflags(ios::fixed);
        cout << tiempo_transcurrido * (double) NUM_VECES << endl;
        cout.unsetf(ios::fixed);
    }

    cout << "\ndivide_venceras.dat:" << endl;
    cout << "===========================" << endl;

    for (i = 0; i < 6; i++) {
        tantes = clock();

        for (j = 0; j < NUM_VECES; j++) biDV = producto2(bi[i], bi[i]);

        tdespues = clock();

        tiempo_transcurrido = ((double) (tdespues - tantes) / (CLOCKS_PER_SEC * (double) NUM_VECES));
        cout << " " << pow(2, i + 1) << " ";
        cout << setiosflags(ios::fixed);
        cout << tiempo_transcurrido * (double) NUM_VECES << endl;
        cout.unsetf(ios::fixed);
    }

    return 0;
}
