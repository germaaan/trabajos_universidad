// Vamos a modificar el ejercicio 3 de la siguiente forma. Queremos leer dos valores
// enteros desde teclado y, en el caso de que uno cualquiera de ellos divida al otro, el
// programa nos debe decir quien divide a quien.
// 
// 	a) En primer lugar, resolved el ejercicio mezclando entradas, computos y salidas de
// 	   resultados
// 
// 	b) En segundo lugar, se pide resolver el ejercicio sin mezclar C/E,S. Para ello, se
// 	   ofrecen varias alternativas. ¿Cual sería la mejor? Escoged una e implementar la
// 	   solucion.
// 
// 		I) Utilizar un variable de tipo "string" de la forma siguiente:
// 			string quien_divide;
// 			.............
// 			if (a%b==0)
// 				quien_divide = "b divide a a";
// 			.............
// 			if (quien_divide == "b divide a a")
// 				cout << b << " divide a " << a;
// 		
// 		Nota. Para poder usar el operador de comparación == entre dos string,
// 		hay que incluir la biblioteca "string".
// 
// 		Si se opta por esta alternativa, el suspenso esta garantizado. ¿Por que?
// 
// 		II) Utilizar dos variables logica de la forma siguiente:
// 			bool a_divide_a, b_divide_a;
// 			int Divdo, Divsor;
// 			.............
// 			if (a%b==0)
// 				Divdo = a;
// 			.............
// 			if (se_dividen)
// 				cout << Dvsor << " divide a " << Dvdo;
// 
// Completar la solucion elegida para contemplar tambien el caso en el que alguno de
// los valores introducidos sea cero, en cuyo caso, ninguno divide al otro.
// 
// Finalidad: Mostrar como se comunican los distintos bloques de un programa a traves
// de variables que indican lo que ha sucedido en el bloque anterior. Dificultad Media.


#include <iostream>
using namespace std;

int main() {
    int a, b;
    bool a_divide_b, b_divide_a;

    cout << "Introduzca primer valor entero: ";
    cin >> a;

    cout << "Introduzca segundo valor entero: ";
    cin >> b;

    if (a == 0 || b == 0) {
        cout << "\nEl numero 0 no puede dividir ni ser dividido entre ningun otro numero.";
    } else {

        if (b%a == 0)
            a_divide_b = true;
        else
            a_divide_b = false;

        if (a%b == 0)
            b_divide_a = true;
        else
            b_divide_a = false;

        if (a_divide_b)
            cout << "\n" << a << " divide a " << b;

        if (b_divide_a)
            cout << "\n" << b << " divide a " << a;
    }

    cout << "\n\n";
}
