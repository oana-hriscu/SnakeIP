#include <SFML/Graphics.hpp>
#include <memory>

#include "SnakeGame.h"
#include "GameScreen.h" 

using namespace nsSnake;

const sf::Time SnakeGame::TimePerFrame = sf::seconds(1.f / 10.f);
std::shared_ptr<Screen> SnakeGame::Screen = std::make_shared<GameScreen>();

SnakeGame::SnakeGame()
	: window_(sf::VideoMode(SnakeGame::Width, SnakeGame::Height), "Snake")
{
	texture.loadFromFile("Image/bck.png");
	sf::Sprite sprite(texture);
	background_sprite = sprite;	

	bgMusic_.openFromFile("Sound/Chocobo-Theme-8bit.wav");
	bgMusic_.setLoop(true);
	bgMusic_.play();
}

void SnakeGame::handleInput()
{
	sf::Event event;

	while (window_.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window_.close();
	}
	SnakeGame::Screen->handleInput(window_);
}

void SnakeGame::update(sf::Time delta)
{
	SnakeGame::Screen->update(delta);
}

void SnakeGame::render()
{
	window_.clear();
	window_.draw(background_sprite);
	SnakeGame::Screen->render(window_);
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