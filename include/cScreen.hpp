#ifndef CSCREEN_HPP
#define CSCREEN_HPP
#include <SFML/Graphics.hpp>

class cScreen
{
    public:
        virtual int Run(sf::RenderWindow &App,int &lifes,int &pontos)=0;
};

#endif // CSCREEN_HPP
