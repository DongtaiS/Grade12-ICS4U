#include "ScoreText.h"
Score::Score()
{

}
Score::Score(sf::Font& font, float x, float y, float fontSize, int initScore)
{
	score = initScore;
	setString("Breakout");
	setCharacterSize(100);
	setFont(font);
	setFillColor(sf::Color::White);
	setOrigin(getLocalBounds().width / 2, getLocalBounds().height / 2);
	setPosition(x, y);
}
void Score::updateScoreText()
{
	setString(std::to_string(score));
	setOrigin(getLocalBounds().width / 2, getLocalBounds().height / 2);
}
void Score::increaseScore(int inc)
{
	score += inc;
	updateScoreText();
}