#pragma once
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include<cstdlib>
#include <random>


class Nagroda {
public:
	

	Nagroda(int Nt) {
			std::mt19937 gen(random());
			std::uniform_int_distribution<> distX(100, 500);
			std::uniform_int_distribution<> distY(100, 500);
			float x = 0;
			float y = 0;
			N = Nt;
			nShape = new sf::RectangleShape[N];
			for (int i = 0; i < N; i++) {
				x = distX(gen);
				y = distY(gen);
				nShape[i].setPosition(sf::Vector2f(x, y));
				nShape[i].setFillColor(sf::Color::Red);
				nShape[i].setSize(sf::Vector2f(20, 20));
			}
		
	}
	int i;
	 sf::Vector2f Pos() { return nShape[i].getPosition(); }


	

	void draw(sf::RenderWindow& window) {
		for (int i = 0; i < N; i++) {
			window.draw(nShape[i]);
		}
	}

	void posN() {
		std::mt19937 gen(random());
		std::uniform_int_distribution<> distX(100, 500);
		std::uniform_int_distribution<> distY(100, 500);
		float x = 0;
		float y = 0;
		x = distX(gen);
		y = distY(gen);
		for (int i = 0; i < N; i++) {
			nShape[i].setPosition(sf::Vector2f(x, y));
		}
	}

private:
	sf::RectangleShape *nShape;
	int N;
	std::random_device random;
	sf::Vector2f position;
	
};








