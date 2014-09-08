// Realizad el ejercicio del reparto de la ganancia de un producto, pero cambiando el tipo
// de dato de la ganancia total a "int" (el resto de variables siguen siendo "double")
//
// Finalidad: Trabajar con expresiones numericas que involucren distintos tipos de datos.
// Dificultad Baja.


#include <iostream>
using namespace std;

int main() {
    int ganancia_total;
    double ganancia;
    double ganancia_diseniador;

    cout << "Introduzca la ganancia total de la empresa: ";
    cin >> ganancia_total;

    ganancia = ganancia_total / 5;
    ganancia_diseniador = ganancia * 2;

    cout << "El diseniador tiene una ganancia de: " << ganancia_diseniador;
    cout << "\nCada fabricante tiene una ganancia de: " << ganancia << "\n\n";
}
