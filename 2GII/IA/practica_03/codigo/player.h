#ifndef PLAYER_H
#define PLAYER_H

#include "environment.h"

class Player {
public:
    Player(int jug);
    Environment::ActionType Think();
    void Perceive(const Environment &env);
    
private:
    int jugador_;
    Environment actual_;
    Environment::ActionType MiniMax(const Environment & actual, int jug, int limite_profundidad);
    double Heuristica(const Environment & actual, int jug);
    double ValorMax(const Environment &actual, int jug, int limite_profundidad, Environment::ActionType &accion);
    double ValorMin(const Environment &actual, int jug, int limite_profundidad);
    double Min(double a, double b);
    double Valoracion(const Environment &actual, int jug);
};
#endif
