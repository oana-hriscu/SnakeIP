#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>

#include "SnakeCharacter.h"
#include "SnakeGame.h"
#include "Food.h"
#include "Node.h"
#include "GameOverScreen.h"

const int SnakeCharacter::InitialSize = 5;

SnakeCharacter::SnakeCharacter() : dir(Movement::Up_Arrow), SnakeHitsSelf(false)
{	
	initNodes();

	EatBuffer.loadFromFile("Sound/Cartoon_Boink_Sound_Effect.wav");
	EatTune.setBuffer(EatBuffer);
	EatTune.setVolume(30);

	AppleBuffer.loadFromFile("Sound/Heart.wav");
	AppleTune.setBuffer(AppleBuffer);
	AppleTune.setVolume(15);

	SpiderBuffer.loadFromFile("Sound/Spider-Notice.wav");
	SpiderTune.setBuffer(SpiderBuffer);
	SpiderTune.setVolume(30);
}

void SnakeCharacter::initNodes()
{
	for (int i = 0; i < SnakeCharacter::InitialSize; ++i)
	{
		nodes.push_back(Node(sf::Vector2f(SnakeGame::Width / 2 - Node::Width / 2, SnakeGame::Height / 2 - (Node::Height / 2) + (Node::Height * i))));
	}
}

void SnakeCharacter::handleInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && dir != Movement::Down_Arrow)
		dir = Movement::Up_Arrow;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && dir != Movement::Up_Arrow)
		dir = Movement::Down_Arrow;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && dir != Movement::Right_Arrow)
		dir = Movement::Left_Arrow;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && dir != Movement::Left_Arrow)
		dir = Movement::Right_Arrow;
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
		if (it->getBounds().intersects(nodes[0].getBounds()))
			toRemove = it;
	}

	if (toRemove != foods.end())
	{
		EatTune.play();
		grow();
		foods.erase(toRemove);
	}
}
void SnakeCharacter::AppleCollisions(std::vector<AppleDouble> & apple)
{
	decltype(apple.begin()) toRemove = apple.end();

	for (auto& it = apple.begin(); it != apple.end(); ++it)
	{
		if (it->getBounds().intersects(nodes[0].getBounds()))
			toRemove = it;
	}

	if (toRemove != apple.end())
	{
		AppleTune.play();
		grow();
		grow();
		apple.erase(toRemove);
	}
}

void SnakeCharacter::SpiderCollisions(std::vector<SpiderShrink> & spider)
{
	decltype(spider.begin()) toRemove = spider.end();

	for (auto& it = spider.begin(); it != spider.end(); ++it)
	{
		if (it->getBounds().intersects(nodes[0].getBounds()))
			toRemove = it;
	}

	if (toRemove != spider.end())
	{
		SpiderTune.play();
		shrink();
		spider.erase(toRemove);
	}
}

void SnakeCharacter::grow()
{
	switch (dir)
	{
	case Movement::Up_Arrow:
		nodes.push_back(Node(sf::Vector2f(nodes[nodes.size() - 1].getPos().x,
			nodes[nodes.size() - 1].getPos().y + Node::Height)));
		break;
	case Movement::Down_Arrow:
		nodes.push_back(Node(sf::Vector2f(nodes[nodes.size() - 1].getPos().x,
			nodes[nodes.size() - 1].getPos().y - Node::Height)));
		break;
	case Movement::Left_Arrow:
		nodes.push_back(Node(sf::Vector2f(nodes[nodes.size() - 1].getPos().x + Node::Width,
			nodes[nodes.size() - 1].getPos().y)));
		break;
	case Movement::Right_Arrow:
		nodes.push_back(Node(sf::Vector2f(nodes[nodes.size() - 1].getPos().x - Node::Width,
			nodes[nodes.size() - 1].getPos().y)));
		break;
	}
}

void SnakeCharacter::shrink()
{
	switch (dir)
	{
	case Movement::Up_Arrow:
		nodes.pop_back();
		nodes.pop_back();
		nodes.pop_back();

		break;
	case Movement::Down_Arrow:
		nodes.pop_back();
		nodes.pop_back();
		nodes.pop_back();
		break;
	case Movement::Left_Arrow:
		nodes.pop_back();
		nodes.pop_back();
		nodes.pop_back();
		break;
	case Movement::Right_Arrow:
		nodes.pop_back();
		nodes.pop_back();
		nodes.pop_back();
		break;
	}
}

unsigned SnakeCharacter::getSize() const
{
	return nodes.size();

}

bool SnakeCharacter::hitSelf() const
{
	return SnakeHitsSelf;
}

void SnakeCharacter::SnakeCollision()
{
	Node& StartNode = nodes[0];

	for (decltype(nodes.size()) i = 3; i < nodes.size(); ++i)
	{
		if (StartNode.getBounds().intersects(nodes[i].getBounds()))
		{
			SnakeHitsSelf = true;

		}
	}
}

void SnakeCharacter::BorderCollision()
{
	Node& StartNode = nodes[0];

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
	for (decltype(nodes.size()) i = nodes.size() - 1; i > 0; --i)
	{
		nodes[i].setPos(nodes.at(i - 1).getPos());
	}
	switch (dir)
	{
	case Movement::Up_Arrow:
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
			nodes[0].move(0, -(Speed * Node::Height));
		else nodes[0].move(0, -Node::Height);
		break;
	case Movement::Down_Arrow:
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
			nodes[0].move(0, Speed * Node::Height);
		else nodes[0].move(0, Node::Height);
		break;
	case Movement::Left_Arrow:
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
			nodes[0].move(-(Speed * Node::Width), 0);
		else nodes[0].move(-Node::Width, 0);
		break;
	case Movement::Right_Arrow:
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
			nodes[0].move(Speed * Node::Width, 0);
		else nodes[0].move(Node::Width, 0);
		break;
	}
}

void SnakeCharacter::render(sf::RenderWindow& window)
{
	for (auto node : nodes)
		node.render(window);
}
