// Definir una funcion recursiva a la que se le pasen dos valores enteros n y k y 
// devuelva como resultado el valor k-esimo comenzando por la derecha del numero n. Por
// ejemplo para n = 427 y k = 3 el resultado seria 4.
// 
// Si k es mayor que el numero de digitos de n la funcion devolvera el valor 0. Por
// ejemplo, para n = 23 y k = 5 el resultado es 0.


#include <iostream>
using namespace std;

int digitokaesimo(int n, int k) {
    int digito;

    if ((k == 1) && (n > 9))
        digito = n % 10;
    else if ((k == 1) && (n < 10))
        digito = n;
    else if ((k > 1) && (n < 10))
        digito = 0;
    else
        digito = digitokaesimo(n / 10, k - 1);

    return digito;
}

int main() {
    int n, k, resultado;

    do {
        cout << "Introduzca el valor de n: ";
        cin >> n;
    } while (n <= 0);

    do {
        cout << "Introduzca el valor de k: ";
        cin >> k;
    } while (k <= 0);

    resultado = digitokaesimo(n, k);

    cout << "El valor k-esimo de n es: " << resultado << endl;
}
