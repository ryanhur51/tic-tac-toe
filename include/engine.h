#pragma once

#include "Board.h"
#include "main.h"
#include <vector>
#include <raylib.h>

using namespace std;

// Minimax functions
// Used the psuedocode from this YouTube video: https://www.youtube.com/watch?v=SLgZhpDsrfc

bool terminal(Board board); // Determines if the board is full or if there was a winner.
int value(Board board); // Returns a value (between -1 and 1) given a terminal board. 
vector<int> actions(Board board); // Returns a vector of available squares. 
int minimax(Board board);

bool terminal(Board board){
    if (checkWin(board) || board.isFull()){
        return true;
    } else {
        return false;
    }
}

int value(Board board){
    array<char, 9> arr = board.getGame();
    if ((arr[0] == arr[1] && arr[1] == arr[2] && arr[2] == 'X') || 
        (arr[3] == arr[4] && arr[4] == arr[5] && arr[5] == 'X') || 
        (arr[6] == arr[7] && arr[7] == arr[8] && arr[8] == 'X') || 
        (arr[0] == arr[4] && arr[4] == arr[8] && arr[8] == 'X') || 
        (arr[2] == arr[4] && arr[4] == arr[6] && arr[6] == 'X') || 
        (arr[0] == arr[3] && arr[3] == arr[6] && arr[6] == 'X') || 
        (arr[1] == arr[4] && arr[4] == arr[7] && arr[7] == 'X') || 
        (arr[2] == arr[5] && arr[5] == arr[8] && arr[8] == 'X')){
            return 1;
        } else if (
        (arr[0] == arr[1] && arr[1] == arr[2] && arr[2] == 'O') || 
        (arr[3] == arr[4] && arr[4] == arr[5] && arr[5] == 'O') || 
        (arr[6] == arr[7] && arr[7] == arr[8] && arr[8] == 'O') || 
        (arr[0] == arr[4] && arr[4] == arr[8] && arr[8] == 'O') || 
        (arr[2] == arr[4] && arr[4] == arr[6] && arr[6] == 'O') || 
        (arr[0] == arr[3] && arr[3] == arr[6] && arr[6] == 'O') || 
        (arr[1] == arr[4] && arr[4] == arr[7] && arr[7] == 'O') || 
        (arr[2] == arr[5] && arr[5] == arr[8] && arr[8] == 'O')){
            return -1; 
        } else {
            return 0;
        }
}

vector<int> actions(Board board){
    vector<int> action;
    for (int i = 0; i < 9; i++){
        if (board.getChar(i) == ' '){
            action.push_back(i);
        }
    }
    return action;
}

int minimax(Board board){
    if (terminal(board)){
        return value(board);
    }
}