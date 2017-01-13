#include <SFML/Graphics.hpp>
#include <memory>
#include "GameScreen.h"
#include "SnakeMenu.h"
#include "InstructionScreen.h"
#include "SnakeGame.h"

SnakeMenu::SnakeMenu()
{
	texture.loadFromFile("Image/menu2.png");
	sf::Sprite sprite(texture);
	background_snakemenu = sprite;

	font.loadFromFile("Fonts/Ginger Snake.ttf");
	label.setFont(font);
	label.setString("\n\n\n\n\n\n\n\nPress [SPACE] to start game""\nPress [I] for instructions""\nPress [ESC] to exit game");
	label.setFillColor(sf::Color::Black);
	label.setStyle(sf::Text::Bold);

	title.setFont(font);
	title.setString("Snake!");
	title.setFillColor(sf::Color::Black);
	title.setCharacterSize(80);
	title.setStyle(sf::Text::Bold);

	sf::FloatRect textBounds = label.getLocalBounds();
	label.setOrigin(textBounds.left + textBounds.width / 2, textBounds.top + textBounds.height / 2);
	label.setPosition(SnakeGame::Width / 2, SnakeGame::Height / 3 + 50);

	sf::FloatRect snakeTextBounds = title.getLocalBounds();
	title.setOrigin(snakeTextBounds.left + snakeTextBounds.width / 2, snakeTextBounds.top + snakeTextBounds.height / 2);
	title.setPosition(SnakeGame::Width / 2 + 15, SnakeGame::Height / 2 - 30);

}

void SnakeMenu::handleInput(sf::RenderWindow& window)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		SnakeGame::Screen = std::make_shared<GameScreen>();
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		window.close();
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::I))
		SnakeGame::Screen = std::make_shared<InstructionScreen>();
}

void SnakeMenu::update(sf::Time delta)
{
}

void SnakeMenu::render(sf::RenderWindow& window)
{
	window.draw(background_snakemenu);
	window.draw(label);
	window.draw(title);
}