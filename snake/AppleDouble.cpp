#include "AppleDouble.h"

AppleDouble::AppleDouble(sf::Vector2f position)
{
	appletexture.loadFromFile("Image/apple.png");
	sf::Sprite sprite(appletexture);
	sprite.setScale(0.4f, 0.4f);
	Apple = sprite;
	Apple.setPosition(position);
}

void AppleDouble::render(sf::RenderWindow& window)
{
	Apple.setTexture(appletexture);
	window.draw(Apple);
}

sf::FloatRect AppleDouble::getBounds() const
{
	return Apple.getGlobalBounds();
}