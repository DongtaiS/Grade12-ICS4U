#pragma once
#include <SFML/Graphics.hpp>
class Paddle : public sf::RectangleShape
{
private:
	int screenWidth;
	float paddleSpeed;
public:
	Paddle(float w, float h, float x, float y, sf::Color color, int screenW, float spd);
	void movePaddle(bool left);
};

