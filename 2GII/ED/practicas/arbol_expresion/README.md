Estructuras de Datos
====================
2º Grado en Ingeniería Informática 2011/2012
--------------------------------------------

# Práctica: Árbol de expresión
### Germán Martínez Maldonado

**Objetivos**: Implementar clases no lineales y aprender a utilizar estructuras jerárquicas (árboles binarios).

**Tareas a realizar**: El alumno deberá definir la clase expresión capaz de manipular expresiones matemáticas del tipo: ( ( 3 * ( 2 + 6 ) ) - ( 5 * 9 ) ). Para introducir los datos se usarán expresiones en prefijo, por ejemplo para la anterior expresión tendramos: - * 3 + 2 6 * 5 9
En esta práctica asumiremos que los operadores son binarios, p.e. suma (3+6).


### 1. Requisitos:

La clase **expresion** debe contener los siguientes componentes públicos y ningún otro (si que se pueden agregar metodos privados):

#### METODOS:

* **expresion()**: Constructor por defecto de la clase.
* **expresion(const  T  &  v)**: Constructor que permite generar una expresión con un único valor.
* **expresion(const  string  &  c)**: Constructor que permite generar una expresión asociada a la cadena c, donde c es una expresión en prefijo. Los operandos y operadores estarn separados por espacios.
* **expresion & operator=(const  expresion  &  e)**: Operador de asignación.
* **expresion operatorX(const expresion & e)**: Donde X ∈ {+, −, *, /}. Devuelve la expresión que se obtiene al considerar en infijo (*this X e), donde X es el operador, *this es la expresión izquierda y e es la expresión derecha. Asi tendremos varios operadores a definir: operator+, operator-, operator* y operator/.
* **string infijo() const**: Devuelve la expresión en infijo, completamente parentizada.
* **string postfijo() const**: Devuelve la expresión en postfijo.
* **string prefijo() const**: Devuelve la expresión en prefijo.
* **string niveles() const**: Devuelve la expresion al hacer un recorrido por niveles.
* **T evalua(const vector< pair<char,T> > & valores) const**: Devuelve el resultado de evaluar la expresión.

### 2. Ejemplos de uso

#### Ejemplo 1:

string a = "- * 3 + 2 6 * 5 9";
expresion<int> e1(a), e_izq, e_der, e2;

e_izq = 5;
e_der = -3;
e2 = e_izq + e_der;

cout << "Valor de Expresion " << e1.infijo() << " = " << e1.evalua(map<char,int>()) << endl;

string c = "* + 2.3 6.1 7.9";
expresion<float> ef(c);

string b = "+ 2.3 6.1";
expresion<float> e3(b);

cout << ef.postfijo() << endl;

#### Ejemplo 2: 
Ilustra como construir expresiones que contienen variables, donde el identificador de las variables es de tipo char. Para la gestión de las variables asumiremos que tenemos un vector vector< pair<char,T> > donde para cada variable almacenaremos su valor. Por ejemplo:

expresion<float> e1;
string g = "* + 2 x - z y";
vector<  pair<char,float> > variables;

e1 = g; // e1 = expresion<float>(g);

variables.push_back(pair<char, float>(’x’, 5));
variables.push_back(pair<char, float>(’y’, 10));
variables.push_back(pair<char, float>(’z’, 1));

cout << e1.evalua(variables) << endl;

En este caso, tendremos como salida a la llamada a evalua -63.

### 3. Representación

Una expresión se pueden representar fácilmente medinate una extructura de árbol, llamado árbol de expresión. 

Un Árbol de Expresión es un arbol donde los nodos externos (hojas) repre- sentan variables o constantes de la expresión (x,y,x, 3,4,...) y los nodos internos representan los operadores (+, -, *, /, ...).

El árbol de expresión se representará haciendo uso del tda bintree<T>.
