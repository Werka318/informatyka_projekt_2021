#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Obiekt.h"
#include<cstdlib>


Obiekt::Obiekt(float startX, float startY){
	position.x = startX;
	position.y = startY;
	oShape.setSize(sf::Vector2f(15, 15));
	oShape.setPosition(position);
	}

/*sf::FloatRect Obiekt::getPosition() {
	return oShape.getGlobalBounds();
	
}*/



sf::RectangleShape Obiekt::getShape() {
	return oShape;
}

float Obiekt::getXV() {
	return xV;
}

void Obiekt::bounceS(){
	xV = -xV;
	srand(time(0));
	oShape.setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));
}

void Obiekt::bounceUD() {
	yV = -yV;
	srand(time(0));
	oShape.setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));
}

void Obiekt::update() {
	position.x += xV;
	position.y += yV;
	oShape.setPosition(position);
}