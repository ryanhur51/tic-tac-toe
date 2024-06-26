#pragma once

#include "Board.h"
#include "main.h"
#include <raylib.h>

using namespace std;

//Minimax functions
bool terminal(Board board);
int value(Board board);

bool terminal(Board board){
    if (checkWin(board) || board.isFull()){
        return true;
    } else {
        return false;
    }
}