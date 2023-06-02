#include "../header/Game_Manager.h"
#include "gtest/gtest.h"
#include <vector>

using namespace std;

TEST(MockTest, test1){
    EXPECT_TRUE(1==1);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}