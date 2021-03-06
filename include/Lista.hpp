#ifndef LISTA_HPP
#define LISTA_HPP
#include <iostream>

#ifdef LISTA
template<typename T>
class Lista{
	public:
        struct node{
            T data;
            node* next;
        };
	private:
		node* head;
		node* tail;
		int length;
	public:
		Lista();
		~Lista();
		void push_back(T data);
		void push_front(T data);

		void pop_back(void);
		void pop_front(void);

		int size(void);
		bool erase(T data);
		bool search(T data);
		bool empty(void);

        void clear(void);
        T getItem(int j=0);

		inline friend
		std::ostream &operator <<(std::ostream &_os,const Lista &list){
			node *pt;
			pt=list.head;
			_os<<"[";
			while(pt->next!=NULL){
				pt=pt->next;
				_os<<pt->data<<",";
			}
			_os<<"]"<<std::endl;
			return _os;
		}
};

template<typename T>
Lista<T>::Lista(){
	length=0;
	head=new node;
	head->next=NULL;
	tail=head;
}
template<typename T>
Lista<T>::~Lista(){
	node *tmp=head;
	while(tmp->next!=NULL){
		node *tmp2=tmp;
		tmp=tmp->next;
		delete tmp2;
	}
}
template<typename T>
void Lista<T>::clear(void){
    node *tmp=head;
	while(tmp->next!=NULL){
		node *tmp2=tmp;
		tmp=tmp->next;
		delete tmp2;
	}
}
template<typename T>
void Lista<T>::push_front(T data){
	node* tmp=new node;
	tmp->data=data;
	tmp->next=this->head->next;

	if(head->next==NULL)
        tail=tmp;

	head->next=tmp;
	length++;
}

template<typename T>
void Lista<T>::push_back(T data){
	node* tmp=new node;
	node* end=head;
	tmp->data=data;

	while(end->next!=NULL)
		end=end->next;

	end->next=tmp;
	tmp->next=NULL;

	tail=tmp;
	length++;
}

template<typename T>
void Lista<T>::pop_back(void){
    node* end=head;
    while(end->next!=tail)
		end=end->next;
    delete end->next;
    end->next=NULL;
}

template<typename T>
void Lista<T>::pop_front(void){
    node* tmp=head->next;;
    head->next=tmp->next;
    delete tmp;
}


template<typename T>
bool Lista<T>::erase(T data){
	node* tmp=head;
	node* tmp2=head;

	while(tmp->next!=tail){
		tmp2=tmp2->next;
		if(tmp2->data==data){
			tmp->next=tmp2->next;
			delete tmp2;
			length--;
			return true;
		}
		tmp=tmp->next;
	}if(tail->data==data){
        tail=tmp;
        delete tmp;
        length--;
        return true;
	}
    return false;
}

template<typename T>
bool Lista<T>::search(T data){
	node* tmp=head;

	while(tmp!=NULL){
		if(tmp->data==data){
			return true;
		}tmp=tmp->next;
	}
	return false;
}

template<typename T>
bool Lista<T>::empty(void){
	return (this->head->next==NULL);
}

template<typename T>
int Lista<T>::size(void){
    return length;
}

template<typename T>
T Lista<T>::getItem(int j){
    node* tmp=head->next;
    for(int i=0;i<j;i++)
        tmp=tmp->next;
    return tmp->data;
}
#else
#include <list>
#define Lista std::list
#endif // LISTA
#endif
