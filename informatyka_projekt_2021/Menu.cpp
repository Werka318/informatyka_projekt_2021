#include "Menu.h"

Menu::Menu(float width, float height)
{
	if (!font.loadFromFile("arial.ttf"))
	{
		//obs³uga b³êdu

	}

	menu[0].setFont(font);
	menu[0].setColor(sf::Color::White);
	menu[0].setString("Gra");
	menu[0].setPosition(sf::Vector2f(width/2,(MAX_NUMBER_OF_ITEMS+1)*1));

	menu[1].setFont(font);
	menu[1].setColor(sf::Color::White);
	menu[1].setString("Opcje gry");
	menu[1].setPosition(sf::Vector2f(width / 2, (MAX_NUMBER_OF_ITEMS + 1) * 2));

	menu[2].setFont(font);
	menu[2].setColor(sf::Color::White);
	menu[2].setString("Opis/gracze");
	menu[2].setPosition(sf::Vector2f(width / 2, (MAX_NUMBER_OF_ITEMS + 1) * 3));

	selectedItemIndex = 0;

}

Menu::~Menu()
{

}

void Menu::draw(sf::RenderWindow& window) 
{
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(menu[i]);
	}
}

void Menu::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setColor(sf::Color::Magenta);
		selectedItemIndex--;
		menu[selectedItemIndex].setColor(sf::Color::White);
	}
}

void Menu::MoveDown()
{
	if (selectedItemIndex + 1 < 0)
	{
		menu[selectedItemIndex].setColor(sf::Color::Magenta);
		selectedItemIndex++;
		menu[selectedItemIndex].setColor(sf::Color::White);
	}
}
