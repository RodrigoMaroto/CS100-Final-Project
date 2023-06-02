#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include "piece.h"
#include "knight.h"
#include "rook.h"
#include "pawn.h"
#include "queen.h"
#include "king.h"
#include "bishop.h"
#include "Chess_Board.h"
#include <vector>

using namespace std;

class Game_Manager
{
    private:

    public:
        bool inCheckMate();
        bool isStalemate();
        void Promote(vector<int> position, char piece);
        void move(vector<int> destination, vector<int> currentLocation);
        vector<string> playedMoves;
        Chess_Board chessboard;
};

#endif