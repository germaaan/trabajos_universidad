// [ondulado] Diremos que un entero positivo es ondulado si sus digitos se
// van repitiendo en la forma ababab.... Solo hay dos digitos (a y b) que
// se repiten. Casos especiales:
// 	
//	• Todos los enteros menores estrictos que 100 son ondulados.
// 	
//	• Los enteros de la forma ababa son ondulados. Es decir, lo importante
// 	  es que se vayan alternando los dos digitos.
// 	
// Ejemplos:
// 	
// 	• Ejemplos de numeros ondulados: 2, 82, 737, 1010, 10101, 222, 5555
// 	
// 	• Ejemplos de numeros no ondulados: 1987, 827, 827827, 1001, 955
// 	
// Se pide lo siguiente:
// 	
// 	• Leer un valor entero n que representara el valor que queremos
//    comprobar si es ondulado o no.
// 	
// 	• El programa mostrara alguna de las siguientes salidas, dependiendo de
// 	  si es o no es ondulado:
// 	
// Entrada: 1010
// Salida:	RESULTADO = SI
// 	
// Entrada: 827
// Salida: RESULTADO = NO


#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int entero, copiaEntero, digitoA, digitoB, comprobadorDigitoA = 0, comprobadorDigitoB = 0, numDigitos = 2;
    bool esOndulado = true;

    cin >> entero;

    if (entero >= 100) {
        copiaEntero = entero;

        while (copiaEntero >= 100) {
            copiaEntero = copiaEntero / 10;
            numDigitos++;
        }

        if (numDigitos % 2 == 0) {
            digitoA = (entero % 100) / 10;
            digitoB = entero % 10;

            entero = entero / 100;
        } else {
            digitoA = entero % 10;
            digitoB = (entero % 100) / 10;

            entero = entero / 10;
        }

        while (esOndulado && (entero >= 10)) {
            comprobadorDigitoA = (entero % 100) / 10;
            comprobadorDigitoB = entero % 10;
            entero = entero / 100;

            if ((comprobadorDigitoA != digitoA) || (comprobadorDigitoB != digitoB))
                esOndulado = false;

        }

    }

    if (esOndulado)
        cout << "RESULTADO = SI";
    else
        cout << "RESULTADO = NO";

    cout << "\n\n";
}
