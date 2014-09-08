// Escribir un programa que permita encriptar y desencriptar el contenido de un fichero de texto. Para encriptar
// sustituiremos cada letra (mayusculas y minusculas) por la letra que esta p posiciones mas adelante en el 
// alfabeto (para las u ́ltimas letras ciclamos el alfabeto). Los caracteres que no sean letras se quedaran igual. 
// Para desencriptar la sustitucion sera a la inversa. La llamada al programa se realizara con este esquema:
// 	
// 	codifica <ficheroE> <ficheroS> <p> <tipo>
// 
// donde:
// 
// 	• <ficheroE> y <ficheroS> son los nombres de los ficheros de entrada y salida, respectivamente
// 	• <p> es el numero entero que se aplica para codificar/descodificar cada uno de los caracteres.
// 	• <tipo> es una cadena de caracteres que puede valer: enc para encriptar y desenc para desencriptar.


#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>

using namespace std;

int main(int argc, char **argv) {
    ifstream fi;
    ofstream fo;
    char valor;

    if ((strncmp("enc", argv[4], 3) != 0) && (strncmp("desenc", argv[4], 6) != 0)) {
        cerr << "Error: modo introducido no valido." << endl;
        cerr << "Uso: " << argv[0] << " [ficheroEntrada] [ficheroSalida] [valor] MODO:[enc/desenc]" << endl;
        exit(1);
    }

    if (argc != 5) {
        cerr << "Error: numero de parametros incorrecto." << endl;
        cerr << "Uso: " << argv[0] << " [ficheroEntrada] [ficheroSalida] [valor] [enc/desenc]" << endl;
        exit(1);
    }

    fi.open(argv[1], ios::in);

    if (!fi) {
        cerr << "Error: no se pudo acceder al fichero de entrada " << argv[1] << endl;
        exit(1);
    }

    fo.open(argv[2], ios::out);

    if (!fo) {
        cerr << "Error: no se pudo crear el fichero de salida " << argv[2] << endl;
        exit(1);
    }

    valor = fi.get();

    if (strcmp("enc", argv[4])) {

        while (!fi.eof()) {

            if ((valor >= 'a') && (valor <= 'z')) {
                if ((valor + atoi(argv[3])) <= 'z')
                    valor += atoi(argv[3]);
                else
                    valor += (atoi(argv[3]) - 'a');
            } else if ((valor >= 'A') && (valor <= 'Z')) {
                if ((valor + atoi(argv[3])) <= 'Z')
                    valor += atoi(argv[3]);
                else
                    valor += (atoi(argv[3]) - 'A');
            }

            fo << valor;

            valor = fi.get();
        }
    } else {

        while (!fi.eof()) {

            if ((valor >= 'a') && (valor <= 'z')) {
                if ((valor - atoi(argv[3])) >= 'a')
                    valor -= atoi(argv[3]);
                else
                    valor -= (atoi(argv[3]) + 'a');
            } else if ((valor >= 'A') && (valor <= 'Z')) {
                if ((valor + atoi(argv[3])) >= 'A')
                    valor -= atoi(argv[3]);
                else
                    valor -= (atoi(argv[3]) + 'A');
            }

            fo << valor;

            valor = fi.get();
        }
    }

    fi.close();
    fo.close();

    return (0);
}
