#pragma once
#include <SFML/Graphics.hpp>
class Brick : public sf::RectangleShape
{
private:
	int pointVal;
public:
	Brick(float w, float h, float x, float y, sf::Color color, int pts);
	int getPoints()
	{
		return pointVal;
	}
};

