// [secuencia] Diremos que un numero entero positivo es secuenciable si se
// puede generar como suma de numeros consecutivos. Por ejemplo, 6 = 1 +
// 2 + 3, 15 = 7 + 8. Esta descomposicion no tiene por que ser unica. Por
// ejemplo, 15 = 7 + 8 = 4 + 5 + 6 = 1 + 2 + 3 + 4 + 5. Escribir un programa
// que lea un entero n y nos diga cuantas descomposiciones posibles tiene.
// Ejemplos de descomposiciones:
// 
// 	• 15 (3), 94 (1), 95 (3), 108 (3)
// 
// 	• Los unicos numeros con 0 descomposiciones son las potencias de 2.
// 
// Entrada:	15
// Salida:	RESULTADO = 3


#include <iostream>
using namespace std;

int main() {
    int entero, contadorDescomposiciones = 0;

    cin >> entero;

    for (int i = 2; i <= entero; i++) {

        if (entero % i == 0) {

            if (i % 2 != 0)
                contadorDescomposiciones++;
        }

    }

    cout << "RESULTADO = " << contadorDescomposiciones;

    cout << "\n\n";
}
