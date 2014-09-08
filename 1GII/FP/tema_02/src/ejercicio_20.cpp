// Diseñar un programa para calcular la suma de los 100 primeros terminos de la
// sucesion siguiente:
// 
// ai = ((-1)^i * (i² - 1)) / 2 * i
// 
// No puede usarse la funcion "pow". Hacedlo calculando explicitamente, en cada iteracion, 
// el valor (−1) i (usad un bucle "for"). Posteriormente, resolvedlo calculando dicho
// valor a partir del calculado en la iteracion anterior, es decir, (−1) i−1 .
//
// Finalidad: Enfatizar la conveniencia de aprovechar computos realizados en la iteracion
// anterior. Dificultad Media.


#include <iostream>
using namespace std;

int main() {
    int base = -1;
    int potenciaAcumulada;
    float termino, sumaSerie;

    sumaSerie = 0;
    for (int i = 1; i <= 100; i++) {
        potenciaAcumulada = 1;
        for (int j = 1; j <= i; j++) //calculo de (-1)^i
            potenciaAcumulada = potenciaAcumulada * base;
        termino = potenciaAcumulada * (i * i - 1) / (2.0 * i); // (-1)^i * (i^2-1)/ 2i
        sumaSerie = sumaSerie + termino;
    }

    cout << "La suma de los 100 primeros terminos de la serie es: " << sumaSerie << endl;

    cout << "\n\n";

    //metodo alternativo aprovechando calculos de iteraciones anteriores
    sumaSerie = 0;
    potenciaAcumulada = 1;
    for (int i = 1; i <= 100; i++) {
        potenciaAcumulada = -1 * potenciaAcumulada; // -1 en la 1ª it., 1 en la 2ª it., ....
        termino = potenciaAcumulada * (i * i - 1) / (2.0 * i); // (-1)^i * (i^2-1)/ 2i
        sumaSerie = sumaSerie + termino;
    }

    cout << "La suma de los 100 primeros terminos de la serie es: " << sumaSerie << endl;

    cout << "\n\n";
}
