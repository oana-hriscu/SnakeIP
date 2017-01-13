#pragma once
#ifndef GAME_SCREEN_H
#define GAME_SCREEN_H

#include <SFML/Graphics.hpp>

#include "Screen.h"
#include "SnakeCharacter.h"
#include "Food.h"

namespace nsSnake
{
	class GameScreen : public Screen
		{
		public:
			GameScreen();
			
			void handleInput(sf::RenderWindow& window) override;
			void update(sf::Time delta) override;
			void render(sf::RenderWindow& window) override;
			
				void generateFood();
			
				private:
					SnakeCharacter snake_;
					std::vector<Food> food_;
					};
	}

#endif