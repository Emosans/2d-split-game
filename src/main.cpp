#include "../bin/include/raylib.h"
#include "../include/SplitScreen.hpp"

int main(){
    const int screenWidth = 800;
    const int screenHeight = 440;

    InitWindow(screenWidth,screenHeight,"Jump&Movement");

    // PlayerStruct playerInfo = {0};
    // playerInfo.pos = (Vector2){400,280};
    // playerInfo.speed = 0;
    // playerInfo.jump=false;

    // EnvItems envItems[]={
    //     {{ 0, 0, 1000, 400 }, 0, LIGHTGRAY },
    //     {{ 0, 400, 1000, 200 }, 1, GRAY },
    //     {{ 300, 200, 400, 10 }, 1, GRAY },
    //     {{ 250, 300, 100, 10 }, 1, GRAY },
    //     {{ 650, 300, 100, 10 }, 1, GRAY }
    // };

    // int envItemsLength = sizeof(envItems)/sizeof(envItems[0]);

    // Camera2D camera = { 0 };
    // camera.target = playerInfo.pos;
    // camera.offset = (Vector2){ screenWidth/2.0f, screenHeight/2.0f };
    // camera.rotation = 0.0f;
    // camera.zoom = 1.0f;

    // Player player;

    // SetTargetFPS(60);

    // while (!WindowShouldClose()){

    //     float deltaTime = GetFrameTime();

    //     camera.zoom += (float) GetMouseWheelMove() *0.05f;

    //     if(camera.zoom>3.0f) camera.zoom=3.0f;
    //     else if(camera.zoom< 0.1f) camera.zoom = 0.1f;

    //     player.UpdatePlayer(&playerInfo,envItems,envItemsLength,deltaTime);

    //     BeginDrawing();
    //     ClearBackground(LIGHTGRAY);
    //     BeginMode2D(camera);

    //             for (int i = 0; i < envItemsLength; i++) DrawRectangleRec(envItems[i].rect, envItems[i].color);

    //             Rectangle playerRect = { playerInfo.pos.x - 20, playerInfo.pos.y - 40, 40.0f, 40.0f };
    //             DrawRectangleRec(playerRect, RED);
                
    //             //DrawCircleV(player.position, 5.0f, GOLD);

    //     EndMode2D();
    //     EndDrawing();
    // }    
    // CloseWindow();
    SplitScreen objectCollision;

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

        if (IsKeyDown(KEY_S)) player1.pos.y += 3.0f;
        else if (IsKeyDown(KEY_W)) player1.pos.y -= 3.0f;
        if (IsKeyDown(KEY_D)) player1.pos.x += 3.0f;
        else if (IsKeyDown(KEY_A)) player1.pos.x -= 3.0f;

        if (IsKeyDown(KEY_UP)) player2.pos.y -= 3.0f;
        else if (IsKeyDown(KEY_DOWN)) player2.pos.y += 3.0f;
        if (IsKeyDown(KEY_RIGHT)) player2.pos.x += 3.0f;
        else if (IsKeyDown(KEY_LEFT)) player2.pos.x -= 3.0f;

        //check collisions with player
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
        EndMode2D();
        EndTextureMode();


        BeginDrawing();
        ClearBackground(WHITE);

        DrawTextureRec(screenCamera1.texture, splitScreenRect, (Vector2){ 0, 0 }, WHITE);
        DrawTextureRec(screenCamera2.texture, splitScreenRect, (Vector2){ screenWidth/2.0f, 0 }, WHITE);

        DrawRectangle(GetScreenWidth()/2 - 2, 0, 4, GetScreenHeight(), LIGHTGRAY);

        EndDrawing();
    }
    UnloadRenderTexture(screenCamera1); // Unload render texture
    UnloadRenderTexture(screenCamera2);
    CloseWindow();

    return 0;
}