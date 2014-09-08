// Escribir un programa que que lea una secuencia indefinida de caracteres de la entrada estandar (terminada por
// EOF) y reciba como argumento desde la linea de ordenes un dato de tipo int.
// 
// El programa mostrara en la salida estandar el numero de palabras leidas de la entrada estandar cuya longitud
// sea igual al argumento suministrado.
// 
// Por ejemplo: cuenta_palabras 10 < ElQuijote.txt mostrara el numero de palabras que hay en ElQuijote.txt
// que tienen 10 caracteres.


#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char **argv) {

    char c;
    int contLetras = 0;
    int contPalabras = 0;
    //int numLetras = *argv[1] - '0';
    int numLetras = atoi(argv[1]);

    if (argc != 2) {
        cerr << "Error: Numumero de parametros recibidos erroneo.\n";
        cerr << "Uso: " << argv[0] << " <numPalabras>\n";
        exit(1);
    }

    c = cin.get();

    while (!cin.eof()) {
        if (c == ' ') {

            if (contLetras == numLetras)
                contPalabras++;

            contLetras = 0;
        } else
            contLetras++;

        c = cin.get();
    }

    cout << "Numero de palabras leidas con " << numLetras << " letras: " << contPalabras << endl;
}
