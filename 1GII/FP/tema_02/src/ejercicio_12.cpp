// Modifiquemos el ejercicio 2 del capital y los intereses de la primera relacion. 
// Supongamos ahora que se quiere reinvertir todo el dinero obtenido (el original C mas los
// intereses producidos) en otro plazo fijo a un año. Construid un programa para que
// lea el capital, el interes y un numero de años N , y calcule e imprima todo el dinero
// obtenido durante cada uno de los N años, suponiendo que todo lo ganado (incluido el
// capital original C) se reinvierte a plazo fijo durante el siguiente año. El programa debe
// mostrar una salida del tipo:
// 
// 	Capital en el año numero 1 = 240
// 	Capital en el año numero 2 = 288
// 	Capital en el año numero 3 = 345.6
// 	....................................
//
// Finalidad: Usar una variable acumuladora dentro del cuerpo de un bucle (aparecera a
// la izquierda y a la derecha de una asignacion). Dificultad Baja.


#include <iostream>
using namespace std;

int main() {
    double capital, interes;
    int anios, contador = 1;

    cout << "Introduzca la cantidad en euros a depositar: ";
    cin >> capital;
    cout << "Introduzca porcentaje de interes a aplicar: ";
    cin >> interes;
    cout << "Introduzca el numero de años de la inversion a plazo fijo: ";
    cin >> anios;

    while (contador <= anios) {
        capital = capital + capital * (interes / 100);
        cout << "\nCapital en el año numero " << contador << " = " << capital;
        contador++;
    }

    cout << "\n\n";
}
