#ifndef TELA1_HPP
#define TELA1_HPP

#include "Pilha.hpp"
#include "Lista.hpp"
#include "Fila.hpp"

#include "Bloco.hpp"
#include "Tela.hpp"
#include "Buff.hpp"

class Tela1:public cScreen,public Tela
{
    public:
        /** Default constructor */
        Tela1(Janela &App, int fase=0);
        /** Default destructor */
        ~Tela1();

        /**
         * @brief Roda os componentes correspondentes a essa classe na janela
         */
        virtual int Run(Janela &App);
        void preenchePilha(sf::Color *arrayColors);
        void preencheBlocos(sf::Color *arrayColors);

        void preencheVidas(Janela &App);
        /**
         *
        */
        void preencheFila(void);
        /**
         *
        */
        void limpar(Janela &App);

        /**
         *
        */
        void setVidas(Janela &App,int _vidas);
        /**
         *
        */
        int getVidas(Janela &App) const;

        /**
         *
        */
        void sabreMuros(sf::Vector2i posMouseApp,bool &colidiuD,bool &colidiuE);
    private:
        int bLife; //!< @brief A quantidade de vidas de um bloco
        int mColor; //!< @brief Quantidade máxima de cores na fase
        int qPilha; //!< @brief Quantidade de elementos colocados na pilha caso ela esteja vazia
        int qBlocos; //!< @brief Quantidade de blocos em cada linha que a fase conterá
        int qBuffs; //!< @brief Quantidade de buffs que a fase conterá
        int bonusPilha; //!< @brief Multiplicador de bonus que será dado ao jogador caso ele termine a pilha
        int fase;
        int numblocos;

        Lista<Bloco> Blocos;
        Lista<sf::Sprite> Vidas;
        Pilha<sf::Color> pilha;
        Fila<Buff> buffs;

        sf::Text sizePilha;
        sf::RectangleShape topPilha;
};

#endif // TELA1_HPP
