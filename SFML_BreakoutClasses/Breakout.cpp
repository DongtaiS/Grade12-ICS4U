#include "Breakout.h"
Breakout::Breakout() : mainMenu(font)
{
    font.loadFromFile("Media/Avant_Garde.ttf");
    window.create(sf::VideoMode(width, height), "Breakout");
    window.setFramerateLimit(120);
    mainMenu.setup(width, height);
    gameState = START;
    srand(time(NULL));
}
void Breakout::setup()
{
    score = Score(font, width / 2, height / 2, 20, 0);
    paddle = Paddle(200, 20, width / 2, height - 20, sf::Color::White, width, 8);
    ball = Ball(30, width / 2, height / 2, 7, width, height);
    popups.clear();
    for (int i = 0; i < 5; i++)
    {
        sf::Color color;
        switch (i)
        {
        case 0:
            color = sf::Color::Blue;
            break;
        case 1:
            color = sf::Color::Green;
            break;
        case 2:
            color = sf::Color::Yellow;
            break;
        case 3:
            color = sf::Color(255, 150, 0);
            break;
        case 4:
            color = sf::Color::Red;
            break;
        }
        int points = (i + 1) * 100;
        for (int k = 0; k < 10; k++)
        {
            float xPos = (k + 0.5) * (width / 10.0f);
            float yPos = (i + 2) * -(height / 15.0f) + (height / 2.0f);
            bricks.push_back({ width / 11.0f, height / 20.0f, xPos, yPos, color, points });
        }
    }
}
void Breakout::getInput()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        paddle.movePaddle(true);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        paddle.movePaddle(false);
    }
}
void Breakout::checkCollision()
{
    ball.checkShapeCollision(paddle);
    for (int i = 0; i < bricks.size(); i++)
    {
        if (ball.checkShapeCollision(bricks[i]))
        {
            score.increaseScore(bricks[i].getPoints());
            float xPos = rand() % width / 10.0 + bricks[i].getPosition().x - width / 20.0;
            float yPos = rand() % height / 10.0 + bricks[i].getPosition().y - height / 20.0;
            popups.push_back({ font, xPos, yPos, bricks[i].getPoints(), bricks[i].getFillColor() });
            bricks.erase(bricks.begin() + i);
            if (bricks[i].getPoints() > 300)
            {
                ball.increaseSpeed(bricks[i].getPoints() / 1000.0);
            }
            break;
        }
    }
    if (ball.checkOutOfBounds())
    {
        score.increaseScore(-100);
        popups.push_back(ScorePopup(font, rand() % width / 3.0 + width / 3.0, rand() % height / 3.0 + height / 3.0, -100, sf::Color::White));
    }
    if (bricks.size() == 0)
    {
        gameState = END;
    }
    ball.updatePos();
}
void Breakout::updatePopups()
{
    for (int i = 0; i < popups.size(); i++)
    {
        popups[i].onUpdate();
        if (popups[i].getTransparency() <= 0)
        {
            popups.erase(popups.begin() + i);
            i--;
        }
    }
}
void Breakout::drawAll()
{
    for (Brick brick : bricks)
    {
        window.draw(brick);
    }
    for (ScorePopup popup : popups)
    {
        window.draw(popup);
    }
    window.draw(ball);
    window.draw(paddle);
    window.draw(score);
}
void Breakout::mainLoop()
{
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        switch (gameState)
        {
            case START:
                mainMenu.startScreen();
                mainMenu.drawAll(window);
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
                {
                    gameState = GAME;
                    setup();
                }
                break;
            case GAME:
                getInput();
                checkCollision();
                updatePopups();
                drawAll();
                break;
            case END:
                mainMenu.endScreen();
                mainMenu.drawAll(window);
                window.draw(score);
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                {
                    gameState = START;
                }
                break;
        }
        window.display();
    }
}