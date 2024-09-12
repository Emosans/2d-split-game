#include "../bin/include/raylib.h"
#include "../include/SplitScreen.hpp"
#include <math.h>
#include<iostream>

void SplitScreen::detectCollisions(PlayerSplitScreen* player,Object* object){
    if(CheckCollisionRecs(player->rect,object->rect)){   
    float deltaX = (player->rect.x + player->rect.width / 2) - (object->rect.x + object->rect.width / 2);
    float deltaY = (player->rect.y + player->rect.height / 2) - (object->rect.y + object->rect.height / 2);
    
    float intersectX = fabs(deltaX) - (player->rect.width / 2 + object->rect.width / 2);
    float intersectY = fabs(deltaY) - (player->rect.height / 2 + object->rect.height / 2);

    if (intersectX < 0.0f && intersectY < 0.0f) {
        if (intersectX > intersectY) {
            if (deltaX > 0.0f) {
                //return "Right"; // Player is colliding from the right
                printf("Right");
                collisionDirection="right";
                object->pos.x -= 2.0f;
                object->rect.x = object->pos.x;
            } else {
                //return "Left"; // Player is colliding from the left
                printf("Left");
                collisionDirection="left";
                object->pos.x += 2.0f;
                object->rect.x = object->pos.x;
            }
        } else {
            if (deltaY > 0.0f) {
                //return "Bottom"; // Player is colliding from the bottom
                printf("Bottom");
                collisionDirection="bottom";
                object->pos.y -= 2.0f;
                object->rect.y = object->pos.y;
            } else {
                //return "Top"; // Player is colliding from the top
                printf("Top");
                collisionDirection="top";
                object->pos.y += 2.0f;
                object->rect.y = object->pos.y;
            }
        }
        
        object->isInteracted = true;
    }
}
}

void SplitScreen::detectCollisionsWithEndpoint(Object* object,EndPoint* endPoint){
    if(CheckCollisionRecs(object->rect,endPoint->rect)){
        object->targetActive=false;
    }
}

string SplitScreen::getCollisionValue(){
    return collisionDirection;
}