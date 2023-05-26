#ifndef BISHOP_H
#define BISHOP_H

#include "piece.h"

class Bishop : public Piece
{
    private:

    public:
        Bishop(char col, vector<int> pos);
        void move(vector<int> destination) override;
        vector<vector<int>> validDestinations() override;
        string getDisplayChar() override;
};

#endif