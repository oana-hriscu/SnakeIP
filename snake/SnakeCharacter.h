#pragma once
#ifndef SNAKE_H
#define SNAKE_H
#include <SFML/Graphics.hpp>

#include <vector>
#include "Node.h"
#include "Food.h"

namespace nsSnake
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
		void FoodCollisions(std::vector<Food>& foods);

		bool hitSelf() const;
		unsigned getSize() const;

	private:
		void move();
		void grow();
		void BorderCollision();
		void SnakeCollision();
		void initNodes();
		bool hitSelf_;

		sf::Sprite Head; 
		sf::Texture HeadTexture;
		sf::Sprite Tail; 
		sf::Texture TailTexture;

		bool JustMadeATurn;

		sf::Vector2f position_;
		Movement direction_;

		std::vector<Node> nodes_;
		static const int InitialSize;
	};
}

#endif
