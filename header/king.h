#ifndef KING_H
#define KING_H

#include "piece.h"

class King : public Piece
{
    public:
        bool hasMoved;
        King(char col, vector<int> pos);
        string getDisplayChar();
        void move(vector<int> destination) override;
        vector<vector<int>> validDestinations() override;
};

#endif