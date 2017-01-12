#pragma once
#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include "SnakeCharacter.h"

namespace Snake
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

	private:
		sf::RenderWindow window_;
		SnakeCharacter theSnake;

		sf::Texture texture;
		sf::Sprite background_sprite;
		
		static const sf::Time TimePerFrame;
	};
}

#endif