#include "Player.hpp"

Player::Player(std::string _nome,int _pontos,int _vidas,int _fase)
{
    nome=_nome;
    pontos=_pontos;
    vidas=_vidas;
    fase=_fase;
}

Player::~Player()
{
    //dtor
}

std::string Player::getNome(void) const { return nome; }

void Player::setNome(std::string val) { nome = val; }

int Player::getPontos(void) const { return pontos; }

void Player::setPontos(int val) { pontos = val; }

int Player::getVidas(void) const{ return vidas; }

void Player::setVidas(int val) { vidas = val; }

int Player::getFase(void) const{ return fase; }

void Player::setFase(int val) { fase = val; }

bool Player::operator< (Player rhs) const{
    return (this->pontos<rhs.getPontos());
}
void Player::limpa(void){
    nome="Player";
    pontos=0;
    vidas=3;
    fase=0;
}
