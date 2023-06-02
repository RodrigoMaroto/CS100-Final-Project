#include "../header/Game_Manager.h"

using namespace std;

int main(){
    // Start menu
    Game_Manager game = Game_Manager();
    game.chessboard.initBoard();
    while (!game.isGameFinished){
        game.chessboard.display();
        game.inputMove();
        game.isStalemate(); //This two functions will cahnge the value of isGameFinished
        game.isCheckMate();
    }
    //Post-game information
}