#pragma once
#include "../bin/include/raylib.h"
#include<string>
using namespace std;

struct PlayerSplitScreen{
    Rectangle rect;
    Vector2 pos;
};

struct Object{
    Rectangle rect;
    Vector2 pos;
    bool isInteracted;
};

struct EndPoint{
    Rectangle rect;
    Vector2 pos;
};

class SplitScreen{
public:
    void detectCollisions(PlayerSplitScreen* player,Object* object);
    string getCollisionValue();
private:
    float playerSpeed = 3.0f;
    string collisionDirection;
};