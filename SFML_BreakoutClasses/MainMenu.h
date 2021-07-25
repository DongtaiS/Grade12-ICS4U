#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
class MainMenu
{
private:
	sf::Font& font;
	sf::Text title;
	sf::Text subTitle;
	sf::Text endScore;
	sf::Text restart;
	bool start;
	void setupText(sf::Text& text, std::string txt, int fontSize, float x, float y);
public:
	MainMenu(sf::Font& fnt);
	void setup(float screenW, float screenH);
	void drawAll(sf::RenderWindow& window);
	void startScreen()
	{
		start = true;
	}
	void endScreen()
	{
		start = false;
	}
};

