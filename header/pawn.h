#ifndef PAWN_H
#define PAWN_H

#include "piece.h"

class Pawn : public Piece
{
    private:

    public:
        bool hasMoved();
        void move(vector<int> destination) override;
        vector<vector<int>> validDestinations() override;
};

#endif