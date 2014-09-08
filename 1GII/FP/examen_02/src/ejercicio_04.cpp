// [palabra] Debemos realizar un programa que lea un texto y que permita localizar la palabra
// n-esima. El texto de entrada consiste en una sucesion de caracteres alfabeticos, espacios en
// blanco y un caracter especial. Se considera que una palabra es cualquier secuencia de caracteres
// alfabeticos consecutivos. Ademas, las palabras estan separadas entre si por secuencias de uno o
// mas espacios en blanco. El caracter especial sirve para indicar el principio y final del texto. El
// primer caracter de la linea de entrada sera ese caracter especial. Por ejemplo, dado el siguiente
// texto de entrada:
// 
// 	# esto es una prueba de entrada #
// 
// la primera palabra es “esto”, la segunda es “es”, la tercera es “una”, y asi sucesivamente. En
// total hay 6 palabras. En este ejemplo el caracter delimitador de comienzo y fin es ‘#‘.
// 
// El programa debe leer una entrada con el siguiente formato:
// 
// 	a) Una primera linea de texto que contiene el delimitador, el texto a procesar y de nuevo el
// 	delimitador (como en el ejemplo anterior).
// 
// 	b) Una segunda linea con el numero de palabra que hay que extraer.
// 
// Restricciones del problema:
// 
// 	a) Debe implementar una clase “Palabras”. Dicha clase debe incorporar la funcionalidad
// 	necesaria para resolver el problema.
// 
// 	b) No se permite declarar vectores fuera de la clase.
// 
// 	c) Para poder leer caracter a caracter incluidos los espacios en blanco, debe realizar la lec-
// 	tura en la forma caracter = cin.get(). Cada vez que se ejecute cin.get() el
// 	compilador lee un caracter (incluido el espacio en blanco) desde la entrada de datos por
// 	defecto.
// 
// 	d) No se admitira que la entrada o la salida de datos se realice dentro de la clase que incorpora
// 	la funcionalidad para resolver este problema. Esas operaciones se resolveran fuera de la
// 	clase.
// 
// Ejemplo de fichero de validacion:
// 	# si hay #
// 
// Salida del programa: Las componentes de la palabra en cuestion.
// 	hay
// 
// En el caso de que la palabra no exista se imprimira un cero (0)


#include <iostream>
#include <stdexcept>
using namespace std;

class Palabras {
private:
    static const int TAMANIO = 50;
    char vectorTexto[TAMANIO];
    char vectorPalabra[TAMANIO];
    int totalUtilizados;

public:

    Palabras()
    : totalUtilizados(0) {
    }

    void Aniade(char letraTexto) {
        if (totalUtilizados < TAMANIO) {
            vectorTexto[totalUtilizados] = letraTexto;
            totalUtilizados++;
        } else
            throw logic_error("No hay componentes suficientes.");
    }

    int AlmacenarPalabraBuscada(int numeroPalabra) {
        int numeroEspacioBlanco = 0;
        int totalUtilizadosPalabra = 0;
        bool encontrada = false;

        for (int i = 1; (i < totalUtilizados - 1) && !encontrada; i++) {
            if (vectorTexto[i] == ' ') {
                numeroEspacioBlanco++;

                while (vectorTexto[i] == ' ')
                    i++;
            }

            if (numeroEspacioBlanco == numeroPalabra) {
                encontrada = true;

                while (vectorTexto[i] != ' ') {
                    vectorPalabra[totalUtilizadosPalabra] = vectorTexto[i];

                    totalUtilizadosPalabra++;
                    i++;
                }
            }
        }

        return totalUtilizadosPalabra;
    }

    char getCaracterPalabraBuscada(int posicion) {
        return vectorPalabra[posicion];
    }

};

int main() {
    char caracter;
    char caracterPalabraBuscada;
    int tamanioPalabraBuscada;
    int numeroPalabraBuscada;
    Palabras palabras;

    caracter = cin.get();
    try {
        palabras.Aniade(caracter);
    } catch (logic_error excepcion) {
        cout << "Error logico: " << excepcion.what();
    }

    do {
        caracter = cin.get();

        try {
            palabras.Aniade(caracter);
        } catch (logic_error excepcion) {
            cout << "Error logico: " << excepcion.what();
        }
    } while (((caracter >= 'a') && (caracter <= 'z')) || (caracter == ' '));

    cin >> numeroPalabraBuscada;

    tamanioPalabraBuscada = palabras.AlmacenarPalabraBuscada(numeroPalabraBuscada);

    if (tamanioPalabraBuscada == 0) {
        cout << 0;
    } else {

        for (int i = 0; i < tamanioPalabraBuscada; i++) {
            caracterPalabraBuscada = palabras.getCaracterPalabraBuscada(i);
            cout << caracterPalabraBuscada;
        }

    }

    cout << "\n\n";
}
