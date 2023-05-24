#include "../header/Chess_Board.h"
#include "../header/piece.h"
#include "../header/knight.h"
#include "../header/rook.h"
#include "../header/pawn.h"
#include "../header/queen.h"
#include "../header/king.h"
#include "../header/bishop.h"
#include <iostream>
#include <string>
using namespace std;


Chess_Board::Chess_Board() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            board[i][j] = nullptr;
        }
    }
}

void Chess_Board::display(){
    for (int i = 7; i >= 0; i--) {
        cout<< i+1 << ' ';
        for (int j = 0; j < 8; j++) {
            if (board[i][j] != nullptr) {
                cout<< board[i][j]->getDisplayChar() << ' ';
            } 
            else {
                if (i%2 && !(j%2))
                    cout << "■ ";
                else if(j%2 && !(i%2))
                    cout << "■ ";
                else
                    cout << "□ ";
            }
        }
        cout << endl;
    }
    cout << "  a b c d e f g h"<<endl;
}
