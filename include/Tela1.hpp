#ifndef TELA1_HPP
#define TELA1_HPP

#include "cScreen.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Random.hpp"

#include <iostream>
#include <list>
//#include <stack>
//#define Pilha std::stack
#include "Pilha.hpp"
#include "Lista.hpp"

#include "Bloco.hpp"

class Tela1:public cScreen
{
    public:
        /** Default constructor */
        Tela1(int fase=0);
        /** Default destructor */
        ~Tela1();

        /**
         * @brief Roda os componentes correspondentes a essa classe na janela
         */
        virtual int Run(sf::RenderWindow &App);
        void preenchePilha(sf::Color *arrayColors);
        void preencheBlocos(sf::Color *arrayColors);
        void preencheVidas(void);
        void limpar(void);

        void setqVidas(int _vidas);
        int getqVidas(void) const;
    protected:
    private:
        int fase;
        int qVidas; //!< @brief As vidas que o jogador possui(começa com 3)
        int pontos; //!< @brief Os pontos atuais do jogador
        int bLife; //!< @brief A quantidade de vidas de um bloco
        int mColor; //!< @brief Quantidade máxima de cores na fase
        int qPilha; //!< @brief Quantidade de elementos colocados na pilha caso ela esteja vazia
        int qBlocos; //!< @brief Quantidade de blocos em cada linha que a fase conterá
        int bonusPilha; //!< @brief Multiplicador de bonus que será dado ao jogador caso ele termine a pilha

        Random ger; //!< @brief Instancia da classe Random. Serve para gerar inteiros aleatórios

        sf::Music music;
        sf::Font font;
        sf::Text pont;

        sf::Texture lightssaber;
        sf::Sprite lightsaber;

        sf::Texture backg;
        sf::Sprite background;

        sf::RectangleShape bordaE;
        sf::RectangleShape bordaD;
        sf::RectangleShape bordaS;

        sf::CircleShape bola;

        Lista<Bloco> Blocos;
        Lista<sf::RectangleShape> Vidas;
        Pilha<sf::Color> pilha;

        sf::Text sizePilha;
        sf::RectangleShape topPilha;
};

#endif // TELA1_HPP
