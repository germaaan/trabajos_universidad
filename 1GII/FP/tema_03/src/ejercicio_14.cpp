// Se quiere construir una clase para realizar la funcionalidad descrita en el ejercicio 10
// de la relacion de problemas I sobre la nomina del fabricante y diseñador (pagina 15).
// La clase debe proporcionar, al menos, los metodos SalarioNetoDisenador y
// SalarioNetoFabricante. El criterio del calculo del salario es el mismo (el dise-
// ñador cobre el doble de cada fabricante) pero ademas, ahora se le va a aplicar una
// retencion fiscal para el computo de los salarios netos. Dicha retencion sera la misma
// tanto para el fabricante como para el diseñador.
// 
// Analizad las siguientes posibilidades y elegid la que crea mas adecuada, justificandolo:
// 
// 	a) Creamos un dato miembro para almacenar el valor de retencion fiscal y pasamos
// 	   su valor en el constructor.
// 
// 	b) Creamos un dato miembro para almacenar su valor y ademas proporcionamos
// 	   un metodo para su modificacion.
// 
// Finalidad: Trabajar con datos miembro constantes. Dificultad Baja.


#include <iostream>
using namespace std;

class CalculaGanancias {
private:
    const double RETENCION_FISCAL;
    double salarioBrutoFabricante;
    double salarioBrutoDisenador;

public:

    CalculaGanancias(double retencion, double importeGanancia)
    : RETENCION_FISCAL(retencion) {
        SetIngresosTotales(importeGanancia);
    }

    void SetIngresosTotales(double ingresos_totales) {
        salarioBrutoFabricante = ingresos_totales / 5.0;
        salarioBrutoDisenador = salarioBrutoFabricante * 2;
    }

    double SalarioNetoDisenador() {
        double salarioNetoDisenador = salarioBrutoDisenador - salarioBrutoDisenador * (RETENCION_FISCAL / 100);

        return salarioNetoDisenador;
    }

    double SalarioNetoFabricante() {
        double salarioNetoFabricante = salarioBrutoFabricante - salarioBrutoFabricante * (RETENCION_FISCAL / 100);

        return salarioNetoFabricante;
    }
};

int main() {
    double gananciaTotal, salarioDisenador, salarioFabricante;
    int retencion;

    do {
        cout << "Introduzca la ganancia total: ";
        cin >> gananciaTotal;
    } while (gananciaTotal <= 0);

    do {
        cout << "Introduzca la retencion fiscal a aplicar: ";
        cin >> retencion;
    } while (retencion <= 0);

    CalculaGanancias calculadora(retencion, gananciaTotal);

    salarioDisenador = calculadora.SalarioNetoDisenador();
    salarioFabricante = calculadora.SalarioNetoFabricante();

    cout << "\nEl salario neto del diseñador es: " << salarioDisenador << endl;
    cout << "El salario neto del fabricante es: " << salarioFabricante << endl;

    cout << "\n\n";
}
