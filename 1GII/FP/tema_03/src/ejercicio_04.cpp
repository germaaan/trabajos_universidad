// Se pide definir las siguientes funciones y cread un programa principal de ejemplo que
// las llame:
//
// 	a) "EsMinuscula" comprueba si un caracter pasado como parametro es una
//	   minuscula. A dicho parametro, llamadlo "una_letra".
// 
//	b) "Convierte_a_Mayuscula" comprueba si un caracter pasado como parametro
//	   es minuscula (para ello, debe llamar a la funcion anterior), en cuyo caso lo
//	   transforma a mayuscula. Si el caracter no es minuscula debe dejar la letra igual. 
//	   A dicho parametro, llamadlo "caracter".
//	   Esta funcion hace lo mismo que la funcion "tolower" de la biblioteca "cctype"
//
// Observad que el parametro "una_letra" de la funcion "EsMinuscula" podria llamarse
// igual que el parametro "caracter" de la otra funcion. Esto es porque estan en ambitos
// distintos y para el compilador son dos variables distintas. Haced el cambio y 
// comprobarlo.
// 
// Finalidad: Entender el ambito de los parametros de las funciones, asi como las llama-
// das entre funciones. Dificultad Baja.


#include <iostream>
using namespace std;

bool EsMinuscula(char letra) {
    bool esMinuscula;
    if (letra >= 'a' && letra <= 'z')
        esMinuscula = true;
    else
        esMinuscula = false;

    return esMinuscula;
}

char Convierte_a_Mayuscula(char letra) {
    const int amplitud = ('a' - 'A');
    if (EsMinuscula(letra))
        letra = letra - amplitud;

    return letra;
}

int main() {

    char primerIntento;
    char segundoIntento;
    char letra = 'f';

    primerIntento = Convierte_a_Mayuscula(letra);

    cout << " caracter original: " << letra << " caracter convertido " << primerIntento << endl;

    cout << "\n\n";
}
