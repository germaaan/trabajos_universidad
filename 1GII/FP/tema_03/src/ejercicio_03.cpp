// Cread funciones que hagan lo siguiente:
//
//	• Comprobar si un numero es par.
//
//	• Comprobar si dos reales son iguales, aceptando un margen en la diferencia de
//	  0,000001
//
//	• Comprobar si un numero es primo.
//
// Incluid un programa principal que llame a dichas funciones con los parametros actua-
// les que se quiera.


#include <iostream>
#include <cmath>

using namespace std;

bool EsPar(int numero) {
    bool es_par = false;

    if (numero % 2 == 0)
        es_par = true;

    return es_par;
}

bool EsAproximadamenteIgual(double numero1, double numero2, double alfa = 0.000001) {
    bool igual = false;

    if (numero1 < numero2 + alfa && numero1 > numero2 - alfa)
        igual = true;

    return igual;
}

bool EsPrimo(int numero) {
    bool esPrimo = false;

    for (int i = numero - 1; i > 1 && !esPrimo; i--)
        if (numero % i == 0)
            esPrimo = false;

    return esPrimo;
}

int main() {

    int numero = 257;

    if (EsPar(numero))
        cout << "El numero " << numero << " es par\n";
    else
        cout << "El numero " << numero << " no es par\n";
    if (EsPrimo(numero))
        cout << "El numero " << numero << " es primo\n";
    else
        cout << "El numero " << numero << " no es primo\n";
    if (EsAproximadamenteIgual(58.3378748, 58.337874, 0.000001))
        cout << "Los dos numeros son aproximadamente iguales\n";
    else
        cout << "Los dos numeros no son aproximadamente iguales\n";

    cout << "\n\n";
}
