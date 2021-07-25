#pragma once
#include <ctime>
#include <random>
class Die
{
private:
	int sides;
	int value;
public:
	Die(int s);
	int getValue();
	void setSides(int s);
	void roll();
};

