#pragma once
#include <iostream>
#include "Ball.h"

Ball::Ball(float r, float x, float y, float spd, int screenW, int screenH) : sf::CircleShape(r)
{
	setOrigin(r, r);
	setFillColor(sf::Color::White);
	setPosition(x, y);
	radius = r;
	speed = spd;
	xSpeed = 0;
	ySpeed = speed;
	screenWidth = screenW;
	screenHeight = screenH;
	bounceB.loadFromFile("Media/Bounce.wav");
	bounce.setBuffer(bounceB);
}
bool Ball::checkShapeCollision(sf::RectangleShape rect)
{
	if (getGlobalBounds().intersects(rect.getGlobalBounds()))
	{
		if (abs((getPosition().x + radius) - (rect.getPosition().x - rect.getSize().x/2)) <= xSpeed || abs((getPosition().x - radius) - (rect.getPosition().x + rect.getSize().x / 2)) <= xSpeed)
		{
			xSpeed *= -1;
		}
		else
		{
			float dist = getPosition().x - rect.getPosition().x;
			xSpeed = (speed - 0.1) * dist / (rect.getSize().x / 2.0 + getRadius());
			ySpeed = sqrt(speed * speed - xSpeed * xSpeed);
			if ((getPosition().y + radius) - rect.getPosition().y - (rect.getSize().y / 2) < ySpeed)
			{
				ySpeed *= -1;
			}
		}
		bounce.setBuffer(bounceB);
		bounce.play();
		return true;
	}
	return false;
}
void Ball::reset()
{
	setPosition(screenWidth / 2.0, screenHeight / 2.0);
	ySpeed = speed;
	xSpeed = 0;
}
bool Ball::checkOutOfBounds()
{
	if (getPosition().x < radius || getPosition().x + radius > screenWidth)
	{
		xSpeed *= -1;
		bounce.setBuffer(bounceB);
		bounce.play();
	}
	else if (getPosition().y < radius)
	{
		ySpeed *= -1;
		bounce.setBuffer(bounceB);
		bounce.play();
	}
	else if (getPosition().y > screenHeight + radius)
	{
		reset();
		return true;
	}
	return false;
}
void Ball::updatePos()
{
	move(xSpeed, ySpeed);
}
void Ball::increaseSpeed(float inc)
{
	xSpeed = xSpeed / speed * (speed + inc);
	ySpeed = ySpeed / speed * (speed + inc);
	speed += inc;
}