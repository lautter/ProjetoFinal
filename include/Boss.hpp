#ifndef BOSS_HPP
#define BOSS_HPP
#include <iostream>
#include <SFML/Graphics.hpp>


class Boss : public sf::Sprite
{
    public:
        Boss();
        ~Boss();
        enum modo{
            ZANGADO,
            PUTO
        };
        int operator--(void);
        int getVidas();
    private:
        sf::Texture textura;
        int vidas;
        modo mAtual;
};

#endif // BOSS_HPP
