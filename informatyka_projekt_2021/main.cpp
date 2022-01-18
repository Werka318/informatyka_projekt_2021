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








const int W = 600;
const int H = 600;







int main()
{
    sf::RenderWindow window(sf::VideoMode(W, H), "Gierka");
    int menu_selected_flag = -1;
    Menu menu1;
    Tlo tlo();
    
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
    sf::Font font;
    font.loadFromFile("arial.ttf");
    tekst.setFont(font);
    tekst.setCharacterSize(50);
    tekst.setFillColor(sf::Color::White);
    
    
    int scores = 0;
    window.getSize().x == W;
    window.getSize().y == H;

    sf::Clock zegar;
    sf::Clock niesmiertelnosc;
    window.setFramerateLimit(60);
    while (window.isOpen())
    {
        
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

            
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
          

       
            if (myObiekt.Pos().y <= 0 || myObiekt.Pos().y>=600) {
                myObiekt.bounceUD();
            }

            if (myObiekt.Pos().x <= 0 || myObiekt.Pos().x >= 600) {
                myObiekt.bounceS();
            }

           

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
           

            myObiekt.update();
            myPilka.update();
            std::stringstream ss;
            ss << "scores:" << scores ;
            tekst.setString(ss.str());

            
            
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
                
                myPlayer.drawPlayer(window);
                window.draw(myObiekt.getShape());
                window.draw(tekst);
                nagrody1.draw(window);
                nagrody11.draw(window);

                
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::M)) {
                    scores = 0;
                    menu_selected_flag = -1;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
                    sf::Text wyjscie;
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

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::H)) {
                    Help help;
                    help.drawHelp(window);
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::M)) {
                    scores = 0;
                    menu_selected_flag = -1;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                    sf::Text wyjscie;
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
                
                Help help;
                help.drawHelp(window);
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::M)) {
                    menu_selected_flag = -1;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {

                    window.close();
                }


            }
            
        window.display();
    }
    return 0;
}