#ifndef BUFFER_HPP
#define BUFFER_HPP

#include <SFML/Graphics.hpp>

#include "Pilha.hpp"

class Buffer : public sf::RectangleShape
{
    public:
        enum type{
            VIDA,
            DIMINUIPILHA,
            CRIABASE
        };
        /** Default constructor */
        Buffer(const sf::Vector2f &size=sf::Vector2f(0,0),sf::Vector2f position=sf::Vector2f(0,0),type _tipo=0);
        /** Default destructor */
        ~Buffer();

        void print(void);
        void evento(sf::RenderWindow &Apps, sf::RectangleShape &sabre,sf::CircleShape &bola,Pilha<sf::RectangleShape> &Vidas);
    private:
        sf::Vector2f speed;
        type tipo;
};

#endif // BUFFER_HPP
