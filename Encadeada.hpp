#include <cstddef>

class Encadeada{
	public:
		struct No{
			int data;
			No* next;
		}
	private:
		No* inicio;
	public:
		Encadeada();
		void add(int data);
		void remove(int data);
		bool search(int data);
		void libera();
};

Encadeada::Encadeada(){
	inicio=new No;
	inicio->next=nullptr;
}
void Encadeada::add(int data){
	No* tmp=new No;
	tmp->data=data;
	tmp->next=inicio->next;
	inicio->next=tmp;
}
void Encadeada::remove(int data){
	No* tmp=inicio;
	No* tmp2=inicio->next;
	while(tmp2!=nullptr){
		if(tmp2->data==data){
			tmp->next=tmp2->next;
			delete tmp2;
		}
		tmp=tmp->next;
		tmp2=tmp2->next;
	}
}
void Encadeada::libera(){
	No* tmp=inicio->next;
	No* tmp2=inicio->next;
	
	while(tmp!=nullptr){
		tmp2=tmp2->next;
		delete tmp;
		tmp=tmp2;
	}
}
