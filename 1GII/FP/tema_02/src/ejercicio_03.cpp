// Realizar un programa en C++ que lea dos valores enteros desde teclado y diga si
// cualquiera de ellos divide o no (de forma entera) al otro. En este problema no hace
// falta decir quien divide a quien. Supondremos que los valores leidos desde teclado
// son ambos distintos de cero y se pueden mezclar cómputos con entradas y salidas.
// 
// Finalidad: Plantear una estructura condicional doble con una expresión logica com-
// puesta. Dificultad Baja.


#include <iostream>
using namespace std;

int main() {
    int entero1;
    int entero2;

    cout << "Introduzca primer valor entero: ";
    cin >> entero1;

    cout << "Introduzca segundo valor entero: ";
    cin >> entero2;

    if ((entero1 % entero2 == 0) || (entero2 % entero1 == 0))
        cout << "\nLos valores introducidos son divisibles entre si." << endl;
    else
        cout << "\nLos valores introducidos no son divisibles entre si." << endl;

    cout << "\n\n";
}
