#include "Bola.hpp"
#define MAXVELOCIDADE 7
#define MINVELOCIDADE 1
#define BOLARADIUS 4


#ifndef DIMENSOES
#define LARGURAJ 1200
#define ALTURAJ 720
#define BORDA 50
#endif // DIMENSOES

Bola::Bola(float radius, unsigned int pointCount):sf::CircleShape(radius,pointCount)
{
    speed.x=0.f;
    speed.y=0.f;

    setRadius(BOLARADIUS);

    if(!laser1.openFromFile("laserfire01.ogg"))
        std::cout << "Não deu pra abrir o som do laser1..." << std::endl;
    if(!laser2.openFromFile("laserfire02.ogg"))
        std::cout << "Não deu pra abrir o som do laser2..." << std::endl;
}

Bola::~Bola()
{
    //dtor
}
void Bola::colidiu(Lista<Bloco> &blocos,Fila<Buff> &buffs,Player &jogador,Pilha<sf::Color> &pilha){
    for(Lista<Bloco>::iterator i=blocos.begin();i!=blocos.end();i++){
         if(this->getGlobalBounds().intersects(i->getGlobalBounds())){
             laser1.play();
             if(this->getPosition().y>i->getPosition().y&&this->getPosition().y<i->getPosition().y+25){
                 speed.x*=-1;
             }else speed.y*=-1;

             --(*i);
             //Olhar essa parte
             ///Mesmo sem quebrar o bloco, a pilha é alterada
             if(!pilha.empty()){
                 if(i->getFillColor()==pilha.top())
                     pilha.pop();
                 else
                     pilha.push(i->getFillColor());
             }
             if(i->getLife()==0){
                jogador.setPontos(jogador.getPontos()+10*i->getType());
                if(i->hasBuff){
                    if(!buffs.front().isActive){
                        buffs.front().isActive=true;
                        buffs.front().setPosition(i->getPosition());
                    }
                }
                i=blocos.erase(i);
             }

         }
    }
}

void Bola::colidiu(sf::Sprite lightsaber){//Testar se realmente funcionou a colisao com sabre menor/maior
    if(this->getGlobalBounds().intersects((lightsaber.getGlobalBounds())))
    {
        laser2.play();
        if(this->getPosition().y<lightsaber.getPosition().y){
            speed.y *=(-1);

            float a=this->getPosition().x-(lightsaber.getPosition().x-(50*lightsaber.getScale().x));
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
}
void Bola::colidiu(void){//Testar se realmente funcionou a colisao com sabre menor/maior
    /*if(bordaD.getGlobalBounds().intersects((bola.getGlobalBounds())))
        {
            speed.x*=(-1);
        }
        if(bordaE.getGlobalBounds().intersects((bola.getGlobalBounds())))
        {
            speed.x *=(-1);
        }
        if(bordaS.getGlobalBounds().intersects((bola.getGlobalBounds())))
            speed.y *=(-1);*/
    if(getPosition().x>=LARGURAJ-BORDA||getPosition().x<=BORDA)
        speed.x*=-1;

    if(getPosition().y<=BORDA)
        speed.y*=-1;
}
void Bola::acao(Player &jogador){
    if(speed.x==0.f&&speed.y==0.f){
        this->setPosition(600,460);
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
            speed.x=0.f;
            speed.y=5.f;
        }
    }else
        this->setPosition(this->getPosition().x+speed.x,this->getPosition().y+speed.y);

    //Controle de velocidade
    if(speed.x>MAXVELOCIDADE){speed.x-=MINVELOCIDADE;}
    if(speed.x<-MAXVELOCIDADE){speed.x+=MINVELOCIDADE;}
    if(speed.y>MAXVELOCIDADE){speed.y-=MINVELOCIDADE;}
    if(speed.y<-MAXVELOCIDADE){speed.y+=MINVELOCIDADE;}


    if(getPosition().y >= ALTURAJ)
    {
        speed.x=0;
        speed.y=0;
        jogador.setVidas(jogador.getVidas()-1);
    }
}


void Bola::setSpeed(sf::Vector2f vetor){
    speed=vetor;
}
