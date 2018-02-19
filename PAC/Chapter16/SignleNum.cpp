#include <iostream>
#include <string>
#include"mapset.h"
#include<assert.h>
#include<math.h>

using namespace std;

MapSet<int> createPrimeSet(int max);
MapSet<int> & doCreatePrimeSet(MapSet<int> & set,int max);

int main() {

    MapSet<int> result=createPrimeSet(100);
    cout<<result<<endl;
    return 0;

}

MapSet<int> createPrimeSet(int max){
    MapSet<int> set;
    return doCreatePrimeSet(set,max);
}

MapSet<int> & doCreatePrimeSet(MapSet<int> & set,int max){
    if(max<=1) return set;
    if(max==2){
        set.add(2);
        return set;
    }
    doCreatePrimeSet(set,sqrt(max));
    bool addList[max-int(sqrt(max))];

    for(int i=0;i<max-int(sqrt(max));i++)
        addList[i]=true;

    for(int value : set.map ){
        for(int i=1;i*value<=max;i++){
            if(i*value>sqrt(max))
                addList[i*value-int(sqrt(max))-1]=false;
        }
    }
    for(int i=0;i<max-int(sqrt(max));i++)
        if(addList[i]==true)
        set.add(i+int(sqrt(max))+1);
    return set;

}
