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

bool Game_Manager::isCheckMate(){
    // As this will be executed after a move, isWhiteTurn has already been changed, and therefore we are checking for opponent
    // First check if king is in check
    vector<int> position;
    position.push_back(0);
    position.push_back(0);
    if (!tempCheck(position, position))
        return false;
    // Loop through all pieces, if one move stops check, return false
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            if (chessboard.board[i][j] != nullptr){
                if(isWhiteTurn){
                    if(chessboard.board[i][j]->color == 'w'){
                        vector<vector<int>> destinations = chessboard.board[i][j]->validDestinations(chessboard.board);
                        for (const auto& dest : destinations) {
                            if (!tempCheck(dest, chessboard.board[i][j]->position))
                                return false;
                        }
                    }
                }
                else{
                    if(chessboard.board[i][j]->color == 'b'){
                        vector<vector<int>> destinations = chessboard.board[i][j]->validDestinations(chessboard.board);
                        for (const auto& dest : destinations) {
                            if (!tempCheck(dest, chessboard.board[i][j]->position))
                                return false;
                        }
                    }
                }
            }
        }
    }
    
    //At the end, change member variables and return
    whiteWin = !isWhiteTurn;
    isGameFinished = true;
    return true;
}

bool Game_Manager::isStalemate(){
    // As this will be executed after a move, isWhiteTurn has already been changed, and therefore we are checking for opponent
    // First check if king is in check
    vector<int> position;
    position.push_back(0);
    position.push_back(0);
    if (tempCheck(position, position))
        return false;
    // Loop through all pieces, if one move is valid and does not provoke a check, return false
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            if (chessboard.board[i][j] != nullptr){
                if(isWhiteTurn){
                    if(chessboard.board[i][j]->color == 'w'){
                        vector<vector<int>> destinations = chessboard.board[i][j]->validDestinations(chessboard.board);
                        for (const auto& dest : destinations) {
                            if (!tempCheck(dest, chessboard.board[i][j]->position))
                                return false;
                        }
                    }
                }
                else{
                    if(chessboard.board[i][j]->color == 'b'){
                        vector<vector<int>> destinations = chessboard.board[i][j]->validDestinations(chessboard.board);
                        for (const auto& dest : destinations) {
                            if (!tempCheck(dest, chessboard.board[i][j]->position))
                                return false;
                        }
                    }
                }
            }
        }
    }

    //At the end, change member variables and return
    isDraw = true;
    isGameFinished = true;
    return true;
}

bool Game_Manager::tempCheck(vector<int> destination, vector<int> currentLocation){
    //Modify board
    Piece* dest = chessboard.board[destination[0]][destination[1]];
    Piece* piece = chessboard.board[currentLocation[0]][currentLocation[1]];
    chessboard.board[currentLocation[0]][currentLocation[1]] = nullptr;
    chessboard.board[destination[0]][destination[1]] = piece;
    if (piece != nullptr)
        piece->position = destination;
    King* king;
    Piece* kingPiece;
    //Call check
    if (isWhiteTurn)
        kingPiece = chessboard.findKing('w');
    else
        kingPiece = chessboard.findKing('b');
    
    king = static_cast<King*>(kingPiece);
    bool result = king->inCheck(chessboard.board);

    //Restore board
    chessboard.board[currentLocation[0]][currentLocation[1]] = piece;
    chessboard.board[destination[0]][destination[1]] = dest;
    if (piece != nullptr)
        piece->position = currentLocation;

    return result;
}

