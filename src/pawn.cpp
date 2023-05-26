#include "../header/pawn.h"

Pawn::Pawn(char col, vector<int> pos)
{
    color = col;
    position = pos;
    hasMoved = false;
}

string Pawn::getDisplayChar()
{
    string displayChar = "no char";
    if (color == 'b')
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
    int currRow = position.at(0);
    int currCol = position.at(1);
    int rowDest;
    int colDest;

    vector<vector<int>> validDestinations;
    vector<int> validDest;

    if (hasMoved == false)
    {
        if (color == 'w')
        {
            rowDest = currRow + 2;
            colDest = 0;

            validDest.push_back(rowDest);
            validDest.push_back(colDest);

            validDestinations.push_back(validDest);
        }

        else //if color == 'b'
        {
            rowDest = currRow - 2;
            colDest = 0;

            validDest.push_back(rowDest);
            validDest.push_back(colDest);

            validDestinations.push_back(validDest);
        }

        validDest.clear();
    }

    if (color == 'w')
    {
        rowDest = currRow + 1;
        colDest = 0;

        validDest.push_back(rowDest);
        validDest.push_back(colDest);

        validDestinations.push_back(validDest);
    }

    else //if color == 'b'
    {
        rowDest = currRow - 1;
        colDest = 0;

        validDest.push_back(rowDest);
        validDest.push_back(colDest);

        validDestinations.push_back(validDest);
    }

    validDest.clear();

    for (unsigned int counter = 0; counter < validDestinations.size(); ++counter)
    {
        for (unsigned int count = 0; count < validDestinations.at(counter).size(); ++count)
        {
            if (validDestinations.at(counter).at(count) > 7 || validDestinations.at(counter).at(count) < 0)
            {
                break;
            }
        }

        validDestinations.erase(validDestinations.begin() + counter);
    }

    return validDestinations;
}