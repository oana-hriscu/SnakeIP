#include <SFML/Graphics.hpp>
#include <random>
#include <memory>
#include "GameScreen.h"
#include "GameOverScreen.h"
#include "SnakeGame.h"
#include "SnakeCharacter.h"

GameScreen::GameScreen() : theSnake()
{
	bgMusic1.openFromFile("Sound/Chocobo-Theme-8bit.wav");
	bgMusic1.setLoop(true);
	bgMusic1.play();
}

void GameScreen::handleInput(sf::RenderWindow& window)
{
	theSnake.handleInput();
}

void GameScreen::update(sf::Time delta)
{
	if (food.size() == 0)
		generateFood();

	theSnake.update(delta);
	theSnake.FoodCollisions(food);
	if (theSnake.hitSelf())
	{
		bgMusic1.setLoop(false);
		SnakeGame::Screen = std::make_shared<GameOverScreen>(theSnake.getSize());
	}
}

void GameScreen::render(sf::RenderWindow& window)
{
	theSnake.render(window);

	for (auto food : food)
		food.render(window);
}

void GameScreen::generateFood()
{
	static std::default_random_engine engine;
	engine.seed(time(NULL));
	static std::uniform_int_distribution<int> xDistribution(0, SnakeGame::Width - Node::Width);
	static std::uniform_int_distribution<int> yDistribution(0, SnakeGame::Height - Node::Height);

	food.push_back(Food(sf::Vector2f(xDistribution(engine), yDistribution(engine))));
}