// Con estas declaracciones:
// 
// 	const int Max = 100;
// 	float v1 [Max] = {2, 3, 8, 22, 44, 88, 99, 100, 101, 255, 665};
// 	float v2 [Max] = {1, 3, 4, 5, 6, 25, 87, 89, 99, 100, 500, 1000};
// 	float res [2*Max];
// 
// 	int tam_v1=11, tam_v2=12;		// 0 <= tam_v1, tam_v2 < Max
// 	int tam_res = tam_v1+tam_v2;	// 0 <= tam_res < 2*Max
// 
// Nota: Observad que v1 y v2 almacenan valores ordenados de menor a mayor.
// 
// Escribir un trozo de codigo para mezclar, de manera ordenada, los valores de v1 y v2 en el vector res.
// 
// No se debe usar el operador [], es decir, se debe resolver usando aritmetica de punteros.


#include <iostream>
using namespace std;

int main() {
    const int Max = 100;
    float v1 [Max] = {2, 3, 8, 22, 44, 88, 99, 100, 101, 255, 665};
    float v2 [Max] = {1, 3, 4, 5, 6, 25, 87, 89, 99, 100, 500, 1000};
    float res [2 * Max];
    int tam_v1 = 11, tam_v2 = 12;
    int tam_res = tam_v1 + tam_v2;

    float *p1, *p2, *r;

    p1 = v1;
    p2 = v2;
    r = res;

    while (r < (res + tam_res)) {

        if (*p1 <= *p2) {
            *r = *p1;
            p1++;
        } else {
            *r = *p2;
            p2++;
        }

        r++;
    }

    cout << "Valores del primer vector:" << endl;

    for (p1 = v1; p1 < (v1 + tam_v1); p1++)
        cout << *p1 << " ";

    cout << "\n\nValores del segundo vector:" << endl;

    for (p2 = v2; p2 < (v2 + tam_v2); p2++)
        cout << *p2 << " ";

    cout << "\n\nValores del vector resultado:" << endl;

    for (r = res; r < (res + tam_res); r++)
        cout << *r << " ";

    cout << "\n\n";
}
