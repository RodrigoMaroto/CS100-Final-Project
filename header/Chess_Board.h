#include "piece.h"
#include "knight.h"
#include "rook.h"
#include "pawn.h"
#include "queen.h"
#include "king.h"
#include "bishop.h"

using namespace std;

class Chess_Board
{
    private:

    public:
        void display();
        Piece* board[8][8];
        void addPiece(vector<int> position, char piece, char color)
        void initBoard();
};