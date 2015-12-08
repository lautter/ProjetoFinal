#include "Tela.hpp"
#include <string>
#include <sstream>

Tela::Tela(Janela &App)
{
    //Fonte
    if(!font.loadFromFile("C:/Windows/Fonts/Arial.ttf"))
        if(!font.loadFromFile("/usr/share/fonts/truetype/ubuntu-font-family/Ubuntu-M.ttf"))
            std::cout<<"Fonte não encontrada!!"<<std::endl;

    //Music
    if(!music.openFromFile("Disco Century.wav"))
        std::cout << "Não deu pra abrir a música caras..." << std::endl;

    //background und parallax
    if(!backg.loadFromFile("parallax-space-backgound.png"))
        std::cout << "Não foi possivel carregar background!" << std::endl;
    background.setTexture(backg);
    background.setScale(6.f,6.f);
    if(!bigPlanet.loadFromFile("parallax-space-big-planet.png"))
        std::cout << "Não foi possivel carregar big planet!" << std::endl;
    bPlanet.setTexture(bigPlanet);
    bPlanet.setScale(4.f,4.f);
    bPlanet.setPosition(1300.f,350);
    if(!farPlanet.loadFromFile("parallax-space-far-planets.png"))
        std::cout << "Não foi possivel carregar far planets!" << std::endl;
    fPlanet.setTexture(farPlanet);
    fPlanet.setScale(3.f,3.f);
    fPlanet.setPosition(900.f,80.f);
    if(!ringPlanet.loadFromFile("parallax-space-ring-planet.png"))
        std::cout << "Não foi possivel carregar ring planet!" << std::endl;
    rPlanet.setTexture(ringPlanet);
    rPlanet.setScale(4.f,4.f);
    rPlanet.setPosition(1000.f,300.f);
    if(!starRs.loadFromFile("parallax-space-stars.png"))
        std::cout << "Não foi possivel carregar stars!" << std::endl;
    stars.setTexture(starRs);
    stars2.setTexture(starRs);
    stars.setPosition(55.f,55.f);
    stars.setScale(4.f,4.f);
    stars2.setPosition(800.f,70.f);
    stars2.setScale(3.f,3.f);


    //Bordas
    bordaE.setSize(sf::Vector2f(50,720));
    bordaE.setPosition(0.f,0.f);
    bordaE.setFillColor(sf::Color(0,0,0));

    bordaD.setSize(sf::Vector2f(50,720));
    bordaD.setPosition(1150.f,0.f);
    bordaD.setFillColor(sf::Color(0,0,0));

    bordaS.setSize(sf::Vector2f(1100,50));
    bordaS.setPosition(50.f,0.f);
    bordaS.setFillColor(sf::Color(0,0,0));


    //Pontuação
    pont.setFont(font);
    pont.setColor(sf::Color(255,255,255));
    pont.setString("Pontos: "+to_string(App.getJogador().getPontos()));
    pont.setPosition(950,10);


    //Sabre
    if(!lightssaber.loadFromFile("lightsaber2.png"))
        std::cout << "Nao foi possivel carregar lightsaber.png" << std::endl;
    lightsaber.setTexture(lightssaber);
    lightsaber.rotate(180);

    //Bola
    bola.setRadius(4);
    bola.setPosition(310,App.getSize().y/2);

    if(!textura.loadFromFile("hearts.png"));
        std::cout << "nao deu pra carregar o coracao, coracao" << std::endl;
}

Tela::~Tela()
{
    //dtor
}
std::string Tela::to_string(int i){
    std::stringstream s;
    std::string a="";
    s<<i;
    a+=s.str();
    return a;
}
