// [libreria] Se desea gestionar una libreria. Para cada libro, se desea almacenar un identificador
// numerico (unico) y el año de su publicacion unicamente.
// 
// Debe construir un programa que lea una serie de datos de libros y que los muestre ordenados
// por año de publicacion (de menor a mayor). En el caso de que haya varios libros de un mismo
// año, se deben ordenar por el identificador, pero esta vez de mayor a menor.
// 
// Por ejemplo, a continuacion tenemos una serie de parejas de numeros. Cada una de ellas
// corresponde a un libro y es de la forma (identificador,año):
// 
// 	{(5, 2006), (8, 2000), (30, 2001), (25, 2000), (11, 2005), (21, 2005), (7, 2005),
// 	(63, 2006), (27, 2006)}
// 
// El resultado de la ordenacion de nuestro programa deberia ser el siguiente:
// 
// 	{(25, 2000), (8, 2000), (30, 2001), (21, 2005), (11, 2005), (7, 2005), (63, 2006),
// 	(27, 2006), (5, 2006)}
// 
// Los datos de entrada al programa se proporcionan con el siguiente formato:
// 
// 	a) Numero de libros.
// 
// 	b) Secuencia de pares con los identificadores y año de publicacion.
// 
// Restricciones del problema:
// 
// 	a) Debe implementar una clase “Biblioteca”. Dicha clase debe incorporar la funcionalidad
// 	necesaria para resolver el problema.
// 
// 	b) No se permite declarar vectores fuera de la clase.
// 
// 	c) No se admitira que la entrada o la salida de datos se realice dentro de la clase que incorpora
// 	la funcionalidad para resolver este problema. Esas operaciones se resolveran fuera de la
// 	clase.
// 
// Ejemplo de fichero de validacion:
// 	9
// 	5 2006
// 	8 2000
// 	30 2001
// 	25 2000
// 	11 2005
// 	21 2005
// 	7 2005
// 	63 2006
// 	27 2006
// 
// Salida del programa: Los libros ordenados segun el criterio anterior.
// 	25 2000 8 2000 30 2001 21 2005 11 2005 7 2005 63 2006 27 2006 5 2006


#include <iostream>
#include <stdexcept>
using namespace std;

class Biblioteca {
private:
    static const int TAMANIO_FIL = 50;
    static const int TAMANIO_COL = 2;
    int vectorLibros[TAMANIO_FIL][TAMANIO_COL];
    int totalFilasUtilizadas;

    void IntercambiaPosicionLibros(int posArriba, int posAbajo) {
        int intercambioIdentificador;
        int intercambioAnioPublicacion;

        intercambioAnioPublicacion = vectorLibros[posArriba][0];
        intercambioIdentificador = vectorLibros[posArriba][1];

        vectorLibros[posArriba][0] = vectorLibros[posAbajo][0];
        vectorLibros[posArriba][1] = vectorLibros[posAbajo][1];

        vectorLibros[posAbajo][0] = intercambioAnioPublicacion;
        vectorLibros[posAbajo][1] = intercambioIdentificador;
    }

public:

    Biblioteca()
    : totalFilasUtilizadas(0) {
    }

    void Aniade(int anioPublicacion, int identificador) {
        if (totalFilasUtilizadas < TAMANIO_FIL) {
            vectorLibros[totalFilasUtilizadas][0] = anioPublicacion;
            vectorLibros[totalFilasUtilizadas][1] = identificador;

            totalFilasUtilizadas++;
        } else
            throw logic_error("No hay componentes suficientes");
    }

    void OrdenarLibros() {
        int principioOrdenacionAnios, i;
        bool cambio = true;

        for (principioOrdenacionAnios = 0; principioOrdenacionAnios < totalFilasUtilizadas && cambio; principioOrdenacionAnios++) {
            cambio = false;

            for (i = totalFilasUtilizadas - 1; i > principioOrdenacionAnios; i--) {

                if (vectorLibros[i][0] < vectorLibros[i - 1][0]) {
                    IntercambiaPosicionLibros(i, i - 1);
                    cambio = true;
                }
            }

        }

    }

    int getIdentificador(int posicion) {
        return vectorLibros[posicion][1];
    }

    int getAnioPublicacion(int posicion) {
        return vectorLibros[posicion][0];
    }

};

int main() {
    int cantidadLibros;
    int identificadorLibro;
    int anioPublicacion;
    int identificadorMostrar;
    int anioMostrar;
    Biblioteca biblioteca;

    cin >> cantidadLibros;

    for (int i = 1; i <= cantidadLibros; i++) {
        cin >> identificadorLibro;
        cin >> anioPublicacion;

        try {
            biblioteca.Aniade(anioPublicacion, identificadorLibro);
        } catch (logic_error excepcion) {
            cout << "Error logico: " << excepcion.what();
        }
    }

    biblioteca.OrdenarLibros();

    for (int i = 0; i < cantidadLibros; i++) {
        identificadorMostrar = biblioteca.getIdentificador(i);
        anioMostrar = biblioteca.getAnioPublicacion(i);

        cout << identificadorMostrar << " " << anioMostrar << " ";
    }

    cout << "\n\n";
}
