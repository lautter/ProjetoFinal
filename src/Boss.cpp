#include "Boss.hpp"

Boss::Boss()
{
    if(textura.loadFromFile("006Charizard_OS_anime.png"))
        std::cout<<"NIONIODMSA";
    mAtual=PUTO;
    setTexture(textura);
    setPosition(600,300);
    setScale(0.3,0.3);
    vidas=30;
}

Boss::~Boss()
{
    //dtor
}

int Boss::operator--(void){
    return --vidas;
}
int Boss::getVidas(){return vidas;}
