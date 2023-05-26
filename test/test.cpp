#include "../header/pawn.h"
#include <iostream>

using namespace std;

int main()//outputs validDestinations for pawn
{
    vector<int> pos;
    pos.push_back(0);
    pos.push_back(1);
    Pawn myPawn('w',pos);
    myPawn.position = pos;
    vector<vector<int>> allMoves = myPawn.validDestinations();
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