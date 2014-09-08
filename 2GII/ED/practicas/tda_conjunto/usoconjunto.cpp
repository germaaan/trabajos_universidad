#include <iostream>
#include "conjunto.h"

using namespace std;

/**
 * @brief Sobrecarga del operador<< para conjunto
 */

ostream & operator <<(ostream &os, const conjunto &c) {
    for (int i = 0; i < c.size(); i++)
        cout << " " << c[i];

    return os;
}

int main() {

    conjunto c;

    cout << "Conjunto: " << c << endl;

    c.insert(5);
    c.insert(2);
    c.insert(1);
    c.insert(4);
    c.insert(3);
    c.insert(1);

    cout << "Conjunto: " << c << endl;

    c.erase(1);
    c.erase(3);
    c.erase(1);

    cout << "Conjunto: " << c << endl;
}
