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
        bool promote(vector<vector<int>> moves);
        bool castle(vector<vector<int>> moves);
        bool enPassant(vector<vector<int>> moves);
        void move(vector<int> destination, vector<int> currentLocation);
        void inputMove();
        bool isWhiteTurn;
        vector<string> playedMoves;
        Chess_Board chessboard;
};

#endif