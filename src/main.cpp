#include "../header/Game_Manager.h"

using namespace std;

bool startMenu();
{
    cout << "Welcome to Chess!" << endl << endl;
    cout << "Would you like to start a game? (type 'y' for yes or 'n' for no)" << endl;
    char input;
    cin >> input;
    cout << endl;

    while (input != 'y' || input != 'n')
    {
        cout << "invalid input: (type 'y' for yes or 'n' for no)" << endl;
        cin >> input;
        cout << endl;
    }

    if (input == 'y')
    {
        return true;
    }

    else if (input == 'n')
    {
        return false;
    }
}

int main(){
    // Start menu
    if (startMenu())
    {
        Game_Manager game = Game_Manager();
        game.chessboard.initBoard();
        while (!game.isGameFinished){
            game.chessboard.display();
            game.inputMove();
            game.isStalemate(); //This two functions will cahnge the value of isGameFinished
            game.isCheckMate();
        }

    //Post-game information

        if (!game.isDraw)
        {
            if (game.whiteWin)
            {
                cout << "White wins!";
            }

            else
            {
                cout << "Black wins!";
            }
        }

        else
        {
            cout << "This game is a draw!";
        }

        cout << endl;
    }

    return 0;
}