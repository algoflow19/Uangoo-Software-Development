#include "stdafx.h"
#include<iostream>
#include<fstream>
#include"Queue.h"
#include<assert.h>

//This file is built for testing the Queue class!

int main() {
	
	Queue<int> Q1,Q2;
	assert(Q1.isEmpty() == true);
	Q1.enqueue(1);
	Q1.enqueue(2);
	Q1.enqueue(3);
	assert(Q1.dequeue() == 1);
	assert(Q1.size() == 2);
	assert(Q1.isEmpty() == false);
	Q2 = Q1;
	assert(Q2.size() == 2);
	assert(Q2.isEmpty() == false);
	assert(Q2.dequeue() == 2);
	assert(Q2.dequeue() == 3);
	assert(Q2.isEmpty() == true);
	Queue<int> Q3(Q1),Q4(Q1);
	Q3.enqueue(4);
	Q3.enqueue(5);
	Q3.enqueue(6);
	assert(Q3.size() == 5);
	assert(Q3.dequeue() == 2);
	assert(Q3.dequeue() == 3);
	assert(Q3.dequeue() == 4);
	assert(Q3.dequeue() == 5);
	assert(Q3.size() == 1);
	assert(Q3.isEmpty() == false);
	assert(Q3.dequeue() == 6);
	assert(Q3.isEmpty() == true);
	assert(Q3.size() == 0);
	//reverse test
	Q4.enqueue(4);
	Q4.enqueue(5);
	Q4.enqueue(6);
	Q4.reverse();
	assert(Q4.dequeue() == 6);
	assert(Q4.dequeue() == 5);
	assert(Q4.dequeue() == 4);
	Q4.reverse();
	assert(Q4.dequeue() == 2);
	assert(Q4.dequeue() == 3);

	std::cout << "Class Queue passed the test! " << std::endl;

	return 0;
}
