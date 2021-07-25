#include <iostream>
#include <ctime>

using namespace std;
int main()
{
    srand(time(0));
    char response;
    do
    {
        int randomNumber = rand() % (100 - 1) + 1;
        int guess;
        int counter = 1;

        cout << "Guess a number between 1 and 100" << endl;
        cin >> guess;

        while (guess != randomNumber)
        {
            cout << "Try again" << endl;
            cin >> guess;
            counter++;
        }

        cout << "Wow! you guessed the number in " << counter << " guesses!" << endl;
        cout << "Would you like to play again? (y/n)" << endl;
        cin >> response;

        while (response != 'y' && response != 'Y' && response != 'N' && response != 'n')
        {
            cout << "Please enter only 'y' or 'n'" << endl;
            cin >> response;
        }
    } while (response == 'y' || response == 'Y');
}