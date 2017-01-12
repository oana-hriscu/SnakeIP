#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>

#include "SnakeCharacter.h"
#include "SnakeGame.h"
#include "Food.h"
#include "Node.h"
#include "GameOverScreen.h"

using namespace nsSnake;

const int SnakeCharacter::InitialSize = 5;

SnakeCharacter::SnakeCharacter() : direction_(Movement::Up_Arrow), hitSelf_(false)
{
	initNodes();
	HeadTexture.loadFromFile("Image/snake.png");
	Head.setTexture(HeadTexture);
	Head.setOrigin(48, 23);
	Head.setScale(sf::Vector2f(0.2f, 0.2f));
	Head.setPosition(0, 0);
	JustMadeATurn = true;
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
	SnakeCollision();
}

void SnakeCharacter::FoodCollisions(std::vector<Food>& foods)
{
	decltype(foods.begin()) toRemove = foods.end();
	
		for (auto& it = foods.begin(); it != foods.end(); ++it)
		{
		if (it->getBounds().intersects(nodes_[0].getBounds()))
			toRemove = it;
		}
	
		if (toRemove != foods.end())
		{
		grow();
		foods.erase(toRemove);
		}
}

void SnakeCharacter::grow()
{
	switch (direction_)
		{
		case Movement::Up_Arrow:
			nodes_.push_back(Node(sf::Vector2f(nodes_[nodes_.size() - 1].getPos().x,
				nodes_[nodes_.size() - 1].getPos().y + Node::Height)));
			break;
			case Movement::Down_Arrow:
				nodes_.push_back(Node(sf::Vector2f(nodes_[nodes_.size() - 1].getPos().x,
					nodes_[nodes_.size() - 1].getPos().y - Node::Height)));
				break;
				case Movement::Left_Arrow:
					nodes_.push_back(Node(sf::Vector2f(nodes_[nodes_.size() - 1].getPos().x + Node::Width,
						nodes_[nodes_.size() - 1].getPos().y)));
					break;
					case Movement::Right_Arrow:
						nodes_.push_back(Node(sf::Vector2f(nodes_[nodes_.size() - 1].getPos().x - Node::Width,
							nodes_[nodes_.size() - 1].getPos().y)));
						break;
		}
}

unsigned SnakeCharacter::getSize() const
{
	return nodes_.size();
}

bool SnakeCharacter::hitSelf() const
{
	return hitSelf_;
}

void SnakeCharacter::SnakeCollision()
{
	Node& StartNode = nodes_[0];

	for (decltype(nodes_.size()) i = 1; i < nodes_.size(); ++i)
	{
		if (StartNode.getBounds().intersects(nodes_[i].getBounds()))
		{
			hitSelf_ = true;
			
		}
	}
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


	if (direction_ != Movement::Up_Arrow)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			if (direction_ != Movement::Down_Arrow)
			{
				direction_ = Movement::Up_Arrow; Head.setRotation(-90);
				JustMadeATurn = true;
			}
		}
	}

	if (direction_ != Movement::Down_Arrow)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			if (direction_ != Movement::Up_Arrow)
			{
				direction_ = Movement::Down_Arrow;
				Head.setRotation(90);
				JustMadeATurn = true;
			}
		}
	}

	if (direction_ != Movement::Left_Arrow)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			if (direction_ != Movement::Right_Arrow)
			{
				direction_ = Movement::Left_Arrow;
				Head.setRotation(180);
				JustMadeATurn = true;
			}
		}
	}

	if (direction_ != Movement::Right_Arrow)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			if (direction_ != Movement::Left_Arrow)
			{
				direction_ = Movement::Right_Arrow;
				Head.setRotation(0);
				JustMadeATurn = true;
			}
		}
	}
}

void SnakeCharacter::render(sf::RenderWindow& window)
{
	for (auto node : nodes_)
		node.render(window);
}
