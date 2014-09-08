//	• Reescribid la solucion al ejercicio 10 de la sesion anterior, usando un bucle "for".
//	• Reescribid la solucion al ejercicio 12 usando un bucle "for".
// Finalidad: Familiarizarnos con la sintaxis de los bucles "for". Dificultad Baja.


#include <iostream>
using namespace std;

int main() {

    //version 2 del ejercicio 10
    //mostrar todos los divisores menores que el numero leido por la entrada
    int divisor;
    int tope;

    do {
        cout << "Dame un positivo " << endl;
        cin >> tope;
    } while (tope <= 0);

    for (divisor = tope - 1; divisor > 0; divisor--)
        if (tope % divisor == 0)
            cout << "Divisor: " << divisor << endl;

    cout << "\n\n";

    //version 2 del ejercicio 12
    float capital, interes;
    int contador, anios;

    cout << "Dame el capital " << endl;
    cin >> capital;
    cout << "Dame el interes " << endl;
    cin >> interes;
    cout << "Dame el número de años " << endl;
    cin >> anios;

    for (contador = 0; contador < anios; contador++) {
        capital = capital + capital * interes / 100.0;
        cout << "Capital para el año " << contador << ": " << capital << endl;
    }

    cout << "\n\n";
}
