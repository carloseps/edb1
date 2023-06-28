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
    if(this->getFirst() != nullptr){
        delete this->first;
    }
}

void LinkedList::setFirst(Node<int>* n)
{
    this->first = n;
}

Node<int>* LinkedList::getFirst(void)
{
    return this->first;
}

bool LinkedList::insertBegin(int x)
{
	Node<int>* novo = new Node<int>(x);

    novo->setNext( this->getFirst() );

    this->setFirst( novo );

    return true;
}

void LinkedList::print(void)
{
	std::cout << "{ ";
    for(auto n = this->getFirst(); n != nullptr; n = n->getNext())
	{
		std::cout << n->getValue() << " ";
	}
	std::cout << "}";
}

int LinkedList::max()
{
    int result = (maiorElem(this->getFirst()))->getValue();
	return result;
}

Node<int>* LinkedList::maiorElem(Node<int>* no)
{
    if(this->getFirst() == nullptr){
        return 0;
    } else if(no->getNext() != nullptr) {
        return comparaNos(no, maiorElem(no->getNext()));
    }
	return no;
}

Node<int>* LinkedList::comparaNos (Node<int>* no1, Node<int>* no2){
    if(no1->getValue() > no2->getValue()){
        return no1;
    } else { return no2; }
}
