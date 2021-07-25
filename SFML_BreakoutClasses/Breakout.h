#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <ctime>
#include <cmath>
#include "Ball.h"
#include "Brick.h"
#include "Paddle.h"
#include "ScoreText.h"
#include "ScorePopup.h"
#include "MainMenu.h"
class Breakout
{
private:
	enum GameStates { START, GAME, END };
	sf::Font font;
	int width = 1600, height = 1000;
	sf::RenderWindow window;
	MainMenu mainMenu;
	Paddle paddle = Paddle(200, 20, width / 2, height - 20, sf::Color::White, width, 8);
	Ball ball = Ball(30, width / 2, height / 2, 7, width, height);
	Score score;
	std::vector<Brick> bricks;
	std::vector<ScorePopup> popups;
	GameStates gameState;
	void setup();
	void getInput();
	void checkCollision();
	void updatePopups();
	void drawAll();
public:
	Breakout();
	void mainLoop();
};

