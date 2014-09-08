// Se quiere construir una clase "DepositoSimulacion" para simular prestamos, ofreciendo
// la funcionalidad descrita en los ejercicios 12 (reinvierte capital e interes un
// numero de años) y 13 (reinvierte capital e interes hasta obtener el doble de la canti-
// dad inicial) de la relacion de problemas II. Por tanto, la clase debe proporcionar, para
// un capital y unos intereses dados, metodos para:
//
//	• calcular el capital que se obtendra al cabo de un numero de años,
//
//	• calcular el numero de años que deben pasar hasta obtener el doble de la cantidad
//	  inicial.
//
// A la hora de diseñar la clase, tendremos que analizar cuestiones como:
//
//	a) Si queremos modificar el capital y el interes una vez creado el objeto,
//
//	b) Si queremos poder modificarlos de forma independiente,
//
//	c) Si hay alguna restriccion a la hora de asignar un valor al capital e interes,
//
//	d) Si es mejor un metodo para calcular el numero de años hasta obtener el doble de
//	   la cantidad inicial, o por el contrario es mejor un metodo para calcular el numero
//	   de años hasta obtener una cantidad especifica.
//
// Finalidad: Diseñar la interfaz de una clase. Dificultad Baja.


#include <iostream>
using namespace std;

class DepositoSimulacion {
private:
    double capital;
    double interes;

public:

    DepositoSimulacion(){
		capital = 0;
		interes = 0;
    }

    void setCapital(double cantidadDinero) {
        if (cantidadDinero >= 0)
            capital = cantidadDinero;
        else
            capital = 0;
    }

    void setInteres(double porcentajeInteres) {
        if (porcentajeInteres >= 0)
            interes = porcentajeInteres;
        else
            interes = 0;
    }

    double CapitalTotalAnios(int numAnios) {
        double capitalTotal = capital;

        for (int i = 1; i < numAnios; i++)
            capitalTotal = capitalTotal + capitalTotal * (interes / 100);

        return capitalTotal;
    }

    int AniosDoblarCapital() {
        double capitalTotal = capital;
        int anios = 0;

        while (capitalTotal < (capital * 2)) {
            capitalTotal = capitalTotal + capitalTotal * (interes / 100);
            anios++;
        }

        return anios;
    }
};

int main() {
    DepositoSimulacion banco;
    double cantidadDinero, capitalTotal;
    int porcentajeInteres, aniosAplicar, aniosDoblar;

    do {
        cout << "Introduzca un importe positivo para el capital a depositar: ";
        cin >> cantidadDinero;
    } while (cantidadDinero <= 0);

    do {
        cout << "Introduzca un porcentaje positivo para el interes a aplicar: ";
        cin >> porcentajeInteres;
    } while (porcentajeInteres <= 0);

    banco.setCapital(cantidadDinero);
    banco.setInteres(porcentajeInteres);

    do {
        cout << "Introduzca un numero de años positivo durante los que aplicar los interes: ";
        cin >> aniosAplicar;
    } while (aniosAplicar <= 0);

    capitalTotal = banco.CapitalTotalAnios(aniosAplicar);

    aniosDoblar = banco.AniosDoblarCapital();

    cout << "\nCapital total acumulado: " << capitalTotal << endl;
    cout << "Años necesarios para doblar el capital: " << aniosDoblar << endl;

    cout << "\n";
}
