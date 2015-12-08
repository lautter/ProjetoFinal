#ifndef CSCREEN_HPP
#define CSCREEN_HPP
#include <SFML/Graphics.hpp>
#include "Janela.hpp"
class cScreen
{
    public:
        virtual int Run(Janela &App)=0;
};

#endif // CSCREEN_HPP
