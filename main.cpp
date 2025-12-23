//newGame.initializeGame("C:\\Users\\benja\\OneDrive\\Documents\\CS1410 Final Project\\ExtremeLevel.txt");
//newGame.initializeGame("C:\\Users\\benja\\OneDrive\\Documents\\CS1410 Final Project\\WinLevel.txt");
#include <iostream>
#include "Tile.h"
#include "Board.h"
#include "Player.h"
#include "Game.h"
using namespace std;

int main() { ///TESTINGGGGGG
    Game newGame;
    newGame.initializeGame("C:\\Users\\benja\\OneDrive\\Documents\\CS1410 Final Project\\Level.txt");
    newGame.run();
    return 0;
}
