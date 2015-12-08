#include "Tela1.hpp"
#include <iostream>
#include <SFML/Audio.hpp>
#include "Boss.hpp"

#ifndef DIMENSOES
#define LARGURAJ 1200
#define ALTURAJ 720
#define BORDA 50
#endif // DIMENSOES
#define MULTIPLICADOR 100

#define MAXBUFFS 4
Tela1::Tela1(Janela &App, int _fase):Tela(App)
{
    App.getJogador().setFase(_fase);
    fase=_fase;
    qPilha=4+fase*2;
    bLife=1+fase;
    mColor=4+fase;
    bonusPilha=fase+1;
    qBlocos=7;

    numblocos=4+fase;
    qBuffs=numblocos;

    sizePilha.setFont(font);
    sizePilha.setColor(sf::Color(255,255,255));
    sizePilha.setString(to_string(pilha.size()));
    sizePilha.setPosition(750,10);

    topPilha.setSize(sf::Vector2f(20,20));
    topPilha.setPosition(800,10);
}
Tela1::~Tela1()
{
    //dtor
}


int Tela1::Run(Janela &App){
    limpar(App);

    sf::Mouse::setPosition(sf::Vector2i(300, 250),App);
    music.play();


    ///Preenchimento
    sf::Color arrayColors[mColor];
    int p=ger.getInt(50,255);
    for(int i=0;i<mColor;i++)
        arrayColors[i]=sf::Color((p*i)%255,(p+i*100)%255,(p*200)%255);

    preencheBlocos(arrayColors);
    preenchePilha(arrayColors);
    preencheVidas(App);
    preencheFila();
    /**********************************************************************/


    ///Controle de muros
    sf::Vector2i posMouseApp;
    bool colidiuE=false; //colidiu borda esquerda?
    bool colidiuD=false;  //colidiu borda direita?
    /**********************************************************************/




    // --------- eventos e logica do jogo
    while (App.isOpen())
    {
        sf::Event event;
        while (App.pollEvent(event))
        {
            if (event.type == sf::Event::Closed /*|| (sf::Keyboard::is(sf::Keyboard::Key::Escape))*/){
                App.close();

            }
        }

        /// MOVIMENTO DA PÁ
        posMouseApp = sf::Mouse::getPosition(App); // posição mouse em relação à janela
        sabreMuros(posMouseApp,colidiuD,colidiuE);
        /*****************************************************************************/

        /// Bola
        bola.acao(App.getJogador());
        bola.colidiu(Blocos,buffs,App.getJogador(),pilha);
        bola.colidiu(lightsaber);
        bola.colidiu();
        /*****************************************************************************/

        ///Buff
        if(!buffs.empty()){
            if(buffs.front().isActive){
                buffs.front().acao();
                buffs.front().colidiuSabre(lightsaber,App.getJogador(),pilha);
            }
        }
        /*****************************************************************************/


        ///Atualiza Coisas
        preencheVidas(App);
        pont.setString("Pontos: "+to_string(App.getJogador().getPontos()));

        //Texto da Pilha
        if(!pilha.empty()) sizePilha.setString(to_string(pilha.size()));

        //Pilha
        if(!pilha.empty()) topPilha.setFillColor(pilha.top());

        /*****************************************************************************/

        ///Verifica coisas
        if(pilha.empty()){
             //preenchePilha(arrayColors);
             //App.getJogador().setPontos(App.getJogador().getPontos()+bonusPilha*MULTIPLICADOR);
             music.stop();
             bola.setPosition(600,300);
             bola.setSpeed(sf::Vector2f(0,0));
             return fase+2;
        }
        if(Blocos.empty()){
            music.stop();
            bola.setPosition(600,300);
            bola.setSpeed(sf::Vector2f(0,0));
            return fase+2;
        }
        if(Vidas.empty()){
            music.stop();
            App.setBestScores();
            break;
        }

        if(!buffs.empty()){
            if(buffs.front().isActive){
                if(buffs.front().caiu()){
                    Buff tmp=buffs.front();
                    buffs.pop();
                    tmp.isActive=false;
                    buffs.push(tmp);
                }
            }
        }
        /*****************************************************************************/


        // ------------ Desenho
        App.clear(sf::Color::White);
        App.draw(background);
        App.draw(stars2);

        // parallax
        stars.setPosition(stars.getPosition().x-0.1,stars.getPosition().y);
        if(stars.getPosition().x<-1000)
            stars.setPosition(1100,stars.getPosition().y);
        fPlanet.setPosition(fPlanet.getPosition().x-0.3,fPlanet.getPosition().y);
        if(fPlanet.getPosition().x<-1000)
            fPlanet.setPosition(1200,fPlanet.getPosition().y);
        rPlanet.setPosition(rPlanet.getPosition().x-0.7,rPlanet.getPosition().y);
        if(rPlanet.getPosition().x<-800)
            rPlanet.setPosition(1100,rPlanet.getPosition().y);
        bPlanet.setPosition(bPlanet.getPosition().x-1,bPlanet.getPosition().y);
        if(bPlanet.getPosition().x<-800)
            bPlanet.setPosition(1200,bPlanet.getPosition().y);

        App.draw(stars);
        App.draw(fPlanet);
        App.draw(rPlanet);
        App.draw(bPlanet);
        App.draw(lightsaber);
        App.draw(bordaE);
        App.draw(bordaD);
        App.draw(bordaS);
        App.draw(bola);

        App.draw(pont);
        App.draw(sizePilha);
        App.draw(topPilha);

        for(Lista<sf::Sprite>::iterator i=Vidas.begin();i!=Vidas.end();i++)
            App.draw(*i);
        for(Lista<Bloco>::iterator i=Blocos.begin();i!=Blocos.end();i++)
            App.draw(*i);

        if(!buffs.empty())
            if(buffs.front().isActive)
                App.draw(buffs.front());

        App.display();
    }

    ///////////////////////////////////////////////////////////////////
    sf::Text text;
    text.setFont(font);
    text.setColor(sf::Color::White);
    text.setString("GAME OVER!!");
    text.setPosition(sf::Vector2f(1200/2-100,720/2-20));

    sf::Text text2;
    text2.setFont(font);
    text2.setColor(sf::Color::Red);
    text2.setString("PLAY AGAIN?");
    text2.setPosition(sf::Vector2f(1200/2-100,720/2+20));

    while(App.isOpen()){
        sf::Event event;
        while (App.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                App.close();
            if (event.type == sf::Event::KeyReleased)
            {
                if (event.key.code == sf::Keyboard::Return){
                    return 0;
                }
            }
        }
        App.clear();

        App.draw(text);
        App.draw(text2);
        App.draw(bordaE);
        App.draw(bordaD);
        App.draw(bordaS);
        App.display();
    }

    return -1;
}

