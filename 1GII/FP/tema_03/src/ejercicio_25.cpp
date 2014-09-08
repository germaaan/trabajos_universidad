// En el ejercicio 5 de la relacion de problemas I se vio como obtener el valor de ordenada
// asignado por la funcion gaussiana, sabiendo el valor de abscisa x. Recordemos que
// esta funcion matematica dependia de dos parametros μ (esperanza) y σ (desviacion),
// y venia definida por:
// 
// 	gaussiana(x) = (1 / (σ * √(2 * π))) * (e ^ ((-1/2) * (((x - μ) / σ)²)))
// 
// Podriamos definir una funcion en C++ que me permitiese evaluar la funcion en cualquier
// valor de x con la siguiente cabecera:
//
// 	double Gaussiana (double esperanza, double desviacion, double x)
//
// Tambien podriamos estar interesados en obtener el area que cubre la funcion en el
// intervalo [−∞, x]. Dicho valor se conoce como la distribucion acumulada en el punto
// x, abreviado CDF(x) (cumulative distribution function). Matematicamente se calcula
// realizando la integral ∫−∞ x gaussiana(x)dx, aunque tambien pueden obtenerse apro-
// ximaciones como por ejemplo la dada por la siguiente formula (ver Wikipedia: Normal
// distribution)
//
// 	area hasta (x) ≈ 1 − gaussiana(x)(b1*t + b2*t² + b3*t³ + b4*t⁴)
//
// donde:
// 
//	t = 1/(1 + b0*x)	b0 = 0,2316419		b1 = 0,319381530	b2 = −0,356563782
//	b3 = 1,781477937 	b4 = −1,821255978 	b5 = 1,330274429
//
// Para implementarlo, podriamos definir la funcion siguiente:
//
// 	double AreaHasta (double esperanza, double desviacion, double x)
// 
// En vez de trabajar con funciones, planteamos la solucion con una clase. La clase se
// llamara "Gaussiana" y crearemos objetos pasandole en el constructor la esperanza
// y la distribucion (los parametros que definen la gaussiana). Le añadiremos metodos
// para:
//
// 	• Obtener el valor de la funcion en un punto x cualquiera.
//	• Obtener el area hasta un punto x cualquiera.
//
// Ejecutad el applet disponible en:
// http://dostat.stat.sc.edu/prototype/calculators/index.php3?dist=Normal
// Dificultad Media.


#include <iostream>
#include <cmath>
using namespace std;

class Gaussiana {
private:
    double esperanza;
    double desviacion;
public:

    Gaussiana(double mu, double sigma)
    : esperanza(mu),
    desviacion(sigma) {
    }

    double ValorGaussiana(double x) {
        double y = exp((-pow((x - esperanza) / desviacion, 2) / 2) / (desviacion * sqrt(2 * 3.1415)));

        return y;
    }

    double AreaHasta(double x) {
        double t, cdf;
        const double b0 = 0.2316419, b1 = 0.319381530, b2 = -0.356563782, b3 = 1.781477937, b4 = -1.821255978, b5 = 1.330274429;

        t = 1 / (1 + b0 * x);

        cdf = 1 - ValorGaussiana(x)*((b1 * t)+(b2 * t * t)+(b3 * pow(t, 3))+(b4 * pow(t, 4)+(b5 * pow(t, 5))));

        return cdf;
    }
};

int main() {
    double mu, sigma, x, valorPunto, valorArea;

    cout << "Introduzca el coeficiente real esperanza o media (mu): ";
    cin >> mu;
    cout << "Introduzca el coeficiente real desviacion tipica (sigma): ";
    cin >> sigma;
    cout << "Introduzca el valor de abscisa (x): ";
    cin >> x;

    Gaussiana gaussiana(mu, sigma);

    valorPunto = gaussiana.ValorGaussiana(x);
    valorArea = gaussiana.AreaHasta(x);

    cout << "\nEl valor de la funcion en un punto " << x << " es " << valorPunto << endl;
    cout << "El area hasta un punto " << x << " es " << valorArea << endl;

    cout << "\n\n";
}
