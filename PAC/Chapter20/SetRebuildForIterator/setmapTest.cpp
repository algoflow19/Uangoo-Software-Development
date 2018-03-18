#include <iostream>
#include <string>
#include "error.h"
#include"mapset.h"
#include"map.h"
// #include"console.h"
using namespace std;


int main() {

    MapSet<int> set;
    set.add(1);
    set.add(2);
    set.add(-2);
    set.add(-1);
    set.add(7);
    set.add(4);
    set.add(5);
    for(MapSet<int>::iterator it=set.begin();it!=set.end();++it){
        cout<<it[0]<<endl;
    }

    return 0;
}
