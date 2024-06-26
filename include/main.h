#pragma once

#include "Board.h"
#include <iostream>
#include <raylib.h>

using namespace std;

bool checkWin(Board board); // Checks if there are any winners in the current state of the board.
void printBoard(Board board); 
int checkAndReturnInput(Board board); // Checks if a space on the board is available or not, and returns the index of the board. 
bool checkPos(int x, int y, Board board); // Checks the mouse coordinates and sees if the spot on the board is empty or not. 
void switchTurn(Board board);

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

void printBoard(Board board){
    for (int i = 0; i < 7; i+=3){
        cout << board.getChar(i) << " | " << board.getChar(i + 1) << " | " << board.getChar(i + 2) << endl;
        if (i != 6){
            cout << "----------" << endl;
        }
    }
    cout << endl;
}

int checkAndReturnInput(Board board){
    bool flag = true;
    int x;
    do{
        cin >> x;
        if ((board.getChar(x) == 'X' || board.getChar(x) == 'O') || (x < 0 || x > 8)){;
            cout << "Incorrect input, please enter an integer that is free on the board." << endl;
            cin.clear();
        } else {
            flag = false;
        }
    } while (flag);
    return x;
}

bool checkPos(int x, int y, Board board){
    if (x < 250 && y < 250){ // Square 0.
        if (board.getChar(0) == 'X' || board.getChar(0) == 'O'){
            return true;
        } else {
            board.setChar(0, board.getTurn());
            switchTurn(board);
            return true;
        }
    } else {
        return false;
    }
    
}

void switchTurn(Board board){
    if (board.getTurn()){
        board.setTurn(false);
    } else {
        board.setTurn(true);
    }
}