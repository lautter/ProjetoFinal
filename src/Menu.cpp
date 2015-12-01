#include "Menu.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
Menu::Menu(float width, float height)
{
    if(!font.loadFromFile("/usr/share/fonts/truetype/ubuntu-font-family/Ubuntu-M.ttf")&&!font.loadFromFile("arial.ttf"))
        std::cout<<"Fonte no encontrada!!"<<std::endl;

    selectedItem=0;

    //Build the Play Option
    menu[0].setFont(font);
    menu[0].setColor(sf::Color::Red);
    menu[0].setString("Play");
    menu[0].setPosition(sf::Vector2f(width/2,height/(QMENUOPTIONS+1)*1));

    //Build the Ranking Option
    menu[1].setFont(font);
    menu[1].setColor(sf::Color::White);
    menu[1].setString("Best Scores");
    menu[1].setPosition(sf::Vector2f(width/2,height/(QMENUOPTIONS+1)*2));

    //Build the Exit Option
    menu[2].setFont(font);
    menu[2].setColor(sf::Color::White);
    menu[2].setString("Exit");
    menu[2].setPosition(sf::Vector2f(width/2,height/(QMENUOPTIONS+1)*3));
}

Menu::~Menu()
{
    //dtor
}

void Menu::moveUp(void){
    if(selectedItem-1>=0){
        menu[selectedItem].setColor(sf::Color::White);
        selectedItem--;
        menu[selectedItem].setColor(sf::Color::Red);
    }
}

void Menu::moveDown(void){
    if(selectedItem+1<QMENUOPTIONS){
        menu[selectedItem].setColor(sf::Color::White);
        selectedItem++;
        menu[selectedItem].setColor(sf::Color::Red);
    }
}


int Menu::Run(sf::RenderWindow &App,int &lifes,int &pontos){
    limpar();
    sf::Event evento;
    while(App.isOpen()){
        App.clear();

        for(int i=0;i<QMENUOPTIONS;i++)
            App.draw(menu[i]);

        if(App.pollEvent(evento)){
            switch(evento.type){
                case sf::Event::KeyReleased:
                    switch(evento.key.code){
                        case sf::Keyboard::Up:
                            moveUp();
                            break;
                        case sf::Keyboard::Down:
                            moveDown();
                            break;
                        case sf::Keyboard::Return:
                            switch(selectedItem){
                                case 0: return 1; break;
                                case 1: return 2; break;
                                case 2: return -1; break;
                            }break;
                        default: break;

                    }break;
                case sf::Event::Closed: return -1; break;
                default: break;
            }
        }
        App.display();
    }return -1;
}

void Menu::limpar(void){
    selectedItem=0;

    //Build the Play Option
    menu[0].setFont(font);
    menu[0].setColor(sf::Color::Red);
    menu[0].setString("Play");

    //Build the Ranking Option
    menu[1].setFont(font);
    menu[1].setColor(sf::Color::White);
    menu[1].setString("Best Scores");

    //Build the Exit Option
    menu[2].setFont(font);
    menu[2].setColor(sf::Color::White);
    menu[2].setString("Exit");
}
