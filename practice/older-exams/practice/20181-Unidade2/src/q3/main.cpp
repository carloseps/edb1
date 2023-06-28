#include "Queue.h"
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	Queue<int> q;
	vector<int> input = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
	
	cout << "Testando 'enqueue'." << endl;
	for(int i : input)
	{
		int before = q.getQuantity();
		q.enqueue(i);
		int after = q.getQuantity();

		assert(before+1 == after);
		assert( q.peek() == 1 );
	}
	
	cout << "Testando 'dequeue'." << endl;
	for(int i : input)
	{
		assert( q.peek() == i );
		int before = q.getQuantity();
		q.dequeue();
		int after = q.getQuantity();

		assert(before == after+1);
	}

	assert( q.getQuantity() == 0 );

	cout << "Q3 - Passou em todos os testes!" << endl;

	return 0;
}
