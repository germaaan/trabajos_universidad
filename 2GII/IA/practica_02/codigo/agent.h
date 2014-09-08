#ifndef AGENT__
#define AGENT__

#include <string>
#include "environment.h"
#include "state.h"
#include "plan.h"

using namespace std;

// -----------------------------------------------------------
//				class Agent
// -----------------------------------------------------------

class Agent {
public:

    Agent() {
        int i,
                j;

        bump_ = false;
        dirty_ = false;
        last_action_ = 5;

        for (i = 0; i < 160; i++)
            for (j = 0; j < 160; j++)
                map_[i][j] = 1;

        posX_ = 80;
        posY_ = 80;

        pre_posX_ = posX_;
        pre_posX_ = posY_;

        map_[posX_][posY_]++;
    }

    ~Agent() {
    }

    void Perceive(const Environment &env);
    Environment::ActionType AgenteReactivo();
    Plan Busqueda_Anchura(state start);
    Plan Busqueda_Profundidad(state start);
    Plan Escalada(state start);
    Plan Think(const Environment &env, int option);

private:
    bool bump_,
    dirty_;

    int last_action_,
    map_[160][160],
    posX_,
    posY_,
    pre_posX_,
    pre_posY_,
    Next_UpDo(int mov),
    Next_LeRi(int mov);

    void Print_Map();
};

string ActionStr(Environment::ActionType);

#endif