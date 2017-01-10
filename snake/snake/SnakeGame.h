#pragma once
#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>

namespace Snake
{
	class SnakeGame
	{
	public:
		SnakeGame();

		void run();

		void handleInput();
		void update(sf::Time delta);
		void render();

		static const int Width = 640;
		static const int Height = 480;

	private:
		sf::RenderWindow window_;

		static const sf::Time TimePerFrame;
	};
}
#endif

