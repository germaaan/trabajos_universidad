// Cread una funcion que calcule el maximo entre tres "double". La cabecera de la 
// funcion sera la siguiente:
// 
//	double Max(double un_valor, double otro_valor, double el_tercero)
// 
// Construid un programa principal que llame a dicha funcion con los parametros actuales
// que se quiera.
//
// Finalidad: Familiarizarnos con la definicion de funciones, el paso de parametros y el
// ambito de las variables. Dificultad Baja.


#include <iostream>
using namespace std;

double Max(double un_valor, double otro_valor, double el_tercero) {
    double max;

    max = un_valor;
    if (otro_valor > max)
        max = otro_valor;
    if (el_tercero > max)
        max = el_tercero;

    return max;
}

int main() {
    double maximo;

    maximo = Max(23, 45, 3);

    cout << "El maximo es " << maximo << endl;

    cout << "\n\n";
}
