#ifndef ROOK_H
#define ROOK_H

#include "piece.h"

class Rook : public Piece
{
    bool hasMoved;

    public:
        void move(vector<int> destination);
        vector<vector<int>> validDestinations();
};

#endif