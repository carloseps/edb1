//
//  LinkedList.cpp
//
//  Created by Eiji Adachi Medeiros Barbosa
//

#include "LinkedList.h"

using namespace std;

LinkedList::LinkedList()
{
    this->head = new Node<string>();
    this->tail = new Node<string>();
    
    this->head->setNext(this->tail);
    this->head->setPrevious(NULL);

    this->tail->setNext(NULL);
    this->tail->setPrevious(this->head);

    this->quantity = 0;
}

LinkedList::~LinkedList()
{
    Node<string>* n = this->head;
    
    while(n != this->tail)
    {
        Node<string>* toDestroy = n;
        
        n = n->getNext();
        
        delete toDestroy;
    }
    
    delete this->tail;
}

Node<string>* LinkedList::getHead(void)
{
    return this->head;
}

Node<string>* LinkedList::getTail(void)
{
    return this->tail;
}

int LinkedList::getQuantity(void)
{
    return this->quantity;
}

bool LinkedList::isEmpty(void)
{
    return this->quantity == 0;
}

void LinkedList::print(void)
{
    std::cout << "{ ";
    for(Node<string>* n = this->head->getNext(); n != this->tail; n = n->getNext())
    {
        std::cout << n->getValue() << ":" << n->getCount() << " ";
    }
    std::cout << "}" << std::endl;
}

ListStatus LinkedList::checkConsistency()
{
    if( this->head == NULL )
    {
        return HeadNull;
    }
    else if( this->head->getNext() == NULL )
    {
        return HeadNextNull;
    }
    else if( this->head->getNext()->getPrevious() != this->head )
    {
        return IncorrectLink;
    }
    else if( this->head->getPrevious() != NULL )
    {
        return HeadPrevious;
    }
    
    if( this->tail == NULL )
    {
        return TailNull;
    }
    else if( this->tail->getPrevious() == NULL )
    {
        return TailPreviousNull;
    }
    else if( this->tail->getPrevious()->getNext() != this->tail )
    {
        return IncorrectLink;
    }
    else if( this->tail->getNext() != NULL )
    {
        return TailNext;
    }
    
    if(this->isEmpty())
    {
        if( this->head->getNext() != this->tail )
        {
            return HeadTail;
        }
        
        if( this->head != this->tail->getPrevious() )
        {
            return HeadTail;
        }
    }
    else
    {
        // Verifica encadeamento dos elementos
        for(Node<string>* i = this->head->getNext(); i != this->tail; i=i->getNext())
        {
            if( i->getNext()->getPrevious() != i )
            {
                return IncorrectLink;
            }
            if( i->getPrevious()->getNext() != i )
            {
                return IncorrectLink;
            }
        }
    }
    
    return OK;
}

bool LinkedList::insertEnd(string s)
{
    Node<std::string>* novoNo = new Node<std::string>(s);
    
    novoNo->setNext(this->getTail());
    novoNo->setPrevious(this->getTail()->getPrevious());

    novoNo->getNext()->setPrevious(novoNo);
    novoNo->getPrevious()->setNext(novoNo);

    ++this->quantity;

    return true;
}

bool LinkedList::swap(Node<std::string>* noAnterior, Node<std::string>* no){

    noAnterior->getPrevious()->setNext(no);
    no->setPrevious(noAnterior->getPrevious());
    noAnterior->setNext(no->getNext());
    no->getNext()->setPrevious(noAnterior);

    no->setNext(noAnterior);
    noAnterior->setPrevious(no);

    return true;
}

Node<string>* LinkedList::searchCF(string key)
{
    Node<std::string>* no = new Node<std::string>;

    no = this->getHead()->getNext();

	if(this->quantity == 0){
        std::cerr << "Lista vazia!" << std::endl;
        return nullptr;
    } else {
        for(int i = 0; i < this->quantity; i++){
            if(no->getValue() == key){
                int contNo = no->getCount(); contNo++;
                no->setCount(contNo);

                while(no->getPrevious() != this->getHead()){
                    if(no->getCount() > no->getPrevious()->getCount()){
                        swap(no->getPrevious(), no);
                    } else {
                        break;
                    }
                }

                return no;
            } else {
                no = no->getNext();
            }
        }

    }

    std::cerr << "Elemento não encontrado!" << std::endl;
    return nullptr;
}
