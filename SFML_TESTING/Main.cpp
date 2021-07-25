#include <SFML/Graphics.hpp>
#include <iostream>
class TextContainer
{
private:
    sf::Text text;
    sf::Font font;
public:
    TextContainer()
    {
        std::cout << "default";
    }
    TextContainer(float x, float y)
    {
        font.loadFromFile("Avant_Garde.ttf");
        std::cout << "Constructor";
        text = sf::Text("test", font, 30);
        text.setCharacterSize(100);
        text.setOrigin(text.getGlobalBounds().width / 2, text.getGlobalBounds().height / 2);
        text.setPosition(20, 20);
        text.setFillColor(sf::Color::White);
        text.setString("asdfasdf");
    }
    sf::Text getText()
    {
        return text;
    }
};

class Game
{
private:
    sf::RenderWindow window;
    TextContainer textC = TextContainer(20, 20);
public:
    Game()
    {
    }
    void mainLoop()
    {
        window.create(sf::VideoMode(200, 200), "SFML works!");
        sf::CircleShape shape(100.f);
        shape.setFillColor(sf::Color::Green);
        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            }
            window.clear();
            window.draw(shape);
            std::cout << textC.getText().getFont();
            window.draw(textC.getText());
            window.display();
        }
    }
};

int main()
{
    Game game;
    game.mainLoop();
    return 0;
}