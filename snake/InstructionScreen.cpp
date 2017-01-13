#include "InstructionScreen.h"
#include <memory>
#include "GameScreen.h"
#include "SnakeMenu.h"
#include "SnakeGame.h"

InstructionScreen::InstructionScreen()
{
	texture.loadFromFile("Image/instructions.png");
	sf::Sprite sprite(texture);
	background_instruction = sprite;

	//bgMusic.openFromFile("Sound/Undertale_OST-_048_-_Alphys.wav");
	//bgMusic.setLoop(true);
	//bgMusic.play();

}

void InstructionScreen::handleInput(sf::RenderWindow& window)
{

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		//bgMusic.setLoop(false);
		SnakeGame::Screen = std::make_shared<SnakeMenu>();
	}
}

void InstructionScreen::update(sf::Time delta)
{
}

void InstructionScreen::render(sf::RenderWindow& window)
{
	window.draw(background_instruction);
}
