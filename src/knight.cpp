#include "../header/knight.h"

Knight::Knight(char col, vector<int> pos)
{
    color = col;
    position = pos;
}

string Knight::getDisplayChar()
{
    string displayChar = "no char";
    if (color == 'b')
    {
        displayChar = "♘";
    } 
    else
    {
        displayChar = "♞";
    }

    return displayChar;
}


vector<vector<int>> Knight::validDestinations(Piece* board[8][8])
{
    int currRow = position.at(0);
    int currCol = position.at(1);
    int rowDest;
    int colDest;

    vector<vector<int>> validDestinations;
    vector<int> validDest;

    rowDest = currRow + 1;
    colDest = currCol + 2;

    validDest.push_back(rowDest);
    validDest.push_back(colDest);

    validDestinations.push_back(validDest);

    validDest.pop_back();
    colDest = currCol - 2;
    validDest.push_back(colDest);

    validDestinations.push_back(validDest);

    validDest.clear();

    rowDest = currRow - 1;
    colDest = currCol - 2;

    validDest.push_back(rowDest);
    validDest.push_back(colDest);

    validDestinations.push_back(validDest);

    validDest.pop_back();
    colDest = currCol + 2;
    validDest.push_back(colDest);

    validDestinations.push_back(validDest);

    validDest.clear();

    rowDest = currRow + 2;
    colDest = currCol + 1;

    validDest.push_back(rowDest);
    validDest.push_back(colDest);

    validDestinations.push_back(validDest);

    validDest.pop_back();
    colDest = currCol - 1;
    validDest.push_back(colDest);

    validDestinations.push_back(validDest);

    validDest.clear();

    rowDest = currRow - 2;
    colDest = currCol - 1;

    validDest.push_back(rowDest);
    validDest.push_back(colDest);

    validDestinations.push_back(validDest);

    validDest.pop_back();
    colDest = currCol + 1;
    validDest.push_back(colDest);

    validDestinations.push_back(validDest);

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