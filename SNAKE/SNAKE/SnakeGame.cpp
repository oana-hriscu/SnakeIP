#include <SFML/Graphics.hpp>
#include "SnakeGame.h"
using namespace Snake;

const sf::Time SnakeGame::TimePerFrame = sf::seconds(1.f / 10.f);

SnakeGame::SnakeGame()
	: window_(sf::VideoMode(SnakeGame::Width, SnakeGame::Height), "Snake"), theSnake()
{

	texture.loadFromFile("Image/bck.png");
	sf::Sprite sprite(texture);
	background_sprite = sprite;
	
}

void SnakeGame::handleInput()
{
	sf::Event event;

	while (window_.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window_.close();
	}
	theSnake.handleInput();
}
void SnakeGame::update(sf::Time delta)
{
	theSnake.update(delta);
}

void SnakeGame::render()
{
	window_.clear();
	window_.draw(background_sprite);
	theSnake.render(window_);
	window_.display();
}

void SnakeGame::GameLoop()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	while (window_.isOpen())
	{
		sf::Time delta = clock.restart();
		timeSinceLastUpdate += delta;

		while (timeSinceLastUpdate > SnakeGame::TimePerFrame)
		{
			timeSinceLastUpdate -= TimePerFrame;
			handleInput();
			update(TimePerFrame);
		}

		render();
	}
}