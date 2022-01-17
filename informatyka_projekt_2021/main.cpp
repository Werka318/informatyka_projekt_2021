/*
Autor:Weronika Rumiñska
Temat: gra o zbieraniu 
Zakres: w tej grze planujê wykorzystaæ osie x i y do poruszania postaciami i animacjami
oraz elementy animowane w celu zbierania np. jedzenia lub kolorowych kulek
*/
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
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
#include <random>
#include "Pilka.h"
#include "Help.h"
#include "Nagroda.h"
#include "Tlo.h"
#include "fstream"

typedef struct {
    int pkt;
}sc;

void save(sc sc) {
    FILE* fp;
    fp = fopen("data.dat", "wb");
    fwrite(&sc, sizeof(sc), 1, fp);
    fclose(fp);
}
sc load() {
    sc sc;
    FILE* fp;
    fp = fopen("data.dat", "rb");
    fread(&sc, sizeof(sc), 1, fp);
    fclose(fp);
    return sc;
}

//typedef struct {
//    char text[10];
//}napis;
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
    sf::RenderWindow window(sf::VideoMode(W, H), "Gierka");
    int menu_selected_flag = -1;
    Menu menu1;
    Tlo tlo();
    //napis napis1;
    //napis1.text[0] = "x";
    //sf::CircleShape shape(R);
    //init();
    //shape.setPosition(W/2-R, H/2-R);
    //shape.setFillColor(sf::Color::Green);
    //Menu menu(window.getSize().x, (window.getSize().y));
    sc punkty;
    sc punkty2;
    Player myPlayer("serce.png");
    srand(time(0));
    Obiekt myObiekt(rand() % W+1 /2, rand() % H+1 /2);
    Pilka myPilka(rand() % W + 1 / 2, rand() % H + 1 / 2);
    Nagroda nagrody1(1);
    Nagroda nagrody11(1);
    Nagroda nagrody2(1);
    sf::Text tekst;
    //sf::Text tekst2;
    sf::Font font;
    font.loadFromFile("arial.ttf");
    tekst.setFont(font);
    tekst.setCharacterSize(50);
    tekst.setFillColor(sf::Color::White);
    
    //tekst2.setFont(font);
    //tekst2.setCharacterSize(50);
    //tekst2.setFillColor(sf::Color::White);
    //tekst1.setPosition(300, 300);
    //Obiekt myObiekt(rand() % W, rand() % H);
    //Obiekt myObiekt2(rand() % W, rand() % H);
    //myPlayer.setPlayer(W / 2, H / 2);
    int scores = 0;
    //int scores2 = 0;
    window.getSize().x == W;
    window.getSize().y == H;

    sf::Clock zegar;
    sf::Clock niesmiertelnosc;
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
        if (myPilka.Pos().y <= 0 || myPilka.Pos().y >= 600) {
            myPilka.bounceUD();
        }

        if (myPilka.Pos().x <= 0 || myPilka.Pos().x >= 600) {
            myPilka.bounceS();
        }
        int distanceP = (myPlayer.Pos().x+34 - myPilka.Pos().x-15) * (myPlayer.Pos().x+34 - myPilka.Pos().x-15)+ (myPlayer.Pos().y+29 - myPilka.Pos().y-15)*(myPlayer.Pos().y+29 - myPilka.Pos().y-15);
        if (distanceP<1000 && niesmiertelnosc.getElapsedTime().asMilliseconds()>1000) {
            std::cout << scores;
            niesmiertelnosc.restart();
            scores--;
        }

        int distanceO = (myPlayer.Pos().x+34 - myObiekt.Pos().x-8) * (myPlayer.Pos().x+34 - myObiekt.Pos().x-8) + (myPlayer.Pos().y+29 - myObiekt.Pos().y-8) * (myPlayer.Pos().y+29 - myObiekt.Pos().y-8);
        if (distanceO < 1500 && niesmiertelnosc.getElapsedTime().asMilliseconds()>1000) {
            std::cout << scores;
            niesmiertelnosc.restart();
            scores--;
        }
        int distanceN1 = (myPlayer.Pos().x - nagrody1.Pos().x) * (myPlayer.Pos().x - nagrody1.Pos().x) + (myPlayer.Pos().y - nagrody1.Pos().y) * (myPlayer.Pos().y - nagrody1.Pos().y);
        if (distanceN1 < 3500 && niesmiertelnosc.getElapsedTime().asMilliseconds()>1000) {
            std::cout << scores;
            niesmiertelnosc.restart();
            nagrody1.posN();
            scores++;
        }
        int distanceN2 = (myPlayer.Pos().x - nagrody2.Pos().x) * (myPlayer.Pos().x - nagrody2.Pos().x) + (myPlayer.Pos().y - nagrody2.Pos().y) * (myPlayer.Pos().y - nagrody2.Pos().y);
        if (distanceN2 < 3500 && niesmiertelnosc.getElapsedTime().asMilliseconds()>1000) {
            std::cout << scores;
            niesmiertelnosc.restart();
            nagrody2.posN();
            scores++;
        }
        int distanceN11 = (myPlayer.Pos().x - nagrody11.Pos().x) * (myPlayer.Pos().x - nagrody11.Pos().x) + (myPlayer.Pos().y - nagrody11.Pos().y) * (myPlayer.Pos().y - nagrody11.Pos().y);
        if (distanceN11 < 3500 && niesmiertelnosc.getElapsedTime().asMilliseconds()>1000) {
            std::cout << scores;
            niesmiertelnosc.restart();
            nagrody11.posN();
            scores++;
        }
          

       /* if (myPlayer.spr(myPilka)) {
            std::cout << scores;
            scores--;
        }*/

        /*if ((myPlayer.Pos().x == myPilka.Pos().x) && (myPlayer.Pos().y == myPilka.Pos().y)) {
            scores--;
        }*/

            if (myObiekt.Pos().y <= 0 || myObiekt.Pos().y>=600) {
                myObiekt.bounceUD();
            }

            if (myObiekt.Pos().x <= 0 || myObiekt.Pos().x >= 600) {
                myObiekt.bounceS();
            }

           //if ((myPlayer.Pos().x==myObiekt.Pos().x) && (myPlayer.Pos().y == myObiekt.Pos().y)) {
           //   scores--;
           //}

           if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && myPlayer.Pos().y >= -50) {
               myPlayer.movePlayer('w', 6.0);
           }

           if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && myPlayer.Pos().y <= H - 50) {
               myPlayer.movePlayer('s', 6.0);
           }
           if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && myPlayer.Pos().x <= W - 50) {
               myPlayer.movePlayer('d', 6.0);
           }
           if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && myPlayer.Pos().x >= -50) {
               myPlayer.movePlayer('a', 6.0);
           }
           

            //myPlayer.update();
            myObiekt.update();
            myPilka.update();
            std::stringstream ss;
            ss << "scores:" << scores ;
            tekst.setString(ss.str());

            
            //std::stringstream ss2;
            //ss1 << "scores:" << scores2;
            //tekst2.setString(ss2.str());

        

        //window.clear();
            if (menu_selected_flag == -1)
            {
                Tlo tlo;
                tlo.drawTlo(window);
                menu1.draw(window);
                menu_selected_flag = menu1.GetPressedItem(sf::Mouse::getPosition(window), sf::Mouse::isButtonPressed(sf::Mouse::Left));
            }
            if (menu_selected_flag == 0)
            {
                window.clear();
                //sf::CircleShape kolo;
                //kolo.setFillColor(sf::Color::White);
                //kolo.setRadius(15);
                //window.draw(kolo);
                myPlayer.drawPlayer(window);
                window.draw(myObiekt.getShape());
                window.draw(tekst);
                nagrody1.draw(window);
                nagrody11.draw(window);

                //tlo().drawTlo(window);
                //std::cout << "Dziala" << "\n";
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::M)) {
                    scores = 0;
                    menu_selected_flag = -1;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
                    //font.loadFromFile("arial.ttf");
                    sf::Text wyjscie;
                    //sf::Font font;
                    wyjscie.setFont(font);
                    wyjscie.setCharacterSize(30);
                    wyjscie.setFillColor(sf::Color::White);
                    wyjscie.setPosition(W / 4, H / 4);
                    std::stringstream sw;
                    sw << "Na pewno chcesz wyjsc?";
                    wyjscie.setString(sw.str());
                    window.draw(wyjscie);
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
                        window.close();
                    }
                    
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::H)) {
                    Help help;
                    help.drawHelp(window);
                }
                if (event.key.code == sf::Keyboard::Z) {
                    punkty.pkt = scores;
                    save(punkty);
                }
                if (event.key.code == sf::Keyboard::O) {
                    punkty = load();
                    scores = punkty.pkt;

                }

            }
            if (menu_selected_flag == 1)
            {
                window.clear();
                myPlayer.drawPlayer(window);
                window.draw(myPilka.getShape());
                window.draw(tekst);
                nagrody2.draw(window);

                //std::cout << "Dziala" << "\n";
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::H)) {
                    Help help;
                    help.drawHelp(window);
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::M)) {
                    scores = 0;
                    menu_selected_flag = -1;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                    //font.loadFromFile("arial.ttf");
                    sf::Text wyjscie;
                    //sf::Font font;
                    wyjscie.setFont(font);
                    wyjscie.setCharacterSize(30);
                    wyjscie.setFillColor(sf::Color::White);
                    wyjscie.setPosition(W / 4, H / 4);
                    std::stringstream sw;
                    sw << "Na pewno chcesz wyjsc?";
                    wyjscie.setString(sw.str());
                    window.draw(wyjscie);
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
                        window.close();
                    }

                }
                if (event.key.code == sf::Keyboard::Z) {
                    punkty2.pkt = scores;
                    save(punkty2);
                }
                if (event.key.code == sf::Keyboard::O) {
                    punkty2 = load();
                    scores = punkty2.pkt;

                }
                


            }
            if (menu_selected_flag == 2)
            {
                window.clear();
                //sf::CircleShape kolo;
                //kolo.setFillColor(sf::Color::White);
                //kolo.setRadius(15);
                //window.draw(kolo);
                //myPlayer.drawPlayer(window);
                //window.draw(myObiekt.getShape());
                //window.draw(tekst);
                //std::cout << "Dziala" << "\n";
                Help help;
                help.drawHelp(window);
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::M)) {
                    menu_selected_flag = -1;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {

                    window.close();
                }


            }
            //.....tu siê pokazuje nr flagi
            //std::cout << menu_selected_flag << "\n";
        //menu.draw(window);
        //for (int i = 0; i < N; i++)
        //   window.draw(naszekolka[i]);
       // myPlayer.drawPlayer(window);
       // window.draw(myObiekt.getShape());
       // window.draw(tekst);
        //myObiekt.drawObiekt(window);
        //myObiekt2.drawObiekt(window);
        window.display();
    }
    return 0;
}