#ifndef TELA_HPP
#define TELA_HPP
#include "cScreen.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Random.hpp"
#include "Janela.hpp"
#include "Bola.hpp"
#include <iostream>


class Tela
{
    public:
        /** Initialized constructor */
        Tela(Janela &App);
        /** Default destructor */
        ~Tela();

        std::string to_string(int i);
    protected:
        //Base
        sf::Music music;

        sf::Font font;
        sf::Text pont;
        Random ger; //!< @brief Instancia da classe Random. Serve para gerar inteiros aleatórios

        //Bordas
        sf::RectangleShape bordaE;
        sf::RectangleShape bordaD;
        sf::RectangleShape bordaS;

        //Background
        sf::Texture backg;
        sf::Sprite background;
        sf::Texture bigPlanet;
        sf::Sprite bPlanet;
        sf::Texture farPlanet;
        sf::Sprite fPlanet;
        sf::Texture ringPlanet;
        sf::Sprite rPlanet;
        sf::Texture starRs;
        sf::Sprite stars;
        sf::Sprite stars2;

        //Objetos
        sf::Texture lightssaber;
        sf::Sprite lightsaber;

        sf::Texture textura;
        Bola bola;
};

#endif // TELA_HPP
