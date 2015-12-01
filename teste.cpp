//Basic Screen Class
#include "cScreen.hpp"
#include "Menu.hpp"
#include "Tela1.hpp"

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#define altura 720
#define largura 1200

int main(int argc, char** argv)
{
    Bloco a;
    Bloco b;
    a=b;
    //Applications variables
    std::vector<cScreen*> Screens;

    //Window creation
    sf::RenderWindow App(sf::VideoMode(largura,altura), "STARKANOID",sf::Style::Close);

    //Mouse cursor no more visible
    App.setMouseCursorVisible(false);
    App.setFramerateLimit(60);

    int lifes=3;
    int pontos=0;

    Menu menu(largura,altura);
    Tela1 tela1;
    Tela1 tela2(1);
    Tela1 tela3(2);
    Tela1 tela4(3);
    Tela1 tela5(4);
    Screens.push_back(&menu);
    Screens.push_back(&tela1);
    Screens.push_back(&tela2);
    Screens.push_back(&tela3);
    Screens.push_back(&tela4);
    Screens.push_back(&tela5);

    for(int i=0;i>=0;i=Screens[i]->Run(App,lifes,pontos));

    return EXIT_SUCCESS;
}

