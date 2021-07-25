#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
void draw(sf::RenderWindow& window, std::vector<sf::Sprite>& sprites, std::vector<float>& fallSpeed, std::vector<float>& rotationSpeed)
{
    window.clear();
    for (int i = 0; i < sprites.size(); i++)
    {
        sprites[i].move(0, fallSpeed[i]);
        sprites[i].rotate(rotationSpeed[i]);
        if (sprites[i].getPosition().y > window.getSize().y+sprites[i].getGlobalBounds().height/2)
        {
            sprites[i].setPosition(rand() % window.getSize().x, -sprites[i].getGlobalBounds().height / 2);
        }
        window.draw(sprites[i]);
    }
    window.display();
}
void changeColors(std::vector<sf::Sprite>& sprites, std::vector<float> fadeRate, std::vector<bool>& increasing)
{
    for (int i = 0; i < sprites.size(); i++)
    {
        if (increasing[i])
        {
            sf::Color temp = sprites[i].getColor();
            temp.a += fadeRate[i];
            sprites[i].setColor(temp);
            if (temp.a >= 255)
            {
                increasing[i] = false;
            }
        }
        else
        {
            sf::Color temp = sprites[i].getColor();
            temp.a -= fadeRate[i];
            sprites[i].setColor(temp);
            if (temp.a < 50)
            {
                increasing[i] = true;
            }
        }
    }
}
void setup(sf::RenderWindow& window, std::vector<sf::Sprite>& sprites, std::vector<float>& fallSpeed, std::vector<float>& rotationSpeed, std::vector<float>& fadeRate, sf::Texture& texture)
{
    window.setFramerateLimit(144);
    for (int i = 0; i < 20; i++)
    {
        sprites.push_back(sf::Sprite(texture));
        sprites[i].setScale(0.25, 0.25);
        sprites[i].setOrigin(sprites[i].getLocalBounds().width / 2, sprites[i].getLocalBounds().height / 2);
        sprites[i].setPosition(rand() % window.getSize().x, rand() % window.getSize().y);
        sprites[i].setRotation(rand() % 360);
        fallSpeed[i] = rand() % 3 + 1;
        float temp = rand() % 2 + 1;
        if (rand() % 2 == 0)
        {
            temp *= -1;
        }
        rotationSpeed[i] = temp;
        fadeRate[i] = rand() % 3 + 1;
    }
}
int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "It's snowing!");
    sf::Texture texture;
    texture.loadFromFile("Images/Snowflake.png");
    std::vector<sf::Sprite> sprites;
    std::vector<float> fallSpeed(20);
    std::vector<float> rotationSpeed(20);
    std::vector<float> fadeRate(20);
    std::vector<bool> increasing(20, false);
    setup(window, sprites, fallSpeed, rotationSpeed, fadeRate, texture);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        changeColors(sprites, fadeRate, increasing);
        draw(window, sprites, fallSpeed, rotationSpeed);
    }

    return 0;
}