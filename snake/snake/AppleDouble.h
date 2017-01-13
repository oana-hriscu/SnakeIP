#pragma once

#include <SFML/Graphics.hpp>
#include "SnakeGame.h"

class AppleDouble
{
public:
	AppleDouble(sf::Vector2f position = sf::Vector2f(0, 0));

	void render(sf::RenderWindow& window);
	sf::FloatRect getBounds() const;

private:
	sf::Texture appletexture;
	sf::Sprite Apple;
};


