#pragma once
#include "../bin/include/raylib.h"
#include <stack>
using namespace std;

class GameState{
    struct savedGameState{
        Vector2 posPlayer1;
        Vector2 posPlayer2;
        Vector2 posObject1;
        Vector2 posObject2;
    };

public:
    void saveGameState(Vector2 posPlayer1, Vector2 posPlayer2, Vector2 posObject1, Vector2 posObject2);
    void undoGameState(Vector2 &posPlayer1, Vector2 &posPlayer2, Vector2 &posObject1, Vector2 &posObject2);

private:
    stack<savedGameState> gameStateHistory; //stack to store the states

};