#include "../header/rook.h"

Rook::Rook(char col, vector<int> pos)
{
    this->color = col;
    this->position = pos;
    this->hasMoved = false;
}

vector<vector<int>> Rook::validDestinations(Piece* board[8][8])
{
    vector<int> pos;
    pos.push_back(0);
    pos.push_back(0);
    int row = position.at(0);
    int column = position.at(1);
    vector<vector<int>> allMoves;
   
    for(int i = 1; i <=7;++i)// up vertical
    {
        row = position.at(0);
        column = position.at(1);
        row = row + i;
        column = column;
        if((row >=0 && row <= 7)&&(column >=0 && column <=7))// checks if location is on the board
        {
            if(board[row][column] == nullptr)//no piece in this spot
            {
                pos.at(0) = row;
                pos.at(1) = column;
                allMoves.push_back(pos);// add move to list
            }
            else if(board[row][column]->color == this -> color)//piece of same color in way
            {
                break;
            }
            else if(board[row][column]->color != this->color)//piece of opposite color (can take)
            {
                pos.at(0) = row;
                pos.at(1) = column;
                allMoves.push_back(pos);// add move to list
                break;
            }
            row = position.at(0);
            column = position.at(1);
        }
    }
    for(int i = 1; i <=7;++i)// down vertical
    {
        row = position.at(0);
        column = position.at(1);
        row = row - i;
        column = column;
        if((row >=0 && row <= 7)&&(column >=0 && column <=7))// checks if location is on the board
        {
            if(board[row][column] == nullptr)//no piece in this spot
            {
                pos.at(0) = row;
                pos.at(1) = column;
                allMoves.push_back(pos);// add move to list
            }
            else if(board[row][column]->color == this -> color)//piece of same color in way
            {
                break;
            }
            else if(board[row][column]->color != this->color)//piece of opposite color (can take)
            {
                pos.at(0) = row;
                pos.at(1) = column;
                allMoves.push_back(pos);// add move to list
                break;
            }
            row = position.at(0);
            column = position.at(1);
        }
    }
    for(int i = 1; i <=7;++i)// right horizontal
    {
        row = position.at(0);
        column = position.at(1);
        row = row;
        column = column +i;
        if((row >=0 && row <= 7)&&(column >=0 && column <=7))// checks if location is on the board
        {
            if(board[row][column] == nullptr)//no piece in this spot
            {
                pos.at(0) = row;
                pos.at(1) = column;
                allMoves.push_back(pos);// add move to list
            }
            else if(board[row][column]->color == this -> color)//piece of same color in way
            {
                break;
            }
            else if(board[row][column]->color != this->color)//piece of opposite color (can take)
            {
                pos.at(0) = row;
                pos.at(1) = column;
                allMoves.push_back(pos);// add move to list
                break;
            }
        }
        row = position.at(0);
        column = position.at(1);
    }
    for(int i = 1; i <=7;++i)// left horizotal
    {
        row = position.at(0);
        column = position.at(1);
        row = row;
        column = column -i;
        if((row >=0 && row <= 7)&&(column >=0 && column <=7))// checks if location is on the board
        {
            if(board[row][column] == nullptr)//no piece in this spot
            {
                pos.at(0) = row;
                pos.at(1) = column;
                allMoves.push_back(pos);// add move to list
            }
            else if(board[row][column]->color == this -> color)//piece of same color in way
            {
                break;
            }
            else if(board[row][column]->color != this->color)//piece of opposite color (can take)
            {
                pos.at(0) = row;
                pos.at(1) = column;
                allMoves.push_back(pos);// add move to list
                break;
            }
            row = position.at(0);
            column = position.at(1);
        }
    } 
    return allMoves; 
}
   /* //iterate in front and behind current position, 
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
    return allMoves;*/


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