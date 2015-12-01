/**
 * @file Fila.hpp
 * @brief Assinatura da classe Fila
 *
 * @author Edye Lautter Cunha de Oliveira
 * @date Sat Oct 10 23:03:50 BRT 2015
 *
 */
#ifndef FILA_HPP
#define FILA_HPP
#include <iostream>

template<typename F>
class Fila{
	protected:
		F *pt_fila;//!<Um ponteiro para o início da memórial sequêncial do tipo F alocada para a fila
		int inicio;//!<Índice que guardará onde a fila começa em relação à memória alocada
		int fim;//!<Índice que guardará onde a fila termina em relação à memória alocada
		int tamanho;//!<Tamanho do do espaço de memória alocado para a filha
       /**
         * @brief _duplica() Duplica a fila caso tenha alcançado a capacidade máxima
         * @return true se a duplicação for bem sucedida, false se não
         */
        bool _duplica();
        int capacidade;//!<Quantidade de elementos armazenados na fila
	public:
        /**@brief Construtor de Fila
        * @param _MaxSz Será o atributo capacidade dessa classe
        */
		Fila(int _MaxSz=50);
        /**
        * Destrói a fila.
        * @brief ~Fila() Destructor da fila.
        */
		~Fila(void);
        /**
        * front retorna o primeiro elemento da fila.
        * @see pt_fila
        * @see inicio
        * @return pt_fila[inicio]
        */
        F front() const;
        /**
        * back retorna o último elemento da fila.
        * @see pt_fila
        * @see fim
        * @return pt_fila[fim]
        */
        F back() const;
        /**
        * @brief "pop" tem por objetivo remover um elemento da fila.
        *
        * Primeiro a função avalia se a fila foi criada/é válida para então remover o primeiro elemento da fila e
        * decrementar o tamanho. Retorna true caso dê certo.
        * @see pt_fila
        * @see empty()
        * @see inicio
        * @see tamanho
        * @return true or false
        */
        bool pop();
        /**
        * @brief Push tem por objetivo inserir um elemento na fila.
        *
        * "push" recebe um argumento _data e, caso a fila seja válida e não estiver cheia, testa se está vazia
        * para então inserir o elemento e incrementar o tamanho da fila.
        * @see pt_fila ponteiro para o primeiro elemento da fila
        * @see full()
        * @see inicio
        * @see fim
        * @see tamanho
        */
        bool push(F _data);
   /**
  * A função full retorna verdadeiro se a fila estiver cheia e falso caso não.
  * @return true or false
  */
		bool full() const;
  /**
  * empty() retorna true se fila estiver vazia.
  * @return true or false
  */
		bool empty() const;
  /**
  * A função size retorna o tamanho da fila.
  * @return this->tamanho
  */
        	int size() const;
  /**
  * sobrecarga do operador <<
  */

        inline friend
		std::ostream &operator <<(std::ostream &_os,const Fila &_obj){
			for(int i=0;i<_obj.tamanho;i++)
				_os<<_obj.pt_fila[(_obj.inicio+i)%_obj.capacidade]<<",";

			return _os;
		}
};

template<typename F>
Fila<F>::Fila(int _MaxSz){
	this->pt_fila=new F[_MaxSz];
	if(this->pt_fila){
		this->capacidade=_MaxSz;
		this->tamanho=0;
		this->inicio=-1;
		this->fim=-1;
	}
}

template<typename F>
Fila<F>::~Fila(){
	delete [] this->pt_fila;
}

template <typename F>
int Fila<F>::size() const
{
	if(pt_fila==NULL) return false;

	return this->tamanho;
}

template <typename F>
bool Fila<F>::full() const
{
	if(pt_fila==NULL) return true;
	if(this->tamanho==this->capacidade) return true;
	else return false;
}

template <typename F>
bool Fila<F>::empty() const
{
	if(this->tamanho==0)
        return true;
	else return false;
}

template <typename F>
bool Fila<F>::push(F _data)
{
	if(pt_fila==NULL) return false;
	if(this->full())
        if(!this->_duplica())
            return false;

	if(this->inicio==-1) this->inicio=0;
	this->fim = (fim+1)%this->capacidade;
	this->pt_fila[fim] = _data;
	this->tamanho++;
	return true;
}

template <typename F>
bool Fila<F>::pop()		//remove
{
	if(pt_fila == NULL || this->empty())
		return false;
    if(this->inicio==this->fim){
        this->inicio=-1;
        this->fim=-1;
    }else
        this->inicio = (this->inicio+1)%this->capacidade;
	this->tamanho--;
	return true;
}

template <typename F>
F Fila<F>::front() const
{
	return this->pt_fila[this->inicio];
}

template <typename F>
F Fila<F>::back() const
{
	return this->pt_fila[this->fim];
}
template<typename F>
bool Fila<F>::_duplica(){
	F *aux=this->pt_fila;
	F *novo=new F[this->capacidade*2];
	if(!novo) return false;
	for(int i=this->inicio,j=0;j<this->capacidade;i=(i+1)%this->capacidade,j++)
        novo[j]=aux[i];
	this->pt_fila=novo;
	delete [] aux;
	this->inicio=0;
    this->fim=this->tamanho-1;
	this->capacidade*=2;
	return true;
}


#endif // FILA_HPP
