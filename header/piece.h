#ifndef PIECE_H
#define PIECE_H

#include <vector>
using namespace std;

class Piece
{
    public:
        char color;
        vector<int> position;

    public:
        virtual void move(vector<int> destination) = 0;
        virtual vector<vector<int>> validDestinations() = 0;
        virtual char getDisplayChar() = 0;
};

#endif