#include "agent.h"
#include "environment.h"
#include "state.h"
#include <cstdlib>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <cmath>

using namespace std;

// -----------------------------------------------------------

Environment::ActionType Agent::AgenteReactivo() {
    int next_action;

    if (dirty_) {
        last_action_ = 4;
        map_[posX_][posY_] = 1;
        return Environment::actSUCK;
    } else if (bump_) {
        map_[posX_][posY_] = 0;
        posX_ = pre_posX_;
        posY_ = pre_posY_;
    }

    next_action = rand() % 4;

    if (last_action_ < 2 and next_action < 2 and last_action_ != next_action)
        next_action = next_action + 2;
    else if (last_action_ < 4 and last_action_ > 1 and next_action > 1 and last_action_ != next_action)
        next_action = next_action - 2;

    switch (next_action) {
        case 0:
            if (map_[posX_ - 1][posY_] == 0)
                next_action = Next_UpDo(next_action);
            break;

        case 1:
            if (map_[posX_ + 1][posY_] == 0)
                next_action = Next_UpDo(next_action);
            break;

        case 2:
            if (map_[posX_][posY_ - 1] == 0)
                next_action = Next_LeRi(next_action);
            break;

        case 3:
            if (map_[posX_][posY_ + 1] == 0)
                next_action = Next_LeRi(next_action);
            break;
    }

    last_action_ = next_action;

    pre_posX_ = posX_;
    pre_posY_ = posY_;

    switch (next_action) {
        case 0: posX_ = posX_ - 1;
            break;
        case 1: posX_ = posX_ + 1;
            break;
        case 2: posY_ = posY_ - 1;
            break;
        case 3: posY_ = posY_ + 1;
            break;
    }

    map_[posX_][posY_]++;

    return static_cast<Environment::ActionType> (next_action);
}

int Agent::Next_UpDo(int mov) {
    int next_action;

    if (map_[posX_][posY_ - 1] != 0 and map_[posX_][posY_ - 1] < map_[posX_][posY_ + 1])
        next_action = 2;
    else if (map_[posX_][posY_ + 1] != 0 and map_[posX_][posY_ + 1] < map_[posX_][posY_ - 1])
        next_action = 3;
    else if (map_[posX_][posY_ - 1] == 0 and map_[posX_][posY_ + 1] != 0)
        next_action = 3;
    else if (map_[posX_][posY_ + 1] == 0 and map_[posX_][posY_ - 1] != 0)
        next_action = 2;
    else if (map_[posX_][posY_ - 1] != 0 and map_[posX_][posY_ + 1] != 0)
        next_action = rand() % 3 + 2;
    else {

        if (mov == 0)
            next_action = 1;
        else
            next_action = 0;
    }

    return next_action;
}

int Agent::Next_LeRi(int mov) {
    int next_action;

    if (map_[posX_ - 1][posY_] != 0 and map_[posX_ - 1][posY_] < map_[posX_ + 1][posY_])
        next_action = 0;
    else if (map_[posX_ + 1][posY_] != 0 and map_[posX_ + 1][posY_] < map_[posX_ - 1][posY_])
        next_action = 1;
    else if (map_[posX_ - 1][posY_] == 0 and map_[posX_ + 1][posY_] != 0)
        next_action = 1;
    else if (map_[posX_ + 1][posY_] == 0 and map_[posX_ - 1][posY_] != 0)
        next_action = 0;
    else if (map_[posX_ - 1][posY_] != 0 and map_[posX_ + 1][posY_] != 0)
        next_action = rand() % 2;
    else {

        if (mov == 2)
            next_action = 3;
        else
            next_action = 2;
    }

    return next_action;
}

void Agent::Print_Map() {
    int i, j;

    printf("\n");

    for (i = 0; i < 30; i++) {
        for (j = 0; j < 30; j++)
            printf("%d ", map_[i][j]);

        printf("\n");
    }
}

// -----------------------------------------------------------

