#ifndef BOLA_HPP
#define BOLA_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "Player.hpp"
#include "Lista.hpp"
#include "Fila.hpp"
#include "Pilha.hpp"
#include "Bloco.hpp"
#include "Buff.hpp"

class Bola : public sf::CircleShape
{
    public:
        Bola(float radius=0, unsigned int pointCount=30);
        ~Bola();
        void colidiu(Lista<Bloco> &blocos,Fila<Buff> &buffs,Player &jogador,Pilha<sf::Color> &pilha);
        void colidiu(sf::Sprite sabre);
        void colidiu(void);
        void acao(Player &jogador);
        void setSpeed(sf::Vector2f vetor);
    private:
        sf::Vector2f speed;
        sf::Music laser1;
        sf::Music laser2;
};

#endif // BOLA_HPP
