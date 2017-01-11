#include "Food.h"

using namespace Snake;

//const float Food::SemiDiameter = 5.f;
//const float Food::Width = 10.f;
//const float Food::Height = 10.f;


Food::Food(sf::Vector2f position)
{
	foodtexture.loadFromFile("Image/bug.png");
	sf::Sprite sprite(foodtexture);
	sprite.setScale(10.f, 10.f);
	LadyBug = sprite;
	LadyBug.setPosition(position);
	/*shape_.setPosition(position);
	shape_.setRadius(Food::SemiDiameter);
	shape_.setFillColor(sf::Color::Red);*/
}

void Food::render(sf::RenderWindow& window)
{
	window.draw(LadyBug);
}

sf::FloatRect Food::getBounds() const
{
	return LadyBug.getGlobalBounds();
}


