
#ifndef AGENT__
#define AGENT__

#include <string>

using std::string;

// -----------------------------------------------------------
//				class Agent
// -----------------------------------------------------------

class Environment;

class Agent {
public:

    Agent() {
        int i,
                j;

        bump_ = false;
        dirty_ = false;
        last_action_ = 5;

        for (i = 0; i < 30; i++)
            for (j = 0; j < 30; j++)
                map_[i][j] = 1;

        posX_ = 10;
        posY_ = 10;

        pre_posX_ = posX_;
        pre_posX_ = posY_;

        map_[posX_][posY_]++;
    }

    enum ActionType {
        actUP, actDOWN, actLEFT, actRIGHT, actSUCK, actIDLE
    };

    void Perceive(const Environment &env);
    ActionType Think();

private:
    bool bump_,
    dirty_;

    int last_action_,
    map_[30][30],
    posX_,
    posY_,
    pre_posX_,
    pre_posY_,
    Next_UpDo(int mov),
    Next_LeRi(int mov);

    void Print_Map();
};

string ActionStr(Agent::ActionType);

#endif