// Todo lo que se puede hacer con un bucle "while" se puede hacer con un "do while".
// Lo mismo ocurre al reves. Sin embargo, cada bucle se usa de forma natural en ciertas
// situaciones. El no hacerlo, nos obligara a escribir mas codigo y este sera mas dificil
// de entender. Para comprobarlo, haced lo siguiente:
// 
// b) Modificad la solucion del ejercicio 12 sustituyendo el bucle "while" por un
// "do while". Observad que debemos considerar el caso en el que el numero de
// años leido N_Anios fuese cero.


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

    if (anios > 0) {
        do {
            capital = capital + capital * (interes / 100);
            cout << "\nCapital en el año numero " << contador << " = " << capital;
            contador++;
        } while (contador <= anios);
    }

    cout << "\n\n";
}
