// Queremos modificar el ejercicio 4 para leer un caracter "letra_original" desde
// teclado y hacer lo siguiente:
// 
// 	• Si es una letra mayuscula, almacenaremos en la variable "letra_convertida"
// 	  la correspondiente letra minuscula. 
// 
// 	• Si es una letra minuscula, almacenaremos en la variable "letra_convertida"
// 	  la correspondiente letra mayuscula.
// 
// 	• Si es un caracter no alfabetico, almacenaremos el mismo caracter en la variable
// 	  "letra_convertida".
// 
// Para ello, añadimos una variable nueva "es_minuscula" para detectar el caso en el
// que la letra sea una minúscula. Si escribimos el siguiente codigo
// 
// 	if ((letra_original >= 'A') && (letra_original <= 'Z')){
// 		es_mayuscula = true;
// 		es_minuscula = false;
// 	}
// 	else{
// 		es_mayuscula = false;
// 		es_minuscula = true;
// 	}
// 
// o si se prefiere, de una forma mas concisa:
// 
// 	es_mayuscula = (letra_original >= 'A') &&
// 				   (letra_original <= 'Z');
// 	es_minuscula = !es_mayuscula;
// 
// En este planteamiento hay un error logico que se comete de forma bastante habitual,
// cuando se quiere detectar mas de dos situaciones posibles. En la asignacion
// 
// 	es_minuscula = !es_mayuscula;
// 
// estamos diciendo que una minúscula es todo aquello que no sea una mayuscula.
// 
// Esto no es correcto, ya que un simbolo como # no es ni mayucula ni minuscula.
// Deberiamos haber usado lo siguiente:
// 
// 	es_mayuscula = (letra_original >= 'A') &&
// 				   (letra_original <= 'Z');
// 	es_minuscula = (letra_original >= 'a') &&
// 				   (letra_original <= 'z');
// 
// Completad el ejercicio, asignandole el valor correcto a la variable
// "letra_convertida" e imprimid en pantalla el valor de "letra_convertida".
// 
// Finalidad: Plantear una estructura condicional anidada. Dificultad Baja.


#include <iostream>
using namespace std;

int main() {
    char letra_convertida, letra_original;
    bool es_mayuscula, es_minuscula;
    const int AMPLITUD = 'a' - 'A';

    cout << "\nIntroduzca una letra --> ";
    cin >> letra_original;

    es_mayuscula = (letra_original >= 'A') && (letra_original <= 'Z');
    es_minuscula = (letra_original >= 'a') && (letra_original <= 'z');

    if (es_mayuscula) {
        letra_convertida = letra_original + AMPLITUD;
    } else {

        if (es_minuscula) {
            letra_convertida = letra_original - AMPLITUD;
        } else {
            letra_convertida = letra_original;
        }

    }

    cout << "\nEl caracter " << letra_original << " una vez convertido es: " << letra_convertida;

    cout << "\n\n";
}
