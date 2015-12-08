#include "Buff.hpp"

Buff::Buff(const sf::Vector2f &size,type _type) : sf::RectangleShape(size)
{
    speed.y=5;
    isActive=false;
    tipo=_type;
    switch(tipo){
        case VIDA: setFillColor(sf::Color(255,0,0)); break;
        case DIMINUIPILHA: setFillColor(sf::Color(255,0,255)); break;
        case DIMINUISABRE: setFillColor(sf::Color(255,0,255)); break;
        case AUMENTASABRE: setFillColor(sf::Color(0,255,0)); break;
    }
}

Buff::~Buff()
{
    //dtor
}

void Buff::acao(void){
    this->setPosition(this->getPosition().x,this->getPosition().y+speed.y);
}

bool Buff::caiu(void){
    return(this->getPosition().y>=720);
}

void Buff::colidiuSabre(sf::Sprite &sabre, Player &jogador, Pilha<sf::Color> &pilha){
    if(this->getGlobalBounds().intersects(sabre.getGlobalBounds())){
        switch(this->tipo){
            case VIDA: jogador.setVidas(jogador.getVidas()+1); break;
            case DIMINUIPILHA: if(!pilha.empty()) pilha.pop(); break;
            case AUMENTASABRE: sabre.scale(1.5,1);
            case DIMINUISABRE: sabre.scale(0.5,1);
        }
        this->isActive=false;
    }
}
