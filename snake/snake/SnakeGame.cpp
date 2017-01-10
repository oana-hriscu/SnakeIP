#include "SnakeGame.h"
#include <SFML/Graphics.hpp>

using namespace Snake;

const sf::Time SnakeGame::TimePerFrame = sf::seconds(1.f / 60.f);

SnakeGame::SnakeGame(): window_(sf::VideoMode(SnakeGame::Width, SnakeGame::Height), "Snake")
{
	sf::Texture texture;
	texture.loadFromFile("Image/bck.png");
	sf::Sprite sprite(texture);
	sf::Event event;

	while (window_.isOpen()) {
		while (window_.pollEvent(event)) {
			if (event.type == sf::Event::EventType::Closed)
				window_.close();
		}

		window_.clear();
		window_.draw(sprite);
		window_.display();
	}
}

void SnakeGame::handleInput()
{
	sf::Event event;

	while (window_.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window_.close();
	}
}

void SnakeGame::update(sf::Time delta)
{

}

void SnakeGame::render()
{
	window_.clear();
	window_.display();
}

void SnakeGame::run()
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

