#include "CrapsGame.h"
CrapsGame::CrapsGame()
{
	die1 = Die(6);
	die2 = Die(6);
	player = Player(500);
}
void CrapsGame::mainLoop()
{
	cout << "Welcome to craps! You have started with $500. Try to win big!" << endl;
	do
	{
		startRound();
	} while (player.playAgain());
	cout << "You have cashed out with $" << player.getMoney() << ". \nThanks for playing!";
}
void CrapsGame::playerWin()
{
	player.setMoney(player.getMoney() + player.getBet());
	cout << "You won!" << endl;
	cout << "Your winnings are $" << player.getBet() <<". \nYou currently have $" << player.getMoney() << "." << endl;
}
void CrapsGame::playerLose()
{
	player.setMoney(player.getMoney() - player.getBet());
	cout << "You lost." << endl;
	cout << "You lost $" << player.getBet() << ". \nYou currently have $" << player.getMoney() << "." << endl;
}
void CrapsGame::crapOut(int sum)
{
	cout << "Crapped out!" << endl;
	if (player.getPass())
	{
		playerLose();
	}
	else if (!player.getPass() && sum == 12)
	{
		cout << "Push!" << endl;
	}
	else
	{
		playerWin();
	}
}
void CrapsGame::natural(int sum)
{
	cout << "Natural!" << endl;
	if (player.getPass())
	{
		playerWin();
	}
	else
	{
		playerLose();
	}
}
void CrapsGame::sevenOut()
{
	cout << "Seven-out!" << endl;
	if (player.getPass())
	{
		playerLose();
	}
	else
	{
		playerWin();
	}
}
void CrapsGame::hit()
{
	cout << "Hit!" << endl;
	if (player.getPass())
	{
		playerWin();
	}
	else
	{
		playerLose();
	}
}
int CrapsGame::rollDice()
{
	die1.roll();
	die2.roll();
	int sum = die1.getValue() + die2.getValue();
	cout << "\nRolling!\n";
	Sleep(250);
	cout << ".\n";
	Sleep(250);
	cout << ".\n";
	Sleep(250);
	cout << ".\n";
	Sleep(250);
	cout << "The first die rolled a " << die1.getValue() << "!\n";
	Sleep(500);
	cout << ".\n";
	Sleep(250);
	cout << ".\n";
	Sleep(250);
	cout << ".\n";
	Sleep(250);
	cout << "The second die rolled a " << die2.getValue() << "!\n";
	Sleep(500);
	cout << "The total is " << sum << "!\n\n";
	Sleep(1000);
	return sum;
}
void CrapsGame::runout(int sum)
{
	int point = sum;
	bool repeat;
	cout << "The point is " << point << endl;
	Sleep(1000);
	do
	{
		sum = rollDice();
		repeat = sum != 7 && sum != point;
		if (repeat)
		{
			cout << "Nothing, go again!" << endl;
		}
	} while (repeat);
	if (sum == 7)
	{
		sevenOut();
	}
	else if (sum == point)
	{
		hit();
	}
}
void CrapsGame::startRound()
{
	player.getBetAndPassInput();
	int sum = rollDice();
	if (sum == 2 || sum == 3 || sum == 12)
	{
		crapOut(sum);
	}
	else if (sum == 7 || sum == 11)
	{
		natural(sum);
	}
	else
	{
		runout(sum);
	}
}