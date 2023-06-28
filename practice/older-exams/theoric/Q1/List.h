#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "Node.h"

class List {
private:
    Node* head;
    Node* tail;

public:
    List();
    Node* getHead() const;
    void setHead(Node* node);
    Node* getTail() const;
    void setTail(Node* node);
    int removeRepeated();
    void addNode(int value);
    int countEven(Node* no);

    void printaLista(){
        Node* no = this->getHead()->getNext();

        while(no->getValue() != this->getTail()->getValue()){
            std::cout << no->getValue() << std::endl;
            no = no->getNext();
        }
    }
};

#endif  // LIST_H
