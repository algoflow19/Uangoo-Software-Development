#include <iostream>
#include <string>
#include "map.h"
#include "grid.h"
// #include"console.h"
using namespace std;


int main() {

    Grid<int> g(5,4);
    for(int i=0;i<5*4;i++)
        g.set(i/4,i%4,i);
    for(Grid<int>::iterator it=g.begin();it!=g.end();it++){
        cout<<*it<<endl;
    }
    for(int num : g){
        cout<<num<<endl;
    }
    for(Grid<int>::iterator it=g.end();it!=g.begin();){
        cout<<*(--it)<<endl;
    }


    return 0;
}
