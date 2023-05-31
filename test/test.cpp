#include "../header/bishop.h"
#include "../header/Chess_Board.h"
#include <iostream>

using namespace std;


//this main compiles with 
//  g++ test/test.cpp src/Chess_Board.cpp src/pawn.cpp src/bishop.cpp src/knight.cpp src/king.cpp src/queen.cpp src/rook.cpp
int main()//outputs validDestinations for bishop
{
    Chess_Board myBoard = Chess_Board();
    vector<int> pos;

    pos.push_back(3);
    pos.push_back(4);
    myBoard.addPiece(pos, 'b', 'w');//adds white bishop to 3,4

    pos.at(0) = 2;
    pos.at(1) = 3;
    myBoard.addPiece(pos, 'p', 'b');//black pawn at 2,3

    pos.at(0) = 6;
    pos.at(1) = 7;
    myBoard.addPiece(pos, 'p', 'w');//white pawn at 6,7

    pos.at(0) = 1;
    pos.at(1) = 6;
    myBoard.addPiece(pos, 'p', 'b');//black pawn at 1,6

    pos.at(0) = 6;
    pos.at(1) = 1;
    myBoard.addPiece(pos, 'p', 'w');//white pawn at 6,1

    Bishop* myBishop = dynamic_cast<Bishop*>(myBoard.board[3][4]);

    vector<vector<int>> allMoves = myBishop->validDestinations(myBoard.board);
    for(int i = 0; i < allMoves.size(); i++)
    {
        for(int j = 0; j < 2; j++)
        {
            cout << allMoves[i][j];
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}