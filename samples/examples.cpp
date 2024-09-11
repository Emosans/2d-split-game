#include "../bin/include/raylib.h"

// enum GameScreen {
//     Logo=0,
//     Title,
//     Gameplay,
//     Endscreen
// };

// int main(){
//     const int screenWidth = 800;
//     const int screenHeight = 450;

//     InitWindow(screenWidth,screenHeight,"Screen Changer");

//     GameScreen gameScreen = Logo;

//     int frameCount = 0;
//     SetTargetFPS(60);

//     while(!WindowShouldClose()){
//         switch(gameScreen){
//             case Logo:
//             frameCount++;
//             if(frameCount>120){
//                 gameScreen=Title;
//             } //wait for 2s
//             break;

//             case Title:
//             if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
//             {
//                 gameScreen = Gameplay;
//             }
//             break;

//             case Gameplay:
//             if(IsKeyPressed(KEY_ENTER)){
//                 gameScreen = Endscreen;
//             } break;

//             case Endscreen:
//             if(IsKeyPressed(KEY_ENTER)){
//                 gameScreen=Logo;
//             } break;

//             default : break;
//         }


        
//         // Draw
//         //----------------------------------------------------------------------------------
//         BeginDrawing();

//             ClearBackground(RAYWHITE);

//             switch(gameScreen)
//             {
//                 case Logo:
//                 {
//                     // TODO: Draw LOGO screen here!
//                     DrawText("LOGO SCREEN", 20, 20, 40, LIGHTGRAY);
//                     DrawText("WAIT for 2 SECONDS...", 290, 220, 20, GRAY);

//                 } break;
//                 case Title:
//                 {
//                     // TODO: Draw TITLE screen here!
//                     DrawRectangle(0, 0, screenWidth, screenHeight, GREEN);
//                     DrawText("TITLE SCREEN", 20, 20, 40, DARKGREEN);
//                     DrawText("PRESS ENTER or TAP to JUMP to GAMEPLAY SCREEN", 120, 220, 20, DARKGREEN);

//                 } break;
//                 case Gameplay:
//                 {
//                     // TODO: Draw GAMEPLAY screen here!
//                     DrawRectangle(0, 0, screenWidth, screenHeight, PURPLE);
//                     DrawText("GAMEPLAY SCREEN", 20, 20, 40, MAROON);
//                     DrawText("PRESS ENTER or TAP to JUMP to ENDING SCREEN", 130, 220, 20, MAROON);

//                 } break;
//                 case Endscreen:
//                 {
//                     // TODO: Draw ENDING screen here!
//                     DrawRectangle(0, 0, screenWidth, screenHeight, BLUE);
//                     DrawText("ENDING SCREEN", 20, 20, 40, DARKBLUE);
//                     DrawText("PRESS ENTER or TAP to RETURN to TITLE SCREEN", 120, 220, 20, DARKBLUE);

//                 } break;
//                 default: break;
//             }

//         EndDrawing();
//         //----------------------------------------------------------------------------------
//     }

//     // De-Initialization
//     //--------------------------------------------------------------------------------------

//     // TODO: Unload all loaded data (textures, fonts, audio) here!

//     CloseWindow();        // Close window and OpenGL context
//     //--------------------------------------------------------------------------------------

//     return 0;
// }

// #define MAX_BUILDINGS 100
// //move player example 
// int main(){
//     const int screenHeight = 450;
//     const int screenWidth = 800;

//     InitWindow(screenWidth,screenHeight,"Player Movement- 2D Camera");

//     Rectangle Player = {400,280,40,40};

//     Rectangle buildings[MAX_BUILDINGS] = { 0 };
//     Color buildColors[MAX_BUILDINGS] = { 0 };

//     int spacing = 0;

//     for (int i = 0; i < MAX_BUILDINGS; i++)
//     {
//         buildings[i].width = (float)GetRandomValue(50, 200);
//         buildings[i].height = (float)GetRandomValue(100, 800);
//         buildings[i].y = screenHeight - 130.0f - buildings[i].height;
//         buildings[i].x = -6000.0f + spacing;

//         spacing += (int)buildings[i].width;

//         buildColors[i] = (Color){ 
//             (unsigned char)GetRandomValue(200, 240), 
//             (unsigned char)GetRandomValue(200, 240), 
//             (unsigned char)GetRandomValue(200, 240), 
//             255  // Assuming you want full opacity
//         };
//     }


//     //camera object 
//     Camera2D camera = {0};
//     camera.target = (Vector2) {Player.x + 20.0f , Player.y + 20.0f };
//     camera.offset = (Vector2) {screenWidth/2.0f, screenHeight/2.0f};
//     camera.rotation = 0.0f;
//     camera.zoom = 1.0f;

//     SetTargetFPS(60);

//     while(!WindowShouldClose()){

//         if(IsKeyDown(KEY_RIGHT)) Player.x+=4;
//         else if (IsKeyDown(KEY_LEFT)) Player.x-=4;

//         camera.target = (Vector2){ Player.x + 20, Player.y + 20 };

//         if(IsKeyDown(KEY_A)) camera.rotation--;
//         else if(IsKeyDown(KEY_S)) camera.rotation++;

//         if(camera.rotation>40.f) camera.rotation = 40.0f;
//         if(camera.rotation<-40.0f) camera.rotation = -40.0f;

//         camera.zoom+= (float) (GetMouseWheelMove()) * 0.05f;

//         if(camera.zoom>3.0f) camera.zoom = 3.0f;
//         if(camera.zoom<0.1f) camera.zoom = 0.1f;

//         if(IsKeyPressed(KEY_R)) {
//             camera.rotation=0.0f;
//             camera.zoom=1.0f;
//         }


//         BeginDrawing();
//         ClearBackground(RAYWHITE);
//         BeginMode2D(camera);
//         DrawRectangle(-6000,320,13000,8000,GRAY);
//         for (int i = 0; i < MAX_BUILDINGS; i++) DrawRectangleRec(buildings[i], buildColors[i]);
//         DrawRectangleRec(Player,RED);

//         EndMode2D();

//         DrawText("Screen Area",640,10,20,RED);

//         EndDrawing();
//     }
//     CloseWindow();

//     return 0;
// }




