#include "Node.h"
#include <SFML/Graphics.hpp>

using namespace nsSnake;

const float Node::Width = 10.f;
const float Node::Height = 10.f;

Node::Node(sf::Vector2f position)
	: position_(position)
{
	/*shape_.setPosition(position_);
	shape_.setFillColor(sf::Color::Blue);
	shape_.setSize(sf::Vector2f(Node::Width, Node::Height));
	shape_.setOutlineColor(sf::Color::White);
	shape_.setOutlineThickness(-1.f);*/

	tex.loadFromFile("Image/snake.png");
	shape_.setTexture(tex);
	shape_.setPosition(position_);
	shape_.setScale(sf::Vector2f(0.3f, 0.3f));
}

void Node::setPos(sf::Vector2f position)
{
	position_ = position;
	shape_.setPosition(position_);
}

void Node::setPos(float x, float y)
{
	position_.x = x;
	position_.y = y;
	shape_.setPosition(position_);
}

void Node::move(float xOffset, float yOffset)
{
	position_.x += xOffset;
	position_.y += yOffset;
	shape_.setPosition(position_);
}

sf::FloatRect Node::getBounds() const
{
	return shape_.getGlobalBounds();
}

sf::Vector2f Node::getPos() const
{
	return position_;
}

void Node::render(sf::RenderWindow& window)
{
	shape_.setTexture(tex);
	window.draw(shape_);
}
