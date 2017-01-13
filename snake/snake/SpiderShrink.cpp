#include "SpiderShrink.h"

SpiderShrink::SpiderShrink(sf::Vector2f position)
{
	spidertexture.loadFromFile("Image/spider.png");
	sf::Sprite sprite(spidertexture);
	sprite.setScale(0.18f, 0.18f);
	Spider = sprite;
	Spider.setPosition(position);
}

void SpiderShrink::render(sf::RenderWindow& window)
{
	Spider.setTexture(spidertexture);
	window.draw(Spider);
}

sf::FloatRect SpiderShrink::getBounds() const
{
	return Spider.getGlobalBounds();
}
