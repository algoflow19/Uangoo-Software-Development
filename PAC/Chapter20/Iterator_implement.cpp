#include <iostream>
#include <string>
#include "error.h"
#include<cmath>
#include"vector.h"
#include<algorithm>
#include"assert.h"
// #include"console.h"
using namespace std;

template<typename IterType>
IterType my_max_element(IterType begin,IterType end);

template<typename IterType>
int my_count_if(IterType begin,IterType end, bool (*pred)(IterType) );

int main() {

    Vector<int> v;
    v.add(0);
    v.add(1);
    v.add(2);
    v.add(3);
    v.add(100);
    v.add(4);
    v.add(5);
    v.add(-1);
    assert(*my_max_element(v.begin(),v.end())==100);
    assert(my_count_if(v.begin(),v.end(),test_count)==3);
    return 0;
}

template<typename IterType>
IterType my_max_element(IterType begin,IterType end){
    IterType max=begin;
    IterType tmp=begin;
    while(tmp!=end){
        if(*max<*tmp) max=tmp;
        tmp++;
    }
    return max;
}

template<typename IterType>
int my_count_if(IterType begin,IterType end, bool (*pred)(IterType) ){
    int count=0;
    for(IterType it=begin;it<end;it++){
        if(pred(it)) count++;
    }
    return count;
}

