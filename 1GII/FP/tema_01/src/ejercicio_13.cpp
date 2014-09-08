// Considerad el siguiente codigo:
//
//	double real, otro_real;
//
//	real = 2e34;
//	otro_real = real + 1;
//	otro_real = otro_real - real;
//
//	cout << otro_real;
//
// • Que imprime en pantalla? Justificar la respuesta.
//
// Finalidad: Entender el problema de la precision con los reales. Dificultad Media.


#include <iostream>
using namespace std;

int main() {
    double real, otro_real;

    real = 2e34;
    otro_real = real + 1;
    otro_real = otro_real - real;

    cout << otro_real << "\n\n";

    /*Al tener los dos numeros reales un numero tan alto de cifras, el ordenador los redondea con una precision meno a la exacta, en la que la incrementacion de 1 unidad es insignificante, por lo que los valores serian iguales, dando como resultado de la resta 0.*/
}
