#ifndef ROOK_H
#define ROOK_H

#include "piece.h"

class Rook : public Piece
{
    public:
        bool hasMoved;
        Rook(char col, vector<int> pos);
        void move(vector<int> destination) override;
        vector<vector<int>> validDestinations() override;
        string getDisplayChar() override;
};

#endif