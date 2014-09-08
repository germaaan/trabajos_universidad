// Escribir un programa que lea un fichero binario como los generados en los problemas 3 y 4 y que muestre en la
// salida estandar la suma de todos esos numeros. Para la lectura se empleara un buffer de 512 bytes.


#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main(int argc, char **argv) {
    const int TAM_BUFFER = 512;
    int buffer[TAM_BUFFER];
    ifstream fi;
    int tam, num, c, suma = 0;

    if (argc != 2) {
        cerr << "Error: Numero de parametros incorrecto.\n";
        cerr << "Uso: " << argv[0] << " [ficheroBinario]\n";
        exit(1);
    }

    fi.open(argv[1], ios::out);

    if (!fi) {
        cerr << "Error: No se pudo abrir " << argv[1] << endl;
        exit(1);
    }

    fi.seekg(0, ios::end);
    tam = fi.tellg();

    cout << "\nFichero: " << argv[1] << " (" << tam << " bytes).\n";

    num = tam / sizeof (int);
    cout << "Contiene : " << num << " enteros.\n\n";

    fi.seekg(0, ios::beg);

    while (!fi.eof()) {
        fi.read((char *) &buffer, TAM_BUFFER);

        for (int c = 0; c < fi.gcount() / sizeof (int); c++) {
            cout << buffer[c] << " ";
            suma += buffer[c];
        }
    }

    cout << "\nSuma de todos los valores contenidos en el fichero binario: " << suma << endl;

    fi.close();

    return (0);
}
