#ifndef BUFFER_HPP
#define BUFFER_HPP

#include <SFML/Graphics.hpp>

#include <stack>
#ifndefine Pilha
#define Pilha std::stack
#endif // Pilha

class Buffer : public sf::RectangleShape
{
    public:
        /** Default constructor */
        Buffer(const sf::Vector2f &size=sf::Vector2f(0,0),sf::Vector2f position=sf::Vector2f(0,0));
        /** Default destructor */
        ~Buffer();

        enum type{
            VIDA,
            DIMINUIPILHA,
            CRIABASE
        };

        void print(void);
        void evento(sf::RenderWindow &Apps, sf::RectangleShape &sabre,sf::CircleShape &bola,Pilha<sf::RectangleShape> &Vidas)
    private:
        sf::Vector2f speed;
};

#endif // BUFFER_HPP
