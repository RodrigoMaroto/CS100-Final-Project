#include "../header/Chess_Board.h"
#include "../header/Game_Manager.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

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
    return false;
}

bool Game_Manager::castle(vector<vector<int>> moves){ //missing implementation
    bool isValidCastle = false;
    Piece* king = chessboard.board[moves[0][0]][moves[0][1]];
    vector<int> kingDestination = {moves[1][0], moves[1][1]};
    if(dynamic_cast<King*>(king) != nullptr){ //if piece is a king
        if(king->hasMoved == false){//if king has not moved
            if(kingDestination[0] == moves[0][0] && kingDestination[1] == moves[0][1] + 2){//position of king's destination is position of kingside castle
                Piece* rook = chessboard.board[moves[0][0]][7];
                if(dynamic_cast<Rook*>(rook) != nullptr){//if rook is on kingside
                    if(rook->hasMoved == false){//rook has not moved
                        if(!tempCheck(rook->position, king->position)){//rook is not under attack
                            if((king->color == rook->color) && (king->color == 'w') && isWhiteTurn){//rook and king both white, it is white's turn
                                if((chessboard.board[moves[0][0]][moves[0][1] + 1] == nullptr) 
                                && (chessboard.board[moves[0][0]][moves[0][1] + 2] == nullptr)){// no pieces between rook and king
                                    if(!tempCheck(king->position, king->position)){//king is not in check
                                        if(!tempCheck({0,5}, king->position) && !tempCheck({0,6},king->position)){//if king's path does not result in check
                                            isValidCastle = true;
                                            delete rook;
                                            delete king;
                                            chessboard.addPiece({0,6}, 'k', 'w');
                                            chessboard.addPiece({0,5}, 'r', 'w');
                                        }
                                    }
                                }
                            }
                            else if((king->color == rook->color) && (king->color == 'b') && !isWhiteTurn){//rook and king both black, it is black's turn
                                if((chessboard.board[moves[0][0]][moves[0][1] + 1] == nullptr) 
                                && (chessboard.board[moves[0][0]][moves[0][1] + 2] == nullptr)){// no pieces between rook and king
                                    if(!tempCheck(king->position, king->position)){//king is not in check
                                        if(!tempCheck({7,5},king->position) && !tempCheck({7,6},king->position)){//if king's path does not result in check
                                            isValidCastle = true;
                                            delete rook;
                                            delete king;
                                            chessboard.addPiece({7,6}, 'k', 'b');
                                            chessboard.addPiece({7,5}, 'r', 'b');
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            else if(kingDestination[0] == moves[0][0] && kingDestination[1] == moves[0][1] - 2){//king's destination is queenside castle
                Piece* rook = chessboard.board[moves[0][0]][0];
                if(dynamic_cast<Rook*>(rook) != nullptr){ //if rook is on queen side
                    if(rook->hasMoved == false){//rook has not moved
                        if(!tempCheck(rook->position, king->position)){//rook is not under attack
                            if((king->color == rook->color) && (king->color == 'w') && isWhiteTurn){//rook and king both white, it is white's turn
                                if((chessboard.board[moves[0][0]][moves[0][1] - 1] == nullptr) 
                                && (chessboard.board[moves[0][0]][moves[0][1] - 2] == nullptr)
                                && (chessboard.board[moves[0][0]][moves[0][1] - 3] == nullptr)){// no pieces between rook and king
                                    if(!tempCheck(king->position, king->position)){//king is not in check
                                        if(!tempCheck({0,1},king->position) && !tempCheck({0,2},king->position) && !tempCheck({0,3},king->position)){//if king's path does not result in check
                                            isValidCastle = true;
                                            delete rook;
                                            delete king;
                                            chessboard.addPiece({0,2}, 'k', 'w');
                                            chessboard.addPiece({0,3}, 'r', 'w');
                                        }
                                    }
                                }
                            }
                            else if((king->color == rook->color) && (king->color == 'b') && !isWhiteTurn){//rook and king both black, it is black's turn
                                if((chessboard.board[moves[0][0]][moves[0][1] - 1] == nullptr) 
                                && (chessboard.board[moves[0][0]][moves[0][1] - 2] == nullptr)
                                && (chessboard.board[moves[0][0]][moves[0][1] - 3] == nullptr)){// no pieces between rook and king
                                    if(!tempCheck(king->position, king->position)){//king is not in check
                                        if(!tempCheck({7,1},king->position) && !tempCheck({7,2},king->position) && !tempCheck({7,3},king->position)){//if king's path does not result in check
                                            isValidCastle = true;
                                            delete rook;
                                            delete king;
                                            chessboard.addPiece({7,2}, 'k', 'b');
                                            chessboard.addPiece({7,3}, 'r', 'b');
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return isValidCastle;
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




