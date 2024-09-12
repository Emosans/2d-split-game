#include "../bin/include/raylib.h"
#include "../include/SplitScreen.hpp"
#include<math.h>

int main(){
    const int screenWidth = 800;
    const int screenHeight = 440;
    float gameTime=60.0f;
    int randomX,randomY;

    InitWindow(screenWidth,screenHeight,"2d-split");

    SplitScreen objectCollision;
    //Rectangle endPoint;

    PlayerSplitScreen player1={0};
    player1.pos = {200,200};
    player1.rect = {player1.pos.x,player1.pos.y,40,40};
    PlayerSplitScreen player2 = {0};
    player2.pos = {200,200};
    player2.rect = {player2.pos.x,player2.pos.y,40,40};

    Object object1={0};
    object1.pos={300,200};
    object1.rect = {object1.pos.x,object1.pos.y,40,40};
    Object object2={0};
    object2.pos={300,200};
    object2.rect = {object2.pos.x,object2.pos.y,40,40};

    randomX=GetRandomValue(0,screenWidth/2-40);
    randomY = GetRandomValue(0,screenHeight/2-40);

    EndPoint endPoint = {0};
    endPoint.pos = {float(randomX),float(randomY)};
    endPoint.rect = {endPoint.pos.x,endPoint.pos.y,40,40};

    Camera2D cameraForPlayer1 = {0};
    cameraForPlayer1.target = (Vector2) {player1.pos.x,player1.pos.y};
    cameraForPlayer1.offset = (Vector2) {200.0f,200.0f};
    cameraForPlayer1.zoom = 1.0f;
    cameraForPlayer1.rotation = 0.0f;

    Camera2D cameraForPlayer2 = {0};
    cameraForPlayer2.target = (Vector2) {player2.pos.x,player2.pos.y};
    cameraForPlayer2.offset = (Vector2) {200.0f,200.0f};
    cameraForPlayer2.zoom = 1.0f;
    cameraForPlayer2.rotation = 0.0f;

    RenderTexture screenCamera1 = LoadRenderTexture(screenWidth/2, screenHeight);
    RenderTexture screenCamera2 = LoadRenderTexture(screenWidth/2, screenHeight);

    // Build a flipped rectangle the size of the split view to use for drawing later
    Rectangle splitScreenRect = { 0.0f, 0.0f, (float)screenCamera1.texture.width, (float)-screenCamera1.texture.height };

    SetTargetFPS(60);

    while(!WindowShouldClose()){
        gameTime-=GetFrameTime();

        if(gameTime<=0.0f){
            CloseWindow();
            exit(0);
        }

        if (IsKeyDown(KEY_S)) player1.pos.y += 3.0f;
        else if (IsKeyDown(KEY_W)) player1.pos.y -= 3.0f;
        if (IsKeyDown(KEY_D)) player1.pos.x += 3.0f;
        else if (IsKeyDown(KEY_A)) player1.pos.x -= 3.0f;

        if (IsKeyDown(KEY_UP)) player2.pos.y -= 3.0f;
        else if (IsKeyDown(KEY_DOWN)) player2.pos.y += 3.0f;
        if (IsKeyDown(KEY_RIGHT)) player2.pos.x += 3.0f;
        else if (IsKeyDown(KEY_LEFT)) player2.pos.x -= 3.0f;

        //check collisions with player and original object
        objectCollision.detectCollisions(&player1,&object1);
        if(object1.isInteracted && objectCollision.getCollisionValue()=="left"){
            //send mirrored object below
            object2.pos.y += 2.0f;
            object2.rect.y = object2.pos.y;
            object1.isInteracted=false;
        }
        else if(object1.isInteracted && objectCollision.getCollisionValue()=="right"){
            //sent mirrored object up
            object2.pos.y -= 2.0f;
            object2.rect.y = object2.pos.y;
            object1.isInteracted=false;
        }
        else if(object1.isInteracted && objectCollision.getCollisionValue()=="top"){
            //send mirrored object to right
            object2.pos.x += 2.0f;
            object2.rect.x = object2.pos.x;
            object1.isInteracted=false;
        }
        else if(object1.isInteracted && objectCollision.getCollisionValue()=="bottom"){
            //send mirrored object to left
            object2.pos.x -= 2.0f;
            object2.rect.x = object2.pos.x;
            object1.isInteracted=false;
        }
        
        //second player and mirrored object
        objectCollision.detectCollisions(&player2,&object2);
        if(object2.isInteracted && objectCollision.getCollisionValue()=="left"){
            //send original object bottom
            object1.pos.y += 2.0f;
            object1.rect.y = object1.pos.y;
            object2.isInteracted=false;
        }
        else if(object2.isInteracted && objectCollision.getCollisionValue()=="right"){
            //send original object above
            object1.pos.y -= 2.0f;
            object1.rect.y = object1.pos.y;
            object2.isInteracted=false;
        }
        if(object2.isInteracted && objectCollision.getCollisionValue()=="top"){
            //send original object left
            object1.pos.x -= 2.0f;
            object1.rect.x = object1.pos.x;
            object2.isInteracted=false;
        }
        if(object2.isInteracted && objectCollision.getCollisionValue()=="bottom"){
            //send original object right
            object1.pos.x += 2.0f;
            object1.rect.x = object1.pos.x;
            object2.isInteracted=false;
        }

        //update rect x and y pos acc to changes in input
        player1.rect.x = player1.pos.x;
        player1.rect.y = player1.pos.y;
        player2.rect.x = player2.pos.x;
        player2.rect.y = player2.pos.y;

        cameraForPlayer1.target = (Vector2){ player1.pos.x, player1.pos.y };
        cameraForPlayer2.target = (Vector2){ player2.pos.x, player2.pos.y };

        BeginTextureMode(screenCamera1);
        ClearBackground(RAYWHITE);
        BeginMode2D(cameraForPlayer1);
        // Draw full scene with first camera
        for (int i = 0; i < screenWidth/40+ 1; i++)
        {
            DrawLineV((Vector2){(float)40*i, 0}, (Vector2){ (float)40*i, (float)screenHeight}, LIGHTGRAY);
        }

        for (int i = 0; i < screenHeight/40+ 1; i++)
        {    
            DrawLineV((Vector2){0, (float)40*i}, (Vector2){ (float)screenWidth, (float)40*i}, LIGHTGRAY);
        }
        DrawRectangleRec(player1.rect, RED);
        DrawRectangleRec(object1.rect,GRAY);
        DrawRectangleRec(endPoint.rect,BLACK);
        EndMode2D();
        EndTextureMode();

        BeginTextureMode(screenCamera2);
        ClearBackground(RAYWHITE);
        BeginMode2D(cameraForPlayer2);
        // Draw full scene with second camera
        for (int i = 0; i < screenWidth/40+ 1; i++)
        {
            DrawLineV((Vector2){(float)40*i, 0}, (Vector2){ (float)40*i, (float)screenHeight}, LIGHTGRAY);
        }

        for (int i = 0; i < screenHeight/40+ 1; i++)
        {    
            DrawLineV((Vector2){0, (float)40*i}, (Vector2){ (float)screenWidth, (float)40*i}, LIGHTGRAY);
        }
        DrawRectangleRec(player2.rect, BLUE);
        DrawRectangleRec(object2.rect,GRAY);
        DrawRectangleRec(endPoint.rect,BLACK);
        EndMode2D();
        EndTextureMode();


        BeginDrawing();
        ClearBackground(WHITE);

        DrawTextureRec(screenCamera1.texture, splitScreenRect, (Vector2){ 0, 0 }, WHITE);
        DrawTextureRec(screenCamera2.texture, splitScreenRect, (Vector2){ screenWidth/2.0f, 0 }, WHITE);

        DrawRectangle(GetScreenWidth()/2 - 2, 0, 4, GetScreenHeight(), LIGHTGRAY);
        DrawText(TextFormat("Time left %.2f",gameTime),630,20,20,RED);
        EndDrawing();
    }
    UnloadRenderTexture(screenCamera1); // Unload render texture
    UnloadRenderTexture(screenCamera2);
    CloseWindow();

    return 0;
}