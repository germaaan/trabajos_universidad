// Una progresion geometrica es una secuencia de elementos en la que cada uno de
// ellos se obtiene multiplicando el anterior por una constante denominada razon o factor
// de la progresion. Queda totalmente determinada por el primer elemento (a1) y la razon
// r. Para un valor de n arbitrario, el elemento an se puede obtener aplicando la formula:
// 
// an = a1 * r ^ n−1
// Cread un programa que calcule la suma de los primeros k valores de una progresion
// geometrica, es decir:
// 
// Σ i=1 i=k ai
//
// Finalidad: Trabajar con bucles "for". Dificultad Baja.


#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int a1, n, contador = 1;
    double razon, progresion;

    cout << "Introduzca el valor sobre el que calcular la progresion geometrica: ";
    cin >> a1;
    cout << "Introduzca el numero de elementos para calcular la progresion geometrica: ";
    cin >> n;
    cout << "Introduzca la constante de razon: ";
    cin >> razon;

    while (contador <= n) {
        progresion = a1 * (pow(razon, contador - 1));
        cout << "\nElemento " << contador << " de la progresion: " << progresion;
        contador++;
    }

    cout << "\n\n";
}

