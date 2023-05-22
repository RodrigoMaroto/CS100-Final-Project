#ifndef KNIGHT_H
#define KNIGHT_H

#include "piece.h"

class Knight : public Piece
{
    private:

    public:
        void move(vector<int> destination) override;
        vector<vector<int>> validDestinations() override;
};

#endif