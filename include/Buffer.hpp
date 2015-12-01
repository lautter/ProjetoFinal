#ifndef BUFFER_HPP
#define BUFFER_HPP

#include <SFML/Graphics.hpp>

#include "Pilha.hpp"
#include "Lista.hpp"

class Buffer : public sf::RectangleShape
{
    public:
        enum type{
            VIDA,
            DIMINUIPILHA
        };
        /** Default constructor */
        Buffer(const sf::Vector2f &size=sf::Vector2f(0,0),sf::Vector2f position=sf::Vector2f(0,0),type _tipo=VIDA);
        /** Default destructor */
        ~Buffer();

        void print(void);
        /**@brief Realiza o evento do sabre
        */
        void evento(sf::RenderWindow &Apps, sf::RectangleShape &sabre,sf::CircleShape &bola,Lista<sf::RectangleShape> &Vidas);
    private:
        sf::Vector2f speed;
        type tipo;
};

#endif // BUFFER_HPP
