#include <SFML/Graphics.hpp>

#include <iostream>
#include <memory>

#include "SnakeGame.h"
#include "GameScreen.h"
#include "GameOverScreen.h"

using namespace nsSnake;

GameOverScreen::GameOverScreen(std::size_t score) : score_(score)
{
	font_.loadFromFile("Fonts/gameover.ttf");
	text_.setFont(font_);
	text_.setString("Your score: " + std::to_string(score) + "!""\n\nPress [SPACE] to retry""\n\nPress [ESC] to quit");
	
		sf::FloatRect textBounds = text_.getLocalBounds();
	text_.setOrigin(textBounds.left + textBounds.width / 2,
		textBounds.top + textBounds.height / 2);
	text_.setPosition(SnakeGame::Width / 2, SnakeGame::Height / 2);
}

void GameOverScreen::handleInput(sf::RenderWindow& window)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		 SnakeGame::Screen = std::make_shared<GameScreen>();
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		 window.close();
}

void GameOverScreen::update(sf::Time delta)
{

}

void GameOverScreen::render(sf::RenderWindow& window)
{
	window.draw(text_);
}