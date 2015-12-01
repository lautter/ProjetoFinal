#ifndef MENU_HPP
#define MENU_HPP
#include "cScreen.hpp"
#include <SFML/Graphics.hpp>

#define QMENUOPTIONS 3
/**
 *@brief Classe que cria um menu
 */
class Menu: public cScreen
{
    public:
        /** Construtor de Menu */
        Menu(float width=1200, float height=720);
        /** Destrutor de Menu */
        ~Menu();

        void moveUp(void);
        void moveDown(void);
        /**
         * @brief Roda os componentes correspondentes a essa classe na janela
        */
        virtual int Run(sf::RenderWindow &App);
    private:
        int selectedItem; //!<Guarda o item do menu selecionado
        sf::Font font; //!<Atributo que guarda informações sobre a fonte que será usada na classe
        sf::Text menu[QMENUOPTIONS];   //!<Array de textos correspondentes às opções do Menu
};

#endif // MENU_HPP
