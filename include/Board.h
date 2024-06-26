#pragma once

#include <array>

using namespace std;

class Board{
    private:
        array<char, 9> game;
        bool turn; //true = X turn. false = O turn. 
        char player;

    public:
        Board();

        array<char, 9> getGame(); 

        bool getTurn();
        void setTurn(bool flag);

        char getPlayer();
        void setPlayer();

        char getChar(int i);
        void setChar(int i, bool turn);
};