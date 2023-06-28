#include <iostream>
#include "List.h"
#include "Node.h"

int main(int argc, char const *argv[])
{
    List* myList = new List();
    // myList.addNode(2);
    // myList.addNode(4);
    // myList.addNode(4);
    // myList.addNode(5);
    // myList.addNode(6);
    // myList.addNode(7);
    // myList.addNode(7);
    // myList.addNode(8);

    if(myList->getHead()->getNext()->getValue() == myList->getTail()->getValue()){
        std::cout << "pqp" << std::endl;
    }

    // std::cout << "Lista antes: " << std::endl;
    // myList.printaLista();
    // myList.removeRepeated();
    // std::cout << "Lista depois: " << std::endl;
    // myList.printaLista();

    // int qtdPares = myList.countEven(myList.getHead()->getNext());

    // std::cout << "QTD PARES: " << qtdPares << std::endl;
    return 0;
}
