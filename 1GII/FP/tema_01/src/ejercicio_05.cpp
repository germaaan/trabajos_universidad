// Realizar un programa que lea los coeficientes reales μ y σ de una funcion gaussiana
// (ver definicion abajo). A continuacion el programa leera un valor de abscisa x y se
// imprimira el valor que toma la funcion en x
// 
// 	gaussiana(x) = (1 / (σ * √(2 * π))) * (e ^ ((-1/2) * (((x - μ) / σ)²)))
// 
// El parametro μ se conoce como esperanza o media y σ como desviacion tipica (mean
// y standard deviation en ingles). Para definir la funcion matematica e usad la funcion
// "exp" de la biblioteca "cmath". En la misma biblioteca esta la funcion "sqrt" para calcular
// la raiz cuadrada. Para elevar un numero al cuadrado se puede usar la funcion "pow",
// que se utiliza en la siguiente forma:
// 
// pow(base, exponente)
//
// En nuestro caso, el exponente es 2 y la base ((x - μ) / σ). Comprobad que los resultados son
// correctos, usando el applet disponible en 
// http://www.danielsoper.com/statcalc/calc54.aspx
// o bien algunos de los ejemplos de la figura siguiente (observad que el valor de la
// desviacion esta elevado al cuadrado):
//
// Finalidad: Trabajar con expresiones numericas mas complejas. Dificultad Baja.


#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double sigma;
    double mu;
    double x;
    double y;

    cout << "Introduzca el coeficiente real esperanza o media (mu): ";
    cin >> mu;
    cout << "Introduzca el coeficiente real desviacion tipica (sigma): ";
    cin >> sigma;
    cout << "Introduzca el valor de abscisa (x): ";
    cin >> x;

    y = exp((-pow((x - mu) / sigma, 2) / 2) / (sigma * sqrt(2 * 3.1415)));

    cout << "\nEl valor que toma la funcion en la abscisa es: " << y << "\n\n";
}
