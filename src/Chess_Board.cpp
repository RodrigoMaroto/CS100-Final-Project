#include "../header/Chess_Board.h"
#include "../header/piece.h"
#include "../header/knight.h"
#include "../header/rook.h"
#include "../header/pawn.h"
#include "../header/queen.h"
#include "../header/king.h"
#include "../header/bishop.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;


Chess_Board::Chess_Board() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            board[i][j] = nullptr;
        }
    }
}

void Chess_Board::addPiece(vector<int> position, char piece, char color) {
    int row = position.at(0);
    int column = position.at(1);
    if (piece == 'b')
        board[row][column] = new Bishop(color, position);
    else if (piece == 'p')
        board[row][column] = new Pawn(color, position);
    else if (piece == 'k')
        board[row][column] = new King(color, position);
    else if (piece == 'q')
        board[row][column] = new Queen(color, position);
    else if (piece == 'n')
        board[row][column] = new Knight(color, position);
    else if (piece == 'r')
        board[row][column] = new Rook(color, position);
}

