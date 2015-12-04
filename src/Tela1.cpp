#include "Tela1.hpp"
#include <iostream>
#include <string>
#include <sstream>
#define NUMBLOCOS 4
Tela1::Tela1(int _fase)
{
    fase=_fase;
    qPilha=4+fase*2;
    qVidas=3;
    pontos=0;
    bLife=1+fase;
    mColor=4+fase;
    bonusPilha=1;
    qBlocos=7;

    //Fonte
    if(/*!font.loadFromFile("/usr/share/fonts/truetype/ubuntu-font-family/Ubuntu-M.ttf")&&*/!font.loadFromFile("C:/Windows/Fonts/Arial.ttf"))
        std::cout<<"Fonte no encontrada!!"<<std::endl;

    //Music
    if(!music.openFromFile("S31-Hit and Run.ogg"))
        std::cout << "Não deu pra abrir a música caras..." << std::endl;
    if(!laser1.openFromFile("laserfire01.ogg"))
        std::cout << "Não deu pra abrir o som do laser1..." << std::endl;
    if(!laser2.openFromFile("laserfire02.ogg"))
        std::cout << "Não deu pra abrir o som do laser2..." << std::endl;

    //Sabre
    if(!lightssaber.loadFromFile("lightsaber2.png"))
        std::cout << "Nao foi possivel carregar lightsaber.png" << std::endl;
    lightsaber.setTexture(lightssaber);
    lightsaber.rotate(180);

    //background
    if(!backg.loadFromFile("parallax-space-backgound.png"))
        std::cout << "Não foi possivel carregar background!" << std::endl;
    background.setTexture(backg);
    background.setScale(6.f,6.f);
    if(!bigPlanet.loadFromFile("parallax-space-big-planet.png"))
        std::cout << "Não foi possivel carregar big planet!" << std::endl;
    bPlanet.setTexture(bigPlanet);
    bPlanet.setScale(4.f,4.f);
    bPlanet.setPosition(1300.f,350);
    if(!farPlanet.loadFromFile("parallax-space-far-planets.png"))
        std::cout << "Não foi possivel carregar far planets!" << std::endl;
    fPlanet.setTexture(farPlanet);
    fPlanet.setScale(3.f,3.f);
    fPlanet.setPosition(900.f,80.f);
    if(!ringPlanet.loadFromFile("parallax-space-ring-planet.png"))
        std::cout << "Não foi possivel carregar ring planet!" << std::endl;
    rPlanet.setTexture(ringPlanet);
    rPlanet.setScale(4.f,4.f);
    rPlanet.setPosition(1000.f,300.f);
    if(!starRs.loadFromFile("parallax-space-stars.png"))
        std::cout << "Não foi possivel carregar stars!" << std::endl;
    stars.setTexture(starRs);
    stars2.setTexture(starRs);
    stars.setPosition(55.f,55.f);
    stars.setScale(4.f,4.f);
    stars2.setPosition(800.f,70.f);
    stars2.setScale(3.f,3.f);

    /*bordaE.setSize(sf::Vector2f(50,720));
    bordaE.setPosition(0.f,0.f);
    bordaE.setFillColor(sf::Color(255,255,255));

    bordaD.setSize(sf::Vector2f(50,720));
    bordaD.setPosition(1150.f,0.f);
    bordaD.setFillColor(sf::Color(255,255,255));

    bordaS.setSize(sf::Vector2f(1100,50));
    bordaS.setPosition(50.f,0.f);
    bordaS.setFillColor(sf::Color(255,255,255));

    bola.setFillColor(sf::Color::White);
    bola.setRadius(4);

    pont.setFont(font);
    pont.setColor(sf::Color(0,0,0));
    pont.setString("Pontos: "+to_string(pontos));
    pont.setPosition(950,10);

    sizePilha.setFont(font);
    sizePilha.setColor(sf::Color(0,0,0));
    sizePilha.setString(to_string(pilha.size()));
    sizePilha.setPosition(750,10);

    topPilha.setSize(sf::Vector2f(20,20));
    topPilha.setPosition(800,10);*/
}
Tela1::~Tela1()
{
    //dtor
}


