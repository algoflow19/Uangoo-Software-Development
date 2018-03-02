#include <iostream>
#include <string>
#include<assert.h>
#include<fstream>
#include"graphio.h"
#include"queue.h"
#define BFS

using namespace std;

bool pathExist(Node* n1,Node* n2);
#ifdef DFS
bool doDFS(Node* start, Node* finish, Set<Node *> &visited);
#endif
#ifdef BFS
bool doBFS(Node* finish, Set<Node *> &visite, Queue<Node *> &queue);
#endif

int main() {
    ifstream infile;
    ofstream outfile;
    SimpleGraph g;
    infile.open("AirlineGraph");
    outfile.open("testfile");
    readGraph(g,infile);
    cout<<pathExist(g.nodeMap.get("Atlanta"),g.nodeMap.get("Justice"))<<endl;
    writeGraph(g,outfile);
    infile.close();
    outfile.close();
    return 0;
}


#ifdef DFS
bool pathExist(Node* n1,Node* n2){
    Set<Node*> visited;
    return doDFS(n1,n2,visited);
}

bool doDFS(Node* start,Node* finish,Set<Node*> &visited){
    cout<<start->name<<endl;
    if(start==finish) return true;
    visited.add(start);
    for(Arc* arc : start->arcs){
        if(!visited.contains(arc->finish))
        if(doDFS(arc->finish,finish,visited)) return true;
    }
    return false;
}

#endif





#ifdef BFS

bool pathExist(Node* n1,Node* n2){
    Set<Node*> visited;
    Queue<Node*> queue;
    queue.enqueue(n1);
    visited.add(n1);
    return doBFS(n2,visited,queue);
}

bool doBFS(Node* finish,Set<Node *> &visite,Queue<Node*> &queue){
    Node* np;
    if(queue.size()!=0)
        np=queue.dequeue();
    else
        return false;
    cout<<np->name<<endl;
    if(np==finish) return true;
    for(Arc* arc: np->arcs){
        if(!visite.contains(arc->finish)){
        queue.enqueue(arc->finish);
        visite.add(arc->finish);
        }
    }
    return doBFS(finish,visite,queue);
}

#endif
