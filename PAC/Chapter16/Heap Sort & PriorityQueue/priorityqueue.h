#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H
#include"vector.h"


template<typename ValueType>
struct node{
    double priority;
    ValueType element;
};


template<typename ValueType>
class PriorityQueue
{
public:

    PriorityQueue();

    void enqueue(const ValueType &element, const double &priority);
    ValueType dequeue();
    void sort(Vector<ValueType> & vec);
    ValueType dequeue(Vector<ValueType> & vec);
private:
     int size;
    Vector<node<ValueType>> store;
};

template<typename ValueType>
PriorityQueue<ValueType>::PriorityQueue()
{
    size=0;
}

template<typename ValueType>
void PriorityQueue<ValueType>::enqueue(const ValueType & element, const double & priority)
{

    store.add(node<ValueType> {priority,element});
     int n=size;
        while (store.get(n).priority<store.get((n-1)/2).priority) {
            store[n]=store[(n-1)/2];
            store[(n-1)/2].element=element;
            store[(n-1)/2].priority=priority;
            n=(n-1)/2;
        }
    size++;
}

template<typename ValueType>
ValueType   PriorityQueue<ValueType>::dequeue(){
    if(size<=0) error("The Queue is Empty!");
    ValueType Rvalue= store.get(0).element;
    store.set(0,store[size-1]);
    store.remove(size-1);
    int n=0;
    size--;
    while (true) {
        if(size-1>=2*n+2){
            if(store[2*n+1].priority>store[2*n+2].priority){
                if(store[n].priority>store[2*n+2].priority){
                    node<ValueType> tmp=store[n];
                    store[n]=store[2*n+2];
                    store[2*n+2]=tmp;
                    n=2*n+2;
                    continue;
            }
        }
        else{
            if(store[n].priority>store[2*n+1].priority){
                node<ValueType> tmp=store[n];
                store[n]=store[2*n+1];
                store[2*n+1]=tmp;
                n=2*n+1;
                continue;
            }
        }
        }
        if(size-1==2*n+1)
            if(store[n].priority>store[2*n+1].priority){
                node<ValueType> tmp=store[n];
                store[n]=store[2*n+1];
                store[2*n+1]=tmp;
                n=2*n+1;
                continue;
            }

        break;
    }
    return Rvalue;
}

template<typename ValueType>
void PriorityQueue<ValueType>::sort(Vector<ValueType> & vec){
    for(int i=0;i<vec.size();i++){
        int n=i;
        while(n!=0){
            if(vec[n]<vec[(n-1)/2]){
                ValueType tmp=vec[n];
                vec[n]=vec[(n-1)/2];
                vec[(n-1)/2]=tmp;
                n=(n-1)/2;
            }
            else
                break;
        }
    }
}

template<typename ValueType>
ValueType   PriorityQueue<ValueType>::dequeue(Vector<ValueType> & vec){
    if(vec.isEmpty()) error("The Queue is Empty!");
        ValueType Rvalue= vec.get(0);
        vec.set(0,vec[vec.size()-1]);
        vec.remove(vec.size()-1);
        int n=0;
        while (true) {
            if(vec.size()-1>=2*n+2){
                if(vec[2*n+1]>vec[2*n+2]){
                    if(vec[n]>vec[2*n+2]){
                        ValueType tmp=vec[n];
                        vec[n]=vec[2*n+2];
                        vec[2*n+2]=tmp;
                        n=2*n+2;
                        continue;
                }
            }
            else{
                if(vec[n]>vec[2*n+1]){
                    ValueType tmp=vec[n];
                    vec[n]=vec[2*n+1];
                    vec[2*n+1]=tmp;
                    n=2*n+1;
                    continue;
                }
            }
            }
            if(vec.size()-1==2*n+1)
                if(vec[n]>vec[2*n+1]){
                    ValueType tmp=vec[n];
                    vec[n]=vec[2*n+1];
                    vec[2*n+1]=tmp;
                    n=2*n+1;
                    continue;
                }

            break;
        }
        return Rvalue;
}

#endif // PRIORITYQUEUE_H
