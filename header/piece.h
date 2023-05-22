#ifndef PIECE_H
#define PIECE_H

#include <vector>
using namespace std;

class Piece
{
    private:
        

    public:
        char color;
        vector<int> position;
        virtual void move() = 0;
        virtual vector<vector<int>> validDestinations() = 0;
        virtual char getDisplayChar() = 0;
};

#endif