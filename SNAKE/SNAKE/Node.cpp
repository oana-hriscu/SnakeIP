#include "Node.h"
#include <SFML/Graphics.hpp>

using namespace Snake;

const float Node::Width = 10.f;
const float Node::Height = 10.f;

Node::Node(sf::Vector2f position)
: position_(position)
{
	shape_.setPosition(position_);
	shape_.setFillColor(sf::Color::Blue);
	shape_.setSize(sf::Vector2f(Node::Width, Node::Height));
	shape_.setOutlineColor(sf::Color::White);
	shape_.setOutlineThickness(-1.f);
}

void Node::setPos(sf::Vector2f position)
{
	position_ = position;
}

void Node::setPos(float x, float y)
{
	position_.x = x;
	position_.y = y;
	}

void Node::move(float xOffset, float yOffset)
{
	position_.x += xOffset;
	position_.y += yOffset;
}

sf::Vector2f Node::getPos() const
{
	return position_;
}

void Node::render(sf::RenderWindow& window)
{
	shape_.setPosition(position_);
	window.draw(shape_);
}