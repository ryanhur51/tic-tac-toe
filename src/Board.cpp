#include "../include/Board.h"
#include <raylib.h>

Board::Board(){
    char initialBoard[9] = {'0', '1', '2', '3', '4', '5', '6', '7', '8'};

    for (int i = 0; i < 9; i++){
        game[i] = initialBoard[i];
    }
}

void Draw(){

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
void Board::setChar(int i, char c){
    game[i] = c;
}