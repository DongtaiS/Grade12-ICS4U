#include "MainMenu.h"
MainMenu::MainMenu(sf::Font& fnt) : font(fnt)
{
}
void MainMenu::setupText(sf::Text& text, std::string str, int fontSize, float x, float y)
{
	text.setString(str);
	text.setCharacterSize(fontSize);
	text.setFont(font);
	text.setFillColor(sf::Color::White);
	text.setOrigin(text.getGlobalBounds().width / 2, text.getGlobalBounds().height / 2);
	text.setPosition(x, y);
}
void MainMenu::setup(float screenW, float screenH)
{
	setupText(title, "Breakout", 100, screenW / 2, screenH / 2);
	setupText(subTitle, "Press space to play", 50, screenW / 2, 2*screenH / 3);
	setupText(endScore, "Your score was:", 75, screenW / 2, screenH / 3);
	setupText(restart, "Press [esc] to return to the main menu", 50, screenW / 2, 2*screenH / 3);
}
void MainMenu::drawAll(sf::RenderWindow& window)
{
	if (start)
	{
		window.draw(title);
		window.draw(subTitle);
	}
	else
	{
		window.draw(endScore);
		window.draw(restart);
	}
}