// -----------------------------------------------------------
// Inserta un estado (st) en una lista de estados (lista) y devuelve un iterador a su posicion en la lista (it)
// La funcion devuelve "true" e inserta el estado (st) al final de la lista si es estado no estaba ya en la lista.
// La funcion devuelve "false" si el estado (st) ya estaba en la lista, y NO LO INSERTA EN LA LISTA
// -----------------------------------------------------------

bool InsertarLista(list <state> &lista, const state &st, list<state>::iterator &it) {
    char ch;
    it = lista.begin();
    bool salida = false;
    while (it != lista.end() and !(*it == st))
        it++;
    if (it == lista.end()) {
        lista.push_back(st);
        it = lista.end();
        it--;
        salida = true;
    }
    return salida;
}

// -----------------------------------------------------------
// Esto sirve para declarar un metodo de ordenacion para la cola con prioridad.
// En esto caso, los ordena de menor a mayor en el primer valor del par (double,iterador)
// -----------------------------------------------------------

struct Comparar {

    bool operator() (const pair<double, list<state>::iterator > &a, const pair<double, list<state>::iterator > &b) {
        return (a.first > b.first);
    }
};

// -----------------------------------------------------------
// Busqueda en Anchura
// -----------------------------------------------------------

Plan Agent::Busqueda_Anchura(state start) {
    Plan plan;
    typedef pair<double, list<state>::iterator > elemento_cola;

    int last_level = 0; // Indica el nivel del grafo por donde va la busqueda
    int estados_evaluados = 0; // Indica el numero de nodos evaluados
    state aux = start; // start es el estado inicial
    state sigActions[6], mejor_solucion; // para almacenar las siguientes acciones y la mejor solucion
    int n_act;

    list<state> lista; // Lista que almacenara todos los estados
    list<state>::iterator p, padre; // Declara dos iteradores a la lista
    priority_queue <elemento_cola, vector<elemento_cola>, Comparar > cola; //Declaracion de la cola con prioridad

    elemento_cola siguiente; // Declara una variable del tipo almacenado en la cola con prioridad

    InsertarLista(lista, aux, padre); // Inserta el estado inicial en la lista y (padre) es un iterador a su posicion.

    while (!aux.Is_Solution()) {
        // Indica si ha incrementado el nivel del grafo por donde esta buscando
        if (aux.Get_g() != last_level) {
            cout << "Level " << aux.Get_g() << endl;
            last_level = aux.Get_g();
        }

        estados_evaluados++; // Incremento del numero de estados evaluados

        n_act = aux.Generate_New_States(sigActions); // Genera los nuevos estados a partir del estado (aux)

        // Para cada estado generado, pone un enlace al estado que lo genero,
        // lo inserta en la lista, y si no estaba ya en dicha lista, lo incluye en la cola con prioridad.
        // El valor de prioridad en la lista lo da el metodo "Get_g()" que indica la energia consumida en dicho estado.
        for (int i = 0; i < n_act; i++) {
            sigActions[i].Put_Padre(padre);
            if (InsertarLista(lista, sigActions[i], p)) {
                double value = sigActions[i].Get_g();
                cola.push(pair<double, list<state>::iterator > (value, p));
            }
        }

        // Saca el siguiente estado de la cola con prioridad.
        padre = cola.top().second;
        aux = *padre;
        cola.pop();
    }

    // Llegados aqui ha encontrado un estado solucion, e
    // incluye la solucion en una variable de tipo plan.
    plan.AnadirPlan(aux.Copy_Road(), lista.size(), estados_evaluados);

    return plan; // Devuelve el plan
}

// -----------------------------------------------------------

