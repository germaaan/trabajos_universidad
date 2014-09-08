#include "agent.h"
#include "environment.h"
#include <cstdlib>

// -----------------------------------------------------------

Agent::ActionType Agent::Think() {
    int next_action;

    if (dirty_) {
        last_action_ = 4;
        map_[posX_][posY_] = 1;
        return actSUCK;
    } else if (bump_) {
        map_[posX_][posY_] = 0;
        posX_ = pre_posX_;
        posY_ = pre_posY_;
    }

    if (last_action_ < 2 and map_[posX_][posY_ - 1] == 0 and map_[posX_][posY_ + 1] == 0)
        next_action = last_action_;
    else if (last_action_ > 1 and last_action_ < 4 and map_[posX_ + 1][posY_] == 0 and map_[posX_ - 1][posY_] == 0)
        next_action = last_action_;
    else {
        next_action = rand() % 4;

        if (last_action_ < 2 and next_action < 2 and last_action_ != next_action)
            next_action = next_action + 2;
        else if (last_action_ < 4 and last_action_ > 1 and next_action > 1 and last_action_ != next_action)
            next_action = next_action - 2;
    }

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

    return static_cast<ActionType> (next_action);
}

// -----------------------------------------------------------

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
// -----------------------------------------------------------
// -----------------------------------------------------------

void Agent::Perceive(const Environment &env) {
    bump_ = env.isJustBump();
    dirty_ = env.isCurrentPosDirty();
}

// -----------------------------------------------------------

string ActionStr(Agent::ActionType action) {
    switch (action) {
        case Agent::actUP: return "UP";
        case Agent::actDOWN: return "DOWN";
        case Agent::actLEFT: return "LEFT";
        case Agent::actRIGHT: return "RIGHT";
        case Agent::actSUCK: return "SUCK";
        case Agent::actIDLE: return "IDLE";
        default: return "???";
    }
}