#ifndef BISHOP_H
#define BISHOP_H

#include "piece.h"

class Bishop : public Piece
{
    private:

    public:
        Bishop();
        void move(vector<int> destination) ;
        vector<vector<int>> validDestinations() ;
        char getDisplayChar();
};

#endif