#include <SFML/Graphics.hpp>
#include "SnakeCharacter.h"
#include <iostream>
#include "SnakeGame.h"

using namespace Snake;

SnakeCharacter::SnakeCharacter() : direction_(Movement::Up_Arrow)
{
	initNodes();
}

void SnakeCharacter::initNodes()
{
	for (int i = 0; i < SnakeCharacter::InitialSize; ++i)
	{
		nodes_.push_back(Node(sf::Vector2f(SnakeGame::Width / 2 - Node::Width / 2, SnakeGame::Height / 2 - (Node::Height / 2) + (Node::Height * i))));
	}
}

void SnakeCharacter::handleInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		direction_ = Movement::Up_Arrow;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		direction_ = Movement::Down_Arrow;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		direction_ = Movement::Left_Arrow;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		direction_ = Movement::Right_Arrow;
}

void SnakeCharacter::update(sf::Time delta)
{
	move();
	BorderCollision();
}

void SnakeCharacter::BorderCollision()
{
	Node& StartNode = nodes_[0];

	if (StartNode.getPos().x <= 0)
		StartNode.setPos(SnakeGame::Width, StartNode.getPos().y);
	else if (StartNode.getPos().x >= SnakeGame::Width)
		StartNode.setPos(0, StartNode.getPos().y);
	else if (StartNode.getPos().y <= 0)
		StartNode.setPos(StartNode.getPos().x, SnakeGame::Height);
	else if (StartNode.getPos().y >= SnakeGame::Height)
		StartNode.setPos(StartNode.getPos().x, 0);
}

void SnakeCharacter::move()
{
	for (decltype(nodes_.size()) i = nodes_.size() - 1; i > 0; --i)
	{
		nodes_[i].setPos(nodes_.at(i - 1).getPos());
	}

	switch (direction_)
	{
	case Movement::Up_Arrow:
		nodes_[0].move(0, -Node::Height);
		break;
	case Movement::Down_Arrow:
		nodes_[0].move(0, Node::Height);
		break;
	case Movement::Left_Arrow:
		nodes_[0].move(-Node::Width, 0);
		break;
	case Movement::Right_Arrow:
		nodes_[0].move(Node::Width, 0);
		break;
	}
}

void SnakeCharacter::render(sf::RenderWindow& window)
{
	for (auto node : nodes_)
		node.render(window);
}
