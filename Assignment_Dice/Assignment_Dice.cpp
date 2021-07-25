#include <iostream>
#include "Die.h"
using namespace std;
int rollDice(Die die1, Die die2)
{
	die1.roll();
	die2.roll();
	int sum = die1.getValue() + die2.getValue();
	cout << "Rolling! \n.\n.\nThe first die rolled a " << die1.getValue() << "!\n.\n.\nThe second die rolled a " << die2.getValue() << "!" << "\n\nThe total is " << sum << "!\n\n";
	return sum;
}
bool getPlayerPass()
{
	char input;
	cout << "Do you want to bet on pass (y) or don't pass (n)?" << endl;
	cin >> input;
	while (input != 'y' && input != 'Y' && input != 'N' && input != 'n')
	{
		cout << "Please only enter a letter. 'y' for pass, 'n' for don't pass." << endl;
		cin >> input;
	}
	if (input == 'Y' || input == 'y')
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool playAgain()
{
	char input;
	cout << "\nDo you want to play again? (y/n)" << endl;
	cin >> input;
	while (input != 'y' && input != 'Y' && input != 'N' && input != 'n')
	{
		cout << "Please only enter a letter, 'y' or 'n'." << endl;
		cin >> input;
	}
	if (input == 'Y' || input == 'y')
	{
		return true;
	}
	else
	{
		return false;
	}
}
int main()
{
	Die die1(6);
	Die die2(6);
	do
	{
		bool pass = getPlayerPass();
		int sum = rollDice(die1, die2);
		if (sum == 2 || sum == 3 || sum == 12)
		{
			cout << "Crapped out!" << endl;
			if (pass)
			{
				cout << "You lost." << endl;
			}
			else if (!pass && sum == 12)
			{
				cout << "Push!" << endl;
			}
			else
			{
				cout << "You won!" << endl;
			}
		}
		else if (sum == 7 || sum == 11)
		{
			cout << "Natural!" << endl;
			if (pass)
			{
				cout << "You win!" << endl;
			}
			else
			{
				cout << "You lost." << endl;
			}
		}
		else
		{
			int point = sum;
			bool repeat;
			cout << "The point is " << point << endl;
			do
			{
				sum = rollDice(die1, die2);
				repeat = sum != 7 && sum != point;
				if (repeat)
				{
					cout << "Nothing, go again!" << endl;
				}
			} while (repeat);
			if (sum == 7)
			{
				cout << "Seven-out!" << endl;
				if (pass)
				{
					cout << "You lost." << endl;
				}
				else
				{
					cout << "You win!" << endl;
				}
			}
			else if (sum == point)
			{
				cout << "Hit!" << endl;
				if (pass)
				{
					cout << "You win!" << endl;
				}
				else
				{
					cout << "You lost." << endl;
				}
			}
		}
	} while (playAgain());
}
