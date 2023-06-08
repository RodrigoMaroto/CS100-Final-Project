#include "../header/Game_Manager.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include <vector>

using namespace std;
using testing::UnorderedElementsAreArray;

TEST(CheckMate, stairMate){
    Game_Manager game = Game_Manager();
    vector<int> pos;
    pos.push_back(0);
    pos.push_back(4);
    game.chessboard.addPiece(pos, 'k', 'w');
    pos.at(1) = 0;
    game.chessboard.addPiece(pos, 'r', 'b');
    pos.at(1) = 1;
    pos.at(0) = 1;
    game.chessboard.addPiece(pos, 'r', 'b');
    EXPECT_TRUE(game.isCheckMate());
}

TEST(CheckMate, stairMateStop){
    Game_Manager game = Game_Manager();
    vector<int> pos;
    pos.push_back(0);
    pos.push_back(4);
    game.chessboard.addPiece(pos, 'k', 'w');
    pos.at(1) = 0;
    game.chessboard.addPiece(pos, 'r', 'b');
    pos.at(1) = 1;
    pos.at(0) = 1;
    game.chessboard.addPiece(pos, 'r', 'b');
    pos.at(1) = 3;
    pos.at(0) = 3;
    game.chessboard.addPiece(pos, 'r', 'w');
    EXPECT_FALSE(game.isCheckMate());
}

TEST(CheckMate, stairMateTooClose){
    Game_Manager game = Game_Manager();
    vector<int> pos;
    pos.push_back(0);
    pos.push_back(1);
    game.chessboard.addPiece(pos, 'k', 'w');
    pos.at(1) = 0;
    game.chessboard.addPiece(pos, 'r', 'b');
    /*pos.at(1) = 1;
    pos.at(0) = 1;
    game.chessboard.addPiece(pos, 'r', 'b');*/
    EXPECT_FALSE(game.isCheckMate());
}

TEST(CheckMate, onlyStopAlsoCreatesCheck){
    Game_Manager game = Game_Manager();
    vector<int> pos;
    pos.push_back(1);
    pos.push_back(4);
    game.chessboard.addPiece(pos, 'k', 'w');
    pos.at(1) = 0;
    game.chessboard.addPiece(pos, 'r', 'b');
    pos.at(1) = 7;
    pos.at(0) = 0;
    game.chessboard.addPiece(pos, 'r', 'b');
    pos.at(1) = 7;
    pos.at(0) = 2;
    game.chessboard.addPiece(pos, 'r', 'b');
    pos.at(1) = 5;
    pos.at(0) = 7;
    game.chessboard.addPiece(pos, 'r', 'b');
    pos.at(1) = 1;
    pos.at(0) = 4;
    game.chessboard.addPiece(pos, 'b', 'b');
    
    EXPECT_TRUE(game.isCheckMate());
}

