#include "Food.h"

using namespace nsSnake;

//const float Food::SemiDiameter = 5.f;
//const float Food::Width = 10.f;
//const float Food::Height = 10.f;


Food::Food(sf::Vector2f position)
{
	foodtexture.loadFromFile("Image/bug.png");
	sf::Sprite sprite(foodtexture);
	sprite.setScale(0.1f, 0.1f);
	LadyBug = sprite;
	LadyBug.setPosition(position);
	/*shape_.setPosition(position);
	shape_.setRadius(Food::SemiDiameter);
	shape_.setFillColor(sf::Color::Red);*/
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