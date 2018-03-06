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

template<typename NodeType,typename ArcType>
Set<NodeType*> findDominatingSet(Graph<NodeType,ArcType> & g);

int calDegree(DegreeNode* node,Set<DegreeNode*> & dominatedNode,Graph<DegreeNode,Arc> &g);
DegreeNode* FindMaxDegreeNode(const Set<DegreeNode*> & set);

int main() {

    Graph<DegreeNode,Arc> g;
    ifstream infile;
    infile.open("AirlineGraph");
    g.readGraph(infile);
    for(DegreeNode* node : findDominatingSet(g)){
        cout<<node->getName()<<endl;
    }
    return 0;
}
\
template<typename NodeType,typename ArcType>
Set<NodeType*> findDominatingSet(Graph<NodeType,ArcType> & g){
    Set<NodeType*> resultS;
    Set<NodeType*>  dominatedNode;
    NodeType* currentPos;
    for(NodeType* node : g.getNodeSet()){
        node->setDegree(calDegree(node,dominatedNode,g));
    }
    while(dominatedNode.size()!=g.size()){
        currentPos=FindMaxDegreeNode(g.getNodeSet());
        resultS.add(currentPos);
        if(!dominatedNode.contains(currentPos))
        dominatedNode.add(currentPos);
        for(NodeType* node : g.getNeighbors(currentPos)){
            if(!dominatedNode.contains(node)){
                dominatedNode.add(node);
            }
        }
        for(NodeType* node : g.getNodeSet())
            node->setDegree(calDegree(node,dominatedNode,g));
    }
    return resultS;
}

int calDegree(DegreeNode* node, Set<DegreeNode *> &dominatedNode, Graph<DegreeNode, Arc> &g){
    int degree=(dominatedNode.contains(node))?0:1;
    for( DegreeNode* other : g.getNeighbors(node))
        if(!dominatedNode.contains(other))
            degree++;
    return degree;
}

DegreeNode* FindMaxDegreeNode(const Set<DegreeNode*> & set){
    DegreeNode* result;
    int degree=0;
    for(DegreeNode* node : set){
        if(node->getDegree()>degree){
            result=node;
            degree=node->getDegree();
        }
    }
    return result;
}
