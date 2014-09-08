// Escribir un programa que lea un fichero como los generados en los problemas 6, 7 y 8 y que muestre en la salida
// estandar la suma de todos esos numeros.


#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main(int argc, char **argv) {
    ifstream fi;
    int valor;
    int final, sumatoria = 0;

    if (argc != 2) {
        cerr << "Error: Numero de parametros erroneo.\n";
        cerr << "Uso: " << argv[0] << " <fichero>\n";
        exit(1);
    }

    fi.open(argv[1]);

    if (!fi) {
        cerr << "Error: No se pudo abrir " << argv[1] << endl;
        exit(1);
    }

    fi.seekg(0, ios::end);
    final = fi.tellg();

    for (int i = 0; i < final; i++) {
        fi.seekg(i, ios::beg);

        valor = fi.get();

        if ((valor == 0) || (valor == 1) || (valor == 2) || (valor == 3) || (valor == 4) || (valor == 5) || (valor == 6) || (valor == 7) || (valor == 8) || (valor == 9))
            sumatoria += valor;
    }

    cout << "\nValores sumados: " << sumatoria << endl;
}
