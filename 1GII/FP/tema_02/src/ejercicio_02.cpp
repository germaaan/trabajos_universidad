// Cread un programa que incluya una variable "edad" en la que guardamos la edad de
// una persona (como una variable entera) y otra variable "ingresos", en la que alma-
// cenamos sus ingresos (como un real). Subid sus ingresos en un "5%" si es un jubilado
// con unos ingresos inferiores a 300 euros e imprimid el resultado por pantalla. En caso
// contrario imprimid el mensaje "No es aplicable la subida". En ambos casos
// imprimid los ingresos resultantes.
//
// Finalidad: Plantear una estructura condicional doble con una expresión lógica com-
// puesta. Dificultad Baja.


#include <iostream>
using namespace std;

int main() {
    int edad;
    double ingresos;
    bool es_aplicable;

    cout << "Introduzca edad de la persona: ";
    cin >> edad;

    cout << "Introduzca ingresos de la persona: ";
    cin >> ingresos;

    if ((edad >= 65) && (ingresos < 300)) {
        ingresos = ingresos * 1.05;
        es_aplicable = true;
    } else {
        es_aplicable = false;
    }

    if (es_aplicable)
        cout << "\nPersona jubilada con subida aplicada a ingresos. Total ingresos: " << ingresos << endl;
    else
        cout << "\nNo es aplicable subida. Total ingresos: " << ingresos << endl;

    cout << "\n\n";
}
