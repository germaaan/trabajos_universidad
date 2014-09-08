// Encontrar el valor de la variable r❡s✉❧t❛❞♦ despues de la ejecucion de este codigo
//
//	real1 = 4.0;
//	real2 = 3.0;
//
//	resultado = real1/real2 - real1*real2;
//	cout << "\nResultado = " << resultado;
//
// Considerad los siguientes casos:
//
//	float real1, real2;
//	double resultado;
//
// y
//
//	float real1, real2, resultado;
//
// Nota. Si se desea ver el contenido de una variable real con "cout", es necesario que
// antes de hacerlo, se establezca el numero de decimales que se quieren mostrar en
// pantalla. Hacedlo escribiendo la sentencia "cout.precision(20)"; en cualquier 
// sitio del programa antes de la ejecucion de "cout << real1 << "," << real2;".
//
// Realizad lo mismo pero asignando los siguientes valores:
//
//	double real1, real2;
//	real1 = 1234567890.1;
//	real2 = 1234567891.2;
//
// Al multiplicar los dos "double" se obtiene un real demasiado grande (se produce un
// desbordamiento), por lo que el resultado final es un real impredecible.
// Generad otro error logico por desbordamiento en las cifras decimales.
//
// Finalidad: Trabajar con tipos distintos en una misma expresion y entender los 
// problemas de desbordamiento. Dificultad Baja.


#include <iostream>
using namespace std;

int main() {
    /*float real1,real2;
    double resultado;*/

    //float real1,real2,resultado;

    double real1, real2, resultado;

    /*real1=4.0;
    real2=3.0;*/

    real1 = 1234567890.1;
    real2 = 1234567891.2;

    //resultado = real1/real2 - real1*real2;

    resultado = real1 * real2;

    cout.precision(20);
    cout << "\nResultado = " << resultado << "\n\n";
}
