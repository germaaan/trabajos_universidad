// Para salir de una crisis economica, el gobierno decide:
//
//	• Bajar un 1 % el gravamen fiscal a los autonomos
//
//	• Para las rentas de trabajo:
//		– Subir un 6 % el gravamen fiscal a las rentas de trabajo inferiores a 20.000
//		  euros
//		– Subir un 8 % el gravamen fiscal a los casados con rentas de trabajo 
//		  superiores a 20.000 euros
//		– Subir un 10 % el gravamen fiscal a los solteros con rentas de trabajo 
//		  superiores a 20.000 euros
//
// Cread un programa que calcule el nuevo gravamen a aplicar, lo aplique a los ingresos 
// e imprima el resultado. Para ello, declarad las variables necesarias (por ejemplo
// "gravamen", "es_autonomo", etc) y asignadles los valores que se deseen directamente
// dentro del codigo (sin leerlas con "cin").
//
// Finalidad: Plantear una estructura condicional anidada. Dificultad Baja.


#include <iostream>
using namespace std;

int main() {
    bool es_autonomo = true;
    bool es_soltero = false;
    double gravamen = 30;
    double ingresos = 50000;
    double impuestos;

    cout << "Datos de la persona: \n\nGravamen actual: " << gravamen << "\nRentas de trabajo actuales: " << ingresos;

    if (es_autonomo)
        gravamen = gravamen - 1;
    else {

        if (ingresos < 20000) {
            gravamen = 6;
        } else {

            if (es_soltero) {
                gravamen = 8;
            } else
                gravamen = 10;

        }
    }

    impuestos = ingresos * gravamen / 100;

    cout << "\nRentas de trabajo despues de aplicar gravamen: " << impuestos;

    cout << "\n\n";
}
