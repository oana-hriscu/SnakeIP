#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <vector>
#include <memory>

#include "Screen.h"

class SnakeGame
{
public:
	SnakeGame();

	void GameLoop();

	void handleInput();
	void update(sf::Time delta);
	void render();

	static const int Width = 640;
	static const int Height = 480;

	static std::shared_ptr<Screen> Screen;

private:
	sf::RenderWindow window;

	sf::Texture texture;
	sf::Sprite background_sprite;
	//sf::Music bgMusic;

	static const sf::Time TimePerFrame;
};
