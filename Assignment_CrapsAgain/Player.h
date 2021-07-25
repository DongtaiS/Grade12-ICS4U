#pragma once
#include <iostream>

using namespace std;
class Player
{
private:
	int money;
	int currentBet;
	bool pass;
	void setBet(int newBet) { currentBet = newBet; }
	void setPass(bool betOnPass) { pass = betOnPass; }
public:
	Player();
	Player(int startMoney);
	int getMoney() { return money; }
	void setMoney(int newMoney) { money = newMoney; }
	int getBet() { return currentBet; }
	bool getPass() { return pass; }
	void getBetAndPassInput();
	bool playAgain();
};