//Definindo Pilha
void Tela1::preenchePilha(sf::Color *arrayColors){
    qPilha++;
    bonusPilha++;
    for(int i=0;i<qPilha;i++)
        pilha.push(arrayColors[ger.getInt(0,mColor-1)]);
}
//Definindo Fila
void Tela1::preencheFila(void){
    for(int i=0;i<MAXBUFFS;i++){
        int a=ger.getInt(0,MAXBUFFS-1);
        //std::cout<<a<<std::endl;
        switch(a){
            case 0: buffs.push(Buff(sf::Vector2f(20,20),Buff::VIDA)); break;
            case 1: buffs.push(Buff(sf::Vector2f(20,20),Buff::DIMINUIPILHA)); break;
            case 2: buffs.push(Buff(sf::Vector2f(20,20),Buff::AUMENTASABRE)); break;
            case 3: buffs.push(Buff(sf::Vector2f(20,20),Buff::DIMINUISABRE)); break;
        }
    }
}
//Definindo Lista de vidas
void Tela1::preencheVidas(Janela& App){
    for(int i=Vidas.size();i!=getVidas(App);){
        if(i>getVidas(App)){
            if(!Vidas.empty())
                Vidas.pop_back();
            i--;
        }
        else{
            sf::Sprite vida;
            vida.setTexture(textura);
            vida.setScale(0.2,0.2);
            vida.setPosition(100+i*40,10); //seta a posicao
            Vidas.push_back(vida);
            i++;
        }
    }
}

//Adicionando blocos na lista
void Tela1::preencheBlocos(sf::Color *arrayColors){
    int vbuffs[qBuffs];
    for(int i=0;i<qBuffs;i++){
        vbuffs[i]=ger.getInt(0,qBuffs-1);
    }
    for(int j=0;j<numblocos;j++){
        for(int i=0;i<qBlocos;i++){
            Bloco bloco(sf::Vector2f(110,30));
            bloco.setFillColor(arrayColors[ger.getInt(0,mColor-1)]); //colore tabela de cores http://www.ufpa.br/dicas/htm/htm-cor2.htm
            bloco.setPosition(100+i*140,100+40*j);
            bloco.setLife(bLife);
            if(i==vbuffs[j])
                bloco.hasBuff=true;
            Blocos.push_back(bloco);
        }
    }
}
void Tela1::setVidas(Janela &App, int _vidas){
    App.getJogador().setVidas(_vidas);
}
int Tela1::getVidas(Janela &App) const{
    return App.getJogador().getVidas();
}

void Tela1::limpar(Janela &App){
    qPilha=3+fase*2;
    bLife=1+fase;
    mColor=4+fase;
    bonusPilha=1;
    qBlocos=7;

    lightsaber.setScale(1,1);
    pilha.clear();
    Blocos.clear();
    Vidas.clear();

    while(!buffs.empty())
        buffs.pop();

    sizePilha.setString(to_string(pilha.size()));
}


void Tela1::sabreMuros(sf::Vector2i posMouseApp,bool &colidiuD,bool &colidiuE){
    //se o sabre não colidiu com as bordas segue o ponteiro do mouse
    if(!colidiuE && !colidiuD){
        lightsaber.setPosition(posMouseApp.x+BORDA,670);
    }
    // se o sabre colide com a borda esquerda
    if(lightsaber.getPosition().x<BORDA+100*lightsaber.getScale().x)/*borda+sabre*/
    {
        lightsaber.setPosition(/*bordaE.getPosition().x+*/BORDA+100*lightsaber.getScale().x, lightsaber.getPosition().y);
        colidiuD = true;
    }
    // se o sabre colide com a borda direita
    else if(lightsaber.getPosition().x>LARGURAJ-BORDA/*janela-borda*/)
    {
        lightsaber.setPosition(LARGURAJ-BORDA, lightsaber.getPosition().y);
        colidiuE = true;
    }
    else // nao colidimos
    {
        colidiuE = false;
        colidiuD = false;
    }
}
