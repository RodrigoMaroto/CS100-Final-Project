#include "../header/Game_Manager.h"

using namespace std;

int main(){
    Game_Manager game = Game_Manager();
    game.chessboard.initBoard();
    while (!game.isGameFinished){
        game.chessboard.display();
        game.inputMove();
    }
}