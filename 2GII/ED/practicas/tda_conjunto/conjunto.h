#ifndef _CONJUNTO_H_
#define _CONJUNTO_H_

/**
 * @file conjunto.h
 * @brief Fichero cabecera del TDA conjunto
 *
 * Se crea un vector dinamico que se comporta como un conjunto. 
 * 
 */
#include "vector_dinamico.h"

/**
 *  @brief TDA conjunto
 *
 *
 * Una instancia @e v del tipo de dato abstracto conjunto sobre el
 * tipo @c float es un tipo de dato que permite insertar, borrar y buscar elementos.
 * Lo podemos representar como
 *
 *  {c[0], c[1], ..., c[n-1]} 
 *
 * donde c[i] es el valor almacenado en la posición i del vector_dinamico.
 *
 * La eficiencia en espacio es @e O(n).
 *
 * Un ejemplo de su uso:
 * @include usoconjunto.cpp
 * @author German Martinez Maldonado
 *
 */
class conjunto {
public:
    /**
     * @brief constructor por defecto
     */
    conjunto();

    /**
     * @brief constructor de copia
     */
    conjunto(const conjunto &x);

    /**
     * @brief inserta un elemento en el conjunto
     * @param x elemento a insertar
     */
    void insert(float x);

    /**
     * @brief borra un elemento del conjunto
     * @param x elemento a borrar
     */
    void erase(float x);

    /**
     * @brief busca un elemento en el conjunto
     * @param x elemento a buscar
     * @return devuelve true si el elemento está y false en caso contrario
     */
    bool find(float x) const;

    /**
     * @brief devuelve el elemento que se encuentra en la posición iésima
     * @param i posición del elemento deseado. 0<=i<size()
     * @return el elemento iésimo
     */
    const float &operator[](int i) const;

    /**
     * @brief devuelve el número de elementos del conjunto
     * @return el número de elementos del conjunto
     */
    int size() const;

private:
    /**
     * @page repvector_dinamico Rep del TDA conjunto
     *
     * @section invvector_dinamico Invariante de la representación
     *
     * Un objeto válido @e v del TDA vector_dinamico debe cumplir 
     * - No pueden existir elementos repetidos en el conjunto
     * - Todos los elementos serán insertados en orden
     *
     * @section favector_dinamico  Función de abstracción
     *
     * Un objeto válido @e rep del TDA conjunto representa un vector_dinámico de
     * tamaño @e n
     *
     * {v[0], v[1], ..., v[n-1]}
     *
     */
    vector_dinamico v;

    /**
     * @brief devuelve la posición en la que se insertará o eliminará un elemento
     * @param x elemento para el que se busca la posición
     * @return la posición correspondiente al elemento
     */
    int buscar_posicion(float x);
};

#endif
