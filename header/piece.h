#ifndef PIECE_H
#define PIECE_H

#include <vector>
using namespace std;

class Piece
{
    private:
        char color;
        vector<int> position;

    public:
        virtual void move() = 0;
        virtual vector<vector<int>> validDestinations() = 0;
        virtual char getDisplayChar();
};

#endif