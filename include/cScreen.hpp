#ifndef CSCREEN_HPP
#define CSCREEN_HPP
#include <SFML/Graphics.hpp>

class cScreen
{
    public:
        /** Default constructor */
        virtual int Run(sf::RenderWindow &App)=0;
};

#endif // CSCREEN_HPP
