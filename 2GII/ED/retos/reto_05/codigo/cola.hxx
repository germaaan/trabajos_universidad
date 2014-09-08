/**
 * @file cola.hxx
 * @brief Fichero implementación métodos del TDA Cola
 *
 */

#include <list>
#include <cassert>

using namespace std;

template<class T>
Cola<T>::Cola() {
    /// No es necesario implementar ningún constructor por defecto
    /// porque como el único dato miembro es un List de la STL
    /// este utilizará su constructor por defecto.
}

template<class T>
Cola<T>::Cola(const Cola<T> &original) {
    /// Nos encontramos con una situción similar a la del constructor
    /// anterior, por eso simplemente tendremos que usar la sobrecarga
    /// del operador de asignación para objetos List de la STL.
    this->lista = original.lista;
}

template<class T>
Cola<T>::~Cola() {
    /// Los destructores de las clases no se pueden llamar explícitamente,
    /// pero disponemos del método clear() para List que cumple con la
    /// misma función.
    this->lista.clear();
}

template<class T>
Cola<T>& Cola<T>::operator=(const Cola<T> &otra) {
    /// Implementamos el constructor de asignación como cualquier otro.
    if (this != &otra)
        this->lista = otra.lista;

    return *this;
}

template<class T>
bool Cola<T>::vacia() const {
    /// Usamos el método de List para comprobar si un objeto de dicha
    /// clase está vacío.
    return this->lista.empty();
}

template<class T>
T& Cola<T>::frente() {
    /// Nos aseguramos que nuestra cola no está vacía, y devolvemos
    /// una referencia al primer elemento de la cola.
    assert(!this->vacia());

    return this->lista.front();
}

template<class T>
const T& Cola<T>::frente() const {
    /// Nos aseguramos que nuestra cola no está vacía, y devolvemos
    /// una referencia constante al primer elemento de la cola.
    assert(!this->vacia());

    return this->lista.front();
}

template<class T>
void Cola<T>::poner(const T &elem) {
    /// Usamos el método de List para poner un elemento al final.
    this->lista.push_back(elem);
}

template<class T>
void Cola<T>::quitar() {
    assert(!this->vacia());

    /// Usamos el método para sacar el primer elemento del objeto List.
    this->lista.pop_front();
}

template<class T>
void Cola<T>::limpiar() {
    this->lista.clear();
}

template<class T>
int Cola<T>::num_elementos() const {
    return this->lista.size();
}
