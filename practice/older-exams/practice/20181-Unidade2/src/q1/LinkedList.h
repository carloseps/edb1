//
//  LinkedList.h
//
//  Created by Eiji Adachi Medeiros Barbosa
//

#ifndef __LinkedList__LinkedList__
#define __LinkedList__LinkedList__

#include "Node.h"
#include <string>

class LinkedList {
private:
    Node<std::string>* first;
    
public:
    LinkedList(void);
    ~LinkedList(void);

    Node<std::string>* getFirst(void);
    void setFirst(Node<std::string>*);
    
    bool insertBegin(std::string);

    void invert();
    
    void reverter(Node<std::string>* n);

    void print(void);
};

#endif /* defined(__LinkedList__LinkedList__) */
