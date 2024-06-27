#pragma once

#include <vector>
#include "Board.h"
#include <raylib.h>

using namespace std;

bool checkWin(Board board); // Checks if there are any winners in the current state of the board.
void checkPos(int x, int y, Board& board, const vector<Vector2>& list); // Checks the mouse coordinates and sees if the spot on the board is empty or not. 
void checkAndPush(Board& board, int i, vector<Vector2>& list, const vector<Vector2>& coordinates); //Checks if the spot is empty and pushes one of the coordinates into list.
void switchTurn(Board& board); //Switches the turn from player to engine or vice versa. 

bool checkWin(Board board){
    array<char, 9> arr = board.getGame();
    return ((arr[0] == arr[1] && arr[1] == arr[2]) || 
            (arr[3] == arr[4] && arr[4] == arr[5]) || 
            (arr[6] == arr[7] && arr[7] == arr[8]) || 
            (arr[0] == arr[4] && arr[4] == arr[8]) || 
            (arr[2] == arr[4] && arr[4] == arr[6]) || 
            (arr[0] == arr[3] && arr[3] == arr[6]) || 
            (arr[1] == arr[4] && arr[4] == arr[7]) || 
            (arr[2] == arr[5] && arr[5] == arr[8]));
}

void checkPos(int x, int y, Board& board, vector<Vector2>& list, const vector<Vector2>& coordinates){
    if (x < 240 && y < 240) { // Square 0.
        checkAndPush(board, 0, list, coordinates);
    } else if (x > 285 && x < 525 && y < 240) { // Square 1.
        checkAndPush(board, 1, list, coordinates);
    } else if (x > 570 && x < 800 && y < 240) { // Square 2.
        checkAndPush(board, 2, list, coordinates);
    } else if (x < 240 && y > 290 && y < 530) { // Square 3.
        checkAndPush(board, 3, list, coordinates);
    } else if (x > 285 && x < 525 && y > 290 && y < 530) { // Square 4.
        checkAndPush(board, 4, list, coordinates);
    } else if (x > 570 && x < 800 && y > 290 && y < 530) { // Square 5.
        checkAndPush(board, 5, list, coordinates);
    } else if (x < 240 && y > 570 && y < 800) { // Square 6.
        checkAndPush(board, 6, list, coordinates);
    } else if (x > 285 && x < 525 && y > 570 && y < 800) { // Square 7.
        checkAndPush(board, 7, list, coordinates);
    } else if (x > 570 && x < 800 && y > 570 && y < 800) { // Square 8.
        checkAndPush(board, 8, list, coordinates);
    }
    return;
}

void checkAndPush(Board& board,  int i, vector<Vector2>& list, const vector<Vector2>& coordinates){
    if (board.getChar(i) == 'X' || board.getChar(i) == 'O'){
        return;
    } else {
        board.setChar(i, board.getTurn());
        list.push_back(coordinates[i]);
        switchTurn(board);
        return;
    }
}

void switchTurn(Board& board){
    if (board.getTurn()){
        board.setTurn(false);
    } else {
        board.setTurn(true);
    }
}