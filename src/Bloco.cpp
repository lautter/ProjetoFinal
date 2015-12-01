#include "Bloco.hpp"

Bloco::Bloco(const sf::Vector2f &size):sf::RectangleShape(size)
{
    life=1;
    type=1;
    hasBuffer=false;
}

Bloco::~Bloco()
{
    //dtor
}

int Bloco::operator--(void){
    return --life;
}

void Bloco::setLife(int _life){
    life=_life;
}
int Bloco::getLife(void) const{
    return life;
}

void Bloco::setType(int _type){
    type=_type;
    life=_type;
}
int Bloco::getType(void) const{
    return life;
}
