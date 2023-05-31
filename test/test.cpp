#include "../header/rook.h"
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
    myBoard.addPiece(pos, 'r', 'w');//adds white rook to 3,4

    pos.at(0) = 1;
    pos.at(1) = 4;
    myBoard.addPiece(pos, 'p', 'b');//black pawn at 1, 4

    pos.at(0) = 3;
    pos.at(1) = 0;
    myBoard.addPiece(pos, 'p', 'w');//white pawn at 3,0

    pos.at(0) = 7;
    pos.at(1) = 4;
    myBoard.addPiece(pos, 'p', 'b');//black pawn at 7,4

    pos.at(0) = 3;
    pos.at(1) = 5;
    myBoard.addPiece(pos, 'p', 'w');//white pawn at 3,5

    Rook* myRook = dynamic_cast<Rook*>(myBoard.board[3][4]);

    vector<vector<int>> allMoves = myRook->validDestinations(myBoard.board);
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