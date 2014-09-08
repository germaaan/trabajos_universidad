// Crear un programa que pida un valor de intensidad y resistencia e imprima el voltaje
// correspondiente, segun la Ley de Ohm:
//
// 	voltaje = intensidad * resistencia
//
// Finalidad: Ejemplo basico de asignacion a una variable del resultado de una expresion.
// Dificultad Baja.


#include <iostream>
using namespace std;

int main() {
    double intensidad;
    double resistencia;
    double voltaje;

    cout << "Introduzca el valor de la intensidad: ";
    cin >> intensidad;
    cout << "Introduzca el valor de la resistencia: ";
    cin >> resistencia;

    voltaje = intensidad * resistencia;

    cout << "\nEl valor del voltaje es: " << voltaje << "\n\n";
}
