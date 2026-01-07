#include <iostream>
#include "Tile.h"
#include "Board.h"
#include "Player.h"
#include "Game.h"
using namespace std;

int main() {
    Game newGame;
    newGame.initializeGame("C:\\Users\\benja\\OneDrive\\Documents\\CS1410 Final Project\\Level.txt");
    newGame.run();
    return 0;
}
