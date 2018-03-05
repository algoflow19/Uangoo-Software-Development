#include <iostream>
#include <string>
#include<assert.h>
#include<fstream>
//#include"console.h"
#include"set.h"
#include"map.h"
#include"graphpriv.h"

using namespace std;

template<typename NodeType,typename ArcType>
bool isBipartite(Graph<NodeType,ArcType> & g);

template<typename NodeType,typename ArcType>
void addToSetOne(Graph<NodeType,ArcType> & g,Set<NodeType*> &one,Set<NodeType*> &zero,string name);

template<typename NodeType,typename ArcType>
void addToSetZero(Graph<NodeType,ArcType> & g,Set<NodeType*> &one,Set<NodeType*> &zero,string name);

int main() {

    Graph<City,Flight> g;
    ifstream infile;
    infile.open("AirlineGraph");
    g.readGraph(infile);
    cout<<isBipartite(g)<<endl;
    return 0;
}

template<typename NodeType,typename ArcType>
void addToSetOne(Graph<NodeType,ArcType> & g,Set<NodeType*> &one,Set<NodeType*> &zero,string name){
    NodeType* node=g.getNode(name);
    if(one.contains(node)) return;
    one.add(node);
    for(NodeType* np : g.getNeighbors(name)){
        addToSetZero(g,one,zero,np->getName());

    }
}


template<typename NodeType,typename ArcType>
bool isBipartite(Graph<NodeType,ArcType> & g){
    Set<NodeType*> one;
    Set<NodeType*> zero;
    for(NodeType* node : g.getNodeSet()){
        if(!one.contains(node)&&!zero.contains(node))
            addToSetOne(g,one,zero,node->getName());
    }
    cout<<one.size()<<endl;
    cout<<zero.size()<<endl;
    return g.size()==(one.size()+zero.size());
}


template<typename NodeType,typename ArcType>
void addToSetZero(Graph<NodeType,ArcType> & g, Set<NodeType *> &one, Set<NodeType *> &zero, string name){
    NodeType* node=g.getNode(name);
    if(zero.contains(node)) return;
    zero.add(node);
    for(NodeType* np : g.getNeighbors(name)){
        addToSetOne(g,one,zero,np->getName());
    }
}
