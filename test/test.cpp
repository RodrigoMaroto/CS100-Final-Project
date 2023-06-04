#include "../header/Game_Manager.h"
#include "gtest/gtest.h"
#include <vector>

using namespace std;

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

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}