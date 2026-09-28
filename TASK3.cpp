#include <iostream>
using namespace std;

class Board {
    private:
        char board[9];
    public:

        Board(){
            resetBoard();
        }

        void resetBoard(){
            for (int i = 0; i<9; i++){
                board[i] = '1' + i;
            }
        }

        void displayBoard() {
            cout << "\n";

            cout << " "<< board[0] << " | " << board[1] << " | " << board[2] << endl;

            cout << "---+---+---" << endl;

            cout << " " << board[3] << " | " << board[4] << " | " << board[5] << endl;

            cout << "---+---+---" << endl;

            cout << " " << board[6] << " | " << board[7] << " | " << board[8] << endl;
            cout << "\n";
           
        }

        bool isValidMove(int position) {
            if (position < 1 || position > 9){
                return false;
            }

            if (board[position - 1] == 'X' || board[position - 1] == 'O') {
                return false;
            }
            return true;
        }

        void makeMove(int position, char player) {
            board [position - 1] = player;
        }

        bool checkWinner(char player) {
            int winningCombinations[8][3] = {
                {0,1,2},
                {3,4,5},
                {6,7,8},

                {0,3,6},
                {1,4,7},
                {2,5,8},
                
                {0,4,8},
                {2,4,6}
            };
            for (int i = 0; i < 8; i++) {
                if (board[winningCombinations[i][0]] == player && board[winningCombinations[i][1]] == player && board[winningCombinations[i][2]] == player){
                    return true;
                }
                
            }
            return false;
        }

        bool checkDraw() {
            for (int i = 0; i < 9; i++){
                if (board[i] != 'X' && board[i] != 'O'){
                    return false;
                }
            }
            return true;
        }

};

class Game 
{
    private:

    Board board;

    char currentPlayer;

    public:

    Game() {
        currentPlayer = 'X';

    }

    void switchPlayer() {
        if (currentPlayer == 'X'){
            currentPlayer = 'O';
        }

        else{
            currentPlayer = 'X';
        }
    }

    void playGame() {
        board.resetBoard();

        currentPlayer = 'X';

        while (true) {
            board.displayBoard();

            int position;

            cout<<"Player " << currentPlayer << " enter the position from (1-9):";

            cin >> position;

            if(!board.isValidMove(position)){
                cout << "Invalid move!\n";
                continue;
            }
            board.makeMove(position, currentPlayer);

            if (board.checkWinner(currentPlayer)){
                board.displayBoard();

                cout << "Player " << currentPlayer << " wins!\n";
                break;
            }

            if (board.checkDraw()){
                board.displayBoard();

                cout << "game is draw\n";

                break;
            }

            switchPlayer();
    
        }
    
    }

    void start() {
        char playAgain;

        do {
            cout << "\n";
            cout << "========================\n";
            cout << "       TIC-TAC-TOE\n";
            cout << "========================\n";

            playGame();
            cout << "\nDo you want to play again? (Y/N)";
            cin >> playAgain;
        }
            while (
                (playAgain == 'Y' || playAgain == 'y')
            );

            cout << "Thanks for playing the game\n";
        
    } 
    
};

int main()
{
    Game game;

    game.start();
    return 0;
}