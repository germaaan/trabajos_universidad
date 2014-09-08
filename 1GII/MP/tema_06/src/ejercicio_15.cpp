// Implementar un programa que similar a head que muestre las primeras lineas de un fichero de texto.
// 
// Por ejemplo, la ejecucion de cabecera 15 reconstruye.cpp mostrara las primeras 15 lineas del fichero de
// texto reconstruye.cpp
// 
// Se aplican las mismas restricciones que las indicadas en el problema 14 (excepto la primera, evidentemente).


#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main(int argc, char **argv) {
    ifstream fi;
    char valorLeido;
    int contadorLinea = 1;

    if (argc != 3) {
        cerr << "Error: numero de parametros incorrectos." << endl;
        cerr << "Uso: " << argv[0] << " [numLineas] [fichero]" << endl;
        exit(1);
    }

    fi.open(argv[2], ios::in);

    if (!fi) {
        cerr << "Error: no se pudo acceder al fichero " << argv[2] << endl;
        exit(1);
    }

    valorLeido = fi.get();

    while ((!fi.eof()) && (contadorLinea <= atoi(argv[1]))) {
        if (valorLeido == '\n')
            contadorLinea++;

        cout << valorLeido;

        valorLeido = fi.get();
    }

    fi.close();

    cout << endl;

    return (0);
}
