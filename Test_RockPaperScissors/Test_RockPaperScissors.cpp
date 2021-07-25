#include <iostream>
#include <ctime>
using namespace std;
int didPlayerWin(int player, int comp) // 2 is tie, 1 is win, 0 is loss (for player)
{
    if (player == comp)
    {
        return 2;
    }
    else if (player == 1 && comp == 3)
    {
        return 1;
    }
    else if (player == 3 && comp == 1)
    {
        return 0;
    }
    else if (player > comp)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    int compScore = 0, playerScore = 0;
    char continueInput;
    srand(time(0));
    cout << "Welcome to rock, paper, scissors!" << endl;
    do
    {
        int roundResult;
        do
        {
            int computerNum = rand() % (3) + 1;
            char playerChoice;
            int playerNum;
            do
            {
                cout << endl << "Please enter either 'R', 'P' or 'S' to play" << endl;
                cout << "'R' for rock, 'P' for paper 'S' for scissors" << endl;
                cin >> playerChoice;
            } while (playerChoice != 'R' && playerChoice != 'P' && playerChoice != 'S');
            
            cout << endl;
            if (playerChoice == 'R')
            {
                playerNum = 1;
                cout << "You chose rock." << endl;
            }
            else if (playerChoice == 'P')
            {
                playerNum = 2;
                cout << "You chose paper." << endl;
            }
            else if (playerChoice == 'S')
            {
                playerNum = 3;
                cout << "You chose scissors." << endl;
            }
            
            if (computerNum == 1)
            {
                cout << "The computer chose rock." << endl;
            }
            else if (computerNum == 2)
            {
                cout << "The computer chose paper." << endl;
            }
            else if (computerNum == 3)
            {
                cout << "The computer chose scissors." << endl;
            }

            roundResult = didPlayerWin(playerNum, computerNum);
            if (roundResult == 2)
            {
                cout << endl << "It's a tie! Go again." << endl << endl;
            }
        } while (roundResult == 2); //keep looping until it's not a tie

        if (roundResult == 1)
        {
            cout << endl << "Congrats, you win!" << endl;
            playerScore++;
        }
        else
        {
            cout << endl << "Sorry, you lose!" << endl;
            compScore++;
        }

        cout << endl << "Scores" << endl << "Computer: " << compScore << "\t Player: " << playerScore << endl;
        cout << "Play again? (y/n)" << endl;
        cin >> continueInput;
        while (continueInput != 'Y' && continueInput != 'y' && continueInput != 'N' && continueInput != 'n')
        {
            cout << "Please enter only 'y' or 'n'." << endl;
            cin >> continueInput;
        }
    } while (continueInput == 'Y' || continueInput == 'y');
    cout << "Thanks for playing!";
}