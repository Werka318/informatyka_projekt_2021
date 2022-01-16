#pragma once
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include<cstdlib>

class Help
{
public:
	Help() {
		!hTexture.loadFromFile("help.png");
		hSprite.setTexture(hTexture);

	}
	void drawHelp(sf::RenderWindow& window) {
		window.draw(hSprite);
	}
private:
	sf::Texture hTexture;
	sf::Sprite hSprite;
};

