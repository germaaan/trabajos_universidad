// Realizar un programa que lea desde teclado un entero "tope" e imprima en pantalla
// todos sus divisores. Para obtener los divisores, basta recorrer todos los enteros me-
// nores que el valor introducido y comprobar si lo dividen. A continuacion, mejorar el
// ejercicio obligando al usuario a introducir un entero positivo, usando un filtro con un
// bucle post test ("do while").
//
// Finalidad: Plantear un ejemplo sencillo de bucle y de filtro de entrada de datos. Difi-
// cultad Baja.


#include <iostream>
using namespace std;

int main() {
    int tope = 0, divisor = 1;

    //Mejor do while
    do {
        cout << "Introduzca un numero entero positivo para calcular todos sus divisores: ";
        cin >> tope;
    } while (tope <= 0);

    cout << "\nDivisores del numero " << tope << ": ";

    //Mejor while
    do {
        if (tope % divisor == 0)
            cout << divisor << " ";

        divisor++;
    } while (divisor < tope);

    cout << "\n\n";
}
