// Cread una funcion para calcular la suma de una progresion geometrica, tal y como
// se vio en el ejercicio 19 de la relacion de problemas II. Analizad cuales deben ser los
// parametros de dicha funcion.
//
// Finalidad: Diseño de una funcion sencilla. Dificultad Baja


#include <iostream>
#include <cmath>
using namespace std;

float CalculaProgresion(float a1, float razon, int numTerminos) {

    int n = 5;
    float total = a1;

    for (int i = 2; i <= numTerminos; i++) {
        total = total + a1 * pow(razon, i - 1);
    }

    return total;
}

int main() {

    float total = CalculaProgresion(2, 1.5, 5);

    cout << "Total sumatoria de la progresion: " << total;

    cout << "\n\n";
}
