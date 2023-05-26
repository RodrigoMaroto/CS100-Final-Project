#include "../header/rook.h"

Rook::Rook(char col, vector<int> pos)
{
    this->color = col;
    this->position = pos;
    this->hasMoved = false;
}
void Rook::move(vector<int> destination) 
{

}
vector<vector<int>> Rook::validDestinations()
{
    //iterate in front and behind current position, 
    //if an enemy piece is on it you can still move there, but no further
    vector<int> pos;
    int row = position.at(0);
    int column = position.at(1);
    vector<vector<int>> allMoves;
    for(int i = -7; i <= 7; i++)
    {
        if(i != 0)//cant move to same spot
        {
            pos = {row, column};
            row = row + i;
            if((row >= 0 && row <= 7)&&(column >= 0 && column <= 7))// checks if location is on the board
            {
                pos.at(0) = row;
                pos.at(1) = column;
                allMoves.push_back(pos);// add move to list
            }
            //reset position for column check
            row = position.at(0);
            column = position.at(1);
            //for rook move - column
            column = column + i;

            if((row >= 0 && row <= 7)&&(column >= 0 && column <= 7)){// checks if location is on the board
                pos.at(0) = row;
                pos.at(1) = column;
                allMoves.push_back(pos);// add move to list
            }
            row = position.at(0);
            column = position.at(1);
        }
    } 
    return allMoves;
}

string Rook::getDisplayChar()
{
    string displayChar = "no char";
    if(this->color == 'w')
    {
        displayChar = "♜";
    }  
    else if(this->color == 'b')
    {
        displayChar = "♖";
    }
    return displayChar;
}