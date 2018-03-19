#include <iostream>
#include <string>
#include "stringmap.h"
// #include"console.h"
using namespace std;


int main() {

    StringMap map;
    map.put("1","7");
    map.put("2","6");
    map.put("3","5");
    map.put("4","4");
    map.put("ss","xx");
    map.put("6","2");
    map.put("7","1");
    for(StringMap::iterator it=map.begin();it!=map.end();++it){
        cout<<*it<<" "<<map.get(*it)<<endl;
    }
    for(string word : map){
        cout<<word<<" "<<map.get(word)<<endl;
    }

    return 0;
}
