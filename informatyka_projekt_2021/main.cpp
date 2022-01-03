/*
Autor:Weronika Rumiñska
Temat: gra o zbieraniu 
Zakres: w tej grze planujê wykorzystaæ osie x i y do poruszania postaciami i animacjami
oraz elementy animowane w celu zbierania np. jedzenia lub kolorowych kulek
*/

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <iostream>
#include <cstdlib>
#include <string>
#include <conio.h>
#include <windows.h>
#include <cstdio>
#include <time.h>
#include <thread>
#include <chrono>
#include "Menu.h"

class menu {

};

class kolo {
public:
    void tworz();
    void animuj();
};

void kolo::tworz() {
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Magenta);
    sf::Clock zegar;
    if (zegar + 10) {
        draw
    }
}

void kolo::animuj() {
    srand(time(NULL));

    shape.move(0, 4);
    if (shape.getPosition().x > W) {
        shape.setPosition(rand(), 0);
    }
}

class gracz {
public:
    void tworz();
    void animuj();
    void rysuj();
};

void gracz::tworz() {
    sf::CircleShape shape(50.f);
    shape.setFillColor(sf::Color::Green);

}

void gracz::animuj() {

    keyboard;
}



const int R = 30;
const int W = 600;
const int H = 600;
const int N = 10;
sf::CircleShape naszekolka[N];

//przesun(4.1, 0, shape);
void init()
{
    srand(time(NULL));
    for (int i = 0; i < N; i++)
    {
        naszekolka[i] = sf::CircleShape(R * (rand() / (float)RAND_MAX));
        naszekolka[i].setPosition(0 + W / 2 * (rand() / (float)RAND_MAX - 0.5), H / 2 + H / 2 * (rand() / (float)RAND_MAX - 0.5));
        naszekolka[i].setFillColor(sf::Color::Magenta);
    }
}
void przesun(float PX, float PY, sf::CircleShape& obiektdoprzes)
{
    // przesuniecie
    obiektdoprzes.move(PX, PY);
    if (obiektdoprzes.getPosition().x > W) {
        obiektdoprzes.setPosition(0, obiektdoprzes.getPosition().y);
        if (obiektdoprzes.getPosition().x == 0)
        {

            init();
        }
    }
}
int main()
{
    sf::RenderWindow window(sf::VideoMode(W, H), "SFML works!");
    //sf::CircleShape shape(R);
    init();
    //shape.setPosition(W/2-R, H/2-R);
    //shape.setFillColor(sf::Color::Green);
    Menu menu(window.getSize().x, (window.getSize().y);

    sf::Clock zegar;
    window.setFramerateLimit(60);
    while (window.isOpen())
    {
        sf::Time czas = zegar.restart();
        std::cout << (1.0 / czas.asSeconds()) << " FPS " << std::endl;

        for (int i = 0; i < N; i++)
            przesun(4.1, 0, naszekolka[i]);


        // spr myszy
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            for (int i = 0; i < N; i++)
            {
                int px = naszekolka[i].getPosition().x + R / 2;
                int py = naszekolka[i].getPosition().y + R / 2;
                int mx = sf::Mouse::getPosition(window).x;
                int my = sf::Mouse::getPosition(window).y;

                if ((px - mx) * (px - mx) + (py - my) * (py - my) < R * R)
                {
                    std::cout << px << " " << py << " , " << mx << " " << my << std::endl;
                }
                //else
                //    std::cout << "nie trafiles" << std::endl;

            }

        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
                //if (event.type == sf::Event::Closed)
            case sf::Event::KeyReleased:
                switch (event.key.code)
                {
                case sf::Keyboard::Up:
                    menu.MoveUp();
                    break;

                case sf::Keyboard::Down:
                    menu.MoveDown();
                    break;

                case sf::Keyboard::Return:
                    switch (menu.GetPressedItem())
                    {
                    case 0:
                        std::cout << "Przycisk gry zostal wlaczony" << std::endl;
                        break;
                    case 1:
                        std::cout << "Przycisk opcji zostal wlaczony" << std::endl;
                        break;
                    case 2:
                        std::cout << "Przycisk opisu/graczy zostal wlaczony" << std::endl;
                        break;
                    }

                    break;
                }
                break;
            case sf::Event::Closed:
                    window.close();
            }
        }

        window.clear();

        menu.draw(window);
        for (int i = 0; i < N; i++)
            window.draw(naszekolka[i]);
        window.display();
    }
    return 0;
}