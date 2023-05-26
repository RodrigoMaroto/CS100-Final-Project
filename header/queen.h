#ifndef QUEEN_H
#define QUEEN_H

#include "piece.h"

class Queen : public Piece
{
    public:
        Queen(char col, vector<int> pos);
        string getDisplayChar();
        void move(vector<int> destination) override;
        vector<vector<int>> validDestinations() override;
};

#endif