#include "Ball.h"
#include <SFML/Graphics.hpp>
#include "Main.cpp"
class Ball
{
    public: 
        sf::CircleShape circle;
	    void checkCollision(sf::Shape shape)
	    {
            if (circle.getGlobalBounds().intersects(shape.getGlobalBounds()))
            {
                int multiplier = 1;
                if (circle.getPosition().x < shape.getPosition().x)
                {
                    multiplier = -1;
                }
                updateSpeed();
                float yDist = circle.getPosition().y - shape.getPosition().y;
                ySpeed = (speed - 0.1) * yDist / (paddleL.getSize().y / 2 + ballRadius);
                xSpeed = sqrt(pow(speed, 2) - pow(ySpeed, 2));
            }
	    }
};