int Tela1::Run(sf::RenderWindow &App,int &lifes,int &_pontos,bool flag,char b[]){
    std::cout<<fase<<std::endl;
    limpar();
    std::cout<<fase<<std::endl;
    if(flag){
        qVidas=lifes;
        pontos=_pontos;
    }
    #define MULTIPLICADOR 100
    //posicao inicial do mouse em relacao a janela
    sf::Mouse::setPosition(sf::Vector2i(300, 250),App);
    music.play();

    //Definindo array de colors
    sf::Color arrayColors[mColor];
    for(int i=0;i<mColor;i++)
        arrayColors[i]=sf::Color(ger.getInt(0,255),ger.getInt(0,255),ger.getInt(0,255));

    preencheBlocos(arrayColors);
    preenchePilha(arrayColors);
    preencheVidas();

    sf::Vector2f speed(0.f,0.f);

    //sf::Vector2i eh um vetor 2d de inteiros e a função getPosition retorna um sf::Vector2i
    sf::Vector2i posMouseApp;

    //colidiu?
    bool colidiuE=false; //colidiu borda esquerda?
    bool colidiuD=false;  //colidiu borda direita?

    // --------- eventos e logica do jogo
    while (App.isOpen())
    {
        lifes=qVidas;
        _pontos=pontos;
        sf::Event event;
        while (App.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)))
                App.close();
        }

        /// MOVIMENTO DA PÁ
        posMouseApp = sf::Mouse::getPosition(App); // posição mouse em relação à janela
        //se o sabre não colidiu com as bordas segue o ponteiro do mouse
        if(!colidiuE && !colidiuD){
            lightsaber.setPosition(posMouseApp.x+50,670);
        }
        // se o sabre colide com a borda direita
        if(lightsaber.getPosition().x<50+100)/*borda+sabre*/
        {
            lightsaber.setPosition(/*bordaE.getPosition().x+*/150, lightsaber.getPosition().y);
            colidiuD = true;
        }
        // se o sabre colide com a borda esquerda
        else if(lightsaber.getPosition().x>1200-50/*janela-borda*/)
        {
            lightsaber.setPosition(1200-50, lightsaber.getPosition().y);
            colidiuE = true;
        }
        else // nao colidimos
        {
            colidiuE = false;
            colidiuD = false;
        }
        /*****************************************************************************/


        ///Bola
        if(speed.x==0.f&&speed.y==0.f){
            bola.setPosition(600,460);
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
                speed.x=0.f;
                speed.y=5.f;
            }
        }
        else
            bola.setPosition(bola.getPosition().x+speed.x,bola.getPosition().y+speed.y);
        // verifica colisao bordas
        if(bordaD.getGlobalBounds().intersects((bola.getGlobalBounds())))
        {
            speed.x*=(-1);
        }
        if(bordaE.getGlobalBounds().intersects((bola.getGlobalBounds())))
        {
            speed.x *=(-1);
        }
        if(bordaS.getGlobalBounds().intersects((bola.getGlobalBounds())))
            speed.y *=(-1);

        // colisao sabre de luz
        /**************************************************/

        if(lightsaber.getGlobalBounds().intersects((bola.getGlobalBounds())))
        {
            laser2.play();
            if(bola.getPosition().y<lightsaber.getPosition().y){
                speed.y *=(-1);

                float a=bola.getPosition().x-(lightsaber.getPosition().x-50);
                if(a<-10){//Lado esquerdo
                    a*=-1;
                    if(speed.x>0)
                        speed.x-=a*0.1;
                    else
                        speed.x-=a*0.1;
                }else if(a>10){//Lado direito
                    if(speed.x>0)
                        speed.x+=a*0.1;
                    else
                        speed.x+=a*0.1;
                }
            }else
                    speed.x*=-1;
        }

        //Controle de velocidade
        if(speed.x>7){speed.x-=1;}
        if(speed.x<-7){speed.x+=1;}
        if(speed.y>7){speed.y-=1;}
        if(speed.y<-7){speed.y+=1;}

        //Bola caindo
        if(bola.getPosition().y >= 720)
        {

            speed.x=0;
            speed.y=0;
            bola.setPosition(lightsaber.getPosition().x-70,lightsaber.getPosition().y-10);
            if(!Vidas.empty())
                Vidas.pop_back();
            else break;
        }
        //Evento dos blocos
        for(Lista<Bloco>::iterator i=Blocos.begin();i!=Blocos.end();i++){
             if(i->getGlobalBounds().intersects(bola.getGlobalBounds())){
                 laser1.play();
                 if(bola.getPosition().y>i->getPosition().y&&bola.getPosition().y<i->getPosition().y+25){
                     speed.x*=-1;
                     }
                 else{
                     speed.y*=-1;
                 }
                 --(*i);
                 //Olhar essa parte
                 ///Mesmo sem quebrar o bloco, a pilha é alterada
                 if(!pilha.empty()){
                     if(i->getFillColor()==pilha.top())
                         pilha.pop();
                     else
                         pilha.push(i->getFillColor());
                 }else{
                     preenchePilha(arrayColors);
                     pontos+=bonusPilha*MULTIPLICADOR;
                 }
                 if(i->getLife()==0){
                     pontos+=10*i->getType();
                     i=Blocos.erase(i);
                 }
             }
        }

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

        pont.setString("Pontos: "+to_string(pontos));
        App.draw(pont);

        sizePilha.setString(to_string(pilha.size()));
        App.draw(sizePilha);
        ////Pilha
        if(!pilha.empty())
            topPilha.setFillColor(pilha.top());
        else
            preenchePilha(arrayColors);
        App.draw(topPilha);

        for(Lista<sf::RectangleShape>::iterator i=Vidas.begin();i!=Vidas.end();i++)
             App.draw(*i);

         //Desenhando blocos
         for(Lista<Bloco>::iterator i=Blocos.begin();i!=Blocos.end();i++)
             App.draw(*i);


        App.display();
        if(Blocos.empty()){
            music.stop();
            return fase+2;
        }

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
//Definindo Lista de vidas
void Tela1::preencheVidas(void){
    for(int i=0;i<qVidas;i++){
        sf::RectangleShape vida(sf::Vector2f(20,20));
        vida.setFillColor(sf::Color((255), (0), (0))); //colore com branco tabela de cores http://www.ufpa.br/dicas/htm/htm-cor2.htm
        vida.setPosition(100+i*40,10); //seta a posicao
        Vidas.push_back(vida);
    }
}

