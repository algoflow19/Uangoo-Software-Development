#ifndef VECTOR_H
#define VECTOR_H

// This file is using for double-linked-list
#include"error.h"

template<typename type>
class Vector{
public:

    Vector();
    Vector(int n,type value);
    ~Vector();

    void add(type value);

    int size() const;
    bool isEmpty() const;

    void insert(int n,type value);
    //
    type & operator[](int index);
    type get(int n) const;
    void set(int n,type value);

    void remove(int n);

    void clear();


    Vector(const Vector<type> & src);
    Vector& operator=(const Vector<type> & src);

private:
    int count;

    struct node{
        node* previousNode;
        node* nextNode;
        type value;
    };
    node* start;
    node* end;
    node* findByIndex(int index) const{
        if(index+1>count||index<0) error("Program error,incorrect index");
        node* tmp=start->nextNode;
        for(int i=0;i<index;i++){
            tmp=tmp->nextNode;
        }
        return tmp;
    }
};

#endif // VECTOR_H


template<typename type>
Vector<type>::Vector(){

    start=new node;
    end=start;
    start->nextNode=NULL;
    count=0;
}

template<typename type>
Vector<type>::~Vector(){
    clear();
    delete start;
}

template<typename type>
Vector<type>::Vector(const Vector<type> &src)
{
    start=new node;
    end=start;
    start->nextNode=NULL;
    count=0;
    (*this)=src;
}

template<typename type>
Vector<type> &Vector<type>::operator=(const Vector<type> &src)
{
    clear();
    node* tmpnode=src.start;
    for(int i=0;i<src.count;i++){
        tmpnode=tmpnode->nextNode;
        add(tmpnode->value);
    }
    return *this;
}

template<typename type>
Vector<type>::Vector(int n, type value)
{
    start=new node;
    end=start;
    start->nextNode=NULL;
    count=0;
    for(int i=0;i<n;i++)
        add(value);

}
template<typename type>
void Vector<type>::add(type value)
{
    end->nextNode=new node;
    end->nextNode->previousNode=end;
    end->nextNode->nextNode=NULL;
    end=end->nextNode;
    end->value=value;
    count++;
}
template<typename type>
void Vector<type>::insert(int n, type value)
{
    if(n==count){
        add(value);
        return;
    }
    node* tmp=findByIndex(n);
    node* prvNode=tmp->previousNode();
    prvNode->nextNode=new node;
    prvNode->nextNode->previousNode=prvNode;
    prvNode->nextNode->nextNode=tmp;
    tmp->previousNode=prvNode->nextNode;
    prvNode->value=value;
    count++;
}

template<typename type>
int Vector<type>::size() const{
    return count;
}

template<typename type>
bool Vector<type>::isEmpty() const{
    return count==0;
}

template<typename type>
type & Vector<type>::operator[](int index){

    node* tmp=findByIndex(index);
    return tmp->value;
}

template<typename type>
type Vector<type>::get(int n) const
{
    return findByIndex(n)->value;
}

template<typename type>
void Vector<type>::set(int n, type value)
{
    (*(findByIndex(n))).value=value;

}

template<typename type>
void Vector<type>::remove(int n){
    node* tmp=findByIndex(n);
    tmp->previousNode->nextNode=tmp->nextNode;
    if(tmp->nextNode!=NULL){
        tmp->nextNode->previousNode=tmp->previousNode;
        end=tmp->previousNode;
    }
    delete tmp;
    count--;
}

template<typename type>
void Vector<type>::clear(){
    while(count!=0)
        remove(0);
}

