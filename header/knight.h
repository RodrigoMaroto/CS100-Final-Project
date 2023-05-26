#ifndef KNIGHT_H
#define KNIGHT_H

#include "piece.h"

class Knight : public Piece
{
    private:

    public:
        Knight(char col, vector<int> pos);
        char getDisplayChar();
        void move(vector<int> destination);
        vector<vector<int>> validDestinations();
};

#endif