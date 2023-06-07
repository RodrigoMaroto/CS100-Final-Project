#include "../header/Game_Manager.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include <vector>

using namespace std;
using testing::UnorderedElementsAreArray;

TEST(MockTest, test1){
    EXPECT_TRUE(1==1);
}
TEST(PromotePawn, PromoteWhite)
{
    Chess_Board myBoard = Chess_Board();
    Game_Manager game = Game_Manager();
    myBoard.addPiece({6,3}, 'p', 'w');
    Piece* pawn = myBoard.board[6][3];
    vector<vector<int>> move = {{6,3},{7,3}};
    EXPECT_TRUE(game.promote(move));
    EXPECT_THAT(pawn->position, testing::UnorderedElementsAreArray<vector<int>>({7,3}));
}
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}