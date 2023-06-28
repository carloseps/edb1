//
//  Queue.hpp
//  Queue
//
//  Created by Eiji Adachi Medeiros Barbosa 
//

#ifndef Queue_hpp
#define Queue_hpp

#include <iostream>
#include <stack>

using namespace std;

template<typename T>
class Queue
{
public:
    Queue();
    Queue(int);
    void enqueue(T);
    void dequeue();
    T peek();
    int getQuantity();
    
private:
    int quantity;
};

template<typename T>
Queue<T>::Queue():quantity(0)
{
}

template<typename T>
int Queue<T>::getQuantity()
{
	return this->quantity;
}

template<typename T>
T Queue<T>::peek(){
    std::cerr << "ERRO: Método 'Queue<T>::peek()' ainda não foi implementado.\n";
    std::abort();
}

template<typename T>
void Queue<T>::enqueue(T element){
    std::cerr << "ERRO: Método 'Queue<T>::enqueue(T element)' ainda não foi implementado.\n";
    std::abort();
}

template<typename T>
void Queue<T>::dequeue(){
    std::cerr << "ERRO: Método 'Queue<T>::dequeue()' ainda não foi implementado.\n";
    std::abort();
}

#endif /* Queue_hpp */
