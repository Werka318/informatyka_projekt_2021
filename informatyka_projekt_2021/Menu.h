#include <iostream>
#include <SFML/Graphics.hpp>
#define MAX_NUMBER_OF_ITEMS 3

class Menu
{
public:
	Menu();

	void draw(sf::RenderWindow& window);

	int GetPressedItem(sf::Vector2i position, bool pressed);
	bool check_mouse(sf::Vector2i mouse, int numer);

private:
	sf::Font font;
	sf::Text menu[MAX_NUMBER_OF_ITEMS];
	sf::RectangleShape prostokat[MAX_NUMBER_OF_ITEMS];
};
Menu::Menu()
{
	font.loadFromFile("arial.ttf");
	for (int i = 0; i < 3; i++)
	{
		menu[i].setFont(font);
		menu[i].setCharacterSize(50);
		menu[i].setFillColor(sf::Color::Blue);

		prostokat[i].setSize(sf::Vector2f(260, 90));
		prostokat[i].setFillColor(sf::Color::Magenta);
		//prostokat[i].setFillColor(sf::Color::Transparent);

		menu[i].setPosition(sf::Vector2f(10, i * 100));
		prostokat[i].setPosition(sf::Vector2f(10, i * 100));

		//menu[i].setString("tekst dowolny");
		menu[0].setString("Gra level 1");
		menu[1].setString("Gra level 2");
		menu[2].setString("Opcje i inne");


	}
}
void Menu::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(prostokat[i]);
		window.draw(menu[i]);
	}
}
bool Menu::check_mouse(sf::Vector2i mouse, int numer)
{
	if (mouse.x > prostokat[numer].getPosition().x && mouse.y > prostokat[numer].getPosition().y && mouse.x < prostokat[numer].getPosition().x + prostokat[numer].getSize().x && mouse.y < prostokat[numer].getPosition().y + prostokat[numer].getSize().y)
		return true;
	return false;
}
int Menu::GetPressedItem(sf::Vector2i position, bool pressed)
{
	for (int i = 0; i < 3; i++)
		if (check_mouse(position, i) && pressed)
		{
			//prostokat[i].setFillColor(sf::Color::White);
			return i;
		}
	return -1;
}
