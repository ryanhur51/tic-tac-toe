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
    Texture2D XImage = LoadTexture("images/X.png");
    Vector2 boardPos = {0.f, 0.f};

    Board board = Board();
    board.setTurn(true);
    
    bool xFlag = false;
    bool oFlag = false;
    while (!WindowShouldClose())
    {
       
        DrawTextureEx(boardImage, boardPos, 0, 1.33, white);
        
        if (board.getTurn() == true){ //Player's turn.
            if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)){
                int x = GetMouseX();
                int y = GetMouseY();
                xFlag = checkPos(x, y);
                board.setTurn(false);
            } else { //Engine's turn

            }
        }
        BeginDrawing();
        ClearBackground(white);
        EndDrawing();
    }


    UnloadTexture(boardImage);
    UnloadTexture(XImage);
    CloseWindow();
    return 0;
}

/**
 *   board.setTurn(true);
    while (checkWin(board) == false){
        printBoard(board);
        if (board.getTurn() == true){
            cout << "X turn. Pick an integer" << endl;
            x = checkAndReturnInput(board);
            board.setChar(x, 'X');
            board.setTurn(false);
        } else {
            cout << "O turn. Pick an integer" << endl;
            x = checkAndReturnInput(board);
            board.setChar(x, 'O');
            board.setTurn(true);
 */