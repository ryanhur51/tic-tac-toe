#include "Board.h"

Board::Board(){
    char initialBoard[9] = {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'};

    for (int i = 0; i < 9; i++){
        game[i] = initialBoard[i];
    }
}

bool Board::getTurn(){
    return true;
}

void Board::setTurn(bool flag){
    turn = flag;
}

array<char, 9> Board::getGame(){
    return game;
}