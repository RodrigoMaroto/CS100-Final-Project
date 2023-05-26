#include "../header/pawn.h"

Pawn::Pawn(char col, vector<int> pos)
{
    color = col;
    position = pos;
}

char Pawn::getDisplayChar()
{
    if (color = 'b')
    {
        return '♙';
    } 

        return '♟︎';
}

void Knight::move(vector<int> destination)
{
    // int currRow = position.at(0);
    // int currCol = position.at(1);
    // int rowDest = destination.at(0);
    // int colDest = destination.at(1);

    // vector<vector<int>> validDestination = validDestinations();

    // for(unsigned int counter = 0; counter < validDestination.size(); ++counter)
    // {
    //     if (validDestination.at(counter) == destination)
    //     {
            
    //     }
    // }
}

vector<vector<int>> Pawn::validDestinations()
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

    else //hasMoved == true
    {
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
    }

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

    return vector<vector<int>> validDestinations;
}