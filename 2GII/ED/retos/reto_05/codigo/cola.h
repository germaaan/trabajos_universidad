/**
 * @file cola.h
 * @brief Fichero cabecera del TDA Cola
 *
 * Gestiona una secuencia de elementos con funcionamiento de cola
 * a través de un tipo de dato List de la STL.
 */

#ifndef __COLA_H__
#define __COLA_H__

#include <list>

using namespace std;

/**
 * @brief TDA Cola basado en List de STL usando templates.
 *
 * @author Germán Martínez Maldonado
 * @author José Rubén Sánchez Iruela
 * @author Pablo Sánchez Robles
 *
 * @date Noviembre 2011
 */
template<class T>

class Cola {
private:
    list<T> lista;

public:
    /**
     * @brief Constructor por defecto.
     */
    Cola();

    /**
     * @brief Constructor de copia.
     * @param original Cola a copiar.
     */
    Cola(const Cola &original);

    /**
     * @brief Destructor.
     */
    ~Cola();

    /**
     * @brief Operador de asignación.
     * @param otra Cola a asignar.
     * @return Referencia a la cola modificada.
     */
    Cola& operator=(const Cola &otra);

    /**
     * @brief Comprueba si la cola está vacía.
     * @return Booleano indicador de si la cola está vacía.
     */
    bool vacia() const;

    /**
     * @brief Devuelve el elemento del frente de la cola.
     * @return Referencia al elemento del frente de la cola.
     */
    T& frente();

    /**
     * @brief Devuelve el elemento del frente de una cola constante
     * @return Referencia constante al elemento del frente de la cola.
     */
    const T& frente() const;

    /**
     * @brief Añade un elemento al final de la cola.
     * @param elem Elemento que se va a añadir.
     */
    void poner(const T &elem);

    /**
     * @brief Quita el elemento del frente de la cola.
     */
    void quitar();

    /**
     * @brief Quita todos los elementos de la cola.
     */
    void limpiar();

    /**
     * @brief Devuelve el número de elementos de la cola.
     * @return Entero con el número de elementos de la cola.
     */
    int num_elementos() const;
};

#include "cola.hxx"

#endif
