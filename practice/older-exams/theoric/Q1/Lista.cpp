#include "List.h"

List::List(){
    this->getHead()->setNext(this->getTail());
    this->getTail()->setPrevious(this->getHead());
}

Node *List::getHead() const
{
    return head;
}

void List::setHead(Node *node)
{
    head = node;
}

Node *List::getTail() const
{
    return tail;
}

void List::setTail(Node *node)
{
    tail = node;
}

int List::removeRepeated()
{
    int qtdElemRepetidos;

    Node *no = this->getHead()->getNext();

    while (no->getValue() != this->getTail()->getValue())
    {

        if (no->getValue() == no->getNext()->getValue())
        {
            Node *noAux = no->getNext();
            no->setNext(noAux->getNext());
            no->getNext()->setPrevious(no);

            delete noAux;
            qtdElemRepetidos++;

            if (no->getNext()->getValue() == no->getValue())
            {
                continue;
            }
        }
        else
        {
            no = no->getNext();
        }
    }

    return qtdElemRepetidos;
}

void List::addNode(int value)
{
    Node *newNode = new Node(); // Cria um novo nó
    newNode->setValue(value);   // Define o valor do novo nó

    if (this->getHead()->getNext()->getValue() == this->getTail()->getValue())
    {
        this->getHead()->setNext(newNode);
        this->getTail()->setPrevious(newNode);
    }
    else
    {
        // Adiciona o novo nó ao final da lista
        this->getTail()->getPrevious()->setNext(newNode);
        newNode->setPrevious(this->getTail()->getPrevious());
        this->getTail()->setPrevious(newNode);
        newNode->setNext(this->getTail());
    }
}

int List::countEven(Node* no){
    if(no->getValue() == this->getTail()->getValue()){
        return 0;
    } else {
        if(no->getValue() % 2 == 0){
            return 1 + countEven(no->getNext());
        } else {
            return countEven(no->getNext());
        }
    }
}
