#include <SFML/Graphics.hpp>
#include <memory>

#include "SnakeGame.h"
#include "SnakeMenu.h" 

const sf::Time SnakeGame::TimePerFrame = sf::seconds(1.f / 10.f);
std::shared_ptr<Screen> SnakeGame::Screen = std::make_shared<SnakeMenu>();


SnakeGame::SnakeGame(): window(sf::VideoMode(SnakeGame::Width, SnakeGame::Height), "Snake")
{
	texture.loadFromFile("Image/bck.png");
	sf::Sprite sprite(texture);
	background_sprite = sprite;

	/*bgMusic.openFromFile("Sound/Chocobo-Theme-8bit.wav");
	bgMusic.setLoop(true);
	bgMusic.play();*/
	
}

void SnakeGame::handleInput()
{
	sf::Event event;

	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();
	}
	SnakeGame::Screen->handleInput(window);
}

void SnakeGame::update(sf::Time delta)
{
	SnakeGame::Screen->update(delta);
}

void SnakeGame::render()
{
	window.clear();
	window.draw(background_sprite);
	SnakeGame::Screen->render(window);
	window.display();
}

void SnakeGame::GameLoop()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	while (window.isOpen())
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