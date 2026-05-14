#include <iostream>

using namespace std;

char board[3][3];
char currentPlayer;

void initializeBoard()
{
    char ch = '1';

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = ch++;
        }
    }
}

void displayBoard()
{
    cout << "\n";

    for (int i = 0; i < 3; i++)
    {
        cout << " ";

        for (int j = 0; j < 3; j++)
        {
            cout << board[i][j];

            if (j < 2)
                cout << " | ";
        }

        cout << endl;

        if (i < 2)
            cout << "---|---|---" << endl;
    }

    cout << "\n";
}

bool makeMove(int choice)
{
    int row = (choice - 1) / 3;
    int col = (choice - 1) % 3;

    if (board[row][col] != 'X' && board[row][col] != 'O')
    {
        board[row][col] = currentPlayer;
        return true;
    }

    return false;
}

bool checkWin()
{
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == currentPlayer &&
            board[i][1] == currentPlayer &&
            board[i][2] == currentPlayer)
        {
            return true;
        }
    }

    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == currentPlayer &&
            board[1][i] == currentPlayer &&
            board[2][i] == currentPlayer)
        {
            return true;
        }
    }

    if (board[0][0] == currentPlayer &&
        board[1][1] == currentPlayer &&
        board[2][2] == currentPlayer)
    {
        return true;
    }

    if (board[0][2] == currentPlayer &&
        board[1][1] == currentPlayer &&
        board[2][0] == currentPlayer)
    {
        return true;
    }

    return false;
}

bool checkDraw()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] != 'X' && board[i][j] != 'O')
            {
                return false;
            }
        }
    }

    return true;
}

void switchPlayer()
{
    if (currentPlayer == 'X')
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

        currentPlayer = 'X';

        int choice;

        bool gameOver = false;

        cout << "\n===== TIC TAC TOE =====\n";

        while (!gameOver)
        {
            displayBoard();

            cout << "Player " << currentPlayer
                 << ", enter position (1-9): ";

            cin >> choice;

            if (choice < 1 || choice > 9)
            {
                cout << "\nInvalid Position!\n";
                continue;
            }

            if (!makeMove(choice))
            {
                cout << "\nPosition Already Taken!\n";
                continue;
            }

            if (checkWin())
            {
                displayBoard();

                cout << "\nPlayer "
                     << currentPlayer
                     << " Wins!\n";

                gameOver = true;
            }
            else if (checkDraw())
            {
                displayBoard();

                cout << "\nGame Draw!\n";

                gameOver = true;
            }
            else
            {
                switchPlayer();
            }
        }

        cout << "\nPlay Again? (Y/N): ";
        cin >> replay;

    } while (replay == 'Y' || replay == 'y');

    cout << "\nThanks for Playing!\n";

    return 0;
}
