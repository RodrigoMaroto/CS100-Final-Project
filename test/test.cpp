
#include "../header/rook.h"
#include <iostream>

using namespace std;

int main()//outputs validDestinations for bishop
{
    vector<int> pos;
    pos.push_back(3);
    pos.push_back(4);
    Bishop myBishop('w',pos);
    myBishop.position = pos;
    vector<vector<int>> allMoves = myBishop.validDestinations();
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