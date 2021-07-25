#include "Brick.h"
Brick::Brick(float w, float h, float x, float y, sf::Color color, int pts) : sf::RectangleShape(sf::Vector2f(w, h))
{
	setOrigin(w / 2, h / 2);
	setPosition(x, y);
	setFillColor(color);
	pointVal = pts;
}