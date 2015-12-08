#include "Janela.hpp"

Janela::Janela(sf::VideoMode mode, const sf::String &title, sf::Uint32 style, const sf::ContextSettings &settings):
                sf::RenderWindow(mode,title,style,settings)
{

}

Janela::~Janela()
{
    //dtor
}
Player& Janela::getJogador(void){return jogador;}

void Janela::setJogador(Player _jogador){jogador=_jogador;}

void Janela::setBestScores(std::vector<Player> _scores){
    if(!_scores.empty()){
        std::sort(_scores.begin(),_scores.end());
        for(unsigned int i=0;i<10&&i<_scores.size();i++)
            bestScores.push_back(_scores[i]);
            std::cout<<"QWYEWUQIYdsasdasd"<<bestScores[0].getNome()<<std::endl;
            std::cout<<"QWYEWUQIY"<<_scores[0].getNome()<<std::endl;
    }
}
void Janela::setBestScores(void){
    bestScores.push_back(this->jogador);
    std::sort(bestScores.begin(),bestScores.end());
}

std::vector<Player>& Janela::getBestScores(void){return bestScores;}
