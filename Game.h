#pragma once
#include "Board.h"
#include "Player.h"
#include <string>
#include <iostream>
#include <iomanip>
using std::cout;
using std::cin;
using std::cerr;
using std::setprecision;
using std::fixed;
using std::endl;

class Game{
    public:
        Game();
        void initializeGame(const string & filename);
        void run();
    private:
        int totalBoulders;
        int bouldersInHole;
        int countBoulders();
        Board board;
        Player player;
        void playerInput(char input);
        bool checkWin();
        
        
};

Game::Game(){
    bouldersInHole = 0;
}

bool Game::checkWin(){
    return bouldersInHole >= totalBoulders;
}

int Game::countBoulders(){
    int count = 0;
    for (int r = 0; r < board.getRows(); r++) {
        for (int c = 0; c < board.getCols(); c++) {
            if (board.getTile(r, c).getType() == Boulder) {
                count++;
            }
        }
    }
    return count;
}

void Game::initializeGame(const string & filename){
    // Load the board from file
    board.loadFromFile(filename);
    player.startPosition(board);
    totalBoulders = countBoulders();
}

        void Game::playerInput(char input){
        int rowMove = 0, colMove = 0;

            switch(input){
                case 'w': rowMove = -1; break;
                case 's': rowMove = 1; break;
                case 'a': colMove = -1; break;
                case 'd': colMove = 1; break;
                default:
                    cerr << "Invalid input, use w/a/s/d to move." << endl;
                    return;
            }

            int curRow = player.getRow();
            int curCol = player.getCol();
            int newRow = curRow + rowMove;
            int newCol = curCol + colMove;

            if (newRow < 0 || newRow >= board.getRows() || newCol < 0 || newCol >= board.getCols()){
                cerr << "You Can't Move Out of Bounds" << endl;
                return;
            }

            Tile &currentTile = board.getTile(curRow, curCol);
            Tile &landingTile = board.getTile(newRow, newCol);

            if (landingTile.isWalkable()){ //Freely walk on floors
                player.setPosition(newRow, newCol);
                currentTile.setType(Floor);
                landingTile.setType(Character);
            }

            else if (landingTile.getType() == Boulder){ //Boulder push logic
                int pushToRow = newRow + rowMove;
                int pushToCol = newCol + colMove;

                if (pushToRow < 0 || pushToRow >= board.getRows() || pushToCol < 0 || pushToCol >= board.getCols()){
                    cerr << "You Can't Move Out of Bounds" << endl;
                    return;
                }
            Tile &pushToTile = board.getTile(pushToRow, pushToCol);
            
            if (pushToTile.isWalkable()){
                pushToTile.setType(Boulder);
                currentTile.setType(Floor);
                player.setPosition(newRow, newCol);
                landingTile.setType(Character);
            } else if (pushToTile.getType() == Hole){
                player.setPosition(newRow, newCol);
                landingTile.setType(Character);
                currentTile.setType(Floor);
                bouldersInHole++;
            }
            }
            else{
                cerr << "Can't Move There" << endl;
            }
            }

void Game::run(){
    char input;

    while(true){
        system("CLS");
        cout << board << endl;
        cout << "Boulders: " << bouldersInHole << "/" << totalBoulders << endl;
        cout <<"W/A/S/D to move Q to quit game: ";

        cin >> input;
            
        if(input == 'q' || input == 'Q'){
            cout << "Game Over ):" << endl;
            float score = (float(bouldersInHole) / totalBoulders) * 100;
            cout << "Your Score: " << setprecision(2) << fixed << score << "%" << endl;
            break;
        }

        playerInput(input);

        if(checkWin()){
            cout << "You Win!!!!!!!" << endl;
            break;
        }
    }
}