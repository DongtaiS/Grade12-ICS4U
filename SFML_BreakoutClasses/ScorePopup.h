#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
class ScorePopup : public sf::Text
{
private:
	sf::Color color;
public:
	ScorePopup(sf::Font& font, float x, float y, int score, sf::Color clr);
	void onUpdate();
	float getTransparency()
	{
		return color.a;
	}
};