#include "LinkedList.h"
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

LinkedList* createList(vector<int> inputs)
{
	LinkedList* l = new LinkedList();

	for(auto s : inputs)
	{
		l->insertBegin(s);	
	}

	int i = inputs.size()-1;
	for(auto node = l->getFirst(); node != nullptr; node = node->getNext() )
	{
		// Só para assegurar que as inserções foram corretas
		assert( node->getValue() == inputs[i] );
		--i;
	}	

	return l;
}

int main(void)
{
	vector<vector<int>> inputs = {
		{1},
		{1, 2},
		{2, 4, 5, 6, 10, 20},
		{1, 2, 40, 20}
	};

	LinkedList* l0 = createList( inputs[0] );
	int max0 = l0->max();
	cout << "Para a lista " ;
	l0->print();
	cout << " o 'max' retornado foi: " << max0 << endl;
	assert( max0 == 1 );

	LinkedList* l1 = createList( inputs[1] );
	int max1 = l1->max();
	cout << "Para a lista " ;
	l1->print();
	cout << " o 'max' retornado foi: " << max1 << endl;
	assert( max1 == 2 );

	LinkedList* l2 = createList( inputs[2] );
	int max2 = l2->max();
	cout << "Para a lista " ;
	l2->print();
	cout << " o 'max' retornado foi: " << max2 << endl;
	assert( max2 == 20 );

	LinkedList* l3 = createList( inputs[3] );
	int max3 = l3->max();
	cout << "Para a lista " ;
	l3->print();
	cout << " o 'max' retornado foi: " << max3 << endl;
	assert( max3 == 40 );

	cout << "\nTodos testes passaram.\n";

	return 0;
}
