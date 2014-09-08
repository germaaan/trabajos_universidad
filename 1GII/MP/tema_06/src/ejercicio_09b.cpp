// Escriba dos programas para transformar ficheros con datos correspondientes a una serie de grupos de valores
// reales (como estan descritos en el problema 8), para transformar entre formato binario y texto:
// 
// 	a) Un programa que transforme un fichero de texto a binario:
// 			text2bin <FichText> <FichBin>
// 
// 	b) Un programa que transforme un fichero de binario a texto:
// 			bin2text <FichBin> <FichText>
// 
// Debe optimizarse el uso de los recursos, y por tanto, se aplican las restricciones enumeradas en el problema 8.


#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main(int argc, char **argv) {
    ifstream fi;
    ofstream fo;
    float valor;

    if (argc != 3) {
        cerr << "Error: numero de argumentos incorrecto." << endl;
        cerr << "Uso: " << argv[0] << " [ficheroBinario] [ficheroTexto]" << endl;
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

	while (fi.read(reinterpret_cast <char *> (&valor), sizeof(float)))
        fo << valor << " ";

    fi.close();
    fo.close();

    return (0);
}
