#include "../header/queen.h"
#include <vector>

// class Queen : public Piece
// {
//     private:

//     public:
//         void move(vector<int> destination) override;
//         vector<vector<int>> validDestinations() override;
// };oijooko
Queen::Queen(char col, vector<int> pos){
    this->color = col;
    this->position = pos;
}
string Queen::getDisplayChar(){
    string displayChar = "no char";
    if(this->color == 'w')
    {
        displayChar = "♛";
    }  
    else if(this->color == 'b')
    {
        displayChar = "♕";
    }
    return displayChar;
}

vector<vector<int>> Queen::validDestinations(Piece* board[8][8]){
  
    vector<int> pos;
    pos.push_back(0);
    pos.push_back(0);
    int row = position.at(0);
    int column = position.at(1);
    vector<vector<int>> allMoves;

  // begin bishop-type moves
  for(int i = 1; i <=7;++i){// up & right
    row = position.at(0);
    column = position.at(1);
    row = row + i;
    column = column +i;
    if((row >=0 && row <= 7)&&(column >=0 && column <=7)){// checks if location is on the board
      if(board[row][column] == nullptr){//no piece in this spot
        pos.at(0) = row;
        pos.at(1) = column;
        allMoves.push_back(pos);// add move to list
      }
      else if(board[row][column]->color == this -> color){//piece of same color in way
        break;
      }
      else if(board[row][column]->color != this->color){//piece of opposite color (can take)
        pos.at(0) = row;
        pos.at(1) = column;
        allMoves.push_back(pos);// add move to list
        break;
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
      if(board[row][column] == nullptr){//no piece in this spot
        pos.at(0) = row;
        pos.at(1) = column;
        allMoves.push_back(pos);// add move to list
      }
      else if(board[row][column]->color == this -> color){//piece of same color in way
        break;
      }
      else if(board[row][column]->color != this->color){//piece of opposite color (can take)
        pos.at(0) = row;
        pos.at(1) = column;
        allMoves.push_back(pos);// add move to list
        break;
      }
      
    }
    row = position.at(0);
    column = position.at(1);
  }
  for(int i = 1; i <=7;++i){// down & left
    row = position.at(0);
    column = position.at(1);
    row = row - i;
    column = column -i;
    if((row >=0 && row <= 7)&&(column >=0 && column <=7)){// checks if location is on the board
      if(board[row][column] == nullptr){//no piece in this spot
        pos.at(0) = row;
        pos.at(1) = column;
        allMoves.push_back(pos);// add move to list
      }
      else if(board[row][column]->color == this -> color){//piece of same color in way
        break;
      }
      else if(board[row][column]->color != this->color){//piece of opposite color (can take)
        pos.at(0) = row;
        pos.at(1) = column;
        allMoves.push_back(pos);// add move to list
        break;
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
      if(board[row][column] == nullptr){//no piece in this spot
        pos.at(0) = row;
        pos.at(1) = column;
        allMoves.push_back(pos);// add move to list
      }
      else if(board[row][column]->color == this -> color){//piece of same color in way
        break;
      }
      else if(board[row][column]->color != this->color){//piece of opposite color (can take)
        pos.at(0) = row;
        pos.at(1) = column;
        allMoves.push_back(pos);// add move to list
        break;
      }
      
    }
    row = position.at(0);
    column = position.at(1);
  }
  //end bushop type moves

  //begin rook type moves
  for(int i = 1; i <=7;++i){// up vertical
    row = position.at(0);
    column = position.at(1);
    row = row + i;
    column = column;
    if((row >=0 && row <= 7)&&(column >=0 && column <=7)){// checks if location is on the board
      if(board[row][column] == nullptr){//no piece in this spot
        pos.at(0) = row;
        pos.at(1) = column;
        allMoves.push_back(pos);// add move to list
      }
      else if(board[row][column]->color == this -> color){//piece of same color in way
        break;
      }
      else if(board[row][column]->color != this->color){//piece of opposite color (can take)
        pos.at(0) = row;
        pos.at(1) = column;
        allMoves.push_back(pos);// add move to list
        break;
      }
        row = position.at(0);
        column = position.at(1);
      
    }
    
  }
  for(int i = 1; i <=7;++i){// down vertical
    row = position.at(0);
    column = position.at(1);
    row = row - i;
    column = column;
    if((row >=0 && row <= 7)&&(column >=0 && column <=7)){// checks if location is on the board
      if(board[row][column] == nullptr){//no piece in this spot
        pos.at(0) = row;
        pos.at(1) = column;
        allMoves.push_back(pos);// add move to list
      }
      else if(board[row][column]->color == this -> color){//piece of same color in way
        break;
      }
      else if(board[row][column]->color != this->color){//piece of opposite color (can take)
        pos.at(0) = row;
        pos.at(1) = column;
        allMoves.push_back(pos);// add move to list
        break;
      }
      row = position.at(0);
        column = position.at(1);
    }
  }
  for(int i = 1; i <=7;++i){// right horizontal
    row = position.at(0);
    column = position.at(1);
    row = row;
    column = column +i;
    if((row >=0 && row <= 7)&&(column >=0 && column <=7)){// checks if location is on the board
      if(board[row][column] == nullptr){//no piece in this spot
        pos.at(0) = row;
        pos.at(1) = column;
        allMoves.push_back(pos);// add move to list
      }
      else if(board[row][column]->color == this -> color){//piece of same color in way
        break;
      }
      else if(board[row][column]->color != this->color){//piece of opposite color (can take)
        pos.at(0) = row;
        pos.at(1) = column;
        allMoves.push_back(pos);// add move to list
        break;
      }
      
    }
    row = position.at(0);
    column = position.at(1);
  }
  for(int i = 1; i <=7;++i){// left horizotal
    row = position.at(0);
    column = position.at(1);
    row = row;
    column = column -i;
    if((row >=0 && row <= 7)&&(column >=0 && column <=7)){// checks if location is on the board
      if(board[row][column] == nullptr){//no piece in this spot
        pos.at(0) = row;
        pos.at(1) = column;
        allMoves.push_back(pos);// add move to list
      }
      else if(board[row][column]->color == this -> color){//piece of same color in way
        break;
      }
      else if(board[row][column]->color != this->color){//piece of opposite color (can take)
        pos.at(0) = row;
        pos.at(1) = column;
        allMoves.push_back(pos);// add move to list
        break;
      }
      row = position.at(0);
      column = position.at(1);
    }
  }
  //end rook type moves


   return allMoves; 
}