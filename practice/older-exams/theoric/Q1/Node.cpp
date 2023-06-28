#include "Node.h"

Node* Node::getNext() const {
    return this->next;
}

void Node::setNext(Node* node) {
    this->next = node;
}

Node* Node::getPrevious() const {
    return this->previous;
}

void Node::setPrevious(Node* node) {
    this->previous = node;
}

int Node::getValue() const {
    return this->value;
}

void Node::setValue(int val) {
    this->value = val;
}