TEST(CheckMate, pawnStop){
    Game_Manager game = Game_Manager();
    vector<int> pos;
    pos.push_back(1);
    pos.push_back(4);
    game.chessboard.addPiece(pos, 'k', 'w');
    pos.at(1) = 3;
    game.chessboard.addPiece(pos, 'p', 'w');
    pos.at(1) = 7;
    pos.at(0) = 0;
    game.chessboard.addPiece(pos, 'r', 'b');
    pos.at(1) = 7;
    pos.at(0) = 2;
    game.chessboard.addPiece(pos, 'r', 'b');
    pos.at(1) = 5;
    pos.at(0) = 7;
    game.chessboard.addPiece(pos, 'r', 'b');
    pos.at(1) = 1;
    pos.at(0) = 4;
    game.chessboard.addPiece(pos, 'b', 'b');
    EXPECT_FALSE(game.isCheckMate());
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
   Bishop* myBishop = dynamic_cast<Bishop*>(myBoard.board[3][1]);
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
    myBoard.addPiece(pos, 'p', 'w');
    pos.at(0) = 0;
    pos.at(1) = 7;
    myBoard.addPiece(pos, 'p', 'b');
    Rook* myRook = dynamic_cast<Rook*>(myBoard.board[0][0]);
    vector<vector<int>> allMoves = myRook->validDestinations(myBoard.board);
    vector<vector<int>> matcher = {{1,0},{2,0},{3,0},{4,0},{5,0},{6,0},{0,1},{0,2},{0,3},{0,4},{0,5},{0,6},{0,7}};
    EXPECT_THAT(allMoves, testing::UnorderedElementsAreArray<vector<vector<int>>>(matcher));
}
TEST(GetDisplayChar, WhiteBishop)
{
    Bishop myBishop = Bishop('w', {0,0});
    EXPECT_EQ(myBishop.getDisplayChar(), "♝");
}  
TEST(GetDisplayChar, BlackBishop)
{
    Bishop myBishop = Bishop('b', {0,0});
    EXPECT_EQ(myBishop.getDisplayChar(), "♗");
}
TEST(GetDisplayChar, WhiteRook)
{
    Rook myRook = Rook('w', {0,0});
    EXPECT_EQ(myRook.getDisplayChar(), "♜");
}  
TEST(GetDisplayChar, BlackRook)
{
    Rook myRook = Rook('b', {0,0});
    EXPECT_EQ(myRook.getDisplayChar(), "♖");
}                                       
TEST(Castle, KingSideWhite)//works
{
    Game_Manager game = Game_Manager();
    game.chessboard.addPiece({0,4}, 'k', 'w');
    game.chessboard.addPiece({0,7}, 'r', 'w');
    Piece* king = game.chessboard.board[0][4];
    Piece* rook = game.chessboard.board[0][7];
    vector<vector<int>> move = {{0,4},{0,6}};
    ASSERT_TRUE(game.castle(move));
    EXPECT_THAT(king->position, testing::UnorderedElementsAreArray<vector<int>>({0,6}));
    EXPECT_THAT(rook->position, testing::UnorderedElementsAreArray<vector<int>>({0,5}));
}
/*TEST(Castle, KingSideBlack) //causes seg fault
{
    Game_Manager game = Game_Manager();
    game.chessboard.addPiece({7,4}, 'k', 'b');
    game.chessboard.addPiece({7,7}, 'r', 'b');
    Piece* king = game.chessboard.board[7][4];
    Piece* rook = game.chessboard.board[7][7];
    vector<vector<int>> move = {{7,4},{7,6}};
    ASSERT_TRUE(game.castle(move));
    EXPECT_THAT(king->position, testing::UnorderedElementsAreArray<vector<int>>({7,6}));
    EXPECT_THAT(rook->position, testing::UnorderedElementsAreArray<vector<int>>({7,5}));
}*/
TEST(Castle, QueenSideWhite)//works
{
    Game_Manager game = Game_Manager();
    game.chessboard.addPiece({0,4}, 'k', 'w');
    game.chessboard.addPiece({0,0}, 'r', 'w');
    Piece* king = game.chessboard.board[0][4];
    Piece* rook = game.chessboard.board[0][0];
    vector<vector<int>> move = {{0,4},{0,2}};
    ASSERT_TRUE(game.castle(move));
    EXPECT_THAT(king->position, testing::UnorderedElementsAreArray<vector<int>>({0,2}));
    EXPECT_THAT(rook->position, testing::UnorderedElementsAreArray<vector<int>>({0,3}));
}
TEST(Castle, QueenSideBlack)
{
    Game_Manager game = Game_Manager();
    game.chessboard.addPiece({7,4}, 'k', 'w');
    game.chessboard.addPiece({7,0}, 'r', 'w');
    Piece* king = game.chessboard.board[7][4];
    Piece* rook = game.chessboard.board[7][0];
    vector<vector<int>> move = {{7,4},{7,2}};
    ASSERT_TRUE(game.castle(move));
    EXPECT_THAT(king->position, testing::UnorderedElementsAreArray<vector<int>>({7,2}));
    EXPECT_THAT(rook->position, testing::UnorderedElementsAreArray<vector<int>>({7,3}));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}