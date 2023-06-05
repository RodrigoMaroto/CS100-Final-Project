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
                    if(board[row][column] == nullptr){
                        allMoves.push_back(pos);
                    }
                    else if(board[row][column]->color != this -> color){
                        allMoves.push_back(pos);
                    }
                    
                    
                }
                row = position.at(0);
                column = position.at(1);
            }
            // at the end of each loop iteration reset the row and column to the current position
            
        }


        
    }
    


return allMoves;

}

bool King::inCheck(Piece* board[8][8]){
    string pieceChar = "";
    int row = position.at(0);
    int column = position.at(1);


  // begin bishop-type checks
  for(int i = 1; i <=7;++i){// up & right
    row = position.at(0);
    column = position.at(1);
    row = row + i;
    column = column +i;
    if((row >=0 && row <= 7)&&(column >=0 && column <=7)){// checks if location is on the board
      if(board[row][column] != nullptr){
        if(board[row][column]->color == this -> color){//piece of same color in way
            break;
        }
        else{//case when piece is opposite color
            pieceChar = board[row][column]->getDisplayChar();
            if(pieceChar =="♗" || pieceChar == "♝" || pieceChar == "♕" || pieceChar == "♛" ){
                pieceChar = "";
                return true;
            }
            
        }
      }
    }
    row = position.at(0);
    column = position.at(1);
    
  }
  
  for(int i = 1; i <=7;++i){// up & left
    row = position.at(0);
    column = position.at(1);
    row = row + i;
    column = column -i;
    if((row >=0 && row <= 7)&&(column >=0 && column <=7)){// checks if location is on the board
      if(board[row][column] != nullptr){
        if(board[row][column]->color == this -> color){//piece of same color in way
            break;
        }
        else{//case when piece is opposite color
            pieceChar = board[row][column]->getDisplayChar();
            if(pieceChar =="♗" || pieceChar == "♝" || pieceChar == "♕" || pieceChar == "♛" ){
                pieceChar = "";
                return true;
            }
            
        }
      }
    }
    row = position.at(0);
    column = position.at(1);
    
  }
  
  for(int i = 1; i <=7;++i){// down & right
    row = position.at(0);
    column = position.at(1);
    row = row - i;
    column = column +i;
    if((row >=0 && row <= 7)&&(column >=0 && column <=7)){// checks if location is on the board
      if(board[row][column] != nullptr){
        if(board[row][column]->color == this -> color){//piece of same color in way
            break;
        }
        else{//case when piece is opposite color
            pieceChar = board[row][column]->getDisplayChar();
            if(pieceChar =="♗" || pieceChar == "♝" || pieceChar == "♕" || pieceChar == "♛" ){
                pieceChar = "";
                return true;
            }
            
        }
      }
    }
    row = position.at(0);
    column = position.at(1);
    
  }
  
  for(int i = 1; i <=7;++i){// down & left
    row = position.at(0);
    column = position.at(1);
    row = row - i;
    column = column - i;
    if((row >=0 && row <= 7)&&(column >=0 && column <=7)){// checks if location is on the board
      if(board[row][column] != nullptr){
        if(board[row][column]->color == this -> color){//piece of same color in way
            break;
        }
        else{//case when piece is opposite color
            pieceChar = board[row][column]->getDisplayChar();
            if(pieceChar =="♗" || pieceChar == "♝" || pieceChar == "♕" || pieceChar == "♛" ){
                pieceChar = "";
                return true;
            }
            
        }
      }
    }
    row = position.at(0);
    column = position.at(1);
    
  }
  
//start rook checks
  for(int i = 1; i <=7;++i){// right
    row = position.at(0);
    column = position.at(1);
    row = row ;
    column = column +i;
    if((row >=0 && row <= 7)&&(column >=0 && column <=7)){// checks if location is on the board
      if(board[row][column] != nullptr){
        if(board[row][column]->color == this -> color){//piece of same color in way
            break;
        }
        else{//case when piece is opposite color
            pieceChar = board[row][column]->getDisplayChar();
            if(pieceChar =="♖" || pieceChar == "♜" || pieceChar == "♕" || pieceChar == "♛" ){
                pieceChar = "";
                return true;
            }
            
        }
      }
    }
    row = position.at(0);
    column = position.at(1);
    
  }
  
  for(int i = 1; i <=7;++i){// left
    row = position.at(0);
    column = position.at(1);
    row = row ;
    column = column - i;
    if((row >=0 && row <= 7)&&(column >=0 && column <=7)){// checks if location is on the board
      if(board[row][column] != nullptr){
        if(board[row][column]->color == this -> color){//piece of same color in way
            break;
        }
        else{//case when piece is opposite color
            pieceChar = board[row][column]->getDisplayChar();
            if(pieceChar =="♖" || pieceChar == "♜" || pieceChar == "♕" || pieceChar == "♛" ){
                pieceChar = "";
                return true;
            }
            
        }
      }
    }
    row = position.at(0);
    column = position.at(1);
    
  }
  
  for(int i = 1; i <=7;++i){// up
    row = position.at(0);
    column = position.at(1);
    row = row + i;
    column = column ;
    if((row >=0 && row <= 7)&&(column >=0 && column <=7)){// checks if location is on the board
      if(board[row][column] != nullptr){
        if(board[row][column]->color == this -> color){//piece of same color in way
            break;
        }
        else{//case when piece is opposite color
            pieceChar = board[row][column]->getDisplayChar();
            if(pieceChar =="♖" || pieceChar == "♜" || pieceChar == "♕" || pieceChar == "♛" ){
                pieceChar = "";
                return true;
            }
            
        }
      }
    }
    row = position.at(0);
    column = position.at(1);
    
  }
  
  for(int i = 1; i <=7;++i){// down
    row = position.at(0);
    column = position.at(1);
    row = row -1;
    column = column;
    if((row >=0 && row <= 7)&&(column >=0 && column <=7)){// checks if location is on the board
      if(board[row][column] != nullptr){
        if(board[row][column]->color == this -> color){//piece of same color in way
            break;
        }
        else{//case when piece is opposite color
            pieceChar = board[row][column]->getDisplayChar();
            if(pieceChar =="♖" || pieceChar == "♜" || pieceChar == "♕" || pieceChar == "♛" ){
                pieceChar = "";
                return true;
            }
            
        }
      }
    }
    row = position.at(0);
    column = position.at(1);
    
  }
  

  //start pawn & knight checks
    row = position.at(0);
    column = position.at(1);
if(this -> color == 'w'){
   row = row +1;
   column = column + 1; //pawn right diagonal
    if((row >=0 && row <= 7)&&(column >=0 && column <=7)){// checks if location is on the board
      if(board[row][column] != nullptr){
        if(board[row][column]->color != this -> color){//piece of oposite color
            pieceChar = board[row][column]->getDisplayChar();
            if(pieceChar == "♙"){
                return true;
            }
        }
      }
    }
 
  row = position.at(0);//reset row and column to match king location
  column = position.at(1);
 
  row = row +1;
  column = column - 1; //pawn left diagonal
    if((row >=0 && row <= 7)&&(column >=0 && column <=7)){// checks if location is on the board
      if(board[row][column] != nullptr){
        if(board[row][column]->color != this -> color){//piece of oposite color
            pieceChar = board[row][column]->getDisplayChar();
            if(pieceChar == "♙"){
                return true;
            }
        }
      }
    }

//knight checks
  row = position.at(0);//reset row and column to match king location
  column = position.at(1);
 
  row = row + 2;//knight location 1 (positions numbered by location clockwise)
  column = column + 1; 
    if((row >=0 && row <= 7)&&(column >=0 && column <=7)){// checks if location is on the board
      if(board[row][column] != nullptr){
        if(board[row][column]->color != this -> color){//piece of oposite color
            pieceChar = board[row][column]->getDisplayChar();
            if(pieceChar == "♘"){
                return true;
            }
        }
      }
    }


row = position.at(0);//reset row and column to match king location
  column = position.at(1);
 
  row = row + 1;//knight location 2 (positions numbered by location clockwise)
  column = column + 2; 
    if((row >=0 && row <= 7)&&(column >=0 && column <=7)){// checks if location is on the board
      if(board[row][column] != nullptr){
        if(board[row][column]->color != this -> color){//piece of oposite color
            pieceChar = board[row][column]->getDisplayChar();
            if(pieceChar == "♘"){
                return true;
            }
        }
      }
    }

  row = position.at(0);//reset row and column to match king location
  column = position.at(1);
 
  row = row - 1;//knight location 3 (positions numbered by location clockwise)
  column = column + 2; 
    if((row >=0 && row <= 7)&&(column >=0 && column <=7)){// checks if location is on the board
      if(board[row][column] != nullptr){
        if(board[row][column]->color != this -> color){//piece of oposite color
            pieceChar = board[row][column]->getDisplayChar();
            if(pieceChar == "♘"){
                return true;
            }
        }
      }
    }

  row = position.at(0);//reset row and column to match king location
  column = position.at(1);
 
  row = row - 2;//knight location 4 (positions numbered by location clockwise)
  column = column + 1; 
    if((row >=0 && row <= 7)&&(column >=0 && column <=7)){// checks if location is on the board
      if(board[row][column] != nullptr){
        if(board[row][column]->color != this -> color){//piece of oposite color
            pieceChar = board[row][column]->getDisplayChar();
            if(pieceChar == "♘"){
                return true;
            }
        }
      }
    }

  row = position.at(0);//reset row and column to match king location
  column = position.at(1);
 
  row = row - 2;//knight location 5 (positions numbered by location clockwise)
  column = column - 1; 
    if((row >=0 && row <= 7)&&(column >=0 && column <=7)){// checks if location is on the board
      if(board[row][column] != nullptr){
        if(board[row][column]->color != this -> color){//piece of oposite color
            pieceChar = board[row][column]->getDisplayChar();
            if(pieceChar == "♘"){
                return true;
            }
        }
      }
    }

row = position.at(0);//reset row and column to match king location
  column = position.at(1);
 
  row = row - 1;//knight location 6 (positions numbered by location clockwise)
  column = column - 2; 
    if((row >=0 && row <= 7)&&(column >=0 && column <=7)){// checks if location is on the board
      if(board[row][column] != nullptr){
        if(board[row][column]->color != this -> color){//piece of oposite color
            pieceChar = board[row][column]->getDisplayChar();
            if(pieceChar == "♘"){
                return true;
            }
        }
      }
    }

  row = position.at(0);//reset row and column to match king location
  column = position.at(1);
 
  row = row + 1;//knight location 7 (positions numbered by location clockwise)
  column = column - 2; 
    if((row >=0 && row <= 7)&&(column >=0 && column <=7)){// checks if location is on the board
      if(board[row][column] != nullptr){
        if(board[row][column]->color != this -> color){//piece of oposite color
            pieceChar = board[row][column]->getDisplayChar();
            if(pieceChar == "♘"){
                return true;
            }
        }
      }
    }


  row = position.at(0);//reset row and column to match king location
  column = position.at(1);
 
  row = row + 2;//knight location 8 (positions numbered by location clockwise)
  column = column - 1; 
    if((row >=0 && row <= 7)&&(column >=0 && column <=7)){// checks if location is on the board
      if(board[row][column] != nullptr){
        if(board[row][column]->color != this -> color){//piece of oposite color
            pieceChar = board[row][column]->getDisplayChar();
            if(pieceChar == "♘"){
                return true;
            }
        }
      }
    }



}
else{//black king
//pawn checks 
row = row - 1;
   column = column + 1; //pawn right diagonal
    if((row >=0 && row <= 7)&&(column >=0 && column <=7)){// checks if location is on the board
      if(board[row][column] != nullptr){
        if(board[row][column]->color != this -> color){//piece of oposite color
            pieceChar = board[row][column]->getDisplayChar();
            if(pieceChar == "♟︎"){
                return true;
            }
        }
      }
    }
 
  row = position.at(0);//reset row and column to match king location
  column = position.at(1);
 
  row = row - 1;
  column = column - 1; //pawn left diagonal
    if((row >=0 && row <= 7)&&(column >=0 && column <=7)){// checks if location is on the board
      if(board[row][column] != nullptr){
        if(board[row][column]->color != this -> color){//piece of oposite color
            pieceChar = board[row][column]->getDisplayChar();
            if(pieceChar == "♟︎"){
                return true;
            }
        }
      }
    }


//knight ckecks

//knight checks
  row = position.at(0);//reset row and column to match king location
  column = position.at(1);
 
  row = row + 2;//knight location 1 (positions numbered by location clockwise)
  column = column + 1; 
    if((row >=0 && row <= 7)&&(column >=0 && column <=7)){// checks if location is on the board
      if(board[row][column] != nullptr){
        if(board[row][column]->color != this -> color){//piece of oposite color
            pieceChar = board[row][column]->getDisplayChar();
            if(pieceChar == "♞"){
                return true;
            }
        }
      }
    }


row = position.at(0);//reset row and column to match king location
  column = position.at(1);
 
  row = row + 1;//knight location 2 (positions numbered by location clockwise)
  column = column + 2; 
    if((row >=0 && row <= 7)&&(column >=0 && column <=7)){// checks if location is on the board
      if(board[row][column] != nullptr){
        if(board[row][column]->color != this -> color){//piece of oposite color
            pieceChar = board[row][column]->getDisplayChar();
            if(pieceChar == "♞"){
                return true;
            }
        }
      }
    }

  row = position.at(0);//reset row and column to match king location
  column = position.at(1);
 
  row = row - 1;//knight location 3 (positions numbered by location clockwise)
  column = column + 2; 
    if((row >=0 && row <= 7)&&(column >=0 && column <=7)){// checks if location is on the board
      if(board[row][column] != nullptr){
        if(board[row][column]->color != this -> color){//piece of oposite color
            pieceChar = board[row][column]->getDisplayChar();
            if(pieceChar == "♞"){
                return true;
            }
        }
      }
    }

  row = position.at(0);//reset row and column to match king location
  column = position.at(1);
 
  row = row - 2;//knight location 4 (positions numbered by location clockwise)
  column = column + 1; 
    if((row >=0 && row <= 7)&&(column >=0 && column <=7)){// checks if location is on the board
      if(board[row][column] != nullptr){
        if(board[row][column]->color != this -> color){//piece of oposite color
            pieceChar = board[row][column]->getDisplayChar();
            if(pieceChar == "♞"){
                return true;
            }
        }
      }
    }

  row = position.at(0);//reset row and column to match king location
  column = position.at(1);
 
  row = row - 2;//knight location 5 (positions numbered by location clockwise)
  column = column - 1; 
    if((row >=0 && row <= 7)&&(column >=0 && column <=7)){// checks if location is on the board
      if(board[row][column] != nullptr){
        if(board[row][column]->color != this -> color){//piece of oposite color
            pieceChar = board[row][column]->getDisplayChar();
            if(pieceChar == "♞"){
                return true;
            }
        }
      }
    }

row = position.at(0);//reset row and column to match king location
  column = position.at(1);
 
  row = row - 1;//knight location 6 (positions numbered by location clockwise)
  column = column - 2; 
    if((row >=0 && row <= 7)&&(column >=0 && column <=7)){// checks if location is on the board
      if(board[row][column] != nullptr){
        if(board[row][column]->color != this -> color){//piece of oposite color
            pieceChar = board[row][column]->getDisplayChar();
            if(pieceChar == "♞"){
                return true;
            }
        }
      }
    }

  row = position.at(0);//reset row and column to match king location
  column = position.at(1);
 
  row = row + 1;//knight location 7 (positions numbered by location clockwise)
  column = column - 2; 
    if((row >=0 && row <= 7)&&(column >=0 && column <=7)){// checks if location is on the board
      if(board[row][column] != nullptr){
        if(board[row][column]->color != this -> color){//piece of oposite color
            pieceChar = board[row][column]->getDisplayChar();
            if(pieceChar == "♞"){
                return true;
            }
        }
      }
    }


  row = position.at(0);//reset row and column to match king location
  column = position.at(1);
 
  row = row + 2;//knight location 8 (positions numbered by location clockwise)
  column = column - 1; 
    if((row >=0 && row <= 7)&&(column >=0 && column <=7)){// checks if location is on the board
      if(board[row][column] != nullptr){
        if(board[row][column]->color != this -> color){//piece of oposite color
            pieceChar = board[row][column]->getDisplayChar();
            if(pieceChar == "♞"){
                return true;
            }
        }
      }
    }



}


return false;

}
