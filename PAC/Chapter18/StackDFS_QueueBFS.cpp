#include <iostream>
#include <string>
#include<assert.h>
#include<fstream>
#include"graphio.h"
#include"stack.h"
#include"queue.h"
using namespace std;

void mapDFS(Node* node);
void mapBFS(Node* node);
void doMapDFS(Stack<Node*> & stack, Set<Node *> &visited);
void doMapBFS(Queue<Node*> & queue, Set<Node *> &visited);

int main() {
    ifstream infile;
    ofstream outfile;
    SimpleGraph g;
    infile.open("AirlineGraph");
    outfile.open("testfile");
    readGraph(g,infile);
    cout<<"The BFS way is:"<<endl;
    mapBFS(g.nodes.first());
    cout<<endl;
    cout<<"The DFS way is:"<<endl;
    mapDFS(g.nodes.first());
    writeGraph(g,outfile);
    infile.close();
    outfile.close();
    return 0;
}

void mapDFS(Node* node){
    Set<Node*> visited;
    Stack<Node*> stack;
    stack.push(node);
    doMapDFS(stack,visited);
}
void mapBFS(Node* node){
    Set<Node*> visited;
    Queue<Node*> queue;
    queue.enqueue(node);
    doMapBFS(queue,visited);
}


void doMapDFS(Stack<Node *> &stack,Set<Node*> &visited){
    if(stack.size()==0) return;
    Node* np=stack.pop();
    cout<<np->name<<endl;
    for(Arc* arc:np->arcs){
        if(!visited.contains(arc->finish)){
            stack.push(arc->finish);
            visited.add(arc->finish);
        }
    }
    doMapDFS(stack,visited);
}

void doMapBFS(Queue<Node*> & queue, Set<Node *> &visited){
    if(queue.size()==0) return;
    Node* np=queue.dequeue();
    cout<<np->name<<endl;
    if(!visited.contains(np)) {
        visited.add(np);
    }
    for(Arc* arc:np->arcs){
        if(!visited.contains(arc->finish)){
            queue.enqueue(arc->finish);
            visited.add(arc->finish);
        }
    }
    doMapBFS(queue,visited);
}



