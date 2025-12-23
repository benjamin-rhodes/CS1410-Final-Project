#pragma once
#include <iostream>
#include "Board.h"
using std::ostream;

class Player
{
    public: 
        Player(int startRow = 0, int startCol = 0); //Constructor
        int getRow() const; //get player X
        int getCol() const; //get play  er Y
        void setPosition(int r, int c);
        void startPosition(const Board & board);
        friend ostream& operator <<(ostream & out, const Player& p);
    private:
        int row, col;
};

Player::Player(int startRow, int startCol){
    row = startRow;
    col = startCol;
}
int Player::getRow() const{
    return row;
}

int Player::getCol() const{
    return col;
}

void Player::setPosition(int r, int c){
    row = r;
    col = c;
}

void Player::startPosition(const Board & board) {
    for (int r = 0; r < board.getRows(); r++) {
        for (int c = 0; c < board.getCols(); c++) {
            if (board.getTile(r, c).getType() == 'P') { // Tile::getType() works
                row = r;
                col = c;
                return; // found player
            }
        }
    }
}
ostream& operator <<(ostream & out, const Player& p){
    out << "(" << p.row << ", " << p.col << ")";
    return out;
}