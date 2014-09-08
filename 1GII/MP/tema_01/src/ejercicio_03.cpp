// Declare una variable v como un vector de 1000 enteros. Escriba un trozo de codigo que recorra el vector y
// modifique todos los enteros negativos cambiandolos de signo.
// 
// No se permite usar el operador [], es decir, el recorrido se efecuara usando aritmetica de punteros y el bucle se
// controlara mediante un contador entero.
// 
// Nota: Para inicializar aleatoriamente el vector con valores enteros entre -50 y 50, por ejemplo, puede emplearse
// el siguiente fragmento de codigo:
//
// 	#include <cstdlib>
// 	#include <ctime>
// 	...
// 	const int MY_MAX_RAND = 50; // Queremos valores -50<=n<=50
// 	time_t t;
// 	...
// 	srand ((int) time(&t)); // Inicializa el generador con el reloj del sistema
// 	...
// 	for int (i=0; i<1000; i++)
// 	v[i] = (rand() % ((2*MY_MAX_RAND)+1)) - MY_MAX_RAND;
// 	Acerca de srand(), rand() y time(): http://www.cplusplus.com


#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {

    int v[1000];
    int *p;

    const int MY_MAX_RAND = 50;
    time_t t;

    srand((int) time(&t));

    for (int i = 0; i < 1000; i++)
        v[i] = (rand() % ((2 * MY_MAX_RAND) + 1)) - MY_MAX_RAND;

    cout << "Vector con valores aleatorios:" << endl;

    for (p = v; p < (v + 1000); p++)
        cout << *p << " ";

    for (p = v; p < (v + 1000); p++) {
        if (*p < 0)
            *p = (*p) * (-1);
    }

    cout << "\n\nVector sin valores negativos:" << endl;

    for (p = v; p < (v + 1000); p++)
        cout << *p << " ";

    cout << "\n\n";
}
