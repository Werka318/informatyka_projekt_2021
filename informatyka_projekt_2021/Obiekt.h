#pragma once
#include "Player.h"
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Obiekt {
public:
	
	Obiekt(float startX, float startY);

	
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



