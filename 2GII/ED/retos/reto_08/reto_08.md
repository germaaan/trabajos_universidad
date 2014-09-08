Estructuras de Datos
====================
2º Grado en Ingeniería Informática 2011/2012
--------------------------------------------

# Reto 8: Árboles-III
### Germán Martínez Maldonado


### PROBLEMA

**Diseñar un iterador inorden para un ABB. La idea es construir una clase iteradora inorden que nos permita recorrer y operar sobre un ABB.**

Como la clase iteradora la vamos a usar sobre arboles ABB, para mayor facilidad, directamente la incrustaremos en la clase que define los arboles ABB, por lo que dentro de la clase ABB, además de sus métodos y atributos, tendremos también las declaraciones de las siguientes clases (todo contenido en el archivo “ABB.h”):

* nodo: representará el nodo como elemento del árbol, proporcionándonos los métodos para trabajar con ellos.
* iterador_inorden: la clase iteradora con la que recorreremos el ABB.
* envoltura_nodo: para representar la forma funcional en la que existen los nodos en nuestro árbol (todo nodo podrá tener un valor definido (su etiqueta), un nodo padre, un nodo hijo izquierda y un nodo hijo derecha), usaremos esta clase que será la encargada de mantener esas propiedades.

```
template <typename Tbase> 
class ABB{
  public:
/* ########## Clase “nodo” ############################################################### */
    class nodo {
      public:
        nodo ();
        nodo (const Tbase & e); nodo (const nodo & n); bool null () const;
        nodo padre () const; nodo izqda () const; nodo drcha () const; Tbase & operator* ();
        const Tbase & operator* () const; void remove ();
        nodo & operator= (const nodo & n); bool operator== (const nodo & n) const; bool operator!= (const nodo & n) const;

      private:
        friend class ABB<Tbase>;
        inline void padre (nodo n);
        inline void izqda (nodo n);
        inline void drcha (nodo n);

        envoltura_nodo * elnodo;
    }
/* ####################################################################################### */

/* ########## Clase “iterador_inorden” ################################################### */
    class iterador_inorden{
      public:
        iterador_inorden ();
        iterador_inorden (const iterador_inorden & i);
        bool operator!= (const iterador_inorden & i) const;
        bool operator== (const iterador_inorden & i) const;
        iterador_inorden & operator= (const iterador_inorden & i);
        T & operator*();
        iterador_inorden & operator++ ();

      private:
        nodo _nodo;
        iterador_inorden (nodo n);
        friend class ABB<Tbase>;
    };
/* ####################################################################################### */

/* ########## Clase “const_iterador_inorden” ############################################# */
    class const_iterador_inorden{
      /// Mismas declaraciones que clase “iterador_inorden”, pero para iterador constante.
    };
* ######################################################################################## */

/* ########## Constructores y resto de métodos públicos de la clase “ABB” ################ */
            ...
/* ####################################################################################### */

  private:
/* ########## Métodos privados de la clase “ABB” ######################################### */
            ...
/* ####################################################################################### */

/* ########## Atributos de la clase “ABB” ################################################ */
      nodo _raiz;
      int nelementos;
/* ####################################################################################### */

/* ########## Clase “envoltura_nodo” ##################################################### */
    class envoltura_nodo {
      public:
        envoltura_nodo ();
        envoltura_nodo (const Tbase & e);

        Tbase etiqueta;
        nodo _padre;
        nodo _izqda;
        nodo _drcha;
      };
/* ####################################################################################### */
};
```

Con todas las declaraciones ya hechas en el archivo “ABB.h”, vamos a implementar los métodos de la clase iterador_inorden en el archivo “ABB.hxx”, que son las que nos interesan para este reto:

```
/* ########## Métodos de la clase “iterador_inorden” ##################################### */
template <typename Tbase>
inline ABB<Tbase>::iterador_inorden::iterador_inorden(){
}

template <typename Tbase>
inline ABB<Tbase>::iterador_inorden::iterador_inorden
(ABB<Tbase>::nodo n)
    : _nodo(n){
}

template <typename Tbase>
inline bool ABB<Tbase>::iterador_inorden::operator!=
(const typename ABB<Tbase>::iterador_inorden & i) const{
    return _nodo != i._nodo;
}

template <typename Tbase>
inline bool ABB<Tbase>::iterador_inorden::operator==
(const typename ABB<Tbase>::iterador_inorden & i) const{
    return _nodo == i._nodo;
}

template <typename Tbase>
inline typename ABB<Tbase>::iterador_inorden & ABB<Tbase>::iterador_inorden::operator=
(const ABB<Tbase>::iterador_inorden & i){
    _nodo = i._nodo;
    return *this;
}

template <typename Tbase>
inline Tbase & ABB<Tbase>::iterador_inorden::operator*(){
    return *_nodo;
}

template <typename Tbase>
typename ABB<Tbase>::iterador_inorden & ABB<Tbase>::iterador_inorden::operator++(){
    /// Si el nodo es nulo, es porque estaremos en árbol vacío o al final de uno.
    if (_nodo.null())
        return *this;

    /* Si existe un hijo a la derecha, es porque hay un subárbol a la derecha, por lo que el siguiente nodo será el nodo más a la izquierda del subárbol derecho. Por ese motivo, descendemos por la derecha y, mientras haya hijos a la izquierda, descenderemos por la izquierda. */
    if (!_nodo.drcha().null()) {
        _nodo = _nodo.drcha();

        while (!_nodo.izqda().null())
            _nodo = _nodo.izqda();
    }
 
    /* En el caso de que no exista un subárbol derecho, mientras que el padre del nodo no sea un nodo nulo, el siguiente nodo será el propio nodo padre. */
    else {
        while (!_nodo.padre().null() && _nodo.padre().drcha() == _nodo)
            _nodo = _nodo.padre();

        _nodo = _nodo.padre();
    }

    return *this;
}
/* ####################################################################################### */

/* ########## Métodos de la clase “const_iterador_inorden” ############################### */
    /// Misma implementación que clase “iterador_inorden”, pero para iterador constante.
/* ####################################################################################### */

/* ### Constructores y resto de métodos de las clases “ABB”, “nodo” y “envoltura_nodo” ### */
            ...
/* ########################################################################################## */
```
