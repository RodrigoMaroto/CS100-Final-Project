#include "../header/king.h"
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

King::King(char col, vector<int> pos){
    this->color = col;
    this->position = pos;
    this->hasMoved = false;
}
string King::getDisplayChar(){
    string displayChar = "no char";
    if(this->color == 'w')
    {
        displayChar = "♚";
    }  
    else if(this->color == 'b')
    {
        displayChar = "♔";
    }
    return displayChar;
}
vector<vector<int>> King::validDestinations(Piece* board[8][8]) {
    vector<int> pos;
    pos.push_back(0);
    pos.push_back(0);
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
                    if(board[row][column]->color == this -> color){}// piece of same color in way
                    else{
                        allMoves.push_back(pos);
                    }
                    
                    //at some point, update the lines above to check the board to see of other piece is there
                    //or if move puts in check, etc
                    
                }
                row = position.at(0);
                column = position.at(1);
            }
            // at the end of each loop iteration reset the row and column to the current position
            
        }


        
    }
    


return allMoves;

}

