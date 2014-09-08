// Escribir un programa que que lea una secuencia indefinida de caracteres de la entrada estandar (terminada por
// EOF) y reciba como argumento desde la linea de ordenes un dato de tipo char. El programa mostrara en la salida
// estandar el numero de caracteres leidos de la entrada estandar iguales al argumento suministrado.
// 
// Por ejemplo: cuenta_letra a < ElQuijote.txt mostrara el numero de caracteres a que hay en ElQuijote.txt.


#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char **argv) {
    char c;
    int cont = 0;

    if (argc != 2) {
        cerr << "Error: Numero de parametros recibidos erroneo.\n";
        cerr << "Uso: " << argv[0] << " <letraBuscada>\n";
        exit(1);
    }

    c = cin.get();

    while (!cin.eof()) {
        if (*argv[1] == c)
            cont++;

        c = cin.get();
    }

    cout << "Numero de caracteres leidos de la entrada estandar iguales al argumento: " << cont << endl;
}
