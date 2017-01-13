#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Node.h"
#include "Food.h"

enum class Movement
{
	Left_Arrow, Right_Arrow, Up_Arrow, Down_Arrow
};

class SnakeCharacter
{
public:
	SnakeCharacter();

	void handleInput();
	void update(sf::Time delta);
	void render(sf::RenderWindow& window);
	void FoodCollisions(std::vector<Food>& foods);

	bool hitSelf() const;
	unsigned getSize() const;

private:
	void move();
	void grow();
	void BorderCollision();
	void SnakeCollision();
	void initNodes();
	bool SnakeHitsSelf;

	//sf::Vector2f postn;
	Movement dir;

	sf::SoundBuffer EatBuffer;
	sf::Sound EatTune;

	std::vector<Node> nodes;
	static const int InitialSize;
};