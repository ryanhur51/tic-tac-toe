#pragma once

#include "Board.h"
#include "main.h"
#include <vector>
#include <raylib.h>
#include <iostream>
#include <algorithm>

using namespace std;

// Minimax functions

bool terminal(Board board); // Determines if the board is full or if there was a winner.
int value(Board board); // Returns a value (between -1 and 1) given a terminal board. 
vector<int> actions(Board board); // Returns a vector of available squares. 
Board result(Board board, int x, bool turn); // Returns a board after a specified turn.
int findBestMove(Board board);  
int minimax(Board board, int depth, bool isMax);


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
        }
    }
    return action;
}

Board result(Board board, int x, bool turn){
    board.setChar(x, turn);
    return board;
}

int findBestMove(Board board){
    vector<int> moves = actions(board);
    int bestScore = -1000;
    int bestMove;

    for (int i = 0; i < (int)moves.size(); i++){
        int score = minimax(result(board, moves[i], true), 0, false); // could be an error
        if (score >= bestScore){
            bestScore = score;
            bestMove = moves[i];
        }
    }
    return bestMove;
}

int minimax(Board board, int depth, bool isMax){
    if (terminal(board)){
        return value(board);
    } 

    if (isMax){ //Max-er (Engine)
        int bestScore = -1000;
        vector<int> moves = actions(board);
        for (int i = 0; i < (int)moves.size(); i++){
            int score = minimax(result(board, moves[i], true), depth+1, false);
            bestScore = max(score-depth, bestScore);
        }
        return bestScore;
    } else { // Min-er (Player)
        int bestScore = 1000;
        vector<int> moves = actions(board);
        for (int i = 0; i < (int)moves.size(); i++){
            int score = minimax(result(board, moves[i], false), depth+1, true);
            bestScore = min(score+depth, bestScore);
        }
        return bestScore;
    }
}

