// Sobre el mismo ejercicio del capital y los intereses, construid un programa para 
// calcular cuantos años han de pasar hasta llegar a doblar, como minimo, el capital inicial.
// Los datos que han de leerse desde teclado son el capital inicial y el interes anual.
//
// Finalidad: Usar la variable acumuladora en la misma condicion del bucle. Dificultad
// Baja.


#include <iostream>
using namespace std;

int main() {
    double capital, capital_objetivo, interes;
    int contador = 0;

    cout << "Introduzca la cantidad en euros a depositar: ";
    cin >> capital;
    cout << "Introduzca porcentaje de interes a aplicar: ";
    cin >> interes;

    capital_objetivo = capital * 2;

    while (capital < capital_objetivo) {
        capital = capital + capital * (interes / 100);
        contador++;
        cout << "\nCapital en el año numero " << contador << " = " << capital;
    }

    cout << "\n\nNumero de años necesarios para que se doble el capital invertido: " << contador;

    cout << "\n\n";
}
