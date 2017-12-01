#pragma once

// This is the array version Implementation.
#include<iostream>

template<typename type>
class Queue {
public:
	Queue();
	~Queue();
	int size() const;
	bool isEmpty();
	void clear();
	void enqueue(type value);
	type dequeue();
	type peek() const;

	Queue(const Queue<type> & src);
	Queue & operator=(const Queue<type> & src);
	

private:
	type* rep;
	int head;
	int count;
	int captity;
	void expRep();

	
	void debugShow() const;		// move this to "public area" to using it.
};

template<typename type>
inline Queue<type>::Queue()
{
	captity = 4;
	rep = new type[captity];
	count = 0;
	head = 0;
}

template<typename type>
inline Queue<type>::~Queue()
{
	delete[] rep;
}

template<typename type>
inline int Queue<type>::size() const
{
	return count;
}

template<typename type>
inline bool Queue<type>::isEmpty()
{
	return count==0;
}

template<typename type>
inline void Queue<type>::clear()
{
	count = 0;
	head = 0;
}

template<typename type>
inline void Queue<type>::enqueue(type value)
{
	if (count >= captity)
		expRep();
	rep[(head + count) % captity] = value;
	count++;
}

template<typename type>
inline type Queue<type>::dequeue()
{
	if (count == 0) {
		std::cout << "Error! No element left in the queue!" << std::endl;
		
	}
	int tmp = head;
	count--;
	head = (head + captity + 1) % captity;
	return rep[tmp];
	
}

template<typename type>
inline type Queue<type>::peek() const
{
	return rep[head];
}

template<typename type>
inline Queue<type>::Queue(const Queue<type>& src)
{
	rep = NULL;
	*this = src;
}

template<typename type>
inline Queue<type> & Queue<type>::operator=(const Queue<type>& src)
{
	captity = src.captity;
	head = src.head;
	count = src.count;
	if(rep!=NULL)
	delete[] rep;
	rep = new type[captity];
	for (int i = 0; i < count; i++) {
		rep[(i + head+captity)%captity] = src.rep[(i + head + captity) % captity];
	}
	return *this;
}

template<typename type>
inline void Queue<type>::debugShow() const
{
	for (int i = 0; i < count; i++) {
		std::cout << rep[(i + head + captity) % captity] << std::endl;
	}
}

template<typename type>
inline void Queue<type>::expRep()
{
	type* tmp = rep;
	rep = new type[captity*2];
	for (int i = 0; i < count; i++) {
		rep[head+i] = tmp[( head + i + captity) % captity];
	}
	captity *= 2;
	delete[] tmp;
}
