// Definir una funcion recursiva para sumar los digitos de un entero positivo.


#include <iostream>
using namespace std;

int SumaDigitos(int numero) {
    int resultado;

    if (numero == 0)
        resultado = numero;
    else
        resultado = SumaDigitos(numero / 10)+(numero % 10);

    return resultado;
}

int main() {
    int numero, resultado;

    do {
        cout << "Introduzca un numero entero positivo para sumar sus digitos: ";
        cin >> numero;
    } while (numero <= 0);

    resultado = SumaDigitos(numero);

    cout << "Resultado: " << resultado << endl;
}
