#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Node.h"
#include "Food.h"
#include "AppleDouble.h"
#include "SpiderShrink.h"
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
	void AppleCollisions(std::vector<AppleDouble> & apple);
	void SpiderCollisions(std::vector<SpiderShrink> & spider);

	bool hitSelf() const;
	unsigned getSize() const;

private:
	void move();
	void grow();
	void shrink();
	void BorderCollision();
	void SnakeCollision();
	void initNodes();
	bool SnakeHitsSelf;
	float Speed = 2;


	//sf::Vector2f postn;
	Movement dir;

	sf::SoundBuffer EatBuffer;
	sf::Sound EatTune;
	sf::SoundBuffer SpiderBuffer;
	sf::Sound SpiderTune;
	sf::SoundBuffer AppleBuffer;
	sf::Sound AppleTune;

	std::vector<Node> nodes;
	static const int InitialSize;
};