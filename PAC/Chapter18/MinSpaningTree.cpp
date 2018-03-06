#include <iostream>
#include <string>
#include<assert.h>
#include<fstream>
//#include"console.h"
#include"set.h"
#include"map.h"
#include"graphpriv.h"
#include"priorityqueue.h"


using namespace std;

void MinSpanTree(Graph<City,Flight>& g, Graph<City, Flight> &resultGraph);

int main() {

    Graph<City,Flight> g,resultGraph;
    ifstream infile;
    infile.open("AirlineGraph");
    g.readGraph(infile);
    MinSpanTree(g,resultGraph);
    City* n1,*n2;
    for(Flight* fp : resultGraph.getArcSet()){
        if(n1==fp->getFinish()&&n2==fp->getStart());
        else{
            n1=fp->getStart();
            n2=fp->getFinish();
            cout<<n1->getName()<<" - "<<n2->getName()<<endl;
        }
    }

    return 0;
}

void MinSpanTree(Graph<City,Flight>& g,Graph<City,Flight>& resultGraph){
    PriorityQueue<Flight*> queue;
    for(City* cp : g.getNodeSet()){
        resultGraph.addNode(cp->getName());
    }
    for(Flight* fp : g.getArcSet()){
        queue.enqueue(fp,fp->getDistance());
    }
    while(!queue.isEmpty()){
        Flight* fp=queue.dequeue();
        City* start=resultGraph.getNode(fp->getStart()->getName());
        City* finish=resultGraph.getNode(fp->getFinish()->getName());
        if(!resultGraph.isExistPath(start,finish)){
            resultGraph.addArc(start,finish);
            resultGraph.addArc(finish,start);
        }
    }
}
