/**
 * @file Pilha.hpp
 * @brief Assinatura da classe Pilha
 *
 * @author Edye Lautter Cunha de Oliveira
 * @date Sat Oct 10 23:03:50 BRT 2015
 *
 */
#ifndef PILHA_HPP
#define PILHA_HPP
#include <iostream>
/**
  * @brief Classe Pilha e seu construtor
  * A função construtora recebe o argumento _MaxSz a fim de definir o tamanho máximo da pilha.
  * Depois testa se a pilha foi criada e inicializa seus elementos.
  * @param _MaxSz tamanho maximo da pilha
  * @param pt_fila ponteiro para a pilha
  * @param tamanho tamanho da pilha, é incrementado ou decrementado de acordo com as ações.
  * @param capacidade capacidade máxima da pilha
  */
template<typename P>
class Pilha{
	protected:
		P *pt_Pilha;//!<Um ponteiro para o início da memórial sequêncial do tipo P alocada para a pilha
		int tamanho;//!<Quantidade de elementos na pilha
		int capacidade;//!<Tamanho do do espaço de memória alocado para a pilha
 /**
 * @brief _duplica() Duplica a pilha caso tenha alcançado a capacidade máxima
 * @see pt_Pilha
 * @return true or false
 * */
		bool _duplica(void);
	public:
	/**@brief Contrutor da classe Pilha
	@param _MaxSz será o valor do atributo capacidade dessa classe
	*/
		Pilha(int _MaxSz=50);
  /**
  * @brief Destructor da pilha.
  * Destrói a pilha.
  */
		~Pilha(void);
 /**
 *@brief pop() remove o último elemento da pilha somente decrementando seu tamanho
 *
 * @see pt_Pilha
 * @see empty()
 * @see tamanho
 **/
		bool pop();
 /**
 * @brief push(P _data) insere o elemento _data do tipo P na pilha
 * @param _data
 * @see pt_Pilha
 * @see tamanho
 * @return true or false
 * */
		bool push(P _data);
 /**
 * top() retorna o último elemento da pilha (tamanho-1)
 * @see pt_Pilha
 * @see tamanho
 * @return pt_Pilha[tamanho-1]
 * */
		P top();
 /**
 * @brief size() retorna o tamanho atual da pilha
 * caso não seja inválida
 **/
		int size() const;
 /**
 * @brief Full() retorna true se o tamanho do vetor tiver alcançado o tamanho máximo
 * @see tamanho
 * @see _MaxSz
 * */
		bool Full() const;
 /**
 * @brief empty() retorna true se a pilha estiver vazia
 * @see tamanho
 * */
		bool empty() const;
        /**@brief Limba a Pilha
        */
        void clear();
        /**@brief Operator << da classe Pilha
        */

		inline friend
		std::ostream &operator <<(std::ostream &_os,const Pilha &_obj){
			_os<<"[ ";
			for(int i=0;i<_obj.tamanho;i++)
				_os<<_obj.pt_Pilha[i]<< " ";
			_os<<" ]"<<std::endl;
			return _os;
		}
};

template<typename P>
void Pilha<P>::clear(){
	this->tamanho=0;
}

template<typename P>
Pilha<P>::Pilha(int _MaxSz){
	this->pt_Pilha=new P[_MaxSz];
	if(this->pt_Pilha){
		this->capacidade=_MaxSz;
		this->tamanho=0;
	}
}

template<typename P>
Pilha<P>::~Pilha(){
	delete [] this->pt_Pilha;
}

template<typename P>
bool Pilha<P>::_duplica(){
	P *aux=this->pt_Pilha;
	P *novo=new P[this->capacidade*2];
	if(!novo) return false;
	for(int i=0;i<this->capacidade;i++)
        novo[i]=aux[i];
	this->pt_Pilha=novo;
	delete [] aux;
	this->capacidade*=2;
	return true;
}

template<typename P>
int Pilha<P>::size() const
{
	if(this->pt_Pilha==NULL) return false;

	return this->tamanho;
}

template<typename P>
bool Pilha<P>::Full() const
{
	if(pt_Pilha==NULL) return true;
	return (this->tamanho==this->capacidade);
}

template <typename P>
bool Pilha<P>::empty() const
{
	return (this->tamanho==0);
}

template <typename P>
bool Pilha<P>::push(P _data)  // insere
{
	if(pt_Pilha==NULL) return false;
    if(this->Full())
        if(!this->_duplica())
            return false;
	this->pt_Pilha[this->tamanho] = _data;
	tamanho++;
	return true;
}

template <typename P>
bool Pilha<P>::pop()
{
	if(pt_Pilha == NULL || this->empty())
		return false;
	this->tamanho--;
	return true;
}

template <typename P>
P Pilha<P>::top()
{
	return this->pt_Pilha[tamanho-1];
}

#endif // PILHA_HPP
