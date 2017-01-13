#include <SFML/Graphics.hpp>
#include <random>
#include <memory>
#include "GameScreen.h"
#include "GameOverScreen.h"
#include "SnakeGame.h"
#include "SnakeCharacter.h"
#include "InstructionScreen.h"



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
	if (apple.size() == 0 && theSnake.getSize() % 7 == 0)
		generateApple();
	if (spider.size() == 0 && theSnake.getSize() % 10 == 0 && apple.size() == 0)
		generateSpider();
	
	theSnake.update(delta);
	theSnake.FoodCollisions(food);
	theSnake.AppleCollisions(apple);
	theSnake.SpiderCollisions(spider);

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
	for (auto apple : apple)
		apple.render(window);
	for (auto spider : spider)
		spider.render(window);
}

void GameScreen::generateFood()
{
	static std::default_random_engine engine;
	engine.seed(time(NULL));
	static std::uniform_int_distribution<int> xDistribution(0, SnakeGame::Width - Node::Width);
	static std::uniform_int_distribution<int> yDistribution(0, SnakeGame::Height - Node::Height);

	food.push_back(Food(sf::Vector2f(xDistribution(engine), yDistribution(engine))));
}

void GameScreen::generateApple()
{
	static std::default_random_engine engine;
	engine.seed(time(NULL) + 130);
	static std::uniform_int_distribution<int> xDistribution(0, SnakeGame::Width - Node::Width);
	static std::uniform_int_distribution<int> yDistribution(0, SnakeGame::Height - Node::Height);

	apple.push_back(AppleDouble(sf::Vector2f(xDistribution(engine), yDistribution(engine))));
}

void GameScreen::generateSpider()
{
	static std::default_random_engine engine;
	engine.seed(time(NULL) + 200);
	static std::uniform_int_distribution<int> xDistribution(0, SnakeGame::Width - Node::Width);
	static std::uniform_int_distribution<int> yDistribution(0, SnakeGame::Height - Node::Height);

	spider.push_back(SpiderShrink(sf::Vector2f(xDistribution(engine), yDistribution(engine))));
}
