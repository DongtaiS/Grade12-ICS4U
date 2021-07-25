#include <SFML/Graphics.hpp>
#include <iostream>

sf::RenderWindow app(sf::VideoMode(800, 600), "SFML window");

int main()
{
    //variables....srand
    double startX(400), startY(300), startXSpeed(3), startYSpeed(3);
    double xpos = startX, ypos = startY;
    double xspeed{ startXSpeed }, yspeed{ startXSpeed };

    // Create the main window
    app.setFramerateLimit(144);

    // Load a circle for the ball
    float ballSize = 20;
    sf::CircleShape ball(ballSize);
    ball.setOrigin(ballSize, ballSize);
    ball.setFillColor(sf::Color::Red);
    ball.setOutlineThickness(0);
    ball.setOutlineColor(sf::Color::White);
    ball.setPosition(xpos, ypos);

    //load up rectangles for the paddles

    sf::RectangleShape paddle(sf::Vector2f(30, 100));
    paddle.setOrigin(15, 50);
    paddle.setPosition(20, 300);
    paddle.setFillColor(sf::Color::Blue);

    sf::RectangleShape paddle2(sf::Vector2f(30, 100));
    paddle2.setOrigin(15, 50);
    paddle2.setPosition(780, 300);
    paddle2.setFillColor(sf::Color::Blue);

    // Start the game loop
    while (app.isOpen())
    {
        // Process events
        sf::Event event;
        while (app.pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed) {
                app.close();
            }
        }

        if (ypos > 600 - 30 || ypos < 0 + 30) yspeed *= -1;
        if (xpos > 800 - 30)
        {
            std::cout << "Player 1 wins!";
            xpos = startX;
            ypos = startY;
        }
        if (xpos < 0 + 30)
        {
            std::cout << "Player 2 wins!";
            xpos = startX;
            ypos = startY;
        }
        if (paddle.getGlobalBounds().intersects(ball.getGlobalBounds()))
        {
            float yDist = paddle.getPosition().y - ball.getPosition().y;
            yspeed = yDist * (startYSpeed / 25);
            xspeed *= -1;
            std::cout << yDist << " " << paddle.getPosition().y << " " << ball.getPosition().y << " " << yspeed << std::endl;
        }
        if (paddle2.getGlobalBounds().intersects(ball.getGlobalBounds()))
        {
            float yDist = abs(paddle2.getPosition().y - ball.getPosition().y);
            yspeed = yDist * (startYSpeed / 25);
            xspeed *= -1;
            std::cout << yDist << " " << paddle2.getPosition().y << " " << ball.getPosition().y << " " << yspeed << std::endl;
        }
        xpos += xspeed;
        ypos += yspeed;
        ball.setPosition(xpos, ypos);


        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {

            paddle2.move(0, -3);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {

            paddle2.move(0, 3);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {

            paddle.move(0, -3);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {

            paddle.move(0, 3);
        }


        //display
        // Clear screen
        app.clear();

        // Draw the sprite
        app.draw(ball);
        app.draw(paddle);
        app.draw(paddle2);

        // Update the window
        app.display();
    }

    return EXIT_SUCCESS;
}