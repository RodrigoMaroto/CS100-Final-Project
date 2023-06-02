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

    vector<int> validDest1;
    validDest1.push_back(0);
    validDest1.push_back(0);

    rowDest = currRow + 1;
    colDest = currCol + 2;

    validDest1.at(0) = rowDest;
    validDest1.at(1) = colDest;

    validDestinations.push_back(validDest1);

    vector<int> validDest2;
    validDest2.push_back(0);
    validDest2.push_back(0);

    colDest = currCol - 2;
    validDest2.at(0) = rowDest;
    validDest2.at(1) = colDest;

    validDestinations.push_back(validDest2);

    vector<int> validDest3;
    validDest3.push_back(0);
    validDest3.push_back(0);

    rowDest = currRow - 1;
    colDest = currCol - 2;

    validDest3.at(0) = rowDest;
    validDest3.at(1) = colDest;

    validDestinations.push_back(validDest3);

    vector<int> validDest4;
    validDest4.push_back(0);
    validDest4.push_back(0);

    colDest = currCol + 2;
    validDest4.at(0) = rowDest;
    validDest4.at(1) = colDest;

    validDestinations.push_back(validDest4);

    vector<int> validDest5;
    validDest5.push_back(0);
    validDest5.push_back(0);

    rowDest = currRow + 2;
    colDest = currCol + 1;

    validDest5.at(0) = rowDest;
    validDest5.at(1) = colDest;

    validDestinations.push_back(validDest5);

    vector<int> validDest6;
    validDest6.push_back(0);
    validDest6.push_back(0);

    colDest = currCol - 1;
    validDest6.at(0) = rowDest;
    validDest6.at(1) = colDest;

    validDestinations.push_back(validDest6);

    vector<int> validDest7;
    validDest7.push_back(0);
    validDest7.push_back(0);

    rowDest = currRow - 2;
    colDest = currCol - 1;

    validDest7.at(0) = rowDest;
    validDest7.at(1) = colDest;

    validDestinations.push_back(validDest7);


    vector<int> validDest8;
    validDest8.push_back(0);
    validDest8.push_back(0);

    colDest = currCol + 1;
    validDest8.at(0) = rowDest;
    validDest8.at(1) = colDest;

    validDestinations.push_back(validDest8);

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

    for (unsigned int counter = 0; counter < validDestinations.size(); ++counter)
    {
        if (board[validDestinations[counter][0]][validDestinations[counter][1]] != nullptr && 
            board[validDestinations[counter][0]][validDestinations[counter][1]]->color == this->color)
        {
            validDestinations.erase(validDestinations.begin() + counter);
            --counter;
        }
    }

    return validDestinations;
}