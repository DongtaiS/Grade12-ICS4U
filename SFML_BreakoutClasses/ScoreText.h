#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
class Score : public sf::Text
{
private:
	int score;
	void updateScoreText();
public:
	Score();
	Score(sf::Font& font, float x, float y, float fontSize, int initScore);
	void increaseScore(int inc);
	int getScore()
	{
		return score;
	}
};