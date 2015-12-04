#include "cScreen.hpp"
#include "Menu.hpp"
#include "Tela1.hpp"

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#define altura 720
#define largura 1200

#include <stdio.h>

int main(int argc, char** argv)
{
    FILE *p;
    if(!(p=fopen("./Scores","a")))
        std::cout<<"ERRO AO ABRIR ARQUIVO"<<std::endl;
    char a[100];
    std::vector<std::string> scores;
    while(fgets(a,99,p)){
        std::string b(a);
        scores.push_back(b);
    }

    fclose(p);

    if(!(p=fopen("./Scores","w")))
        std::cout<<"ERRO AO ABRIR ARQUIVO"<<std::endl;

    //Applications variables
    std::vector<cScreen*> Screens;

    //Window creation
    sf::RenderWindow App(sf::VideoMode(largura,altura), "STARKANOID",sf::Style::Close);

    //Mouse cursor no more visible
    App.setMouseCursorVisible(false);
    App.setFramerateLimit(60);

    int lifes=3;
    int pontos=0;

    int anterior;
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

    bool flag;
    for(int i=0;i>=0 && i<5;i=Screens[i]->Run(App,lifes,pontos,flag,a)){
        if(i==0)
            flag=false;
        else
            flag=true;
    }
    sscanf(a,"%d",&anterior);
    if(pontos>anterior)
        sprintf(a,"%d",pontos);
    fputs(a,p);
    fclose(p);

    return EXIT_SUCCESS;
}

