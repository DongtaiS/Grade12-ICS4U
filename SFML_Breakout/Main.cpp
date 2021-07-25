#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <ctime>
#include <cmath>
#include "Util.h"

sf::SoundBuffer bounceB;
sf::Sound bounce;
void drawBricks(sf::RenderWindow& window, std::vector<sf::RectangleShape>& bricks, int num)
{
    if (num == 0)
    {
        return;
    }
    window.draw(bricks[num - 1]);
    drawBricks(window, bricks, num - 1);
}
bool checkRect(sf::CircleShape ball, sf::RectangleShape rect, float& xSpeed, float& ySpeed, int speed) //Returns true if collision is detected
{
    if (ball.getGlobalBounds().intersects(rect.getGlobalBounds()))
    {
        float dist = ball.getPosition().x - rect.getPosition().x;
        xSpeed = (speed - 0.1) * dist / (rect.getSize().x/2.0 + ball.getRadius());
        ySpeed = sqrt(speed * speed - xSpeed * xSpeed);
        if (ball.getPosition().y < rect.getPosition().y - (rect.getSize().y / 2))
        {
            ySpeed *= -1;
        }
        bounce.play();
        return true;
    }
    return false;
}
void recursiveBrickCheck(sf::CircleShape& ball, std::vector<sf::RectangleShape>& bricks, float& xSpeed, float& ySpeed, int speed, int counter)
{
    if (counter == 0)
    {
        return;
    }
    if (checkRect(ball, bricks[counter - 1], xSpeed, ySpeed, speed))
    {
        bricks.erase(bricks.begin() + counter - 1); //I used a vector and removed the brick but this could just set the position of the brick outside of the window
        return;
    }
    recursiveBrickCheck(ball, bricks, xSpeed, ySpeed, speed, counter - 1);
}
void checkCollision(sf::CircleShape& ball, sf::RectangleShape paddle, std::vector<sf::RectangleShape>& bricks, float& xSpeed, float& ySpeed, int speed)
{
    checkRect(ball, paddle, xSpeed, ySpeed, speed);
    recursiveBrickCheck(ball, bricks, xSpeed, ySpeed, speed, bricks.size());
    if (ball.getPosition().x < ball.getRadius() || ball.getPosition().x + ball.getRadius() > 1600)
    {
        bounce.play();
        xSpeed *= -1;
    }
    if (ball.getPosition().y < ball.getRadius())
    {
        bounce.play();
        ySpeed *= -1;
    }
    if (ball.getPosition().y - ball.getRadius() > 800)
    {
        ball.setPosition(800, 400);
        ySpeed = rand() % 3 + 4;
        xSpeed = sqrt(speed * speed - ySpeed * ySpeed);
        if (rand() % 2 < 1)
        {
            xSpeed *= -1;
        }
    }
    std::cout << ySpeed << std::endl;
    ball.move(xSpeed, ySpeed);
}
void movePaddle(sf::RectangleShape& paddle)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && paddle.getPosition().x > paddle.getSize().x / 2)
    {
        paddle.move(-8, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && paddle.getPosition().x + paddle.getSize().x / 2 < 1600)
    {
        paddle.move(8, 0);
    }
}
int main()
{
    bounceB.loadFromFile("Media/Bounce.wav");
    bounce.setBuffer(bounceB);
    int width = 1600, height = 800;
    int speed = 7; 
    float ySpeed = rand() % 3 + 4;
    float xSpeed = sqrt(speed*speed - ySpeed*ySpeed);
    if (rand() % 2 < 1)
    {
        xSpeed *= -1;
    }
    srand(time(NULL));
    
    sf::RenderWindow window(sf::VideoMode(width, height), "SFML works!");
    window.setFramerateLimit(120);

    sf::CircleShape ball(30.f);
    sf::RectangleShape paddle(sf::Vector2f(200, 20));
    setupShapes(ball, paddle);

    std::vector<sf::RectangleShape> bricks(55, sf::RectangleShape());

    createBricks(bricks);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        movePaddle(paddle);
        checkCollision(ball, paddle, bricks, xSpeed, ySpeed, speed);
        window.clear();
        window.draw(ball);
        window.draw(paddle);
        drawBricks(window, bricks, bricks.size());
        window.display();
    }

    return 0;
}