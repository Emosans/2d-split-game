#pragma once
#include "../bin/include/raylib.h"

struct PlayerStruct{
    Vector2 pos;
    float speed;
    bool jump;
};

struct EnvItems{
    Rectangle rect;
    int blocking;
    Color color;
};

class Player{
public:
    void UpdatePlayer(PlayerStruct *player, EnvItems *envitems, int envItemsLength, float deltaTime);
private:
    bool hitObstacle;
};