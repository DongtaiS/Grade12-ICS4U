#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(600, 600), "SFML works!");
    sf::CircleShape shape[15];

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i * 3 + j == 7) {
                continue;
            }
            shape[i * 3 + j].setRadius(25);
            shape[i * 3 + j].setFillColor(sf::Color::Green);
            shape[i * 3 + j].setPosition(i * 60, j * 60);
        }
    }

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        for (int i = 0; i < 15; i++)
        {
            window.draw(shape[i]);
        }
        window.display();
    }

    return 0;
}