#pragma once
#include <iostream>
#include "windows.h"
using std::ostream;
enum {Boulder = 'B', Floor = 'X', Hole = 'O', Wall = 'W', Character = 'P'};

class Tile
{
    public:
        Tile(); //Default Constructor
        Tile(char t); //Type Constructor
        char getType() const; //Getter for the Type
        void setType(char c); //Set Type
        bool isWalkable() const; //Returns True if the tile type is walkable
        friend ostream& operator <<(ostream & out, const Tile& t);
    private:
        char type;
        
};

Tile::Tile(){
    type = Floor;
}

Tile::Tile(char t){
    type = t;
}

char Tile::getType() const{ 
    return type;
}

void Tile::setType(char c){
    type = c;
}

bool Tile::isWalkable() const{
    if (type != Wall && type != Boulder && type != Hole){
        return true;
    }
    else return false;
}

ostream& operator <<(ostream & out, const Tile& t){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    if( t.getType() == Floor){
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN);}
    if( t.getType() == Wall){
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);}
    if( t.getType() == Hole){
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);}
    if( t.getType() == Boulder){
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_RED);}
     if( t.getType() == Character){
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE);}
    out << t.getType();
    return out;
}