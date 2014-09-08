// [polidivisible] Supongamos un numero entero positivo n cuyos digitos son
// abcde..... Por ejemplo el entero 1632 tendria como digitos a=1, b=6,
// c=3, d=2. Diremos que es un entero polidivisible si verifica las siguientes
// propiedades:
// 	
// 	• Si es un entero de una sola cifra, como por ejemplo el 7, es polidivisible
//    El cero no es polidivisible.
// 	
// 	• El numero formado por sus dos primeros digitos ab es multiplo de 2.
// 	
// 	• El numero formado por sus tres primeros digitos abc es multiplo de
// 	  3.
// 	
// 	• Y asi sucesivamente hasta que se acaben los digitos.
// 	
// Por ejemplo, el numero 345654 es un numero polidivisible, pero 123456 no
// lo es, porque 1234 no es multiplo de 4.
// 	
// 	• Ejemplos de numeros polidivisibles: 1, 7, 10, 102, 6064
//
// 	• Ejemplos de numeros no polidivisibles: 41, 265, 38164
// 	
// Se pide lo siguiente:
// 	
// 	• Leer el entero n (supondremos que los valores leidos caben en un tipo
// 	  int).
// 	
// 	• Comprobar si es polidivisible.
// 	
// 	• El programa mostrara alguna de las siguientes salidas, dependiendo de
// 	  si es o no es polidivisible:
// 	
// 	Entrada:	10					Entrada: 	41
// 	Salida:		RESULTADO = SI		Salida: 	RESULTADO = NO


#include <iostream>
using namespace std;

int main() {
    int entero, copiaEntero, numDigitos = 2;
    bool esPolidivisible = true;

    cin >> entero;

    if (entero == 0) {
        esPolidivisible = false;
    } else {

        if (entero >= 10) {

            copiaEntero = entero;

            while (copiaEntero >= 100) {
                copiaEntero = copiaEntero / 10;
                numDigitos++;
            }

            while (esPolidivisible && numDigitos >= 2) {

                if (entero % numDigitos != 0)
                    esPolidivisible = false;
                else {
                    numDigitos--;
                    entero = entero / 10;
                }

            }

        }

    }

    if (esPolidivisible)
        cout << "RESULTADO = SI" << endl;
    else
        cout << "RESULTADO = NO" << endl;

    cout << "\n\n";
}
