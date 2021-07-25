#include "ScorePopup.h"
ScorePopup::ScorePopup(sf::Font& font, float x, float y, int score, sf::Color clr)
{
	color = clr;
	std::string str = "+";
	if (score < 0)
	{
		str = "";
	}
	str += std::to_string(score);
	setString(str);
	setCharacterSize(75);
	setFont(font);
	setFillColor(color);
	setOrigin(getGlobalBounds().width / 2, getGlobalBounds().height / 2);
	setPosition(x, y);
}
void ScorePopup::onUpdate()
{
	color.a -= 0.5f;
	setFillColor(color);
}