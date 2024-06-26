#include <raylib.h>
#include <vector>
#include "../include/Board.h"
#include "../include/engine.h"
#include "../include/main.h"

int main(){
    const int screenWidth = 800;
    const int screenHeight = 800; 

    InitWindow(screenWidth, screenHeight, "Tic-Tac-Toe Engine");
    SetTargetFPS(60);

    Texture2D boardImage = LoadTexture("images/board.png");
    Texture2D xImage = LoadTexture("images/X.png");
    Texture2D oImage = LoadTexture("images/O.png");

    Vector2 boardPos = {-50.f, -50.f};

    Board board = Board();
    board.setTurn(true);

    vector<Vector2> coordinates{{0.f, 0.f},   {285.f, 0.f},   {570.f, 0.f}, 
                                {0.f, 290.f}, {285.f, 290.f}, {570.f, 290.f}, 
                                {0.f, 570.f}, {285.f, 570.f}, {570.f, 570.f}};
    vector<Vector2> xList;
    vector<Vector2> oList;

    while (!WindowShouldClose()){
        DrawTextureEx(boardImage, boardPos, 0, 1.5, WHITE);

        if (board.getTurn() == true){ //Player's turn.
            if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)){ 
                int x = GetMouseX();
                int y = GetMouseY();
                checkPos(x, y, board, xList, coordinates); // Check the position if open
            } 
        } else { // Engine's turn.

        }

        for (int i = 0; i < (int)xList.size(); i++){
            DrawTextureEx(xImage, xList[i], 0, 0.038, WHITE);
        }
        for (int i = 0; i < (int)oList.size(); i++){
            DrawTextureEx(oImage, oList[i], 0, 0.1, WHITE);
        }
        BeginDrawing();
        ClearBackground(WHITE);
        EndDrawing();
    }
    
    UnloadTexture(boardImage);
    UnloadTexture(xImage);
    CloseWindow();
    return 0;
}