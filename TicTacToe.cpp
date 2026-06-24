#include <iostream>
using namespace std;

char board[3][3];
char currentPlayer;

void initializeBoard()
{
    char ch = '1';

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            board[i][j] = ch++;
        }
    }

    currentPlayer = 'X';
}

void displayBoard()
{
    cout << "\n";

    for(int i = 0; i < 3; i++)
    {
        cout << " ";

        for(int j = 0; j < 3; j++)
        {
            cout << board[i][j];

            if(j < 2)
                cout << " | ";
        }

        cout << "\n";

        if(i < 2)
            cout << "---|---|---\n";
    }

    cout << "\n";
}

bool makeMove(int position)
{
    int row = (position - 1) / 3;
    int col = (position - 1) % 3;

    if(position < 1 || position > 9)
        return false;

    if(board[row][col] == 'X' || board[row][col] == 'O')
        return false;

    board[row][col] = currentPlayer;
    return true;
}

bool checkWinner()
{
    for(int i = 0; i < 3; i++)
    {
        if(board[i][0] == board[i][1] &&
           board[i][1] == board[i][2])
            return true;

        if(board[0][i] == board[1][i] &&
           board[1][i] == board[2][i])
            return true;
    }

    if(board[0][0] == board[1][1] &&
       board[1][1] == board[2][2])
        return true;

    if(board[0][2] == board[1][1] &&
       board[1][1] == board[2][0])
        return true;

    return false;
}

bool boardFull()
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(board[i][j] != 'X' &&
               board[i][j] != 'O')
                return false;
        }
    }

    return true;
}

void switchPlayer()
{
    if(currentPlayer == 'X')
        currentPlayer = 'O';
    else
        currentPlayer = 'X';
}

int main()
{
    char replay;

    do
    {
        initializeBoard();

        bool gameOver = false;

        while(!gameOver)
        {
            displayBoard();

            int position;

            cout << "Player "
                 << currentPlayer
                 << ", enter position (1-9): ";

            cin >> position;

            if(!makeMove(position))
            {
                cout << "Invalid move! Try again.\n";
                continue;
            }

            if(checkWinner())
            {
                displayBoard();

                cout << "Player "
                     << currentPlayer
                     << " wins!\n";

                gameOver = true;
            }
            else if(boardFull())
            {
                displayBoard();

                cout << "Game Draw!\n";

                gameOver = true;
            }
            else
            {
                switchPlayer();
            }
        }

        cout << "\nPlay Again? (Y/N): ";
        cin >> replay;

    } while(replay == 'Y' || replay == 'y');

    cout << "\nThank You For Playing!\n";

    return 0;
}
