// Escribir un programa que reciba los nombres de dos ficheros de texto de la linea de ordenes. El programa creara
// un fichero (cuyo nombre se especifica en el segundo argumento) a partir de un fichero existente (cuyo nombre se
// especifica en el primer argumento) copiando su contenido y a ̃
// nadiendo al principio de cada linea, su numero.


#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main(int argc, char **argv) {
    ifstream fi;
    ofstream fo;
    char sobreescribir, caracter;
    int final, contador = 0;

    if (argc != 3) {
        cerr << "Error: Numero de parametros erroneo.\n";
        cerr << "Uso: " << argv[0] << " <ficheroEntrada> <ficheroSalida>\n";
        exit(1);
    }

    fi.open(argv[1], ios::in);

    if (!fi) {
        cerr << "Error: No se pudo abrir " << argv[1] << endl;
        exit(1);
    }

    fo.open(argv[2], ios::out);

    if (!fo) {
        cerr << "Error: no se pudo crear " << argv[2] << endl;
        exit(1);
    }

    fi.seekg(0, ios::end);
    final = fi.tellg();

    fo << contador << '\t';
    contador++;

    for (int i = 0; i < final - 1; i++) {
        fi.seekg(i, ios::beg);

        caracter = fi.get();

        if (caracter == '\n') {
            fo << '\n' << contador << '\t';
            contador++;
        } else
            fo.put(caracter);
    }

    fo.put('\n');

    fi.close();
    fo.close();

    return (0);
}
