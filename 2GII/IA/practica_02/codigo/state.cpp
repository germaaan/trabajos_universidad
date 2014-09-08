#include <iostream>
#include "state.h"
#include "environment.h"
#include <list>
#include <queue>
#include <cmath>

using namespace std;

state::state(const Environment &env) {
    Tam_Y = Tam_X = env.SizeMaze();
    mundo = new int*[Tam_Y];
    for (int i = 0; i < Tam_Y; i++)
        mundo[i] = new int [Tam_X];

    int **m = env.SeeMap();
    for (int i = 0; i < Tam_Y; i++)
        for (int j = 0; j < Tam_X; j++)
            mundo[i][j] = m[i][j];

    posX = env.Position_X();
    posY = env.Position_Y();
    Consumed_Energy = 0;
    Pending_Dirty = env.DirtAmount();
    last_action = 5;
    g = h = f = 0;
}

state::~state() {
    for (int i = 0; i < Tam_Y; i++)
        delete [] mundo[i];
    delete [] mundo;

    Tam_X = Tam_Y = 0;
}

state::state(const state& other) {
    Tam_X = other.Tam_X;
    Tam_Y = other.Tam_Y;
    posX = other.posX;
    posY = other.posY;
    Consumed_Energy = other.Consumed_Energy;
    Pending_Dirty = other.Pending_Dirty;
    last_action = other.last_action;
    pos_padre = other.pos_padre;
    g = other.g;
    h = other.h;
    f = other.f;

    mundo = new int*[Tam_Y];
    for (int i = 0; i < Tam_Y; i++)
        mundo[i] = new int [Tam_X];

    for (int i = 0; i < Tam_Y; i++)
        for (int j = 0; j < Tam_X; j++)
            mundo[i][j] = other.mundo[i][j];

    road = other.road;

}

state& state::operator=(const state& other) {
    if (this == &other) return *this; // handle self assignment

    if (Tam_Y != 0) {
        for (int i = 0; i < Tam_Y; i++)
            delete [] mundo[i];
        delete [] mundo;
    }

    // Copiar other en this
    Tam_X = other.Tam_X;
    Tam_Y = other.Tam_Y;
    posX = other.posX;
    posY = other.posY;
    Consumed_Energy = other.Consumed_Energy;
    Pending_Dirty = other.Pending_Dirty;
    last_action = other.last_action;
    pos_padre = other.pos_padre;
    g = other.g;
    h = other.h;
    f = other.f;

    mundo = new int*[Tam_Y];
    for (int i = 0; i < Tam_Y; i++)
        mundo[i] = new int [Tam_X];

    for (int i = 0; i < Tam_Y; i++)
        for (int j = 0; j < Tam_X; j++)
            mundo[i][j] = other.mundo[i][j];

    road = other.road;

    return *this;
}

//------------------------------------------------------------------------

bool state::operator<(const state &other) const {
    return (f < other.f);
}

//------------------------------------------------------------------------

bool state::operator>(const state &other) const {
    return (f > other.f);
}

//------------------------------------------------------------------------

bool state::operator==(const state &other) const {
    if (posX != other.posX)
        return false;
    else if (posY != other.posY)
        return false;
    else if (Pending_Dirty != other.Pending_Dirty)
        return false;
    else {
        int x = 0, y;
        bool casillas_distintas = false;
        while (x < Tam_X and !casillas_distintas) {
            y = 0;
            while (y < Tam_Y and mundo[x][y] == other.mundo[x][y])
                y++;
            if (y < Tam_Y)
                casillas_distintas = true;
            else
                x++;
        }
        return !casillas_distintas;
    }
}

//------------------------------------------------------------------------

void state::Add_Step_in_Road(int new_action) {
    road.push_back(new_action);
}

//------------------------------------------------------------------------

void state::AlterState(const state &other) {
    g = other.g;
    road = other.road;
    pos_padre = other.pos_padre;
    last_action = other.last_action;
}

//------------------------------------------------------------------------

void state::Show_Road() {
    int longitud = 0, energia = 0;
    list<int>::iterator i;
    for (i = road.begin(); i != road.end(); i++) {
        cout << "->";
        switch (*i) {
            case 0: cout << "UP";
                break;
            case 1: cout << "DOWN";
                break;
            case 2: cout << "LEFT";
                break;
            case 3: cout << "RIGHT";
                break;
            case 4: cout << "SUCK";
                break;
            case 5: cout << "NO_ACTION";
                break;
        }
        longitud++;
        if (*i < 4)
            energia++;
        else
            energia += 2;

    }
    cout << endl;
    cout << "Longitud: " << longitud << endl;
    cout << "Energia: " << energia << endl;
}

//------------------------------------------------------------------------

void state::possible_actions(bool *act) const {
    // Mover hacia arriba
    if (last_action != 1 and mundo[posX - 1][posY] != -1)
        act[0] = true;
    else
        act[0] = false;

    // Mover hacia abajo
    if (last_action != 0 and mundo[posX + 1][posY] != -1)
        act[1] = true;
    else
        act[1] = false;

    // Mover izquierda
    if (last_action != 3 and mundo[posX][posY - 1] != -1)
        act[2] = true;
    else
        act[2] = false;

    // Mover derecha
    if (last_action != 2 and mundo[posX][posY + 1] != -1)
        act[3] = true;
    else
        act[3] = false;

    // Aspirar basura
    if (mundo[posX][posY] > 0)
        act[4] = true;
    else
        act[4] = false;

    // No hacer nada no se considera una accion util
    act[5] = false;
}

//------------------------------------------------------------------------

int state::Generate_New_States(state *V) const {
    bool act[6];
    int n_act = 0;
    possible_actions(act);
    for (int i = 0; i < 5; i++) {
        if (act[i]) {
            V[n_act] = *this;
            V[n_act].last_action = i;
            V[n_act].Add_Step_in_Road(i);
            switch (i) {
                case 0: V[n_act].posX--;
                    V[n_act].Consumed_Energy++;
                    V[n_act].g++;
                    break;
                case 1: V[n_act].posX++;
                    V[n_act].Consumed_Energy++;
                    V[n_act].g++;
                    break;
                case 2: V[n_act].posY--;
                    V[n_act].Consumed_Energy++;
                    V[n_act].g++;
                    break;
                case 3: V[n_act].posY++;
                    V[n_act].Consumed_Energy++;
                    V[n_act].g++;
                    break;
                case 4: V[n_act].Pending_Dirty--;
                    V[n_act].mundo[posX][posY]--;
                    V[n_act].Consumed_Energy += 2;
                    V[n_act].g += 2;
                    break;

            }
            V[n_act].h = 0;
            V[n_act].f = V[n_act].g + V[n_act].h;
            n_act++;
        }
    }
    return n_act;
}

//------------------------------------------------------------------------

void state::Datos_Finales() const {
    cout << "Energia consumida: " << Consumed_Energy << endl;
    cout << "Suciedad Presente: " << Pending_Dirty << endl;

}

void state::PrintState() const {
    cout << "Pos(" << posX << "," << posY << ") Suciedad: " << Pending_Dirty << " Accion: " << last_action << endl;
    cout << "g()= " << g << endl;
    for (int x = 0; x < Tam_X; x++) {
        for (int y = 0; y < Tam_Y; y++) {
            if (mundo[x][y] == -1)
                cout << "X";
            else
                cout << mundo[x][y];
        }
        cout << endl;
    }
    cout << endl;
}