bool Game_Manager::promote(vector<vector<int>> moves){ //missing implementaation
    bool isValidPromote = false;
    Piece* pawn = chessboard.board[moves[0][0]][moves[0][1]];
    if(dynamic_cast<Pawn*>(pawn) != nullptr){//piece is a pawn
        if ((isWhiteTurn && (pawn->color == 'w') && (moves[1][0] == 7))  //white's turn and moving white piece to black side
            || (!isWhiteTurn && (pawn->color == 'b') && (moves[1][0] == 0))){//black's turn and moving black piece to white's side
            if(isVectorInVector(moves[1], pawn->validDestinations(chessboard.board))){//destination is a valid Destination
                if(!tempCheck(moves[1], moves[0])) {//destination is not under attack
                    Piece* destination = chessboard.board[moves[1][0]][moves[1][1]];
                    if(destination !=  nullptr){ delete destination; }// if destination has a piece, delete the piece
                    isValidPromote = true;
                    cout << "Input letter of the piece you would like to promote your pawn to:" << endl;
                    cout << "Q -> Queen\nB -> Bishop\nR -> Rook\nN -> Knight\n";
                    string newPieceChar;
                    delete pawn;
                    chessboard.board[moves[0][0]][moves[0][1]] = nullptr;
                    bool validLetter = false;
                    while(!validLetter){
                        getline(cin, newPieceChar);
                        if(newPieceChar == "Q" || newPieceChar == "q"){
                            validLetter = true;
                            if(isWhiteTurn)
                                chessboard.addPiece({moves[1][0],moves[1][1]}, 'q', 'w');
                            else{
                                chessboard.addPiece({moves[1][0], moves[1][1]}, 'q', 'b');
                            }
                        }
                        else if(newPieceChar == "B" || newPieceChar == "b"){
                            validLetter = true;
                            if(isWhiteTurn)
                                chessboard.addPiece({moves[1][0], moves[1][1]}, 'b', 'w');
                            else{
                                chessboard.addPiece({moves[1][0], moves[1][1]}, 'b', 'b');
                            }
                        }
                        else if(newPieceChar == "R" || newPieceChar == "r"){
                            validLetter = true;
                            if(isWhiteTurn)
                                chessboard.addPiece({moves[1][0], moves[1][1]}, 'r', 'w');
                            else{
                                chessboard.addPiece({moves[1][0], moves[1][1]}, 'r', 'b');
                            }
                        }
                        else if(newPieceChar == "N" || newPieceChar == "n"){
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

bool Game_Manager::castle(vector<vector<int>> moves){ 
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
                                            move({0,6}, king->position);
                                            move({0,5}, rook->position);
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
                                            move({7,6}, king->position);
                                            move({7,5}, rook->position);
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
                                            move({0,2}, king->position);
                                            move({0,3}, rook->position);
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
                                            move({7,2}, king->position);
                                            move({7,3}, rook->position);
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
    if(isValidCastle){
        isWhiteTurn = !isWhiteTurn;
    }
    return isValidCastle;
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

bool Game_Manager::enPassant(vector<vector<int>> moves){ //missing implementation
/*
    moves[0][0] == initial row, moves[0][1] == initial column, moves[1][0] == new row, moves[1][1] == new column
    check if piece at chessboard.board[moves[0][0]][moves[0][1]] == pawn
    check if the piece next to it is a pawn as well (chessboard.board[moves[0][0]][moves[1][1] == pawn)
    check if the previous move before involved the pawn moving 2 spaces (playedMoves.at(playedMoves.size() - 1))
    check if the place it wants to move to is open and in the correct location for a proper en passant (moves[1] == enpassant location && nullptr)
    if all condidtions met: call move function, switch turns, return true (chessboard.board[moves[0][0]][moves[1][1] == nullptr? / delete pawn there?)
    (MAKE SURE YOU ACCOUNT FOR WHOSE TURN IT IS)
*/

    Piece* pawn = chessboard.board[moves[0][0]][moves[0][1]];
    if (dynamic_cast<Pawn*>(pawn) != nullptr)
    //if chessboard.board[moves[0][0]][moves[0][1] == pawn
    {
        Piece* enemyPawn = chessboard.board[moves[0][0]][moves[1][1]];
        if (dynamic_cast<Pawn*>(enemyPawn) != nullptr && enemyPawn->color != pawn->color 
            && (moves[0][1] + 1 == moves[1][1] || moves[0][1] - 1 == moves[1][1]))
        //piece next to currLoc != nullptr && == pawn && != this->color (chessboard.board[moves[0][0]][moves[1][1] == pawn)
        {
            string prevInput = playedMoves.at(playedMoves.size() - 1);
            vector<vector<int>> prevMove = parseInput(prevInput);

            if ((prevMove[0][0] + 2 == prevMove[1][0] || prevMove[0][0] - 2 == prevMove[1][0]) && prevMove[0][1] == prevMove[1][1] 
                 && prevMove[1][0] == moves[0][0] && moves[1][1] == prevMove[1][1])
            //checks if previous move (playedMoves.at(playedMoves.size() - 1)) moved pawn 2 spaces and the rows/columns match
            {
                if (isWhiteTurn && moves[0][0] + 1 == moves[1][0] && (moves[0][1] + 1 == moves[1][1] || moves[0][1] - 1 == moves[1][1]) 
                    && chessboard.board[moves[1][0]][moves[1][1]] == nullptr) 
                //white turn (checks if proper en passant) (up 1 row & left/right 1)
                {
                    chessboard.board[moves[0][0]][moves[1][1]] = nullptr;
                    if (!tempCheck(moves[1], moves[0]))
                    {
                        move(moves[1], moves[0]);
                        //delete/make null chessboard.board[moves[0][0]][moves[1][1]
                        delete enemyPawn;
                        isWhiteTurn = !isWhiteTurn;
                        return true;
                    }

                    else
                    {
                        chessboard.board[moves[0][0]][moves[1][1]] = enemyPawn;
                        return false;
                    }
                }

                else if (!isWhiteTurn && moves[0][0] - 1 == moves[1][0] && (moves[0][1] + 1 == moves[1][1] || moves[0][1] - 1 == moves[1][1])
                         && chessboard.board[moves[1][0]][moves[1][1]] == nullptr) 
                //black turn (checks if proper en passant) (down 1 row & left/right 1)
                {
                    chessboard.board[moves[0][0]][moves[1][1]] = nullptr;
                    if (!tempCheck(moves[1], moves[0]))
                    {
                        move(moves[1], moves[0]);
                        //delete/make null chessboard.board[moves[0][0]][moves[1][1]
                        delete enemyPawn;
                        isWhiteTurn = !isWhiteTurn;
                        return true;
                    }

                    else
                    {
                        chessboard.board[moves[0][0]][moves[1][1]] = enemyPawn;
                        return false;
                    }
                }
            }
        }
    }

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
            pauseMenu();

            if (!isGameFinished)
            {
                cout << "Input move: "; //gets new input if player enters "back"
                getline(cin, input);
            }

            else
            {
                break; //ends function if user enters "surrender"
            }
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
                    {
                        playedMoves.push_back(input);
                        break;
                    }
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

void Game_Manager::pauseMenu()
{
    cout << "Input: 'surrender' in order to forfeit the game or 'back' to go back to the game." << endl;
    string input;
    getline(cin, input);
    cout << endl;

    while (input != "surrender" && input != "back")
    {
        cout << "invalid input: enter 'surrender' or 'back'" << endl;
        getline(cin, input);
        cout << endl;
    }

        if (input == "surrender")
        {
            isGameFinished = true;

            if (isWhiteTurn)
            {
                whiteWin = false;
            }

            else
            {
                whiteWin = true;
            }
        }

        return;
}


