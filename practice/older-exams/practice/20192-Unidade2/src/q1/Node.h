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
    Node* next;
    
public:
    Node();
    
    Node( T );
    
    T getValue();
    
    void setValue(T val);
    
    Node* getNext();
    
    void setNext(Node*);
};

template<typename T>
Node<T>::Node(void):
next(NULL) {}

template<typename T>
Node<T>::Node(T val):
value(val), next(NULL){}

template<typename T>
T Node<T>::getValue(void)
{
    return this->value;
}

template<typename T>
void Node<T>::setValue(T value)
{
    this->value = value;
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
#endif /* defined(__LinkedList__Node__) */
