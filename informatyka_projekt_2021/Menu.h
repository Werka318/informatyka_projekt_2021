#pragma once
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#define MAX_NUMBER_OF_ITEMS 3

class Menu
{
public:
	Menu();
	//Menuuu();

	void draw(sf::RenderWindow& window);
	void MoveUp();
	void MoveDown();
	int GetPressedItem() { return selectedItemIndex; }

private:
	int selectedItemIndex;
	sf::Font font;
	sf::Text menu[MAX_NUMBER_OF_ITEMS];
	void init(float width, float height);
	void Font();
	void MAX();

};

