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
   myBoard.addPiece(pos, 'b', 'w');
   pos.at(0) = 2;
   pos.at(1) = 3;
   myBoard.addPiece(pos, 'p', 'b');
   pos.at(0) = 6;
   pos.at(1) = 1;
   myBoard.addPiece(pos, 'p', 'w');
   pos.at(0) = 1;
   pos.at(1) = 6;
   myBoard.addPiece(pos, 'p', 'b');
   pos.at(0) = 6;
   pos.at(1) = 7;
   myBoard.addPiece(pos, 'p', 'w');
   Bishop* myBishop = dynamic_cast<Bishop*>(myBoard.board[3][4]);
   vector<vector<int>> allMoves = myBishop->validDestinations(myBoard.board);
   vector<vector<int>> matcher = {{4,5},{5,6},{2,5},{1,6},{2,3},{4,3},{5,2}};
   EXPECT_THAT(allMoves, testing::UnorderedElementsAreArray<vector<vector<int>>>(matcher));
}
TEST(ValidDestinations, BishopNearEdge)
{
   Chess_Board myBoard = Chess_Board();
   vector<int> pos;
   pos.push_back(3);
   pos.push_back(1);
   myBoard.addPiece(pos, 'b', 'w');
   pos.at(0) = 2;
   pos.at(1) = 0;
   myBoard.addPiece(pos, 'b', 'b');
   pos.at(0) = 0;
   pos.at(1) = 4;
   myBoard.addPiece(pos, 'p', 'w');
   Bishop* myBishop = dynamic_cast<Bishop*>(myBoard.board[3][4]);
   vector<vector<int>> allMoves = myBishop->validDestinations(myBoard.board);
   vector<vector<int>> matcher = {{4,2},{5,3},{6,4},{7,5},{2,2},{1,3},{2,0},{4,0}};
   EXPECT_THAT(allMoves, testing::UnorderedElementsAreArray<vector<vector<int>>>(matcher));
}

TEST(ValidDestinations, RookNearCenter)
{
    Chess_Board myBoard = Chess_Board();
    vector<int> pos;
    pos.push_back(3);
    pos.push_back(4);
    myBoard.addPiece(pos, 'r', 'w');
    pos.at(0) = 1;
    pos.at(1) = 4;
    myBoard.addPiece(pos, 'p', 'b');
    pos.at(0) = 3;
    pos.at(1) = 0;
    myBoard.addPiece(pos, 'p', 'w');
    pos.at(0) = 7;
    pos.at(1) = 4;
    myBoard.addPiece(pos, 'p', 'b');
    pos.at(0) = 3;
    pos.at(1) = 5;
    myBoard.addPiece(pos, 'p', 'w');
    Rook* myRook = dynamic_cast<Rook*>(myBoard.board[3][4]);
    vector<vector<int>> allMoves = myRook->validDestinations(myBoard.board);
    vector<vector<int>> matcher = {{2,4},{1,4},{4,4},{5,4},{6,4},{7,4},{3,3},{3,2},{3,1}};
    EXPECT_THAT(allMoves, testing::UnorderedElementsAreArray<vector<vector<int>>>(matcher));
}
TEST(ValidDestinations, RookAtEdge)
{
    Chess_Board myBoard = Chess_Board();
    vector<int> pos;
    pos.push_back(0);
    pos.push_back(0);
    myBoard.addPiece(pos, 'r', 'w');
    pos.at(0) = 7;
    pos.at(1) = 0;
    myBoard.addPiece(pos, 'p', 'b');
    pos.at(0) = 0;
    pos.at(1) = 7;
    myBoard.addPiece(pos, 'p', 'b');
    Rook* myRook = dynamic_cast<Rook*>(myBoard.board[3][4]);
    vector<vector<int>> allMoves = myRook->validDestinations(myBoard.board);
    vector<vector<int>> matcher = {{1,0},{2,0},{3,0},{4,0},{5,0},{6,0},{0,1},{0,2},{0,3},{0,4},{0,5},{0,6},{0,7}};
    EXPECT_THAT(allMoves, testing::UnorderedElementsAreArray<vector<vector<int>>>(matcher));
}



int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}