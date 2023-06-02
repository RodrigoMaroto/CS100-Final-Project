#include "../header/pawn.h"
#include <vector>

Pawn::Pawn(char col, vector<int> pos)
{
    this->color = col;
    this->position = pos;
    this->hasMoved = false;
}

string Pawn::getDisplayChar()
{
    string displayChar = "no char";
    if (this->color == 'b')
    {
        displayChar = "♙";
    } 
    else
    {
        displayChar = "♟︎";
    }

    return displayChar;
}


vector<vector<int>> Pawn::validDestinations(Piece* board[8][8])
{
    int currRow = this->position.at(0);
    int currCol = this->position.at(1);
    int rowDest;

    vector<vector<int>> validDestinations;

    
    vector<int> validDest1;
    validDest1.push_back(0);
    validDest1.push_back(0);

    vector<int> validDest2;
    validDest2.push_back(0);
    validDest2.push_back(0);

    if (this->color == 'w')
    {
        if (board[currRow + 1][currCol] == nullptr)
        {
            if (this->hasMoved == false)
            {
                rowDest = currRow + 2;

                validDest1.at(0) = rowDest;
                validDest1.at(1) = currCol;

                validDestinations.push_back(validDest1);
            }

            rowDest = currRow + 1;

            validDest2.at(0) = rowDest;
            validDest2.at(1) = currCol;

            validDestinations.push_back(validDest2);
        }

        else if (board[currRow + 1][currCol] != nullptr && board[currRow + 1][currCol]->color != this->color)
        {
            if (board[currRow + 1][currCol + 1] != nullptr && board[currRow + 1][currCol + 1]->color != this->color)
            {
                validDest1.at(0) = currRow + 1;
                validDest1.at(1) = currCol + 1;

                validDestinations.push_back(validDest1);
            }

            else if (board[currRow + 1][currCol - 1] != nullptr && board[currRow + 1][currCol - 1]->color != this->color)
            {
                validDest2.at(0) = currRow + 1;
                validDest2.at(1) = currCol - 1;

                validDestinations.push_back(validDest2);
            }
        }
    }

    else //if color == 'b'
    {
        if (board[currRow - 1][currCol] == nullptr)
        {
            if (this->hasMoved == false)
            {
                rowDest = currRow - 2;

                validDest1.at(0) = rowDest;
                validDest1.at(1) = currCol;

                validDestinations.push_back(validDest1);
            }

            rowDest = currRow - 1;

            validDest2.at(0) = rowDest;
            validDest2.at(1) = currCol;

            validDestinations.push_back(validDest2);
        }

        else if (board[currRow - 1][currCol] != nullptr && board[currRow + 1][currCol]->color != this->color)
        {
            if (board[currRow - 1][currCol + 1] != nullptr && board[currRow - 1][currCol + 1]->color != this->color)
            {
                validDest1.at(0) = currRow - 1;
                validDest1.at(1) = currCol + 1;

                validDestinations.push_back(validDest1);
            }

            else if (board[currRow - 1][currCol - 1] != nullptr && board[currRow - 1][currCol - 1]->color != this->color)
            {
                validDest2.at(0) = currRow - 1;
                validDest2.at(1) = currCol - 1;

                validDestinations.push_back(validDest2);
            }
        }
    }

    for (unsigned int counter = 0; counter < validDestinations.size(); ++counter)
    {
        for (unsigned int count = 0; count < 2; ++count)
        {
            if (validDestinations[counter][count] > 7 || validDestinations[counter][count] < 0)
            {
                validDestinations.erase(validDestinations.begin() + counter);
                --counter;
            }
        }
    }

    return validDestinations;
}   