//
//  LinkedList.cpp
//
//  Created by Eiji Adachi Medeiros Barbosa
//

#include "LinkedList.h"

using namespace std;

LinkedList::LinkedList(): first(nullptr)
{
}

LinkedList::~LinkedList()
{
    if(this->getFirst()!=nullptr)
    {
        delete this->first;
    }
}

void LinkedList::setFirst(Node<string>* n)
{
    this->first = n;
}

Node<string>* LinkedList::getFirst(void)
{
    return this->first;
}

bool LinkedList::insertBegin(string s)
{
	Node<string>* no = new Node<string>;
    no->setValue(s);
    if(this->getFirst() == nullptr){
        std::cout << "Adicionando na lista: (Primeiro elemento) -> " << no->getValue() << std::endl;
        this->setFirst(no);
        no->setNext(nullptr);

    } else {
        std::cout << "Adicionando na lista: " << no->getValue() << std::endl;
        no->setNext(this->getFirst());
        this->setFirst(no);
        this->print();
    }
    return true;
    
}

void LinkedList::print(void)
{
	for(auto n = this->getFirst(); n != nullptr; n = n->getNext())
	{
		std::cout << n->getValue() << " ";
	}
	std::cout << std::endl;
}

void LinkedList::invert()
{
	reverter(this->getFirst());
}

void LinkedList::reverter(Node<string>* n)
{
    Node<string>* no = new Node<string>;
    no = n;
	if(n->getNext() != nullptr){
        
        std::cout << "Mandando " << no->getValue() << " pra ser add no inicio"<<  std::endl;
        insertBegin(no->getValue());
        Node<string>* novoNo = no->getNext();
        delete no;
        reverter(novoNo);
    } else {
        std::cout << "Mandando " << no->getValue() << " pra ser add no inicio (else)"<<  std::endl;
        insertBegin(no->getValue());
        delete no;
        std::cout << "Printando lista dps de apagar n "<<  std::endl;
        this->print();
    }
}
