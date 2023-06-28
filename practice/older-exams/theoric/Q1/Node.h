#ifndef NODE_H
#define NODE_H

class Node {
private:
    Node* next;
    Node* previous;
    int value;

public:
    Node* getNext() const;
    void setNext(Node* node);
    Node* getPrevious() const;
    void setPrevious(Node* node);
    int getValue() const;
    void setValue(int val);
};

#endif  // NODE_H
