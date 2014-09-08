// Definid una clase para representar una progresion geometrica, tal y como se definio
// en el ejercicio 19 de la relacion de problemas II.
// 
// 	a) Pensad cual deberia ser el constructor de la clase y los metodos basicos que la
// 	   clase deberia tener.
// 
// 	b) Añadid un metodo llamado "SumaHasta" para que sume los "k" primeros elementos
// 	   de la progresion. Para implementar el metodo "SumaHasta", usad el mismo algoritmo
// 	   (con un bucle "for") que se vio como solucion del ejercicio 19 de la relacion
// 	   de problemas II.
// 	   Cread un programa principal que construya la progresion con los valores a 1 =
// 	   3,5 y r = 4,1 y calcule la suma hasta k = 30.
// 
// 	c) Cambiemos ahora la implementacion del metodo "SumaHasta". Para ello, en vez
// 	   de usar un bucle "for" aplicamos la siguiente formula que nos da la sumatoria
// 	   aplicando unicamente cinco operaciones:
// 
// 			Σ i=1 i=k a1 * (r ^ i) = a1 * ((r^k - 1)/(r - 1))
// 
// 	   Es muy importante remarcar que el programa "main" no cambia nada. Hemos
// 	   cambiado la implementacion del metodo "SumaHasta" y lo hemos podido hacer
// 	   sin cambiar el "main", ya que este no tenia acceso al codigo que hay dentro del
// 	   metodo. Esto es ocultacion de informacion tal y como se describio en las clases
// 	   de teoria.
// 	   Nota. La potenciacion (en nuestro ejemplo r^k) es una operacion costosa, por
// 	   lo que hasta podria ser mas lenta la version nueva que la antigua usando un
// 	   bucle "for". Probad distintos valores para ver si hay diferencias significativas. En
// 	   cualquier caso, lo importante es que mientras no cambiemos la cabecera del
// 	   metodo "SumaHasta", podemos cambiar su implementacion sin tener que cambiar
// 	   ni una linea de codigo del "main".
// 
// 	d) Añadid ahora otro metodo "MultiplicaHasta" para que multiplique los "k" primeros
// 	   elementos de la progresion, aplicando la formula:
// 
// 	   		∏ i=1 i=k a1 * r^i = √((a1 * ak) ^ k)
// 
// Finalidad: Enfatizar la importancia de la ocultacion de informacion. Dificultad Baja.


#include <iostream>
#include <cmath>
using namespace std;

class ProgresionGeometrica {
private:
    double a1;
    double r;
    int k;

public:

    ProgresionGeometrica(double termino = 0.0, double razon = 0.0, int numero_terminos = 0)
    : a1(termino),
    r(razon),
    k(numero_terminos) {
    }

    void SetTermino(double termino) {
        a1 = termino;
    }

    void SetRazon(double razon) {
        r = razon;
    }

    void SetNumeroTerminos(int numero_terminos) {
        k = numero_terminos;
    }

    double GetTermino() {
        return a1;
    }

    double GetRazon() {
        return r;
    }

    int GetNumeroTerminos() {
        return k;
    }

    double SumaHasta() {
        /* Primero implementacion

        double total_suma=a1;

        for(int i =2; i<=k; i++){
                total_suma = total_suma + a1*pow(r,i-1);
        }	

        return total_suma;
		
         */

        return a1 * ((pow(r, k) - 1) / (r - 1));
    }

    double MultiplicaHasta() {
        double total_multiplicacion = a1;

        for (int i = 2; i <= k; i++) {
            total_multiplicacion = total_multiplicacion * a1;
        }

        return sqrt(pow(total_multiplicacion, k));
    }
};

int main() {
    ProgresionGeometrica progresion(3.5, 4.1, 30);

    cout << "\nTermino de la progresion geometrica: " << progresion.GetTermino() << endl;
    cout << "Constante de razon: " << progresion.GetRazon() << endl;
    cout << "Numero de terminos: " << progresion.GetNumeroTerminos() << endl;

    cout << "\nValor de la suma de la progresion geometrica: " << progresion.SumaHasta() << endl;
    cout << "\nValor de la multiplicacion de la progresion geometrica: " << progresion.MultiplicaHasta() << endl;

    cout << "\n";
}
