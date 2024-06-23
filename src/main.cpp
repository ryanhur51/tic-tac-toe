#include <raylib.h>
#include "../include/Board.h"
#include "../include/main.h"

int main()
{
    Color white = Color{255, 255, 255, 255};
    Color black = Color{0, 0, 0, 255};

    const int screenWidth = 800;
    const int screenHeight = 800; //800px x 800px

    InitWindow(screenWidth, screenHeight, "Tic-Tac-Toe Engine");
    SetTargetFPS(60);

    Texture2D boardImage = LoadTexture("images/board.png");
    Vector2 boardPos = {0.f, 0.f};

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(white);
        DrawTextureEx(boardImage, boardPos, 0, 1.33, white);
        DrawRectangle(0, 0, 260, 260, black);
        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)){
            int x = GetMouseX();
            int y = GetMouseY();
            
        }
        
    
        EndDrawing();
    }
    UnloadTexture(boardImage);
    CloseWindow();
    return 0;
}