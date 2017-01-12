#pragma once
#ifndef FRUIT_H
#define FRUIT_H

#include <SFML/Graphics.hpp>
#include "SnakeGame.h"

namespace nsSnake
{
	class Food
	{
	public:
		Food(sf::Vector2f position = sf::Vector2f(0, 0));

		void render(sf::RenderWindow& window);
		sf::FloatRect getBounds() const;
		//static const float Width;
		//static const float Height;

	private:
		//static const float SemiDiameter;
		sf::Texture foodtexture;
		sf::Sprite LadyBug;



	};

}

#endif