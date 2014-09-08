// [ruso] El algoritmo de la multiplicacion rusa es una forma distinta de calcular
// la multiplicacion de dos numeros enteros n ∗ m. Para ello este algoritmo
// va multiplicando por 2 el multiplicador m y dividiendo (sin decimales) por
// dos el multiplicando n hasta que n tome el valor 1 y suma todos aquellos
// multiplicadores cuyos multiplicandos sean impares. Por ejemplo, para
// multiplicar 37 y 12 se harian las siguientes iteraciones
// 	
// 	Iteracion	Multiplicando	Multiplicador
// 		1			37				12
// 		2			18				24
// 		3			9				48
// 		4			4				96
// 		5			2				192
// 		6			1				384
// 	
// Con lo que el resultado de multiplicar 37 y 12 seria la suma de los multiplicadores
// correspondientes a los multiplicandos impares (en negrita), es decir
// 	
// 	37*12=12+48+384=444
// 	
// 	Entrada: 	37 12
// 	Salida: 	RESULTADO = 444


#include <iostream>
using namespace std;

int main() {
    int multiplicando, multiplicador, valorMultiplicacion = 0;

    cin >> multiplicando;
    cin >> multiplicador;

    do {
        if (multiplicando % 2 != 0)
            valorMultiplicacion = valorMultiplicacion + multiplicador;

        multiplicador = multiplicador * 2;
        multiplicando = multiplicando / 2;
    } while (multiplicando >= 1);

    cout << "RESULTADO = " << valorMultiplicacion;

    cout << "\n\n";
}
