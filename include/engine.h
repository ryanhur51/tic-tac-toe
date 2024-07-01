#pragma once

#include "Board.h"
#include "main.h"
#include <vector>
#include <raylib.h>
#include <iostream>
#include <algorithm>

using namespace std;

// Minimax functions
// Used the psuedocode from this YouTube video: https://www.youtube.com/watch?v=SLgZhpDsrfc

bool terminal(Board board); // Determines if the board is full or if there was a winner.
int value(Board board); // Returns a value (between -1 and 1) given a terminal board. 
vector<int> actions(Board board); // Returns a vector of available squares. 
Board result(Board board, int x);
bool player(Board board); // true -> X turn. false -> O turn. 
int minimax(Board board, int &x);


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
            return 10;
        } else if (
        (arr[0] == arr[1] && arr[1] == arr[2] && arr[2] == 'O') || 
        (arr[3] == arr[4] && arr[4] == arr[5] && arr[5] == 'O') || 
        (arr[6] == arr[7] && arr[7] == arr[8] && arr[8] == 'O') || 
        (arr[0] == arr[4] && arr[4] == arr[8] && arr[8] == 'O') || 
        (arr[2] == arr[4] && arr[4] == arr[6] && arr[6] == 'O') || 
        (arr[0] == arr[3] && arr[3] == arr[6] && arr[6] == 'O') || 
        (arr[1] == arr[4] && arr[4] == arr[7] && arr[7] == 'O') || 
        (arr[2] == arr[5] && arr[5] == arr[8] && arr[8] == 'O')){
            return -10; 
        } else {
            return 0;
        }
}

vector<int> actions(Board board){
    vector<int> action;
    for (int i = 0; i < 9; i++){
        if (board.getChar(i) == '0'){
            action.push_back(i);
            cout << i << endl;
        }
    }
    return action;
}

Board result(Board board, int x){
    board.setChar(x, player(board));
    return board;
}

bool player(Board board){
    int xCount = 0, oCount = 0;
    array<char, 9> arr = board.getGame();
    for (int i = 0; i < 9; i++){
        if (arr[i] == 'X'){
            xCount++;
        } else if (arr[i] == 'O'){
            oCount++;
        }
    }

    if (xCount == oCount){
        return true;
    } else {
        return false;
    }
}

int minimax(Board board, int &x){
    if (terminal(board)){
        return value(board);
    } 

    if (player(board) == false){
        int val = -1000;
        vector<int> moves = actions(board);
        for (int i = 0; i < (int)moves.size(); i++){
            if (val < minimax(result(board, moves[i]), x)){
                x = moves[i];
                val = minimax(result(board, moves[i]), x);
              
            }
        }
        return val;
    } else {
        int val = 1000;
        vector<int> moves = actions(board);
        for (int i = 0; i < (int)moves.size(); i++){
            //val = max(val, minimax(result(board, moves[i])));
            if (val > minimax(result(board, moves[i]), x)){
                x = moves[i];
                val = minimax(result(board, moves[i]), x);
                
            }
        }
        return val;
    }
    cout << "error";
    return -1;
}

