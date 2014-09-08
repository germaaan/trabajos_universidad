// Deseamos guardar un numero indefinido de valores double y procesarlos (exactamente como en el problema 4).
// 
// Resuelva el problema almacenando los elementos en un vector dinamico que va creciendo de uno en uno cuando
// no haya espacio para almacernar un nuevo valor. Reservar inicialmente 10 casillas.


#include <iostream>
#include "vector.h"
//#include <vector>
using namespace std;

int main() {
    //vector<double> x,y,z;
    vector x, y, z;

    for (int i = 0; i < 7; i++)
        x.push_back(i + 2.7);

    x.print();

    for (int i = 0; i < 12; i++)
        x.push_back(i + 3.0);

    x.print();

    z = x;

    for (int i = 1; i < 10; i++)
        z.push_back(i * 2.7);

    z.print();
    x.print();
}
