#include <iostream>
#include "main.h"
#include "Board.h"

using namespace std;

/**
 * 0 | 1 | 2 
 * ---------
 * 3 | 4 | 5
 * ---------
 * 6 | 7 | 8
 */

int main(){
    Board board = Board(); 
    while (checkWin(board) == true){
        if (board.getTurn() == true){

        } else {

        }
    }
}

bool checkWin(Board board){
    if (board.getGame()[0] == board.getGame()[1] == board.getGame()[2] ||
        board.getGame()[3] == board.getGame()[4] == board.getGame()[5] ||
        board.getGame()[6] == board.getGame()[7] == board.getGame()[8] ||
        board.getGame()[0] == board.getGame()[3] == board.getGame()[6] ||
        board.getGame()[1] == board.getGame()[4] == board.getGame()[7] ||
        board.getGame()[2] == board.getGame()[5] == board.getGame()[8] ||
        board.getGame()[0] == board.getGame()[4] == board.getGame()[8] ||
        board.getGame()[2] == board.getGame()[4] == board.getGame()[6])
    {
        return false;
    } else {
        return true;
    }
}