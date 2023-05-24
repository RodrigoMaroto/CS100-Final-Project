//#include <gtest/gtest.h>
#include "../header/rook.h"
#include <iostream>

using namespace std;

int main()//outputs validDestinations for rook
{
    vector<int> pos;
    pos.push_back(0);
    pos.push_back(1);
    Rook myRook('w',pos);
    myRook.position = pos;
    vector<vector<int>> allMoves = myRook.validDestinations();
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