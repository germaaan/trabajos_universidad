// Definid una funcion recursiva con prototipo
// 
//	int MCD(int un_entero, int otro_entero)
//
// para que calcule el maximo comun divisor entre dos enteros, aplicando el algoritmo
// de Euclides.


#include <iostream>
using namespace std;

int MCD(int un_entero, int otro_entero) {
    int resultado;

    if (un_entero == otro_entero)
        resultado = un_entero;
    else {

        if (un_entero > otro_entero)
            resultado = MCD(otro_entero, un_entero - otro_entero);
        else
            resultado = MCD(un_entero, otro_entero - un_entero);
    }

    return resultado;
}

int main() {
    int a, b, resultado;

    cout << "Calcular Maximo Comun Divisor de dos numeros aplicando el algoritmo de Euclides: " << endl;

    cout << "Introduzca el primer numero: ";
    cin >> a;

    cout << "Introduzca el segundo numero: ";
    cin >> b;

    resultado = MCD(a, b);

    cout << "Resultado: " << resultado << endl;
}
