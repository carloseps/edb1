//
//  LinkedList.h
//
//  Created by Eiji Adachi Medeiros Barbosa
//

#ifndef __LinkedList__LinkedList__
#define __LinkedList__LinkedList__

#include "Node.h"

class LinkedList {
private:
    Node<int>* first;
    
public:
    LinkedList(void);
    ~LinkedList(void);

    Node<int>* getFirst(void);
    
    void setFirst(Node<int>*);
    
    bool insertBegin(int);

    int max();

    Node<int>* maiorElem(Node<int>* no);

    Node<int>* comparaNos (Node<int>* no1, Node<int>* no2);
    
    void print(void);
};

#endif /* defined(__LinkedList__LinkedList__) */
