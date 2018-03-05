#include <iostream>
#include <string>
#include<assert.h>
#include<fstream>
#include"console.h"
#include"map.h"
#include"graphpriv.h"

using namespace std;

int main() {

    Graph<City,Flight> g;
    ifstream infile;
    infile.open("AirlineGraph");
    g.readGraph(infile);
    Vector<Flight*> path=g.findShortestPath();
    for(int i=0;i<path.size();i++){
        cout<<path[i]->getStart()->getName()<<"->";
    }
    if(path.size()!=0)
    cout<<path[path.size()-1]->getFinish()->getName();
    else
        cout<<"No path found! Please ensure the start and the finish point is not the same and both in the graph."<<endl;
    return 0;
}

