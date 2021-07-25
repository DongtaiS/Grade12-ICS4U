#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
class Ball : public sf::CircleShape
{
private:
	float radius;
	float xSpeed, ySpeed, speed;
	int screenWidth, screenHeight;
	sf::SoundBuffer bounceB;
	sf::Sound bounce;
	void reset();
public:
	Ball(float r, float x, float y, float spd, int screenW, int screenH);
	bool checkOutOfBounds();
	bool checkShapeCollision(sf::RectangleShape rect);
	void updatePos();
	void increaseSpeed(float inc);
};

