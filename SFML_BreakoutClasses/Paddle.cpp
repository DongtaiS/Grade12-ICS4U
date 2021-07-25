#include "Paddle.h"
Paddle::Paddle(float w, float h, float x, float y, sf::Color color, int screenW, float spd) : sf::RectangleShape(sf::Vector2f(w,h))
{
    setOrigin(w / 2, h / 2);
    setPosition(x, y);
    setFillColor(color);
    screenWidth = screenW;
    paddleSpeed = spd;
}
void Paddle::movePaddle(bool left)
{
    int tempSpeed = paddleSpeed;
    if (left)
    {
        tempSpeed *= -1;
    }
    float tempX = getPosition().x + tempSpeed;
    if (tempX > getSize().x / 2 && tempX + getSize().x / 2 < screenWidth)
    {
        move(tempSpeed, 0);
    }
}