// Escribir un programa que reciba el nombre de dos ficheros. El programa copiara, en el mismo orden, los numeros
// que contiene el fichero de entrada en el fichero de salida.
// 
// 	- El primer fichero (entrada) contiene una serie indefinida de numeros enteros:
// 
// 		• Es un fichero de texto.
// 
// 		• Se pueden usar espacios, tabuladores o saltos de lineas (en cualquier numero y combinacion) para
// 		separar dos numeros enteros consecutivos.
// 
// 	- El segundo fichero (salida) es un fichero binario.
// 
// 	- El programa leera los numeros y los copiara de uno en uno.


#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main(int argc, char **argv) {
    ifstream fi;
    ofstream fo;
    int final, tam = 0, num;
    int valor, comprobacion;

    if (argc != 3) {
        cerr << "Error: Numero de parametros incorrecto.\n";
        cerr << "Uso: " << argv[0] << " [ficheroEntrada] [ficheroSalida]\n";
        exit(1);
    }

    fi.open(argv[1], ios::in);

    if (!fi) {
        cerr << "Error: No se pudo abrir " << argv[1] << endl;
        exit(1);
    }

    fo.open(argv[2], ios::out);

    if (!fo) {
        cerr << "Error: No se pudo crear " << argv[2] << endl;
        exit(1);
    }

    while (!fi.eof()) {
        fi >> valor;

        if (fi)
            fo.write((const char *) (&valor), sizeof (int));
    }

    fi.close();
    fo.close();

    return (0);
}
