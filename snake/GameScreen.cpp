#include <SFML/Graphics.hpp>
#include <random>
#include <memory>

#include "GameScreen.h"
#include "GameOverScreen.h"
#include "SnakeGame.h"

using namespace nsSnake;

GameScreen::GameScreen() : snake_()
{

}

void GameScreen::handleInput(sf::RenderWindow& window)
{
	snake_.handleInput();
}

void GameScreen::update(sf::Time delta)
{
	if (food_.size() == 0)
		 generateFood();
	
		snake_.update(delta);
	snake_.FoodCollisions(food_);
	if (snake_.hitSelf())
		 SnakeGame::Screen = std::make_shared<GameOverScreen>(snake_.getSize());
}

void GameScreen::render(sf::RenderWindow& window)
{
	snake_.render(window);
	
		for (auto food : food_)
		 food.render(window);
}

void GameScreen::generateFood()
{
	static std::default_random_engine engine;
	engine.seed(time(NULL));
	static std::uniform_int_distribution<int> xDistribution(0, SnakeGame::Width - Node::Width);
	static std::uniform_int_distribution<int> yDistribution(0, SnakeGame::Height - Node::Height);
	
	food_.push_back(Food(sf::Vector2f(xDistribution(engine), yDistribution(engine))));
}