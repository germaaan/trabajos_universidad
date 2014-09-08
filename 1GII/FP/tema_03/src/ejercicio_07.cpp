// Vamos a añadir una funcion al ejercicio 4 de esta relacion de problemas. Se pide
// implementar la funcion "Transforma", a la que se le pase como parametro un "char" y
// haga lo siguiente:
// 
//	• si el argumento es una letra en mayuscula, devuelve su correspondiente letra en
//	  minuscula,
//
//	• si el argumento es una letra en minuscula, devuelve su correspondiente letra en
//	  mayuscula,
//
//	• si el argumento no es ni una letra mayuscula, ni una letra mayuscula, devuelve el
//	  caracter pasado como argumento.
//
// Observad que la constante de amplitud
// 	
//	const int AMPLITUD = 'a'-'A';
//
// es necesaria declararla como constante local en ambas funciones. Para no repetir
// este codigo, ¿que podemos hacer?
// 
// Finalidad: Entender como se llaman las funciones entre si. Dificultad Baja.


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

bool EsMayuscula(char letra) {
    bool esMayuscula;
    if (letra >= 'A' && letra <= 'Z')
        esMayuscula = true;
    else
        esMayuscula = false;

    return esMayuscula;
}

char Convierte_a_Minuscula(char letra) {
    const int amplitud = ('a' - 'A');
    if (EsMayuscula(letra))
        letra = letra + amplitud;

    return letra;
}

char Transforma(char letra) {
    if (EsMayuscula(letra))
        letra = Convierte_a_Minuscula(letra);
    else
        if (EsMinuscula(letra))
        letra = Convierte_a_Mayuscula(letra);
    return letra;

    return letra;
}

int main() {

    char primerIntento;
    char segundoIntento;
    char letra = 'f';

    primerIntento = Transforma(letra);
    segundoIntento = Transforma(primerIntento);

    cout << "Caracter convertido: " << primerIntento << ". Caracter convertido: " << segundoIntento << endl;

    cout << "\n\n";
}
