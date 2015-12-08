#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <iostream>

class Player
{
    public:
        /** Initialized constructor
         *\param _nome será o valor do atributo nome
         *\param _pontos será o valor do atributo pontos
         *\param _vidas será o valor do atributo vidas
         *\param _fase será o valor do atributo fase
        */
        Player(std::string _nome="Player",int _pontos=0,int _vidas=3,int _fase=0);
        /** Default destructor */
        ~Player();
        /** Access nome
         * \return The current value of nome
         */
        std::string getNome(void) const;
        /** Set nome
         * \param val New value to set
         */
        void setNome(std::string val);
        /** Access pontos
         * \return The current value of pontos
         */
        int getPontos(void) const;
        /** Set pontos
         * \param val New value to set
         */
        void setPontos(int val);
        /** Access vidas
         * \return The current value of vidas
         */
        int getVidas(void) const;
        /** Set vidas
         * \param val New value to set
         */
        void setVidas(int val);
        /** Access fase
         * \return The current value of fase
         */
        int getFase(void) const;
        /** Set fase
         * \param val New value to set
         */
        void setFase(int val);
        /**Overload of operator<
         *\param rhs A Player Object what will be compared to this Player
         */
        bool operator< (Player rhs) const;
        /** Set attibutes to default values
         */
        void limpa(void);

    private:
        std::string nome; //!< Nome do jogador
        int pontos; //!< Pontos feitos pelo jogador
        int vidas; //!< Vidas restantes do jogador-1 (Pois existe a vida 0)
        int fase; //!< Fase atual do jogador
};

#endif // PLAYER_HPP
