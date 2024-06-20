#include <raylib.h>
#include "Board.h"
#include "main.h"

int main()
{
    Color white = Color{252, 252, 252, 252};

    const int screenWidth = 800;
    const int screenHeight = 800; //800px x 800px

    Board board = Board();

    InitWindow(screenWidth, screenHeight, "Tic-Tac-Toe Engine");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(white);
        board.Draw();


/**
 * 0 | 1 | 2 
 * ---------
 * 3 | 4 | 5
 * ---------
 * 6 | 7 | 8


int main(){
    int x;
    Board board = Board(); 
    board.setTurn(true);
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
        }
    }
    printBoard(board);
}
*/



        EndDrawing();
    }

    CloseWindow();
    return 0;
}