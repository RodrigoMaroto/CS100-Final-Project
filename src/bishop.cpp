#include "../header/bishop.h"
using namespace std;

Bishop::Bishop(char col, vector<int> pos)
{
    this->color = col;
    this->position = pos;
}
void Bishop::move(vector<int> destination)
{
   
}
vector<vector<int>> Bishop::validDestinations()
{
    vector<int> pos;
    pos.push_back(0);
    pos.push_back(0);
    int row = position.at(0);
    int column = position.at(1);
    vector<vector<int>> allMoves;
    for(int i = -7; i <= 7 ; ++i)
    {
        if(i != 0)// cant move to current position
        {
        // for diagonals - use similar alg for bishop
            row = row + i;
            column = column +i;
            if((row >=0 && row <= 7)&&(column >=0 && column <=7))// checks if location is on the board
            {
                pos.at(0) = row;
                pos.at(1) = column;
                allMoves.push_back(pos);// add move to list
            }
            //resets the position to check for rook type move
            row = position.at(0);
            column = position.at(1);
            //top left to bottom right alg for bishop move
            row = row -i;
            column = column +i;
            if((row >=0 && row <= 7)&&(column >=0 && column <=7))// checks if location is on the board
            {
                pos.at(0) = row;
                pos.at(1) = column;
                allMoves.push_back(pos);// add move to list
            }
        }
    }
}
char Bishop::getDisplayChar()
{
    if(this->color == 'w')
    {
        return '♝';
    }
    else if(this->color == 'b')
    {
        return '♗';
    }
}
