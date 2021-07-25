#pragma once
#include "Player.h"
#include "Die.h"
#include<Windows.h>
class CrapsGame
{
private:
	Die die1;
	Die die2;
	Player player;
	int rollDice();
	void crapOut(int sum);
	void natural(int sum);
	void sevenOut();
	void hit();
	void runout(int sum);
	void playerWin();
	void playerLose();
	void startRound();
public:
	CrapsGame();
	void mainLoop();
};

