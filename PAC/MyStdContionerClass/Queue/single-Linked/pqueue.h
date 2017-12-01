#ifndef PQUEUE_H
#define PQUEUE_H

// This is the array version Implementation.
#include<iostream>
#include"error.h"
using namespace std;

template<typename type>
class Queue {
public:

    Queue();
    ~Queue();
    int size() const;
    bool isEmpty();
    void clear();
    void enqueue(type value, double priority);
    type dequeue();
    type peek() const;
    // void reverse();


    Queue(const Queue<type> & src);
    Queue<type> & operator=(const Queue<type> & src);

private:
    struct node {
        type value;
        double pri;
        node* link;
    };
    node* start;
    int count;


};

template<typename type>
inline Queue<type>::Queue()
{
    start = new node;
    count = 0;
    start->link = NULL;
    start->pri = 0;
}

template<typename type>
inline Queue<type>::~Queue()
{
    while (start->link != NULL) {
        node* tmp = start->link;
        delete start;
        start = tmp;
    }
    delete start;
}

template<typename type>
inline int Queue<type>::size() const
{
    return count;
}

template<typename type>
inline bool Queue<type>::isEmpty()
{
    return count == 0;
}

template<typename type>
inline void Queue<type>::clear()
{
    while(count!=0)
        dequeue();
}

template<typename type>
inline void Queue<type>::enqueue(type value, double priority)
{
    node* tmp = start;
    while (true)
    {
        if ((tmp->pri <= priority&&tmp->link == NULL) || (tmp->pri <= priority&&tmp->link->pri >= priority)) {
            node* tmp2 = tmp->link;
            tmp->link = new node;
            tmp->link->pri = priority;
            tmp->link->value = value;
            tmp->link->link = tmp2;
            break;
        }
        tmp = tmp->link;
    }
    count++;
}

template<typename type>
inline type Queue<type>::dequeue()
{
    if (count == 0) error("It's dequeue, no element left!");
    node* tmp = start->link;
    type tmp1 = tmp->value;
    start->link = tmp->link;
    delete tmp;
    count--;
    return tmp1;
}

template<typename type>
inline type Queue<type>::peek() const
{
    if (count != 0)
        return start->link->value;
    else
        error("This is no element left!");
    return start->link->value;
}

template<typename type>
inline Queue<type>::Queue(const Queue<type>& src)
{
    start = new node;
    count = 0;
    start->link = NULL;
    start->pri = 0;
    *this = src;
}

template<typename type>
inline Queue<type> & Queue<type>::operator=(const Queue<type>& src)
{
    if (this != &src) {
        clear();
        node* tmp=src.start;
        for(int i=0;i<src.count;i++){
            tmp=tmp->link;
            enqueue(tmp->value,tmp->pri);
        }
        }
    return *this;
}

#endif // PQUEUE_H

