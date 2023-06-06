#include "../header/Game_Manager.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include <vector>

using namespace std;
using testing::UnorderedElementsAreArray;

TEST(MockTest, test1){
    EXPECT_TRUE(1==1);
}

TEST(ValidDestinations, BishopNearCenter)
{
   Chess_Board myBoard = Chess_Board();
   vector<int> pos;
   pos.push_back(3);
   pos.push_back(4);
   myBoard.addPiece(pos, 'b', 'w');//adds white rook to 3,4
   pos.at(0) = 2;
   pos.at(1) = 3;
   myBoard.addPiece(pos, 'p', 'b');//black pawn at 2, 3
   pos.at(0) = 6;
   pos.at(1) = 1;
   myBoard.addPiece(pos, 'p', 'w');//white pawn at 6,1
   pos.at(0) = 1;
   pos.at(1) = 6;
   myBoard.addPiece(pos, 'p', 'b');//black pawn at 1,6
   pos.at(0) = 6;
   pos.at(1) = 7;
   myBoard.addPiece(pos, 'p', 'w');//white pawn at 6,7
   Bishop* myBishop = dynamic_cast<Bishop*>(myBoard.board[3][4]);
   vector<vector<int>> allMoves = myBishop->validDestinations(myBoard.board);
   vector<vector<int>> matcher = {{4,5},{5,6},{2,5},{1,6},{2,3},{4,3},{5,2}};
   EXPECT_THAT(allMoves, testing::UnorderedElementsAreArray<vector<vector<int>>>(matcher));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}