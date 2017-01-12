#pragma once
#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <vector>
#include <memory>

#include "Screen.h"

namespace nsSnake
{
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
		sf::RenderWindow window_;
		
		sf::Texture texture;
		sf::Sprite background_sprite;
		sf::Music bgMusic_;

		static const sf::Time TimePerFrame;
	};
}
#endif

