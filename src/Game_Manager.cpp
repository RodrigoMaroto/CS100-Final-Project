#include "../header/Chess_Board.h"
#include "../header/Game_Manager.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;


bool Game_Manager::promote(vector<vector<int>> moves){ //missing implementation
    return false;
}

bool Game_Manager::castle(vector<vector<int>> moves){ //missing implementation
    return false;
}

bool Game_Manager::enPassant(vector<vector<int>> moves){ //missing implementation
    return false;
}

bool isValidInput(string input) {
    // Check if the input has the correct format
    if (input.length() != 5 || !isalpha(input[0]) || !isalpha(input[3]) ||
        !isdigit(input[1]) || !isdigit(input[4]) || input[2] != ' ')
    {
        return false;
    }
    
    // Check if the column and row values are within the valid range
    if (input[0] < 'a' || input[0] > 'h' || input[3] < 'a' || input[3] > 'h' ||
        input[1] < '1' || input[1] > '8' || input[4] < '1' || input[4] > '8')
    {
        return false;
    }
    
    return true;
}

vector<vector<int>> parseInput(string input) {
    // Parse input string to extract column and row values
    vector<vector<int>> move(2, vector<int>(2));
    move[0][1] = input[0] - 'a';  // Convert column from character to integer index
    move[0][0] = input[1] - '1';  // Convert row from character to integer index
    move[1][1] = input[3] - 'a';  // Convert column from character to integer index
    move[1][0] = input[4] - '1';  // Convert row from character to integer index
    return move;
}

bool isVectorInVector(vector<int> target, vector<vector<int>> vectorList) {
    for (const auto& vec : vectorList) {
        if (vec == target) {
            return true;
        }
    }
    return false;
}

void Game_Manager::inputMove(){
    if (isWhiteTurn)
        cout << "White’s turn ";
    else
        cout << "Black’s turn ";
    cout << "(Input the location [column, row] of the piece you want to move, then where you want to put it i.e. C8 D7)"<<endl;
    cout << "Input move: ";

    while(true){
        string input;
        getline(cin, input);

        if (input == "pause") {
            // Handle pause option
            // Invoke pause menu
            break;
        } 
        if (isValidInput(input)){
            vector<vector<int>> moves = parseInput(input);
            Piece* piece = chessboard.board[moves[0][0]][moves[0][1]];
            if (piece != nullptr){
                if ((piece->color == 'w' && isWhiteTurn) || (piece->color == 'b' && !isWhiteTurn)){
                    if (promote(moves)) //This functions will return true if valid and execute the move
                        break;
                    if (castle(moves))
                        break;
                    if (enPassant(moves))
                        break;
                    if(isVectorInVector(moves[1], piece->validDestinations(chessboard.board))){
                        // Missing discover check
                        move(moves[1], moves[0]);
                        isWhiteTurn = !isWhiteTurn;
                        playedMoves.push_back(input);
                        break;
                    }
                }
            }
        }
        cout << "Move was invalid, input new move: ";            
    }
}





