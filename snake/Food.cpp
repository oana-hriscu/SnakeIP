#include <SFML/Graphics.hpp>
#include "Food.h"

Food::Food(sf::Vector2f position) 
{
	foodtexture.loadFromFile("Image/bug.png");
	sf::Sprite sprite(foodtexture);
	sprite.setScale(0.08f, 0.08f);
	LadyBug = sprite;
	LadyBug.setPosition(position);
}

void Food::render(sf::RenderWindow& window)
{
	LadyBug.setTexture(foodtexture);
	window.draw(LadyBug);
}

sf::FloatRect Food::getBounds() const
{
	return LadyBug.getGlobalBounds();
}


