#pragma once
#include <SFML/Graphics.hpp>

class Node
{
public:
	Node(sf::Vector2f position = sf::Vector2f(0, 0));

	void setPos(sf::Vector2f position);
	void setPos(float x, float y);
	void move(float xOffset, float yOffset);
	void render(sf::RenderWindow& window);

	sf::Vector2f getPos() const;
	sf::FloatRect getBounds() const;

	static const float Width;
	static const float Height;

private:
	sf::Sprite shape;
	sf::Texture tex;
	sf::Vector2f thePosition;
};

