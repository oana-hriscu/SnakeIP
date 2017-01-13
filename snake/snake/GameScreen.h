#pragma once
#include <SFML/Graphics.hpp>
#include "Screen.h"
#include "SnakeCharacter.h"
#include "Food.h"
#include <SFML/Audio.hpp>
#include "AppleDouble.h"
#include "SpiderShrink.h"

class GameScreen : public Screen
{
public:
	GameScreen();

	void handleInput(sf::RenderWindow& window) override;
	void update(sf::Time delta) override;
	void render(sf::RenderWindow& window) override;
	void generateFood();
	void generateApple();
	void generateSpider();

private:
	SnakeCharacter theSnake;
	std::vector<Food> food;
	std::vector<AppleDouble> apple;
	std::vector<SpiderShrink> spider;

	sf::Music bgMusic1;
};