Plan Agent::Busqueda_Profundidad(state start) {
    Plan plan;
    typedef list<state>::iterator elemento_pila;

    int last_level = 0; // Nivel del grafo en el que se encuentra la busqueda
    int estados_evaluados = 0; // Numero de nodos evaluados
    state aux = start; // Inicializamos un estado auxiliar al nodo inicial.
    state sigActions[6]; // Para almacenar las siguientes acciones
    int n_act; // Numero de estados generados a partir del estado actual

    list<state> lista; // Lista que almacenara todos los estados
    list<state>::iterator p, padre; // Declara dos iteradores a la lista para gestionarla
    stack <elemento_pila, vector<elemento_pila> > pila; // Declaracion de la pila

    InsertarLista(lista, aux, padre); // Inserta el estado inicial en la lista y (padre) es un iterador a su posicion.

    while (!aux.Is_Solution()) {
        // Indica si ha cambiado el nivel del grafo por donde esta buscando
        if (aux.Get_g() != last_level) {
            cout << "Level " << aux.Get_g() << endl;
            last_level = aux.Get_g();
        }

        estados_evaluados++; // Incremento del numero de estados evaluados

        n_act = aux.Generate_New_States(sigActions); // Genera los nuevos estados a partir del estado (aux)

        // Para cada estado generado, se enlaza al estado actual
        // Comprueba si estaba ya en la lista de nodos visitados,
        // Insertandolo en la pila en caso de que no estuviera
        for (int i = 0; i < n_act; i++) {
            sigActions[i].Put_Padre(padre);
            if (InsertarLista(lista, sigActions[i], p)) {
                pila.push(p);
            }
        }

        // Para seguir explorando el grafo, se apunta al elemento en la cima de la pila,
        // se copia, y se saca de la pila
        padre = pila.top();
        aux = *padre;
        pila.pop();
    }

    // Devolvemos el plan con el camino hacia el estado solucion
    plan.AnadirPlan(aux.Copy_Road(), lista.size(), estados_evaluados);

    return plan; // Devuelve el plan
}

// -----------------------------------------------------------
// --------------------- Busqueda Heuristica -----------------
// -----------------------------------------------------------

double Heuristica(const state &estado) {
    state aux = estado; // Copia del estado actual con la trabajaremos
    int **mundo = aux.Get_mundo(); // Copia del mundo actual en el que se mueve la aspiradora
    int distSuciedad, menorDistSuciedad = 0; // Enteros para almacenar la distancia hacia un punto con suciedad
    bool choque = false; // Booleano que nos indica si hemos chocado de camino a un punto con suciedad

    for (int i = 0; i < aux.Get_Tam_X(); i++) {

        for (int j = 0; j < aux.Get_Tam_Y(); j++) {

            // En funcion de si la ultima accion fue limpiar, el valor inicial para calcular la distancia variara
            if (mundo[i][j] > 0) {
                if (aux.Last_Action() == 4)
                    distSuciedad = -50;
                else
                    distSuciedad = 0;

                //Si estoy mas arriba que la suciedad, buscare llegar a la suciedad bajando hasta que llegue o choque
                if (aux.Get_posX() < i) {
                    for (int k = aux.Get_posX(); k < i & !choque; k++) {

                        if (mundo[k + 1][aux.Get_posY()] < 0) {
                            distSuciedad += aux.Get_Tam_X(); // Si hay obstaculos, penalizo aumento el valor dado
                            choque = true;
                        } else {
                            distSuciedad++; // Si no hay obstaculos, sumo un paso dado
                        }
                    }
                }//Si estoy mas abajo que la suciedad, buscare llegar a la suciedad subiendo hasta que llegue o choque
                else {
                    for (int k = aux.Get_posX(); k > i & !choque; k--) {

                        if (mundo[k - 1][aux.Get_posY()] < 0) {
                            distSuciedad += aux.Get_Tam_X();
                            choque = true;
                        } else {
                            distSuciedad++;
                        }
                    }
                }

                //Despues de medir la distancia vertical, si no hemos chocado, medimos la distancia horizontal.
                if (!choque) {
                    //Si estoy mas a la izquierda que la suciedad, buscare llegar a la suciedad iendo hacia la derecha hasta que llegue o choque
                    if (aux.Get_posY() < j) {
                        for (int k = aux.Get_posY(); k < j & !choque; k++) {

                            if (mundo[i][k + 1] < 0) {
                                distSuciedad += aux.Get_Tam_Y();
                                choque = true;
                            } else {
                                distSuciedad++;
                            }
                        }
                    }//Si estoy mas a la derecha que la suciedad, buscare llegar a la suciedad iendo hacia la izquierda hasta que llegue o choque
                    else {
                        for (int k = aux.Get_posY(); k > j & !choque; k--) {

                            if (mundo[i][k - 1] < 0) {
                                distSuciedad += aux.Get_Tam_Y();
                                choque = true;
                            } else {
                                distSuciedad++;
                            }
                        }
                    }
                }

                // Vuelvo a establecer la condicion de choque para la proxima busqueda
                choque = false;

                // Si estoy en una casilla con suciedad o al lado de una, como son situaciones preferibles,
                // disminuyo los valores dados para que se beneficie estos estados sobre otros.
                if (distSuciedad == 0) {
                    distSuciedad -= 100;
                } else if (distSuciedad == 1) {
                    distSuciedad -= 50;
                }

                if ((menorDistSuciedad == 0) || (distSuciedad < menorDistSuciedad)) {
                    menorDistSuciedad = distSuciedad;
                }
            }
        }
    }

    return estado.Get_Pending_Dirty()*100 + menorDistSuciedad;
}

