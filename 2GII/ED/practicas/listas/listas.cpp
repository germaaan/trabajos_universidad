#include <iostream>
#include <list>

using namespace std;

void leer(list<int> &l) {
    int aux = 0;

    while (aux >= 0) {
        cin >> aux;

        if (aux >= 0)
            l.push_back(aux);
    }
}

void escribir(const list<int> &l) {
    list<int>::const_iterator it;

    for (it = l.begin(); it != l.end(); it++)
        cout << *it << " ";

    cout << endl;
}

void elimina(const list<int> &rep, list<int> &l) {
    list<int>::const_iterator it1;
    list<int>::iterator it2;

    for (it1 = rep.begin(); it1 != rep.end(); it1++) {
        for (it2 = l.begin(); it2 != l.end(); it2++) {
            if (*it2 == *it1)
                it2 = l.erase(it2);
        }
    }

}

void mezcla(const list<int> &l1, const list<int> &l2, list<int> &l) {
    list<int>::const_iterator it1 = l1.begin();
    list<int>::const_iterator it2 = l2.begin();

    while ((it1 != l1.end()) || (it2 != l2.end())) {

        if (it2 == l2.end()) {
            while (it1 != l1.end()) {
                l.push_back(*it1);
                it1++;
            }
        } else if (it1 == l1.end()) {
            while (it2 != l2.end()) {
                l.push_back(*it2);
                it2++;
            }
        } else if (*it1 <= *it2) {
            l.push_back(*it1);
            it1++;
        } else {
            l.push_back(*it2);
            it2++;
        }

    }
}

int main() {
    list<int> lista1, lista2, lista3, lista4, lista5;

    cout << "\nIntroduzca elementos en lista1:\n";
    leer(lista1);

    cout << "\nIntroduzca elementos en lista2:\n";
    leer(lista2);

    cout << "\nEliminando repetidos de lista1 en lista2...\n";
    elimina(lista1, lista2);

    cout << "\nElementos actuales en lista2:\n";
    escribir(lista2);

    cout << "\nIntroduzca elementos en lista3 (de forma ordenada):\n";
    leer(lista3);

    cout << "\nIntroduzca elementos en lista4 (de forma ordenada):\n";
    leer(lista4);

    cout << "\nMezclando listas de elementos ordenador:\n";
    mezcla(lista3, lista4, lista5);

    cout << "\nResultado de mezclar las listas: \n";
    escribir(lista5);

    return (0);
}
