#ifndef MAIN_H
#define MAIN_H

#include "Board.h"
#include <iostream>

using namespace std;

bool checkWin(Board board);
void printBoard(Board board);
int checkAndReturnInput(Board board);


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

#endif