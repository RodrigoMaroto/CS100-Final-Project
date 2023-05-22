#include "../header/bishop.h"
#include <iostream>

using namespace std;
int main()
{
    vector<int> pos;
    pos.push_back(3);
    pos.push_back(4);
    Bishop myBishop;
    myBishop.position = pos;
    vector<vector<int>> allMoves = validDestinations(pos);
    for(int i = 0; i < allMoves.size(); i++)
    {
        for(int j = 0; j < 2; i++)
        {
            cout << allMoves[i][j];
        }
    }
    return 0;
}