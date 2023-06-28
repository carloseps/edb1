//
//  Node.h
//
//  Created by Eiji Adachi Medeiros Barbosa
//

#ifndef __LinkedList__Node__
#define __LinkedList__Node__

#include <iostream>

template <typename T>
class Node
{
private:
    T value;
	int count;
    Node<T>* next;
    Node<T>* prev;
    
public:
    Node();
    
    Node( T );
    
    Node( T, Node*, Node* );
    
    T getValue();
    
    void setValue(T val);
    
    Node* getNext();
    
    void setNext(Node*);
	
	Node* getPrevious();
	
	void setPrevious(Node*);
	
	int getCount();
	
	void setCount(int);
};

template<typename T>
Node<T>::Node(void):
count(0), next(NULL), prev(NULL) {}

template<typename T>
Node<T>::Node(T val):
value(val), count(0), next(NULL), prev(NULL) {}

template<typename T>
Node<T>::Node(T val, Node* n, Node* p):
value(val), next(n), prev(p) {}

template<typename T>
T Node<T>::getValue(void)
{
    return this->value;
}

template<typename T>
Node<T>* Node<T>::getNext(void)
{
    return this->next;
}

template<typename T>
void Node<T>::setNext(Node<T>* n)
{
    this->next = n;
}

template<typename T>
Node<T>* Node<T>::getPrevious(void)
{
	return this->prev;
}

template<typename T>
void Node<T>::setPrevious(Node<T>* p)
{
	this->prev = p;
}

template<typename T>
int Node<T>::getCount()
{
	return this->count;
}

template<typename T>
void Node<T>::setCount(int c)
{
	this->count = c;
}

#endif /* defined(__LinkedList__Node__) */
