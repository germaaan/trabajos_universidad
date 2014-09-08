#include <sstream>
#include <iostream>
#include <cstdlib>

template <typename T>
expresion<T>::expresion() {
    this->arbol = bintree<string > ();
}

template <typename T>
expresion<T>::expresion(const T & v) {
    stringstream flujo;
    string aux;

    flujo << v;
    flujo >> aux;

    this->arbol = bintree<string > (aux);
}

template <typename T>
expresion<T>::expresion(const string & c) {
    string aux;
    istringstream flujo(c);

    flujo >> aux;
    this->arbol = bintree<string > (aux);

    bintree<string>::node n(this->arbol.root());

    while (flujo >> aux) {
        switch (aux[0]) {
            case '+':
            case '-':
            case '*':
            case '/':
                if (n.left().null()) {
                    this->arbol.insert_left(n, aux);
                    n = n.left();
                } else {
                    this->arbol.insert_right(n, aux);
                    n = n.right();
                }
                break;

            default:
                if (n.left().null())
                    this->arbol.insert_left(n, aux);
                else {
                    this->arbol.insert_right(n, aux);

                    while ((!n.right().null()) && (n != this->arbol.root()))
                        n = n.parent();
                }
        }
    }
}

template <typename T>
expresion<T> & expresion<T>::operator=(const expresion<T> & e) {
    this->arbol = e.arbol;
}

template <typename T>
expresion<T> expresion<T>::operator+(const expresion<T> & e) const {
    string resultado;

    resultado = "+" + this->prefijo() + e.prefijo();

    expresion<T> aux(resultado);

    return aux;
}

template <typename T>
expresion<T> expresion<T>::operator-(const expresion<T> & e) const {
    string resultado;

    resultado = "-" + this->prefijo() + e.prefijo();

    expresion<T> aux(resultado);

    return aux;
}

template <typename T>
expresion<T> expresion<T>::operator*(const expresion<T> & e) const {
    string resultado;

    resultado = "*" + this->prefijo() + e.prefijo();

    expresion<T> aux(resultado);

    return aux;
}

template <typename T>
expresion<T> expresion<T>::operator/(const expresion<T> & e) const {
    string resultado;

    resultado = "/" + this->prefijo() + e.prefijo();

    expresion<T> aux(resultado);

    return aux;
}

template <typename T>
string expresion<T>::infijo() const {
    string resultado = "";

    resultado = resultado + this->parentesisInfijo(this->arbol.root());

    return resultado;
}

template <typename T>
string expresion<T>::postfijo() const {
    string resultado = "";

    if (this->arbol.root().null())
        return resultado;

    for (bintree<string>::const_postorder_iterator iterador = this->arbol.begin_postorder(); iterador != this->arbol.end_postorder(); ++iterador)
        resultado = resultado + " " + *iterador;

    return resultado;
}

template <typename T>
string expresion<T>::prefijo() const {
    string resultado = "";

    if (this->arbol.root().null())
        return resultado;

    for (bintree<string>::const_preorder_iterator iterador = this->arbol.begin_preorder(); iterador != this->arbol.end_preorder(); ++iterador)
        resultado = resultado + " " + *iterador;

    return resultado;
}

template <typename T>
string expresion<T>::niveles() const {
    string resultado = "";

    if (this->arbol.root().null())
        return resultado;

    for (bintree<string>::const_level_iterator iterador = this->arbol.begin_level(); iterador != this->arbol.end_level(); ++iterador)
        resultado = resultado + " " + *iterador;

    return resultado;
}

template <typename T>
T expresion<T>::evalua(const vector< pair<char, T> > & valores) const {
    T resultado = 0;

    if (this->arbol.root().null())
        return resultado;

    resultado = this->calculo(this->arbol.root(), valores);

    return resultado;
}

template <typename T>
string expresion<T>::parentesisInfijo(const bintree<string>::node & n) const {
    string resultado = "";

    // Mientras que no lleguemos a un nodo nudo, significará que todavia hay parentesis que añadir a la subexpresion actual.
    if (!n.null()) {
        resultado = resultado + "(";
        resultado = resultado + this->parentesisInfijo(n.left());
        resultado = resultado + *n;
        resultado = resultado + this->parentesisInfijo(n.right());
        resultado = resultado + ")";
    }

    return resultado;
}

template <typename T>
T expresion<T>::calculo(const bintree<string>::node & n, const vector< pair<char, T> > & valores) const {
    T resultado = 0;

    // Mientras no lleguemos al caso base de que nuestro nodo no tiene hijos, significara que el nodo actual es un operador, asi que haremos llamadas recursivas para calcular el valor del subarbol.
    if ((n.left().null()) && (n.right().null())) {
        resultado = this->buscaValor(*n, valores);
    } else {
        if (*n == "+") {
            resultado = this->calculo(n.left(), valores) + this->calculo(n.right(), valores);
        } else if (*n == "-") {
            resultado = this->calculo(n.left(), valores) - this->calculo(n.right(), valores);
        } else if (*n == "*") {
            resultado = this->calculo(n.left(), valores) * this->calculo(n.right(), valores);
        } else if (*n == "/") {
            resultado = this->calculo(n.left(), valores) / this->calculo(n.right(), valores);
        }
    }

    return resultado;
}

template <typename T >
T expresion<T>::buscaValor(const string & etiqueta, const vector< pair<char, T> > & valores) const {
    T valor;
    stringstream flujo;
    bool encontrado = false;

    // Si la etiqueta de un nodo operando no está en el vector, es porque no es una variable, es un valor númerico.
    for (typename vector<pair<char, T> >::const_iterator iterador = valores.begin(); (iterador != valores.end()) & !encontrado; ++iterador) {
        if (iterador->first == etiqueta[0]) {
            valor = iterador->second;
            encontrado = true;
        }
    }

    if (!encontrado) {
        flujo << etiqueta;
        flujo >> valor;
    }

    return valor;
}
