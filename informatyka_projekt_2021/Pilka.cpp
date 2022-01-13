#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Pilka.h"
#include<cstdlib>


Pilka::Pilka(float startX, float startY) {
	position.x = startX;
	position.y = startY;
	pShape.setSize(sf::Vector2f(30, 30));
	pShape.setPosition(position);
}

/*sf::FloatRect Obiekt::getPosition() {
	return oShape.getGlobalBounds();

}*/



sf::RectangleShape Pilka::getShape() {
	return pShape;
}

float Pilka::getXV() {
	return xV;
}

void Pilka::bounceS() {
	srand(time(0));
	xV = -xV;
	pShape.setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));

}

void Pilka::bounceUD() {
	srand(time(0));
	yV = -yV;
	pShape.setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));

}

void Pilka::update() {
	position.x += xV;
	position.y += yV;
	pShape.setPosition(position);
}