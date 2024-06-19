#include <iostream>

#include "../include/main.h"
#include "../include/Board.h"

using namespace std;

/**
 * 0 | 1 | 2 
 * ---------
 * 3 | 4 | 5
 * ---------
 * 6 | 7 | 8
 */

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


