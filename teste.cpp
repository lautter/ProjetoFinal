#include "cScreen.hpp"      //Para o vetor de telas
#include "Menu.hpp"         //Menu
#include "Tela1.hpp"        //Tela

#include <iostream>         //
#include <fstream>          //Arquivos
#include <stdio.h>
#include <vector>           //Vetor de scores e de Janelas

#include <SFML/Graphics.hpp>//SFML
#include "Janela.hpp"
#include "Player.hpp"

#define altura 720
#define largura 1200
#define ENTRADA "./Scores"

int main(void)
{
    //Manipulação dos scores
	std::ifstream inputFile;
    std::ofstream outputFile;
    char buff[500];
    char nome[100];
    int pontos;
    int fase;

    //Scores
    std::vector<Player> scores;

    //Leitura de arquivo e gravação da lista de players
    inputFile.open(ENTRADA);
    while(!inputFile.fail()){
		Player p;
		inputFile.getline(buff, 500);

        sscanf(buff,"%s %i %i",nome,&fase,&pontos);

        std::string name(nome);
        if(name!=""){
            p.setNome(name);
            p.setPontos(pontos);
            p.setFase(fase);
            scores.push_back(p);
        }
    }
    inputFile.close();

    //Applications variables
    std::vector<cScreen*> Screens;

    //Window creation
    Janela App(sf::VideoMode(largura,altura), "STARKANOID",sf::Style::Close);

    App.setBestScores(scores);

    //Mouse cursor no more visible
    App.setMouseCursorVisible(false);
    App.setFramerateLimit(60);

    Menu menu(largura,altura);
    Tela1 tela(App,0);
    Tela1 tela2(App,1);
    Tela1 tela3(App,2);

    Screens.push_back(&menu);
    Screens.push_back(&tela);
    Screens.push_back(&tela2);
    Screens.push_back(&tela3);

    for(int i=0;i>=0 && i<4;i=Screens[i]->Run(App)){

    }

    outputFile.open(ENTRADA,std::ifstream::trunc);
    for(unsigned int i=0;i<App.getBestScores().size();i++){
        //BestScores guarda os 10 melhores + os correntes
        outputFile<<App.getBestScores()[i].getNome()<<std::endl;
        outputFile<<App.getBestScores()[i].getFase()<<std::endl;
        outputFile<<App.getBestScores()[i].getPontos()<<std::endl;
	}
    return EXIT_SUCCESS;
}

