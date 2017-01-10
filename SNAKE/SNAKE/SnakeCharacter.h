#pragma once
#ifndef SNAKE_H
#define SNAKE_H
#include <SFML/Graphics.hpp>

#include <vector>
#include "Node.h"

namespace Snake
{
	enum class Movement
	{
		Left_Arrow, Right_Arrow, Up_Arrow, Down_Arrow
	};

	class SnakeCharacter
	{
	public:
		SnakeCharacter();

		void handleInput();
		void update(sf::Time delta);
		void render(sf::RenderWindow& window);

	private:
		void move();

		void initNodes();

		sf::Vector2f position_;
		Movement direction_;

		std::vector<Node> nodes_;
		static const int InitialSize = 3;
	};
}

#endif