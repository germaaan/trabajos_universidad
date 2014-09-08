// Se quiere leer un caracter "letra_original" desde teclado, y comprobar con una
// estructura condicional si es una letra mayuscula. En dicho caso, hay que 
// calcular la minuscula correspondiente en una variable llamada "letra_convertida".
// En cualquier otro caso, le asignaremos a "letra_convertida" el valor que
// tenga "letra_original". Finalmente, imprimiremos en pantalla el valor de
// "letra_convertida". No pueden usarse las funciones "tolower" ni "toupper" de la
// biblioteca "cctype".
//
// Se propone una primera solucion como sigue:
// 
//	char letra_convertida, letra_original;
//	const int AMPLITUD = 'a'-'A';
//
//	cout << "\nIntroduzca una letra  --> ";
//	cin >> letra_original;
// 
//	if ((letra_original >= 'A') && (letra_original <= 'Z')){
//		letra_convertida = letra_original + AMPLITUD;
//		cout << letra_convertida;
//	}
//	else{
//		cout << letra_original << " no es mayuscula";
//	}
//
// El problema es que dentro de la misma sentencia condicional se realizan computos
// (letra_convertida = letra_original + AMPLITUD) y salidas de resultados
// en pantalla (cout << letra_convertida;). Para evitarlo, se propone el uso de
// una variable logica llamada "es_mayuscula", de la siguiente forma:
//
//	if ((letra_original >= 'A') && (letra_original <= 'Z'))
//		es_mayuscula = true;
//
//	if (es_mayuscula)
//		letra_convertida = letra_original + AMPLITUD;
//	else
//		letra_convertida = letra_original;
//
//	cout << "\nEl caracter " << letra_original
//		 << " una vez convertido es: " << letra_convertida;
//
// Sin embargo, hay un error logico ya que la variable "es_mayuscula" se podria quedar
// sin un valor asignado (en el caso de que la expresion logica fuese false) El compilador
// lo detecta y da el aviso al inicio de la sentencia "if(es_mayuscula)". Comprobadlo
// para familiarizarnos con este tipo de avisos y proponer una solucion.
//
// Moraleja: Hay que garantizar la asignacion de las variables logicas, en todos los
// casos posibles.
//
// Finalidad: Plantear una condicion compuesta y destacar la importancia de incluir un
// bloque "else", para garantizar que siempre se ejecuta el codigo adecuado, en todas
// las situaciones posibles. Dificultad Baja.


#include <iostream>
using namespace std;

int main() {
    char letra_convertida, letra_original;
    bool es_mayuscula;
    const int AMPLITUD = 'a' - 'A';

    cout << "\nIntroduzca una letra --> ";
    cin >> letra_original;

    if ((letra_original >= 'A') && (letra_original <= 'Z'))
        es_mayuscula = true;
    else
        es_mayuscula = false;

    if (es_mayuscula)
        letra_convertida = letra_original + AMPLITUD;
    else
        letra_convertida = letra_original;

    cout << "\nEl caracter " << letra_original << " una vez convertido es: " << letra_convertida;

    cout << "\n\n";
}
