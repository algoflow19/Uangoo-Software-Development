#include<iostream>
#include<string>
#include"pqueue.h"
#include<assert.h>
using namespace std;

int main(){

    Queue<int> Q1,Q2;
    assert(Q1.isEmpty() == true);
    assert(Q1.size() == 0);
    Q1.enqueue(1, 1.5);
    assert(Q1.dequeue() == 1);
    Q1.enqueue(10, 1);
    Q1.enqueue(5, 0.5);
    Q1.enqueue(3, 0.3);
    assert(Q1.isEmpty() == false);
    assert(Q1.dequeue() == 3);
    assert(Q1.dequeue() == 5);
    assert(Q1.dequeue() == 10);
    assert(Q1.isEmpty() == true);
    assert(Q1.size() == 0);
    Q1.enqueue(4, 0.4);
    Q1.enqueue(2, 0.2);
    Q1.enqueue(3, 0.3);
    assert(Q1.peek() == 2);
    Q2 = Q1;
    Queue<int> Q3(Q1);
    Q1 = Q1;
    Q1.clear();
    assert(Q1.isEmpty() == true);
    assert(Q1.size() == 0);
    assert(Q3.dequeue() == 2);
    assert(Q3.peek() == 3);
    Q3.enqueue('Q', 0.1);
    assert(Q3.dequeue() == 'Q');
    assert(Q2.size() == 3);
    assert(Q2.dequeue() == 2);
    assert(Q2.dequeue()==3);

    return 0;
}
