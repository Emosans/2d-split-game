#include "../include/Player.hpp"
#define PLAYER_JUMP_SPD 350.0f
#define PLAYER_HOR_SPD 200.0f


void Player::UpdatePlayer(PlayerStruct* player,EnvItems *envItems, int envItemsLength, float deltaTime){
    if(IsKeyDown(KEY_LEFT)) player->pos.x -= PLAYER_HOR_SPD*deltaTime;
    else if(IsKeyDown(KEY_RIGHT)) player->pos.x += PLAYER_HOR_SPD*deltaTime;

    else if(IsKeyDown(KEY_SPACE) && player->jump){
        player->speed = -PLAYER_JUMP_SPD;
        player->jump = false;
    }

    Player::hitObstacle = false;
    for (int i=0;i<envItemsLength;i++){
        EnvItems *ei = envItems+i;
        Vector2 *p = &(player->pos);

        if (ei->blocking &&
            ei->rect.x <= p->x &&
            ei->rect.x + ei->rect.width >= p->x &&
            ei->rect.y >= p->y &&
            ei->rect.y <= p->y + player->speed*deltaTime)
        {
            hitObstacle = true;
            player->speed = 0.0f;
            p->y = ei->rect.y;
            break;
        }
    }

    if(!hitObstacle){
        player->pos.y += player->speed*deltaTime;
        player->speed += 400*deltaTime;
        player->jump = false;
    } else player->jump = true;

}
