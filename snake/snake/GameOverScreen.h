#pragma once
#include <SFML/Graphics.hpp>

#include "Screen.h"

class GameOverScreen : public Screen
{
public:
	GameOverScreen(std::size_t score);

	void handleInput(sf::RenderWindow& window) override;
	void update(sf::Time delta) override;
	void render(sf::RenderWindow& window) override;

private:
	sf::Font font;
	sf::Font titlefont;
	sf::Text title;
	sf::Text text;
	sf::Sprite background_gameover;
	sf::Texture texture;
	sf::Music bgMusic2;

	unsigned HiScore;
};
