#pragma once
#include "Pilka.h"
#include "Obiekt.h"
#include <iostream>
#include <SFML/Window.hpp>
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
	
	bool spr(Pilka &p) {
		auto r = pSprite.getGlobalBounds();
		return pSprite.getGlobalBounds().intersects(p.obrys());
	}

	/*bool sprO(Obiekt &o) {
		auto r = pSprite.getGlobalBounds();
		return pSprite.getGlobalBounds().intersects(o.obrysO());
	}*/

	void setPlayer(float x, float y) {
		pSprite.setPosition(x, y);
	}

	sf::Vector2f Pos() { return pSprite.getPosition(); }

	void xPlayer() {
		pSprite.getPosition().x;
	}

	void yPlayer() {
		pSprite.getPosition().y;
	}

	void movePlayer(char direction, float moveSpeed) {
		if (direction == 'w') {
			pSprite.move(0, -moveSpeed);
		}
		else if(direction == 's') {
			pSprite.move(0, moveSpeed);
		}
		else if (direction == 'd') {
			pSprite.move( moveSpeed, 0);
		}
		else if (direction == 'a') {
			pSprite.move(-moveSpeed, 0);
		}
}
	void update() {
		pSprite.setPosition(position);
	}
private:
	sf::Texture pTexture;
	sf::Sprite pSprite;
	sf::Vector2f position;

};

