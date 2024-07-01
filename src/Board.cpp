#include "../include/Board.h"

Board::Board(){
    // Chose to do a 1D board because I felt it would have been easier to manage since there are only 9 tiles in a board. 
    char initialBoard[9] = {'0', '0', '0', '0', '0', '0', '0', '0', '0'};

    for (int i = 0; i < 9; i++){
        game[i] = initialBoard[i];
    }
}

array<char, 9> Board::getGame(){
    return game;
}

bool Board::getTurn(){
    return turn;
}

void Board::setTurn(bool flag){
    turn = flag;
}
char Board::getChar(int i){
    return game[i];
}
void Board::setChar(int i, bool turn){
    if (turn){
        game[i] = 'X';
    } else {
        game[i] = 'O';
    }
}
bool Board::isFull(){
    for (int i = 0; i < 9; i++){
        if (game[i] != 'X' || game[i] != 'O'){
            return false;
        }
    }
    return true;
}