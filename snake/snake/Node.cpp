#include "Node.h"
#include <SFML/Graphics.hpp>

const float Node::Width = 12.f;
const float Node::Height = 12.f;

Node::Node(sf::Vector2f position) : thePosition(position)
{
	/*shape.setPosition(thePosition);
	shape.setFillColor(sf::Color::Green);
	shape.setRadius(8.f);
	shape.setOutlineColor(sf::Color::White);
	shape.setOutlineThickness(-1.f);*/

	tex.loadFromFile("Image/snakeskin.png");
	shape.setTexture(tex);
	shape.setPosition(position);
	shape.setScale(sf::Vector2f(0.35f, 0.35f));

}

void Node::setPos(sf::Vector2f position)
{
	thePosition = position;
	shape.setPosition(thePosition);
}

void Node::setPos(float x, float y)
{
	thePosition.x = x;
	thePosition.y = y;
	shape.setPosition(thePosition);
}

void Node::move(float xOffset, float yOffset)
{
	thePosition.x += xOffset;
	thePosition.y += yOffset;
	shape.setPosition(thePosition);
}

sf::FloatRect Node::getBounds() const
{
	return shape.getGlobalBounds();
}

sf::Vector2f Node::getPos() const
{
	return thePosition;
}

void Node::render(sf::RenderWindow& window)
{
	shape.setTexture(tex);
	window.draw(shape);
}
