// [vendedores] Una empresa peque ̃na tiene tres comerciales identificados con
// los caracteres ’A’, ’B’ y ’C’. Almacena en un fichero las ventas realizadas
// durante un mes. Cada comercial realiza una serie de ventas que se almacenan 
// en una linea de enteros positivos. Supondremos que:
// 
// 	• Cada linea termina con un -1, que se considera caracter terminador y
// 	  no se tendra en cuenta en los calculos.
// 
// 	• Puede haber varias lineas por cada vendedor y no tienen por que estar
// 	  consecutivas.
// 
// 	• Cada linea corresponde a las ventas de un dia. Como un vendedor
// 	  puede estar de baja, puede que no haya ninguna linea asociada a
// 	  alguno de los vendedores.
// 	  Como un vendedor puede que no haya vendido nada, puede que haya
// 	  entradas de la forma A -1.
// 
// Se pide construir un programa que lea los datos de ventas y nos diga cual es
// el vendedor que mas ventas ha realizado y el numero total de las mismas.
// 
// Los datos se disponen de la siguiente forma: Cada linea comienza con un
// caracter que identifica al vendedor. Dicho caracter sera unos de los siguientes
// verb:’A’:, ’B’ o ’C’. A continuacion vienen una serie de enteros positivos
// correspondientes a las ventas del dia, finalizando con un -1. Los datos
// terminan con la aparicion del caracter ’@’.
// 
// En el ejemplo siguiente, aparecen las ventas de varios dias de los tres
// vendedores. Si sumamos las ventas de cada uno, observamos que el vendedor
// identificado por A, consiguio el maximo numero, con un total de 36 (7+4+25).
// 
// 				B 3 5 7 1 3 1 -1
// 				A 7 -1
// 	Entrada:	C 4 8 2 3 -1
// 				A 4 25 -1
// 				@
// 
// 	Salida:		RESULTADO = A 36


#include <iostream>
using namespace std;

int main() {
    char comercial, maxVendedor;
    int ventasA, ventasTotalesA = 0, ventasB, ventasTotalesB = 0, ventasC, ventasTotalesC = 0, maxVentas = 0;

    do {
        cin >> comercial;

        if (comercial != '@') {

            if (comercial == 'A') {
                cin >> ventasA;

                while (ventasA != -1) {
                    ventasTotalesA = ventasTotalesA + ventasA;

                    cin >> ventasA;
                }

                if (maxVentas < ventasTotalesA) {
                    maxVentas = ventasTotalesA;
                    maxVendedor = 'A';
                }

            } else {

                if (comercial == 'B') {
                    cin >> ventasB;

                    while (ventasB != -1) {
                        ventasTotalesB = ventasTotalesB + ventasB;

                        cin >> ventasB;
                    }

                    if (maxVentas < ventasTotalesB) {
                        maxVentas = ventasTotalesB;
                        maxVendedor = 'B';
                    }

                } else {
                    cin >> ventasC;

                    while (ventasC != -1) {
                        ventasTotalesC = ventasTotalesC + ventasC;

                        cin >> ventasC;
                    }

                    if (maxVentas < ventasTotalesC) {
                        maxVentas = ventasTotalesC;
                        maxVendedor = 'C';
                    }

                }

            }

        }

    } while (comercial != '@');

    cout << "RESULTADO = " << maxVendedor << " " << maxVentas;

    cout << "\n\n";
}
