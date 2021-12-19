/*
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
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        for (int i = 0; i < N; i++)
            window.draw(naszekolka[i]);
        window.display();
    }
    return 0;
}