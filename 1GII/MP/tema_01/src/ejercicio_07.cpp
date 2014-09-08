// Las cadenas de caracteres representan un ejemplo clasico en el uso de punteros. La cadena almacena un numero
// indeterminado de caracteres (para los ejercicios basatara un valor siempre menor que 100) delimitados al final
// por el caracter nulo ('\0').
// 
// Escriba un trozo de codigo que localice la posicion del primer caracter espacio (' ') en una cadena de caracteres
// “clasica”.
// 
// La cadena debe recorrerse usando aritmetica de punteros y sin usar ningun entero. El programa debe indicar su
// posicion (0: primer caracter, 1: segundo caracter, etc.).
// 
//	Nota: Usar la funcion getline() para la lectura de la cadena (Cuidado: usar el metodo publico de istream
//	sobre cin, o sea cin.getline()). Ver http://www.cplusplus.com/reference/iostream/istream/getline/


#include <iostream>
using namespace std;

int main() {

    const int TAMANIO = 100;
    char cadena[TAMANIO], *p;
    bool encontrado = false;
    int contador = 0;

    cout << "Introduzca texto: ";
    cin.getline(cadena, TAMANIO);

    for (p = cadena; (*p != '\0') && !encontrado; p++) {

        if (*p == ' ') {
            encontrado = true;
            cout << "El primer espacio en blanco se encuentra en la posicion: " << contador << endl;
        } else
            contador++;

    }

    cout << "\n";
}
