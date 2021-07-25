#include "Player.h"
Player::Player()
{

}
Player::Player(int startMoney)
{
	money = startMoney;
	currentBet = 0;
}
void Player::getBetAndPassInput()
{
	cout << "Would you like to bet on pass (y) or don't pass (n)?" << endl;
	char passChar;
	cin >> passChar;
	while (passChar != 'y' && passChar != 'Y' && passChar != 'N' && passChar != 'n')
	{
		cout << "Please only enter a letter. 'y' for pass, 'n' for don't pass." << endl;
		cin >> passChar;
	}
	if (passChar == 'Y' || passChar == 'y')
	{
		setPass(true);
	}
	else
	{
		setPass(false);
	}
	cout << "What would you like to bet?" << endl;
	cout << "You currently have $" << money << endl;
	int input;
	cin >> input;
	while (input > money || input <= 0)
	{
		cout << "You can only bet positive values below the amount of money you have." << endl;
		cout << "What would you like to bet?" << endl;
		cin >> input;
	}
	setBet(input);
	if (pass)
	{
		cout << "You bet $" << currentBet << " on pass (7 or 11). " << endl;
	}
	else
	{
		cout << "You bet $" << currentBet << " on don't pass (2, 3, or 12). " << endl;
	}
}
bool Player::playAgain()
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