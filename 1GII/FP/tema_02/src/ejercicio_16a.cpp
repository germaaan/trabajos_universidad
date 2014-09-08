// Todo lo que se puede hacer con un bucle "while" se puede hacer con un "do while".
// Lo mismo ocurre al reves. Sin embargo, cada bucle se usa de forma natural en ciertas
// situaciones. El no hacerlo, nos obligara a escribir mas codigo y este sera mas dificil
// de entender. Para comprobarlo, haced lo siguiente:
// 
// a) Modificad la solucion del ejercicio 10 de forma que el filtro de entrada usado para
// leer la variable "tope", se haga con un bucle pre-test "while".


#include <iostream>
using namespace std;

int main() {
    int tope = 0, divisor = 1;

    while (tope <= 0) {
        cout << "Introduzca un numero entero positivo para calcular todos sus divisores: ";
        cin >> tope;
    }

    cout << "\nDivisores del numero " << tope << ": ";

    while (divisor < tope) {
        if (tope % divisor == 0)
            cout << divisor << " ";

        divisor++;
    }

    cout << "\n\n";
}
