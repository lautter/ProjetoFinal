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
    //Applications variables
    std::vector<cScreen*> Screens;

    //Window creation
    sf::RenderWindow App(sf::VideoMode(largura,altura), "STARKANOID",sf::Style::Close);

    //Mouse cursor no more visible
    App.setMouseCursorVisible(false);
    App.setFramerateLimit(60);

    Menu menu(largura,altura);
    Tela1 tela1;
    Screens.push_back(&menu);
    Screens.push_back(&tela1);

    for(int i=0;i>=0;i=Screens[i]->Run(App));

    return EXIT_SUCCESS;
}