//Adicionando blocos na lista
void Tela1::preencheBlocos(sf::Color *arrayColors){
    for(int j=0;j<NUMBLOCOS;j++){
        for(int i=0;i<qBlocos;i++){
            Bloco bloco(sf::Vector2f(110,30));
            bloco.setFillColor(arrayColors[ger.getInt(0,mColor-1)]); //colore com branco tabela de cores http://www.ufpa.br/dicas/htm/htm-cor2.htm
            //Blocos[i].setOutlineThickness(10); //
            //Blocos[i].setOutlineColor(sf::Color(85, 23, 139));
            bloco.setPosition(100+i*140,100+40*j);
            bloco.setLife(bLife);
            Blocos.push_back(bloco);
        }
    }
}
void Tela1::setqVidas(int _vidas){
    qVidas=_vidas;
}
int Tela1::getqVidas(void) const{
    return qVidas;
}

void Tela1::limpar(void){
    qPilha=3+fase*2;
    qVidas=3;
    pontos=0;
    bLife=1+fase;
    mColor=4+fase;
    bonusPilha=1;
    qBlocos=7;

    bordaE.setSize(sf::Vector2f(50,720));
    bordaE.setPosition(0.f,0.f);
    bordaE.setFillColor(sf::Color(0,0,0));

    bordaD.setSize(sf::Vector2f(50,720));
    bordaD.setPosition(1150.f,0.f);
    bordaD.setFillColor(sf::Color(0,0,0));

    bordaS.setSize(sf::Vector2f(1100,50));
    bordaS.setPosition(50.f,0.f);
    bordaS.setFillColor(sf::Color(0,0,0));

    bola.setFillColor(sf::Color::White);
    bola.setRadius(4);

    pont.setFont(font);
    pont.setColor(sf::Color(0,0,0));
    pont.setString("Pontos: "+to_string(pontos));
    pont.setPosition(950,10);

    sizePilha.setFont(font);
    sizePilha.setColor(sf::Color(0,0,0));
    sizePilha.setString(to_string(pilha.size()));
    sizePilha.setPosition(750,10);

    topPilha.setSize(sf::Vector2f(20,20));
    topPilha.setPosition(800,10);

    pilha.clear();
    Blocos.clear();
    Vidas.clear();
}
std::string Tela1::to_string(int i){
    std::stringstream s;
    std::string a="";
    s<<i;
    a+=s.str();
    return a;
}
