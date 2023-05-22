#ifndef ROOK_H
#define ROOK_H

#include "piece.h"

class Rook : public Piece
{
    private:

    public:
        void move(vector<int> destination) override;
        vector<vector<int>> validDestinations() override;
        char getDisplayChar() override;
};

#endif