// [contact] La NASA ha captado una comunicacion extraterrestre compuesta
// exclusivamente de 1 y 0 que siempre termina con 5 ceros, por ejemplo
// 
// 	0 0 1 1 1 0 0 0 1 1 0 0 0 1 1 0 1 1 1 1 1 1 1 0 0 0 0 0
// 
// y se cree que esta secuencia codifica un numero cabalistico. Este numero
// estaria descompuesto en sus factores primos y cada factor apareceria en la
// secuencia como la longitud de cada secuencia concreta de valores 1. Por
// ejemplo la secuencia anterior codificaria los numeros primos 3, 2, 2 y 7,
// lo que nos da el numero cabalistico 84=3*2*2*7. Se pide construir un pro-
// grama que lea la secuencia de numeros y determine el numero cabalistico
// oculto.
// 
// 	Entrada:	0 0 1 1 1 0 0 0 1 1 0 0 0 1 1 0 1 1 1 1 1 1 1 0 0 0 0 0
// 	Salida:		RESULTADO = 84


#include <iostream>
using namespace std;

int main() {
    int valorLeido, numeroCabalistico = 1, contCeros = 0, contUnos = 0;

    do {
        cin >> valorLeido;

        if (valorLeido == 0) {
            if (contUnos > 0)
                numeroCabalistico = numeroCabalistico * contUnos;
            contUnos = 0;
            contCeros++;
        } else {
            contCeros = 0;
            contUnos++;
        }
    } while (contCeros < 5);

    cout << "RESULTADO = " << numeroCabalistico;

    cout << "\n\n";
}
