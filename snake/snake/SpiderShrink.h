#pragma once

#include <SFML/Graphics.hpp>
#include "SnakeGame.h"

class SpiderShrink
{
public:
	SpiderShrink(sf::Vector2f position = sf::Vector2f(0, 0));

	void render(sf::RenderWindow& window);
	sf::FloatRect getBounds() const;

private:
	sf::Texture spidertexture;
	sf::Sprite Spider;
};