#ifndef BLOCO_HPP
#define BLOCO_HPP

#include <SFML/Graphics.hpp>
#include "Buff.hpp"
class Bloco : public sf::RectangleShape
{
    public:
        /** Default constructor */
        Bloco(const sf::Vector2f &size=sf::Vector2f(0, 0));
        /** Default destructor */
        ~Bloco();

        int operator--(void);

        void setLife(int _life);
        int getLife(void) const;

        void setType(int _type);
        int getType(void) const;

        bool hasBuff;
    private:
        int life;
        int type;   //!< @brief Armazena a quantidade de vida inicial do bloco

};

#endif // BLOCO_HPP
