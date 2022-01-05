#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class Player
{
public:
	Player() {
		//domyœlny
	}
	Player(std::string imgDirectory) {
		if (!pTexture.loadFromFile(imgDirectory)) {
			std::cerr << "Spirte \n";
		}
		pSprite.setTexture(pTexture);
	}
	void drawPlayer(sf::RenderWindow& window) {
		window.draw(pSprite);
	}

	void movePlayer(char direction, float moveSpeed) {
		if (direction == 'w') {
			pSprite.move(0, -moveSpeed);
		}
		else if(direction == 's') {
			pSprite.move(0, moveSpeed);
		}
		else if (direction == 'd') {
			pSprite.move(-moveSpeed, 0);
		}
		else if (direction == 'a') {
			pSprite.move(-moveSpeed, 0);
		}
}
private:
	sf::Texture pTexture;
	sf::Sprite pSprite;

};

