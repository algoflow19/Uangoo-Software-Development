#include <iostream>
#include <string>
#include<assert.h>
#include<fstream>
#include"graphio.h"
#include"queue.h"
#include"map.h"
#define BFS
using namespace std;


int hopCount(Node* n1,Node* n2);
int BFSLength(Node* finish, Map<Node *,int> &visite, Queue<Node*> &queue);

int main() {
    ifstream infile;
    ofstream outfile;
    SimpleGraph g;
    infile.open("AirlineGraph");
    outfile.open("testfile");
    readGraph(g,infile);
    cout<<"Boston To San Los Angeles"<<hopCount(g.nodeMap.get("Boston"),g.nodeMap.get("Los Angeles"))<<endl;
    infile.close();
    outfile.close();
    return 0;
}


int BFSLength(Node* finish, Map<Node *,int> &visite, Queue<Node*> &queue){
    Node* np;
    if(queue.size()==0) return -1;
    np=queue.dequeue();
    if(np==finish) return visite.get(np);
    for(Arc* arc:np->arcs){
        if(visite.get(arc->finish)==int()){
            queue.add(arc->finish);
            visite.add(arc->finish,visite.get(np)+1);
        }
    }
    return BFSLength(finish,visite,queue);
}



int hopCount(Node* n1,Node* n2){
    Queue<Node*> queue;
    Map<Node*,int> visited;
    queue.enqueue(n1);
    visited.add(n1,1);
    return BFSLength(n2,visited,queue)-1;
}
