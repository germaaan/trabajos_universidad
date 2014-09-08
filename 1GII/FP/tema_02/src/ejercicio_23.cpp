// Un numero entero de n digitos se dice que es narcisista si se puede obtener como la
// suma de las potencias n-esimas de cada uno de sus digitos. Por ejemplo 153 y 8208
// son numeros narcisistas porque 153 = 1³ + 5³ + 3³ y 8208 = 8⁴ + 2⁴ + 0⁴ + 8⁴.
// Construir un programa que, dado un numero entero positivo, nos indique si el numero
// es o no narcisista.
// 
// Finalidad: Ejercitar los bucles. Dificultad Media.


#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int entero, enteroReducido, numDigitos;
    float digito, sumaTotal = 0;
    bool esNarcisista = false;

    do {
        cout << "\nIntroduce un numero positivo: ";
        cin >> entero;
    } while (entero < 0);

    enteroReducido = entero;
    numDigitos = 0;
    while (enteroReducido > 0) {
        enteroReducido = enteroReducido / 10;
        numDigitos++;
    }

    enteroReducido = entero;
    sumaTotal = 0;
    for (int i = 0; i < numDigitos; i++) {
        digito = enteroReducido % 10;
        sumaTotal = sumaTotal + pow(digito, numDigitos);
        enteroReducido = enteroReducido / 10;
    }

    if (sumaTotal == entero)
        esNarcisista = true;
    else
        esNarcisista = false;

    if (esNarcisista)
        cout << "\nEl numero " << entero << " es narcisista" << endl;
    else
        cout << "\nEl numero " << entero << " no es narcisista" << endl;

    cout << "\n\n";
}
