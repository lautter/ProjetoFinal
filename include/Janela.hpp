#ifndef JANELA_HPP
#define JANELA_HPP

#include <SFML/Graphics.hpp>

#include "Player.hpp"
#include <vector>
class Janela : public sf::RenderWindow
{
    public:
        /** Default constructor */
        Janela(sf::VideoMode mode, const sf::String &title, sf::Uint32 style=sf::Style::Default, const sf::ContextSettings &settings=sf::ContextSettings());
        /** Default destructor */
        ~Janela();
        /** A reference of jogador attribute
         * \return The current value of jogador
         */
        Player &getJogador(void);
        /** Set jogador
         * \param _jogador New value to set
         */
        void setJogador(Player _jogador);
        /** Set bestScores
         * \param _scores a vector of players
         */
        void setBestScores(std::vector<Player> _scores);
        /** Set bestScores
         */
        void setBestScores(void);
        /** A reference of scores attribute
         * \return The current value of jogador
         */
        std::vector<Player> &getBestScores(void);

    private:
        Player jogador; //!<Jogador atual
        //Caso mude, mudar serBestScores
        std::vector<Player> bestScores; //!< 10 melhores scores + os scores armazenados

};

#endif // JANELA_HPP
