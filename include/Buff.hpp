#ifndef BUFFER_HPP
#define BUFFER_HPP

#include <SFML/Graphics.hpp>

#include "Pilha.hpp"
#include "Lista.hpp"

#include "Player.hpp"

/**
 *\brief Um retângulo correspondente a um buff, que pode ajudar ou atrapalhar o jogador
*/
class Buff : public sf::RectangleShape
{
    public:
        bool isActive;  //!<Determina se o buff vai ser desenhado na tela principal ou não
        enum type{
            VIDA,
            DIMINUIPILHA,
            AUMENTASABRE,
            DIMINUISABRE
        };
        /** Default constructor */
        Buff(const sf::Vector2f &size=sf::Vector2f(0,0),type _tipo=VIDA);
        /** Default destructor */
        ~Buff();

        /** Move o buff
         * \brief Move o Buff
        */
        void acao(void);
        /** Se o Buff caiu ou não
         * \brief Se o Buff caiu ou não
        */
        bool caiu(void);
        /**
         *\param sabre O sabre do jogo
         *\param jogador O objeto correspondente ao jogador atual
         *\param pilha A pilha de cores
        */
        void colidiuSabre(sf::Sprite &sabre, Player &jogador, Pilha<sf::Color> &pilha);

    private:
        sf::Vector2f speed; //!<Velocidade de caída do Buff
        type tipo;      //!<Tipo do Buff
};

#endif // BUFFER_HPP
