#ifndef PAWN_H
#define PAWN_H

#include "piece.h"

class Pawn : public Piece
{
    private:
        
    public:
        bool hasMoved;
        Pawn(char col, vector<int> pos);
        char getDisplayChar();
        void move(vector<int> destination);
        vector<vector<int>> validDestinations();
};

#endif