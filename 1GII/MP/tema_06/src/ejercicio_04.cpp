// Escribir un programa con las mismas caracteristicas que las descritas en el problema 3 pero que escriba en el
// fichero de salida bloques de 512 bytes.


#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main(int argc, char **argv) {
    const int TAM_BUFFER = 512 / sizeof (int);
    int buffer [TAM_BUFFER];
    int c = 0;

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
        while ((!fi.eof()) && (c < TAM_BUFFER)) {
            fi >> valor;

            if (fi) {
                buffer[c] = valor;
                c++;
            }
        }

        fo.write((const char*) (&buffer), c * sizeof (int));
        c = 0;
    }

    fi.close();
    fo.close();

    return (0);
}
