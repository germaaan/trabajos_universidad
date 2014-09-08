// Calcular mediante un programa en C++ la función potencia x^n , la función factorial n! y
// el combinatorio (n m) con n, m valores enteros y x un valor real. No pueden usarse
// las funciones de la biblioteca "cmath".
//
// El factorial de un entero n se define de la forma siguiente:
// 
// 	0! = 1
//	n! = 1 × 2 × 3 × · · · n, ∀n ≥ 1
//
// El combinatorio de n sobre m (con n ≥ m) es un número entero que se define como
// sigue:
// 
// (n m) = n! / (m! * (n - m)!)
//
// Finalidad: Trabajar con bucles controlados por contador. Dificultad Media.


#include <iostream>
using namespace std;

int main() {
    int n, m, factorial_n = 1, factorial_m = 1, factorial_resta = 1, contador;
    double x, potencia, combinatorio;

    cout << "Introduzca un valor entero para 'n': ";
    cin >> n;
    do {
        cout << "Introduzca un valor entero para 'm' menor o igual que el de 'n': ";
        cin >> m;
    } while (m > n);
    cout << "Introduzca un valor real para 'x': ";
    cin >> x;

    potencia = x;

    for (contador = 1; contador < n; contador++) {
        potencia = potencia * x;
    }

    if (n != 0) {
        for (contador = 1; contador <= n; contador++) {
            factorial_n = factorial_n * contador;
        }
    }

    if (m != 0) {
        for (contador = 2; contador <= m; contador++) {
            factorial_m = factorial_m * contador;
        }
    }

    if (n - m != 0) {
        for (contador = 2; contador <= n - m; contador++) {
            factorial_resta = factorial_resta * contador;
        }
    }

    combinatorio = factorial_n / (factorial_m * factorial_resta);

    cout << "\nPotencia de " << x << " elevado a " << n << " es " << potencia;
    cout << "\nFactorial de " << n << " es " << factorial_n;
    cout << "\nCombinatorio de " << n << " sobre " << m << " es " << combinatorio;

    cout << "\n\n";
}
