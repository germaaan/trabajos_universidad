// Cread sendas funciones recursivas para:
// 
// 	a) Calcular la division entera entre dos numeros enteros positivos.
// 	b) Calcular el resto de la division entera de dos numeros enteros positivos.
// 
// Pasad como parametros a cada funcion los dos enteros, y suponed que en la llamada
// siempre pasaran numeros positivos (es la precondicion de la funcion)
// 
// En la definicion de las funciones no pueden utilizarse los operadores de division, mul-
// tiplicacion ni modulo.


#include <iostream>
using namespace std;

int Division(int a, int b) {
    int resultado;

    if (a < b)
        resultado = 0;
    else
        resultado = 1 + Division(a - b, b);

    return resultado;
}

int Resto(int a, int b) {
    int resultado;

    if (a < b)
        resultado = a;
    else
        resultado = Resto(a - b, b);

    return resultado;
}

int main() {
    int dividendo, divisor, cociente, resto;

    do {
        cout << "Introduzca un numero entero positivo como dividendo: ";
        cin >> dividendo;
    } while (dividendo <= 0);

    do {
        cout << "Introduzca un numero entero positivo como divisor: ";
        cin >> divisor;
    } while (divisor <= 0);

    cociente = Division(dividendo, divisor);

    resto = Resto(dividendo, divisor);

    cout << "Valor cociente: " << cociente << endl;
    cout << "Valor resto: " << resto << endl;
}
