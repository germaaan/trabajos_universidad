#include "expresion.h"
#include <iostream>

using namespace std;

int main() {
    string a = "* + 2.3 6.1 7.9";
    expresion<float> e1;
    expresion<int> e2("- * x + 2 y * z 9");
    expresion<int> e3("100");
    expresion<int> e4(e2);
    expresion<int> e5 = e2;
    expresion<int> e6("1");
    expresion<int> e7(a);

    vector< pair<char, int> > variablesI;
    variablesI.push_back(pair<char, int>('x', 10));
    variablesI.push_back(pair<char, int>('y', 20));
    variablesI.push_back(pair<char, int>('z', 30));

    cout << "Expresiones originales:" << endl;
    cout << "Infijo:" << endl;
    cout << "\te1:" << e1.infijo() << endl;
    cout << "\te2:" << e2.infijo() << endl;
    cout << "\te3:" << e3.infijo() << endl;
    cout << "Postfijo:" << endl;
    cout << "\te1:" << e1.postfijo() << endl;
    cout << "\te2:" << e2.postfijo() << endl;
    cout << "\te3:" << e3.postfijo() << endl;
    cout << "Prefijo:" << endl;
    cout << "\te1:" << e1.prefijo() << endl;
    cout << "\te2:" << e2.prefijo() << endl;
    cout << "\te3:" << e3.prefijo() << endl;
    cout << "Niveles:" << endl;
    cout << "\te1:" << e1.niveles() << endl;
    cout << "\te2:" << e2.niveles() << endl;
    cout << "\te3:" << e3.niveles() << endl;

    e3 = e3 + e3;
    e6 = e6 - e3;
    e7 = e6 * e3;
    e5 = e6 / e3;

    cout << "\nExpresiones despues de las operaciones:" << endl;
    cout << "Infijo:" << endl;
    cout << "\te1:" << e1.infijo() << endl;
    cout << "\te2:" << e2.infijo() << endl;
    cout << "\te5:" << e5.infijo() << endl;
    cout << "\te6:" << e6.infijo() << endl;
    cout << "Postfijo:" << endl;
    cout << "\te1:" << e1.postfijo() << endl;
    cout << "\te2:" << e2.postfijo() << endl;
    cout << "\te5:" << e5.postfijo() << endl;
    cout << "\te6:" << e6.postfijo() << endl;
    cout << "Prefijo:" << endl;
    cout << "\te1:" << e1.prefijo() << endl;
    cout << "\te2:" << e2.prefijo() << endl;
    cout << "\te5:" << e5.prefijo() << endl;
    cout << "\te6:" << e6.prefijo() << endl;
    cout << "Niveles:" << endl;
    cout << "\te1:" << e1.niveles() << endl;
    cout << "\te2:" << e2.niveles() << endl;
    cout << "\te5:" << e5.niveles() << endl;
    cout << "\te6:" << e6.niveles() << endl;

    cout << "\nResultados de evaluar las expresiones:" << endl;
    cout << "\te2: " << e2.evalua(variablesI) << endl;
    cout << "\te3: " << e3.evalua(variablesI) << endl;

    return 0;
}
