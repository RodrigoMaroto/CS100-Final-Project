#include "../header/Chess_Board.h"
#include "../header/Game_Manager.h"
#include <iostream>
#include <string>
#include <vector>

//g++ src/main.cpp src/Game_Manager.cpp src/Chess_Board.cpp src/pawn.cpp src/bishop.cpp src/king.cpp src/queen.cpp src/knight.cpp src/rook.cpp
using namespace std;

bool isVectorInVector(vector<int> target, vector<vector<int>> vectorList);

Game_Manager::Game_Manager(){
    isWhiteTurn = true;
    isGameFinished = false;
    isDraw = false;
    whiteWin = false;
    chessboard = Chess_Board();
}

void Game_Manager::move(vector<int> destination, vector<int> currentLocation){
    Piece* piece = chessboard.board[currentLocation.at(0)][currentLocation.at(1)];
    if (chessboard.board[destination.at(0)][destination.at(1)] != nullptr)
        delete chessboard.board[destination.at(0)][destination.at(1)];
    chessboard.board[destination.at(0)][destination.at(1)] = piece;
    chessboard.board[currentLocation.at(0)][currentLocation.at(1)] = nullptr;
    piece->position = destination;
    piece->hasMoved = true;
}

//This will be checked at the end of the turn, so it must be checked for the opposite color
//Or pass it as a parameter
bool Game_Manager::isCheckMate(){ 
    return false;
}

bool Game_Manager::isStalemate(){
    return false;
}

bool Game_Manager::tempCheck(vector<int> destination, vector<int> currentLocation){
    return false;
}

bool Game_Manager::promote(vector<vector<int>> moves){ //missing implementation
    /* Pseudo Code
    initialize bool isValidPromote to false
    if board at position of location is a pawn
    if black is moving its pawn to whites side or if white is moving pawn to blacks side
    isValidPromote is true
    give user a choice of a piece to get back as a char (B, N, K, Q, R, P)
    check char against each piece for match, 
    if match create a new piece accordingly, delete pawn from board, place piece on ending location of pawn
    other players turn
    return isValidPromote*/
    bool isValidPromote = false;
    Piece* pawn = chessboard.board[moves[0][0]][moves[0][1]];
    Pawn* pawnChecker = dynamic_cast<Pawn*>(pawn);
    if(pawnChecker != nullptr){
        if ((isWhiteTurn && (pawn->color == 'w') && (moves[1][0] == 7))  
            || (!isWhiteTurn && (pawn->color == 'b') && (moves[1][0] == 0))){
            if(isVectorInVector(moves[1], pawn->validDestinations(chessboard.board))){//piece is a pawn 
                if(!tempCheck(moves[1], moves[0])) {
                    isValidPromote = true;
                    cout << "Input letter of the piece you would like to promote your pawn to:" << endl;
                    cout << "Q -> Queen\nB -> Bishop\nR -> Rook\nN -> Knight\n";
                    char newPieceChar;
                    delete pawn;
                    chessboard.board[moves[0][0]][moves[0][1]] = nullptr;
                    bool validLetter = false;
                    while(!validLetter){
                        cin >> newPieceChar;
                        cout << endl;
                        if(newPieceChar == 'Q' || newPieceChar == 'q'){
                            validLetter = true;
                            if(isWhiteTurn)
                                chessboard.addPiece({moves[1][0],moves[1][1]}, 'q', 'w');
                            else{
                                chessboard.addPiece({moves[1][0], moves[1][1]}, 'q', 'b');
                            }
                        }
                        else if(newPieceChar == 'B' || newPieceChar == 'b'){
                            validLetter = true;
                            if(isWhiteTurn)
                                chessboard.addPiece({moves[1][0], moves[1][1]}, 'b', 'w');
                            else{
                                chessboard.addPiece({moves[1][0], moves[1][1]}, 'b', 'b');
                            }
                        }
                        else if(newPieceChar == 'R' || newPieceChar == 'r'){
                            validLetter = true;
                            if(isWhiteTurn)
                                chessboard.addPiece({moves[1][0], moves[1][1]}, 'r', 'w');
                            else{
                                chessboard.addPiece({moves[1][0], moves[1][1]}, 'r', 'b');
                            }
                        }
                        else if(newPieceChar == 'N' || newPieceChar == 'n'){
                            validLetter = true;
                            if(isWhiteTurn)
                                chessboard.addPiece({moves[1][0], moves[1][1]}, 'n', 'w');
                            else{
                                chessboard.addPiece({moves[1][0], moves[1][1]}, 'n', 'b');
                            }
                        }
                        else{
                            cout << "Invalid input" << endl;
                            cout << "Input letter of the piece you would like to promote your pawn to" << endl;
                            cout << "Q -> Queen\nB -> Bishop\nR -> Rook\nN -> Knight\n";
                        }
                    }
                }
            }
        }
    }
    if(isValidPromote){
        isWhiteTurn = !isWhiteTurn;
        }
    return isValidPromote;
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
                        if (!tempCheck(moves[1], moves[0])){
                            move(moves[1], moves[0]);
                            isWhiteTurn = !isWhiteTurn;
                            playedMoves.push_back(input);
                            break;
                        }
                    }
                }
            }
        }
        cout << "Move was invalid, input new move: ";            
    }
}




