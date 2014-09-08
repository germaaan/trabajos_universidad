#include <iostream>
#include <cstdlib>
#include <list>
#include <cmath>
#include "player54097023.h"
#include "environment.h"

using namespace std;

Player54097023::Player54097023(int jug) {
    jugador_ = jug;
}

void Player54097023::Perceive(const Environment & env) {
    actual_ = env;
}

/**
Calcula el valor heuristico de un estado de la frontera de busqueda
Devuelve: El valor heuristico asociado al estado "actual" desde el punto de vista del jugador "jug"
Parametros:
    "actual" estado que contiene el tablero a evaluar.
    "jug" indique que jugador esta pidiendo el valor heuristico.
OBSERVACION: esta parametrizacion es solo indicativa, y el alumno podra modificarla segun sus necesidades
 */
double Player54097023::Heuristica(const Environment & actual, int jug) {
    int marcador_propio = 0, marcador_rival = 0, valoracion1 = 0, valoracion2 = 0;

    // Para el estado actual del tablero, calculamos nuestra puntuacion y una valoracion sobre como de bueno se puede considerar esta situacion.
    valoracion1 = Valoracion(actual, jug);

    if (jug == 1) {
        marcador_propio = actual.Marcador(1);
        marcador_rival = actual.Marcador(2);
        valoracion2 += Valoracion(actual, 2);
    } else {
        marcador_propio = actual.Marcador(2);
        marcador_rival = actual.Marcador(1);
        valoracion2 += Valoracion(actual, 1);
    }

    if (marcador_propio > marcador_rival + actual.Total_Suciedad())
        return 1000000; // Si esta situacion nos hiciera ganar, devolvemos un valor elevado.
    else if (marcador_rival > marcador_propio + actual.Total_Suciedad())
        return -1000000; // Si esta situacion nos hiciera perder, devolvemos un valor bajo.
    else
        return valoracion1 - valoracion2; // Si no se tiene un resultado absoluto, devolvemos una estimacion de la bondad del estado.
}

/**
Esta funcion devuelve la siguiente mejor accion guiada por la heuristica usando el algoritmo minimax.
Devuelve: La siguiente accion a realizar.
Parametros:
    "actual" contiene el estado del tablero.
    "jug" indica que jugador esta pidiendo el valor heuristico.
    "limite_profundidad" establece el limite de exploracion del grafo.
OBSERVACION: esta parametrizacion es solo indicativa, y el alumno podra modificarla segun sus necesidades

Se puede resolver por recursividad o con pila, para la version recursiva se recomiendo usar mas parametros
 */
Environment::ActionType Player54097023::MiniMax(const Environment &actual, int jug, int limite_profundidad) {
    Environment::ActionType accion;

    // Llamamos el metodo para comenzar con la busqueda de nuestro mejor movimiento.
    double v = ValorMax(actual, jug, limite_profundidad, accion);

    return accion;
}

double Player54097023::ValorMax(const Environment &actual, int jug, int limite_profundidad, Environment::ActionType &accion) {
    // Si hemos llegado a un nodo frontera, evaluamos el estado del mapa.
    if (limite_profundidad == 0)
        return Heuristica(actual, jug);

    double v = -1000000, aux;
    int n, s;
    Environment descendientes[4];
    Environment::ActionType local;

    // Generamos todos los movimientos posibles para nuestro jugador.
    n = actual.GenerateNextMove(descendientes, jug);

    // Para todos nuestros posibles movimientos, buscamos el mejor el movimiento en base a que nuestro rival buscara nuestro peor.
    for (s = 0; s < n; s++) {
        aux = ValorMin(descendientes[s], jug, limite_profundidad - 1);

        // Si encontramos un movimiento mejor teniendo en cuenta cual seria la respues del rival, lo elegiremos como el mejor por el momento.
        if (aux > v) {
            v = aux;
            local = static_cast<Environment::ActionType> (descendientes[s].Last_Action(jug));
        }
    }

    accion = local;

    return aux;
}

double Player54097023::ValorMin(const Environment &actual, int jug, int limite_profundidad) {
    // Ahora vamos a funcionar desde la perspectiva del rival.
    if (jug == 1)
        jug = 2;
    else
        jug = 1;

    // Si hemos llegado a un nodo frontera, evaluamos el estado del mapa.
    if (limite_profundidad == 0)
        return Heuristica(actual, jug);

    double v = 1000000;
    int n, s;
    Environment descendientes[4];
    Environment::ActionType accion;

    // Generamos todos los movimientos posibles para el rival.
    n = actual.GenerateNextMove(descendientes, jug);

    // Buscamos el estado con valor minimo para el rival.
    for (s = 0; s < n; s++)
        v = Min(v, ValorMax(descendientes[s], jug, limite_profundidad - 1, accion));

    return v;
}

double Player54097023::Min(double a, double b) {
    if (a < b)
        return a;
    else
        return b;
}

double Player54097023::Valoracion(const Environment &actual, int jug) {
    int **mundo = actual.SeeMap(); // Hacemos una copia del estado actual del mapa.
    int posX, posY, posX2, posY2, auxX, auxY, puntuacion = 1000000, distSuciedad, valorSuciedad;
    list<pair<pair<int, int>, int> > suciedades; // Declaramos una lista donde almacenaremos las coordenadas de la suciedad y su valor.
    list<pair<pair<int, int>, int> >::iterator it; // Un iterador para recorrer la lista anterior.

    // Establecemos la posicion actual del jugador.
    if (jug == 1) {
        posX = actual.Position1_X();
        posY = actual.Position1_Y();
    } else {
        posX = actual.Position2_X();
        posY = actual.Position2_Y();
    }

    // Almacenamos todos los puntos con suciedad.
    for (int i = 0; i < actual.SizeMaze(); i++) {
        for (int j = 0; j < actual.SizeMaze(); j++) {
            if (mundo[i][j] > 0)
                suciedades.push_back(pair<pair<int, int>, int> (pair<int, int> (i, j), mundo[i][j]));
        }
    }

    // Buscamos el punto de suciedad mas cercano.
    for (it = suciedades.begin(); it != suciedades.end(); ++it) {
        posX2 = (*it).first.first;
        posY2 = (*it).first.second;
        distSuciedad = sqrt(pow((posX2 - posX), 2) + pow((posY2 - posY), 2));

        if (distSuciedad < puntuacion) {
            puntuacion = distSuciedad;
            valorSuciedad = (*it).second;
        }
    }

    return puntuacion * valorSuciedad * 100;
}

/**
Funcion que invoca al metodo Minimax
 */
Environment::ActionType Player54097023::Think() {
    return MiniMax(actual_, jugador_, 10);
}