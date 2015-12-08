#include "Menu.hpp"
#include "Tela1.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

#include <string>
#include <sstream>
Menu::Menu(float width, float height)
{
    if(!font.loadFromFile("C:/Windows/Fonts/Arial.ttf"))
        if(!font.loadFromFile("/usr/share/fonts/truetype/ubuntu-font-family/Ubuntu-M.ttf"))
            std::cout<<"Fonte no encontrada!!"<<std::endl;
    if(!mMusic.openFromFile("S31-Hit and Run.ogg"))
        std::cout << "Não deu pra abrir a música do menu caras..." << std::endl;
    if(!Mbackg.loadFromFile("parallax-space-backgound.png"))
        std::cout << "Não foi possivel carregar background do menu!" << std::endl;
    if(!starRs.loadFromFile("parallax-space-stars.png"))
        std::cout << "Não foi possivel carregar stars!" << std::endl;
    stars.setTexture(starRs);
    Mbackground.setTexture(Mbackg);
    Mbackground.setScale(5,5);
    stars.setScale(4,4);
    stars.setPosition(0,100);

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

    nomeJogo.setFont(font);
    nomeJogo.setCharacterSize(80);
    nomeJogo.setColor(sf::Color::White);
    nomeJogo.setString("Starkanoid");
    nomeJogo.setPosition(100,550);
    nomeJogo.setRotation(270);

    //Build the Play Option
    for(int i=0;i<11;i++){
        scores[i].setFont(font);
        scores[i].setColor(sf::Color::White);
        scores[i].setPosition(sf::Vector2f(600,20+i*100));
    }
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


int Menu::Run(Janela &App){
    limpar(App.getJogador());
    sf::Event evento;

    sf::Text text2;
    text2.setFont(font);
    text2.setColor(sf::Color::Red);

    text2.setPosition(sf::Vector2f(1200/2-100,720/2+20));
    std::cout<<"NOWNSO"<<App.getBestScores().size();
    scores[0].setString("Nome Fase Pontos");
    for(unsigned int i=1;i<2&&i<App.getBestScores().size();i++){
        std::cout<<App.getBestScores()[i-1].getNome()<<std::endl;
        std::string a(App.getBestScores()[i-1].getNome());
        std::string b(to_string(App.getBestScores()[i-1].getFase()));
        std::string c(to_string(App.getBestScores()[i-1].getPontos()));
        std::string d(a+" "+b+" "+c);
        scores[i].setString(d);
    }


    while(App.isOpen()){
        App.clear();
        App.draw(Mbackground);
        App.draw(stars);

        for(int i=0;i<QMENUOPTIONS;i++)
            App.draw(menu[i]);
        App.draw(nomeJogo);

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
                                case 0: mMusic.stop(); return 1; break;
                                case 1:
                                while(App.isOpen()){
                                    sf::Event event;
                                    while (App.pollEvent(event))
                                    {
                                        if (event.type == sf::Event::Closed)
                                            App.close();
                                        if (event.type == sf::Event::KeyReleased)
                                        {
                                            if (event.key.code == sf::Keyboard::Return){
                                                return 0;
                                            }
                                        }
                                    }
                                    App.clear();
                                    App.draw(Mbackground);
                                    App.draw(stars);
                                    App.draw(text2);
                                        for(int i=0;i<11;i++){
                                            App.draw(scores[i]);
                                        }
                                    App.display();
                                }
                                break;
                                case 2: return -1; break;
                            }break;
                        default: break;

                    }break;
                case sf::Event::Closed: return -1; break;
                default: break;
            }
        }
        //App.draw(background);
        App.display();
    }return -1;
}

void Menu::limpar(Player &jogador){
    selectedItem=0;

    menu[0].setColor(sf::Color::Red);
    menu[1].setColor(sf::Color::White);
    menu[2].setColor(sf::Color::White);

    jogador.limpa();
    mMusic.play();
}
std::string Menu::to_string(int i){
    std::stringstream s;
    std::string a="";
    s<<i;
    a+=s.str();
    return a;
}
