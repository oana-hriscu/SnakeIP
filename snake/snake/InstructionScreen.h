#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Screen.h"

class InstructionScreen : public Screen
{
public:
	InstructionScreen();

	void handleInput(sf::RenderWindow& window) override;
	void update(sf::Time delta) override;
	void render(sf::RenderWindow& window) override;

private:
	sf::Sprite background_instruction;
	sf::Texture texture;
	//sf::Music bgMusic;
};
