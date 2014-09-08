// En el ejercicio 6 se han usado dos variables logicas ("es_mayuscula",
// "es_minuscula"), que nos proporciona la distincion entre 4 casos distintos
// "VV, VF, FV, FF"). Sin embargo, solo queremos distinguir tres posibilidades, a 
// saber, es mayuscula, es minuscula y no es un caracter alfabetico. Para ello, volved a
// resolver el ejercicio 6 sustituyendo las dos variables logicas por un tipo enumerado
// adecuado.
//
// Finalidad: Usar el tipo enumerado para detectar cuando se produce una situacion
// determinada. Dificultad Media.

#include <iostream>
using namespace std;

int main() {
    char letra_convertida, letra_original;

    enum TipoLetras {
        mayuscula = 1, minuscula = 2, no_letra = 3
    };
    TipoLetras dimension_letra;
    const int AMPLITUD = 'a' - 'A';

    cout << "\nIntroduzca una letra --> ";
    cin >> letra_original;

    if ((letra_original >= 'A') && (letra_original <= 'Z'))
        dimension_letra = mayuscula;
    else {

        if ((letra_original >= 'a') && (letra_original <= 'z')) {
            dimension_letra = minuscula;
        } else {
            dimension_letra = no_letra;
        }

    }

    if (dimension_letra == 1) {
        letra_convertida = letra_original + AMPLITUD;
    } else {

        if (dimension_letra == 2) {
            letra_convertida = letra_original - AMPLITUD;
        } else {
            letra_convertida = letra_original;
        }

    }

    cout << "\nEl caracter " << letra_original << " una vez convertido es: " << letra_convertida;

    cout << "\n\n";
}
