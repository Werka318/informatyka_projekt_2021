/*
Autor:Weronika Rumi�ska
Temat: gra o zbieraniu 
Zakres: w tej grze planuj� wykorzysta� osie x i y do poruszania postaciami i animacjami
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
#include "Player.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics/BlendMode.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/ConvexShape.hpp>
#include <SFML/Graphics/Drawable.hpp>
 #include <SFML/Graphics/Font.hpp>
 #include <SFML/Graphics/Glyph.hpp>
 #include <SFML/Graphics/Image.hpp>
 #include <SFML/Graphics/PrimitiveType.hpp>
 #include <SFML/Graphics/Rect.hpp>
 #include <SFML/Graphics/RectangleShape.hpp>
 #include <SFML/Graphics/RenderStates.hpp>
 #include <SFML/Graphics/RenderTarget.hpp>
 #include <SFML/Graphics/RenderTexture.hpp>
 #include <SFML/Graphics/RenderWindow.hpp>
 #include <SFML/Graphics/Shader.hpp>
 #include <SFML/Graphics/Shape.hpp>
 #include <SFML/Graphics/Sprite.hpp>
 #include <SFML/Graphics/Text.hpp>
 #include <SFML/Graphics/Texture.hpp>
 #include <SFML/Graphics/Transform.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/Vertex.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/Graphics/VertexBuffer.hpp>
#include <SFML/Graphics/View.hpp>
#include "Obiekt.h"
#include "sstream"
#include "cstdlib"


/*class menu {

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
}*/




const int W = 600;
const int H = 600;

/*
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
}*/

int main()
{
    sf::RenderWindow window(sf::VideoMode(W, H), "SFML works!");
    //sf::CircleShape shape(R);
    //init();
    //shape.setPosition(W/2-R, H/2-R);
    //shape.setFillColor(sf::Color::Green);
    //Menu menu(window.getSize().x, (window.getSize().y));
    Player myPlayer("serce.png");
    srand(time(0));
    Obiekt myObiekt(rand() % W+1 /2, rand() % H+1 /2);
    sf::Text tekst;
    sf::Font font;
    font.loadFromFile("arial.ttf");
    tekst.setFont(font);
    tekst.setCharacterSize(50);
    tekst.setFillColor(sf::Color::White);
    //Obiekt myObiekt(rand() % W, rand() % H);
    //Obiekt myObiekt2(rand() % W, rand() % H);
    //myPlayer.setPlayer(W / 2, H / 2);
    int scores = 0;
    window.getSize().x == W;
    window.getSize().y == H;

    sf::Clock zegar;
    window.setFramerateLimit(60);
    while (window.isOpen())
    {
        //sf::Time czas = zegar.restart();
        //std::cout << (1.0 / czas.asSeconds()) << " FPS " << std::endl;

       // for (int i = 0; i < N; i++)
       //     przesun(4.1, 0, naszekolka[i]);


        // spr myszy
        /*if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
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

            }*/

        //Player myPlayer("serce.png");
        //myPlayer.setPlayer(20, 30);
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

            //switch (event.type)
            //{
                //if (event.type == sf::Event::Closed)
            /*case sf::Event::KeyReleased:
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
                break;*/

            //case sf::Event::Closed:
            //        window.close();
            //}
            //sf::Vector2f pos = myPlayer.setPlayer();
            
            if (myObiekt.Pos().y <= 0 || myObiekt.Pos().y>=600) {
                myObiekt.bounceUD();
            }

            if (myObiekt.Pos().x <= 0 || myObiekt.Pos().x >= 600) {
                myObiekt.bounceS();
            }

           if ((myPlayer.Pos().x==myObiekt.Pos().x) && (myPlayer.Pos().y == myObiekt.Pos().y)) {
              scores++;
           }

           if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && myPlayer.Pos().y >= -50 ) {
                myPlayer.movePlayer('w', 6.0);
            }

           if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && myPlayer.Pos().y <= H-50 ) {
                myPlayer.movePlayer('s', 6.0);
            }
           if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && myPlayer.Pos().x <= W-50 ) {
                myPlayer.movePlayer('d', 6.0);
            }
           if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && myPlayer.Pos().x >=-50 ) {
                myPlayer.movePlayer('a', 6.0);
            }

            myPlayer.update();
            myObiekt.update();
            std::stringstream ss;
            ss << "scores:" << scores ;
            tekst.setString(ss.str());

        

        window.clear();

        //menu.draw(window);
        //for (int i = 0; i < N; i++)
        //   window.draw(naszekolka[i]);
        myPlayer.drawPlayer(window);
        window.draw(myObiekt.getShape());
        window.draw(tekst);
        //myObiekt.drawObiekt(window);
        //myObiekt2.drawObiekt(window);
        window.display();
    }
    return 0;
}