#pragma once
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Obiekt {
public:
	Obiekt() {
		//domyœlny
	}
	Obiekt(float startX, float startY);

	/*void drawObiekt(sf::RenderWindow& window) {
		window.draw(pSprite);
	}*/

	/*void setPlayer(float x, float y) {
		pSprite.setPosition(x, y);
	}*/

	//sf::Vector2f Pos() { return pSprite.getPosition(); }

	/*void movePlayer(char direction, float moveSpeed) {
		if (direction == 'w') {
			pSprite.move(0, -moveSpeed);
		}
		else if (direction == 's') {
			pSprite.move(0, moveSpeed);
		}
		else if (direction == 'd') {
			pSprite.move(moveSpeed, 0);
		}
		else if (direction == 'a') {
			pSprite.move(-moveSpeed, 0);
		}
	}*/
	//sf::FloatRect getPosition();
	sf::Vector2f Pos() { return oShape.getPosition(); }
	sf::RectangleShape getShape();
	float getXV();
	void bounceUD();
	void bounceS();
	void update();


private:
	sf::RectangleShape oShape;

	sf::Vector2f position;
	float xV=2.f;
	float yV=2.f;
};

/*Obiekt::Obiekt(float x, float y) {
	position.x = x;
	position.y = y;
	pSprite.setRadius(10);
	pSprite.setFillColor(sf::Color::Magenta);
	pSprite.setPosition(position);
}*/