// -----------------------------------------------------------

Plan Agent::Escalada(state start) {
    Plan plan;
    state aux = start; // Inicializamos una variable auxiliar con el estado inicial
    int estados_expandidos = 0, estados_evaluados = 0, n_act, mejorEstado;
    state sigActions[6];
    double valorInicial, valorDesc, mejorValor = 0; // Diferentes valores obtenidos de la funcion objetivo
    bool salida = false;

    while (!aux.Is_Solution() & !salida) {

        estados_expandidos++;
        n_act = aux.Generate_New_States(sigActions);
        estados_evaluados += n_act;

        cout << "\nEstados expandidos: " << estados_expandidos << ". Estados evaluados: " << estados_evaluados << endl;

        valorInicial = Heuristica(aux);

        //Primero vamos a buscar cual de los descendientes es el mejor estado
        for (int i = 0; i < n_act; i++) {
            valorDesc = Heuristica(sigActions[i]);

            if ((mejorValor == 0) || (valorDesc < mejorValor)) {
                mejorValor = valorDesc;
                mejorEstado = i;
            }
        }

        //Si ninguno de los descendientes mejora el nodo inicial, devolvemos optimo local
        if (mejorValor == valorInicial) {
            salida = true;
        } else {
            aux = sigActions[mejorEstado];
        }
    }

    // Llegados aqui ha encontrado un estado solucion, e
    // incluye la solucion en una variable de tipo plan.
    plan.AnadirPlan(aux.Copy_Road(), estados_expandidos, estados_evaluados);

    return plan; // Devuelve el plan
}

// -----------------------------------------------------------

Plan Agent::Think(const Environment &env, int option) {
    state start(env);
    Plan plan;

    switch (option) {
        case 0: //Agente Reactivo
            break;
        case 1: //Busqueda Anchura
            plan = Busqueda_Anchura(start);
            cout << "\n Longitud del Plan: " << plan.Get_Longitud_Plan() << endl;
            plan.Pinta_Plan();
            break;
        case 2: //Busqueda Profundidad
            plan = Busqueda_Profundidad(start);
            cout << "\n Longitud del Plan: " << plan.Get_Longitud_Plan() << endl;
            plan.Pinta_Plan();
            break;
        case 3: //Busqueda Profundidad
            plan = Escalada(start);
            cout << "\n Longitud del Plan: " << plan.Get_Longitud_Plan() << endl;
            plan.Pinta_Plan();
            break;
    }

    return plan;
}

// -----------------------------------------------------------

void Agent::Perceive(const Environment &env) {
    bump_ = env.isJustBump();
    dirty_ = env.isCurrentPosDirty();
}

// -----------------------------------------------------------

string ActionStr(Environment::ActionType action) {
    switch (action) {
        case Environment::actUP: return "UP";
        case Environment::actDOWN: return "DOWN";
        case Environment::actLEFT: return "LEFT";
        case Environment::actRIGHT: return "RIGHT";
        case Environment::actSUCK: return "SUCK";
        case Environment::actIDLE: return "IDLE";
        default: return "???";
    }
}
