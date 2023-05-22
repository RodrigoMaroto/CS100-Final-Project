#ifndef ROOK_H
#define ROOK_H

#include "piece.h"

class Rook : public Piece
{
    private:
        bool hasMoved();
    public:
        void move(vector<int> destination) override;
        vector<vector<int>> validDestinations() override;
};

#endif