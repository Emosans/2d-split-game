#include "../bin/include/raylib.h"
#include "../include/GameState.hpp"

void GameState::saveGameState(Vector2 posPlayer1,Vector2 posPlayer2,Vector2 posObject1,Vector2 posObject2){
    savedGameState currentState = {posPlayer1,posPlayer2,posObject1,posObject2};
    gameStateHistory.push(currentState);
}

void GameState::undoGameState(Vector2 &posPlayer1,Vector2 &posPlayer2,Vector2 &posObject1,Vector2 &posObject2){
    if(!gameStateHistory.empty()){
        // Ensure there's still a previous state to undo to
        savedGameState prevState = gameStateHistory.top();
        gameStateHistory.pop();
        posPlayer1 = prevState.posPlayer1;
        posPlayer2 = prevState.posPlayer2;
        posObject1 = prevState.posObject1;
        posObject2 = prevState.posObject2;
    }
}