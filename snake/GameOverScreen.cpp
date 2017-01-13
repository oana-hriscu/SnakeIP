#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>

#include "SnakeGame.h"
#include "GameScreen.h"
#include "GameOverScreen.h"

GameOverScreen::GameOverScreen(std::size_t score) : HiScore(score)
{
	bgMusic2.openFromFile("Sound/Undertale_OST-sans.wav");
	bgMusic2.setLoop(true);
	bgMusic2.play();

	texture.loadFromFile("Image/gameover.png");
	sf::Sprite sprite(texture);
	background_gameover = sprite;

	font.loadFromFile("Fonts/gameover.ttf");
	text.setFont(font);
	text.setString("\n\n\n\n\n\n\n\nYour score: " + std::to_string(score) + "\n\nPress [SPACE] to retry""\n\nPress [ESC] to exit game");
	text.setCharacterSize(27);
	text.setFillColor(sf::Color::Black);

	titlefont.loadFromFile("Fonts/Ginger Snake.TTF");
	title.setFont(titlefont);
	title.setString("Game Over!");
	title.setFillColor(sf::Color::Black);
	title.setCharacterSize(70);
	title.setStyle(sf::Text::Bold);

	sf::FloatRect textBounds = text.getLocalBounds();
	text.setOrigin(textBounds.left + textBounds.width / 2, textBounds.top + textBounds.height / 2);
	text.setPosition(SnakeGame::Width / 2-35, SnakeGame::Height / 3 + 30);

	sf::FloatRect snakeTextBounds = title.getLocalBounds();
	title.setOrigin(snakeTextBounds.left + snakeTextBounds.width / 2, snakeTextBounds.top + snakeTextBounds.height / 2);
	title.setPosition(SnakeGame::Width / 2, SnakeGame::Height / 4 + 40);
}

void GameOverScreen::handleInput(sf::RenderWindow& window)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		bgMusic2.setLoop(false);
		SnakeGame::Screen = std::make_shared<GameScreen>();
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		window.close();
}

void GameOverScreen::update(sf::Time delta)
{

}

void GameOverScreen::render(sf::RenderWindow& window)
{
	window.draw(background_gameover);
	window.draw(title);
	window.draw(text);
}