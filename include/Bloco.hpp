#ifndef BLOCO_HPP
#define BLOCO_HPP

#include <SFML/Graphics.hpp>
#include "Buffer.hpp"
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

    private:
        int life;
        int type;   //!< @brief Armazena a quantidade de vida inicial do bloco
        bool hasBuffer;
};

#endif // BLOCO_HPP
