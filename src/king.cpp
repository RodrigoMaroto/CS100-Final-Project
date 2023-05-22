#include "header/king.h"
#include <vector>
using namespace std;

// class King : public Piece
// {
//     private:

//     public:
//         bool hasMoved;
//         void move(vector<int> destination) override;
//         vector<vector<int>> validDestinations() override;
// };


vector<vector<int>> King::validDestinations() override{
    vector<int> pos;
    int row = position.at(0);
    int column = position.at(1);
    vector<vector<int>> allMoves;
    //valid moves are 1 space away in any direction

    //this double loop generates all moves within a 1 square radius
    for(int i = -1; i <= 1; ++i){
        for(int j = -1; j <= 1; ++ j){
            if(i == 0 && j == 0){}// cant move to current location
            else{
                row = row + i;
                column = column +j;
                if((row <= 7 && row >=0 ) && (column <=7 && column >=0)){ // checks if location is on the board 
                //& adds to list of moves
                    pos.at(0) = row;
                    pos.at(1) = column;
                    allMoves.push_back(pos);
                    //at some point, update the lines above to check the board to see of other piece is there
                    //or if move puts in check, etc
                }
            }
            // at the end of each loop iteration reset the row and column to the current position
            int row = position.at(0);
            int column = position.at(1);
        }


        
    }
    

return allMoves;

}

void King::move(vector<int> destination) override{
    //main will check if move is in the valid destination BEFORE this is called!!

    // new board position -> at king
    board[destination.at(0)][destination.at(1)] -> this King;//idt this is correct... update if wrong

    // old board position -> null
    board[position.at(0)][position.at(1)] -> null;

    //update position data to match new position
    position.at(0) = destination.at(0);
    position.at(1) = destination.at(1)
    hasMoved = true;

}
