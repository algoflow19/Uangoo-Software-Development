#include <iostream>
#include <string>
#include"Map.h"
#include"assert.h"
using namespace std;

typedef mapNode<int,int> IntNode;


int main() {

    MyMap<int,int> IntMap;
    IntMap.put(1,1);
    IntMap.put(2,2);
    IntMap.put(3,3);
    IntMap.put(4,4);
    IntMap.put(1,1);


    for(auto it=IntMap.begin();it!=IntMap.end();++it){
        cout<<*it<<endl;
        IntMap.put(*it,-99);
        assert(IntMap.get(*it)==-99);
    }
    assert(IntMap.containsKey(4));
    return 0;
}
