#include "Nagroda.h"
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include<cstdlib>


Nagroda::Nagroda(float startX, float startY) {
	position.x = startX;
	position.y = startY;
	nShape.setSize(sf::Vector2f(30, 30));
	nShape.setFillColor(sf::Color::Red);
	nShape.setPosition(position);
}





sf::RectangleShape Nagroda::getShape() {
	return nShape;
}

float Nagroda::getXV() {
	return xV;
}

void Nagroda::bounceS() {
	srand(time(0));
	xV = -xV;
	nShape.setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));

}

void Nagroda::bounceUD() {
	srand(time(0));
	yV = -yV;
	nShape.setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));

}

void Nagroda::update() {
	position.x += xV;
	position.y += yV;
	nShape.setPosition(position);
}