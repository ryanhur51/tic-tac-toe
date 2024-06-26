#include <raylib.h>
#include <vector>
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
    Texture2D xImage = LoadTexture("images/X.png");
    Vector2 boardPos = {-50.f, -50.f};

    Board board = Board();
    board.setTurn(true);

    vector<Vector2> coordinates{{0.f, 0.f},   {285.f, 0.f},   {570.f, 0.f}, 
                                {0.f, 290.f}, {285.f, 290.f}, {570.f, 290.f}, 
                                {0.f, 570.f}, {285.f, 570.f}, {570.f, 570.f}};
    vector<Vector2> xList;
    vector<Vector2> oList;
    
    bool xFlag = false;
    bool oFlag = false;

    while (!WindowShouldClose()){
        DrawTextureEx(boardImage, boardPos, 0, 1.5, white);

        if (board.getTurn() == true){ //Player's turn.
            if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)){ 
                int x = GetMouseX();
                int y = GetMouseY();
                xFlag = checkPos(x, y, board); // Check the position if open
            } 
        } else { // Engine's turn.

        }

        for (int i = 0; i < coordinates.size(); i++){
            DrawTextureEx(xImage, coordinates[i], 0, 0.038, white);
           
        }

           
    
        if (oFlag){

        }
        BeginDrawing();
        ClearBackground(white);
        EndDrawing();
    }

    UnloadTexture(boardImage);
    UnloadTexture(xImage);
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