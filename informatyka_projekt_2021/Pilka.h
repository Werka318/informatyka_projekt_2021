#pragma once
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


class Pilka {
public:
	
	Pilka(float startX, float startY);

	
	sf::Vector2f Pos() { return pShape.getPosition(); }
	sf::RectangleShape getShape();
	float getXV();
	void bounceUD();
	void bounceS();
	void update();

	sf::FloatRect obrys() {
		auto r = pShape.getGlobalBounds();
		return r;
	}


private:
	sf::RectangleShape pShape;
	sf::Vector2f position;
	float xV = 10.f;
	float yV = 1.f;
};




