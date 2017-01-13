#pragma once
#include <SFML/Graphics.hpp>
#include "Screen.h"
#include "SnakeCharacter.h"
#include "Food.h"
#include <SFML/Audio.hpp>

class GameScreen : public Screen
{
public:
	GameScreen();

	void handleInput(sf::RenderWindow& window) override;
	void update(sf::Time delta) override;
	void render(sf::RenderWindow& window) override;
	void generateFood();

private:
	SnakeCharacter theSnake;
	std::vector<Food> food;
	sf::Music bgMusic1;
};