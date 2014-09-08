// Escribir un programa similar a diff para comparar dos ficheros de texto. El programa imprimira el numero
// de la primera linea en la que difieren y el contenido de estas. Por ejemplo, la ejecucion de diff Fich1 Fich2
// producira como resultado:
// 
// 	( 20)	Fich1: en formato binario. Estos ficheros son especialmente adecuados para
// 			Fich2: en formato binario. Estos ficheros, aunque no son legibles, son especialmente
// 
// si las 19 primeras lineas de Fich1 y Fich2 coinciden exactamente, y la primera diferencia se encuentra en la
// linea 20.
// 
// Nota: Este programa puede ser u ́til para comprobar si despues de encriptar y desencriptar un fichero 
// (problema 6), obtenemos un fichero identico al original.


#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

void Diferencias(ifstream &fi1, ifstream &fi2);

int main(int argc, char **argv) {
    ifstream fi1, fi2;
    char caracter1, caracter2;
    int final1, final2, masCorto, contadorBusqueda = 1, posLineaDiferente, contadorResultado = 1;
    bool diferencia = false;

    if (argc != 3) {
        cerr << "Error: Numero de parametros erroneo.\n";
        cerr << "Uso: " << argv[0] << " <fichero1> <fichero2>\n";
        exit(1);
    }

    fi1.open(argv[1], ios::in);

    if (!fi1) {
        cerr << "Error: No se pudo abrir " << argv[1] << endl;
        exit(1);
    }

    fi2.open(argv[2], ios::in);

    if (!fi2) {
        cerr << "Error: No se pudo abrir " << argv[2] << endl;
        exit(1);
    }

    fi1.seekg(0, ios::end);
    final1 = fi1.tellg();

    fi2.seekg(0, ios::end);
    final2 = fi2.tellg();

    if (final1 <= final2)
        masCorto = final1;
    else
        masCorto = final2;

    for (int i = 0; (i < masCorto) && !diferencia; i++) {
        fi1.seekg(i, ios::beg);
        fi2.seekg(i, ios::beg);

        caracter1 = fi1.get();
        caracter2 = fi2.get();

        if (caracter1 != caracter2)
            diferencia = true;

        if (caracter1 == '\n') {
            contadorBusqueda++;
            posLineaDiferente = i + 1;
        }
    }

    if (diferencia) {
        cout << "Diferencia entre ficheros en la linea: " << contadorBusqueda << endl << endl;

        fi1.seekg(posLineaDiferente, ios::beg);

        cout << argv[1] << ": ";

        caracter1 = fi1.get();

        while (caracter1 != '\n') {
            cout.put(caracter1);
            caracter1 = fi1.get();
        }

        cout << endl;

        fi2.seekg(posLineaDiferente, ios::beg);

        cout << argv[2] << ": ";

        caracter2 = fi2.get();

        while (caracter2 != '\n') {
            cout.put(caracter2);
            caracter2 = fi2.get();
        }

        cout << endl;
    } else
        cout << "Los dos ficheros son exactamente iguales." << endl;

    fi1.close();
    fi2.close();

    return (0);
}
