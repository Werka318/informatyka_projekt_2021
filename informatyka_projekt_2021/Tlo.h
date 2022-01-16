#pragma once
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include<cstdlib>

class Tlo
{
public:
	Tlo() {
		!tTexture.loadFromFile("tlo.png");
		tSprite.setTexture(tTexture);

	}
	void drawTlo(sf::RenderWindow& window) {
		window.draw(tSprite);
	}
private:
	sf::Texture tTexture;
	sf::Sprite tSprite;
};
