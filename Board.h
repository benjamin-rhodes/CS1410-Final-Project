    #pragma once
    #include <vector>
    #include <string>
    #include <iostream>
    #include <fstream>
    #include <sstream>
    #include "windows.h"
    #include "Tile.h"
    using std::vector;
    using std::string;
    using std::ostream;
    using std::stringstream;
    using std::ifstream;
    using std::ios;
    using std::endl;

    class Board
    {
        public:
            Board();
            void loadFromFile(const string& filename);
            int getRows() const;
            int getCols() const;
            Tile& getTile(int r, int c);
            const Tile& getTile(int r, int c) const; //const version for player.h
            friend ostream& operator <<(ostream & out, const Board& board);
            
        private:
            vector<vector<Tile>> tiles;
            int rows, cols;
        
    };

    Board::Board(){
         rows = 0;
         cols = 0;
    }

    int Board::getRows() const{
        return tiles.size();
    }

    int Board::getCols() const{
        return tiles[0].size();
    }

    Tile& Board::getTile(int r, int c){
        return tiles[r][c];
    }

    const Tile& Board::getTile(int r, int c) const{
        return tiles[r][c];
    }
    void Board::loadFromFile(const string& filename){
         ifstream fin(filename, ios::in);
         string line;
         int ln = 0;

         while(getline(fin, line)) {
            if (line.empty()) break; 

            vector<Tile> temp;
            tiles.push_back(temp);

             for(char i: line)
             {
                 tiles[ln].push_back(Tile(i));
             }
            ln++;
         }
          rows = tiles.size();
          cols = tiles[0].size();
    }

    ostream& operator <<(ostream & out, const Board& board){
        //  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

        // // Set text color to green
        //  SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
        for(int r = 0; r < board.tiles.size(); r++){
            for(int c = 0; c < board.tiles[0].size(); c++){
                out << board.tiles[r][c] << "  ";
            }
            out << endl;
        }
        return out;
    }