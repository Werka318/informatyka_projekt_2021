#pragma once
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include<cstdlib>


class Nagroda {
public:
	Nagroda() {
		//domyœlny
	}
	Nagroda(float startX, float startY);

	
	sf::Vector2f Pos() { return nShape.getPosition(); }
	sf::RectangleShape getShape();
	float getXV();
	void bounceUD();
	void bounceS();
	void update();


private:
	sf::RectangleShape nShape;
	sf::Vector2f position;
	float xV = 1.f;
	float yV = 1.f;
};






