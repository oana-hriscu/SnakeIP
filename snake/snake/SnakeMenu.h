#include <SFML/Graphics.hpp>
#include "Screen.h"
#include <SFML/Audio.hpp>

class SnakeMenu : public Screen
{
public:
	SnakeMenu();

	void handleInput(sf::RenderWindow& window) override;
	void update(sf::Time delta) override;
	void render(sf::RenderWindow& window) override;

private:
	sf::Font font;
	sf::Text title;
	sf::Text label;
	sf::Sprite background_snakemenu;
	sf::Texture texture;
	sf::Music bgMusic;
};