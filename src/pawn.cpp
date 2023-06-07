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

    vector<int> validDest3;
    validDest3.push_back(0);
    validDest3.push_back(0);

    vector<int> validDest4;
    validDest4.push_back(0);
    validDest4.push_back(0);

    if (this->color == 'w')
    {
        if (board[currRow + 1][currCol] == nullptr)
        {
            rowDest = currRow + 1;

            validDest2.at(0) = rowDest;
            validDest2.at(1) = currCol;

            validDestinations.push_back(validDest2);

            if (this->hasMoved == false && board[currRow + 2][currCol] == nullptr)
            {
                rowDest = currRow + 2;

                validDest1.at(0) = rowDest;
                validDest1.at(1) = currCol;

                validDestinations.push_back(validDest1);
            }
        }

        if (currCol + 1 < 8 && (board[currRow + 1][currCol + 1] != nullptr && board[currRow + 1][currCol + 1]->color != this->color))
        {
            validDest3.at(0) = currRow + 1;
            validDest3.at(1) = currCol + 1;

            validDestinations.push_back(validDest3);
        }

        if (currCol - 1 >= 0 && (board[currRow + 1][currCol - 1] != nullptr && board[currRow + 1][currCol - 1]->color != this->color))
        {
            validDest4.at(0) = currRow + 1;
            validDest4.at(1) = currCol - 1;

            validDestinations.push_back(validDest4);
        }
    }

    else //if color == 'b'
    {
        if (board[currRow - 1][currCol] == nullptr)
        {
            if (this->hasMoved == false && board[currRow - 2][currCol] == nullptr)
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

            if (currCol + 1 < 8 && (board[currRow - 1][currCol + 1] != nullptr && board[currRow - 1][currCol + 1]->color != this->color))
            {
                validDest3.at(0) = currRow - 1;
                validDest3.at(1) = currCol + 1;

                validDestinations.push_back(validDest3);
            }

            if (currCol - 1 >= 0 && (board[currRow - 1][currCol - 1] != nullptr && board[currRow - 1][currCol - 1]->color != this->color))
            {
                validDest4.at(0) = currRow - 1;
                validDest4.at(1) = currCol - 1;

                validDestinations.push_back(validDest4);
            }
    }

    for (unsigned int counter = 0; counter < validDestinations.size(); ++counter)
    {
        if ((validDestinations[counter][0] > 7 || validDestinations[counter][0] < 0) ||
            (validDestinations[counter][1] > 7 || validDestinations[counter][1] < 0))
        {
            validDestinations.erase(validDestinations.begin() + counter);
            --counter;
        }
    }

    return validDestinations;
}   