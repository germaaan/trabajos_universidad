// Las ganancias de un determinado producto se reparten entre el dise�ador y los tres
// fabricantes del mismo. Diseñar un programa que pida la ganancia total de la empresa
// (los ingresos realizados con la venta del producto) y diga cuanto cobran cada uno de
// ellos, sabiendo que el diseñador cobra el doble que cada uno de los fabricantes. El
// dato de entrada sera la ganancia total a repartir. Utilizad el tipo "double" para todas las
// variables.
//
// Importante: No repetid calculos ya realizados.
//
// Finalidad: Entender la importancia de no repetir computos para evitar errores de pro-
// gramacion. Dificultad Baja.


#include <iostream>
using namespace std;

int main() {
    double ganancia_total;
    double ganancia;
    double ganancia_diseniador;

    cout << "Introduzca la ganancia total de la empresa: ";
    cin >> ganancia_total;

    ganancia = ganancia_total / 5;
    ganancia_diseniador = ganancia * 2;

    cout << "El diseniador tiene una ganancia de: " << ganancia_diseniador;
    cout << "\nCada fabricante tiene una ganancia de: " << ganancia << "\n\n";
}
