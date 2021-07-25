#pragma once
#include <SFML/Graphics.hpp>
void createBricks(std::vector<sf::RectangleShape>& bricks)
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 11; j++)
        {
            bricks[i * 11 + j].setSize(sf::Vector2f(1600 / 12, 800 / 20));
            bricks[i * 11 + j].setOrigin(bricks[i * 11 + j].getSize().x / 2, bricks[i * 11 + j].getSize().y / 2);
            bricks[i * 11 + j].setPosition((j + 0.5f) * 1600 / 11, (i + 2) * 800 / 16);
            bricks[i * 11 + j].setFillColor(sf::Color::Blue);
        }
    }
}
void setupShapes(sf::CircleShape& ball, sf::RectangleShape& paddle)
{
    ball.setFillColor(sf::Color::Red);
    ball.setOrigin(30.0, 30.0);
    ball.setPosition(800, 400);

    paddle.setOrigin(100, 10);
    paddle.setPosition(800, 780);
}