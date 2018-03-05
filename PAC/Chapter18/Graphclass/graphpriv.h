#ifndef GRAPH_H
#define GRAPH_H

#include<iostream>
#include<string>
#include"set.h"
#include"map.h"
#include<fstream>
#include"strlib.h"
#include"vector.h"
#include"priorityqueue.h"
#include"queue.h"
class City;       /* Forward references to these two types so  */
class Flight;     /* that the C++ compiler can recognize them. */






template<typename NodeType,typename ArcType>
class Graph
{
public:

    Graph();
    Graph(const Graph & src);
    const Graph& operator =(const Graph& src);
    void readGraph( std::ifstream & infile);
    ~Graph();

    int size() const;
    bool isEmpty() const;
    void clear();

    NodeType* addNode(std::string name);
    NodeType* addNode(NodeType* node);
    void removeNode(std::string name);
    void removeNode(NodeType* node);
    NodeType* getNode(std::string name);

    ArcType* addArc(std::string s1,std::string s2);
    ArcType* addArc(NodeType* n1,NodeType* n2);
    ArcType* addArc(ArcType* arc);
    ArcType* addArc(NodeType *n1, NodeType *n2,const int & cost);
    void removeArc(std::string s1,std::string s2);
    void removeArc(NodeType* n1,NodeType *n2);
    void removeArc(ArcType* arc);

    bool isConnected(std::string s1,std::string s2);
    bool isConnected(NodeType* n1,NodeType* n2);

    Set<NodeType*> getNodeSet();
    Set<ArcType*> getArcSet();
    Set<ArcType*> getArcSet(std::string s1);
    Set<ArcType*> getArcSet(NodeType* n1);

    Set<NodeType*> getNeighbors(std::string name);
    Set<NodeType*> getNeighbors(NodeType* node);

    /*
     * The fllow is the Problem solution
     */

    Vector<ArcType*>  findShortestPath();

private:
    Set<NodeType*> nodeSet;
    Set<ArcType*> arcSet;
    Map<std::string,NodeType*> nameMap;


/* Private methods */
    void deepCopy(const Graph & src);
    NodeType *getExistingNode(std::string name) const;

    Vector<ArcType*>  DijkstraFindPath(NodeType* start,NodeType* finish);
    int getPathLength(Vector<ArcType*>& path);
};
template <typename NodeType,typename ArcType>
inline Vector<ArcType*> Graph<NodeType,ArcType>::findShortestPath(){
    std::string start;
    std::string finish;
    std::cout<<"Please input the start point:";
    std::getline(std::cin,start);
    std::cout<<"Please input the finish point:";
    std::getline(std::cin,finish);
    return DijkstraFindPath(nameMap.get(start),nameMap.get(finish));
}

template <typename NodeType,typename ArcType>
inline Vector<ArcType*> Graph<NodeType,ArcType>::DijkstraFindPath(NodeType* start,NodeType* finish){
    PriorityQueue<Vector<ArcType*> > leftPath;
    Map<NodeType*,int> fixed;
    Vector<ArcType*> path;
    fixed.add(start,0);
    while(start!=finish){
        for(ArcType* arc : start->arcs){
            if(!fixed.containsKey(arc->finish)){
                path.add(arc);
                leftPath.enqueue(path,getPathLength(path));
                path.remove(path.size()-1);
            }
        }
        if(leftPath.isEmpty()){
            path.clear();
            return path;
        }
        path=leftPath.dequeue();
        fixed.add(path.get(path.size()-1)->finish,getPathLength(path));
        start=path[path.size()-1]->finish;
    }
    return path;
}

template <typename NodeType,typename ArcType>
inline int Graph<NodeType,ArcType>::getPathLength(Vector<ArcType*> & path){
    int sum=0;
    for(ArcType* arc : path){
        sum += arc->distance;
    }
    return sum;
}

template <typename NodeType,typename ArcType>
inline Graph<NodeType,ArcType>::Graph() {
   /* Empty */
}


template<typename NodeType,typename ArcType>
inline Graph<NodeType,ArcType>::~Graph(){
    clear();
}


template<typename NodeType,typename ArcType>
inline NodeType *Graph<NodeType,ArcType>::addNode(std::__cxx11::string name)
{
    NodeType* np=new NodeType;
    np->name=name;
    return addNode(np);
}

template<typename NodeType,typename ArcType>
inline NodeType *Graph<NodeType,ArcType>::addNode(NodeType* node){
    nodeSet.add(node);
    nameMap.add(node->name,node);
    return node;
}

template<typename NodeType,typename ArcType>
inline void Graph<NodeType,ArcType>::removeNode(std::string name){
    NodeType* np=nameMap.get(name);
    removeNode(np);
}

template<typename NodeType,typename ArcType>
inline void Graph<NodeType,ArcType>::removeNode(NodeType* node){
    for(ArcType* arc : node->arcs){
        if(arc->finish!=node)
            arc->finish->arcs.remove(arc);
        else
            arc->start->arcs.remove(arc);
        nodeSet.remove(node);
        nameMap.remove(node->getName());
    }
}

template<typename NodeType,typename ArcType>
inline void Graph<NodeType,ArcType>::clear(){
    for(ArcType* arc : arcSet)
        delete arc;
    for(NodeType* node : nodeSet)
        delete node;
    nodeSet.clear();
    arcSet.clear();
    nameMap.clear();

}

template<typename NodeType,typename ArcType>
inline int Graph<NodeType,ArcType>::size() const{
    return nodeSet.size();
}

template<typename NodeType,typename ArcType>
inline bool Graph<NodeType,ArcType>::isEmpty() const{
    return nodeSet.size()==0;
}

template<typename NodeType,typename ArcType>
inline ArcType*  Graph<NodeType,ArcType>::addArc(std::string s1,std::string s2){
    return addArc(nameMap.get(s1),nameMap.get(s2));
}

template<typename NodeType,typename ArcType>
inline ArcType*  Graph<NodeType,ArcType>::addArc(NodeType* n1,NodeType* n2){
    ArcType* ap=new ArcType;
    ap->start=n1;
    ap->finish=n2;
    return addArc(ap);
}

template<typename NodeType,typename ArcType>
inline ArcType*  Graph<NodeType,ArcType>::addArc(ArcType* arc){
    arc->start->arcs.add(arc);
    arc->finish->arcs.add(arc);
    arcSet.add(arc);
    return arc;
}

template<typename NodeType,typename ArcType>
inline void Graph<NodeType,ArcType>::removeArc(std::string s1,std::string s2){
    removeArc(nameMap.get(s1),nameMap.get(s2));
}

template<typename NodeType,typename ArcType>
inline void Graph<NodeType,ArcType>::removeArc(NodeType* n1,NodeType *n2){
    for(ArcType* ap : n1->arcs)
        if(ap->finish==n2){
            removeArc(ap);
            return;
        }

}

template<typename NodeType,typename ArcType>
inline void Graph<NodeType,ArcType>::removeArc(ArcType* arc){
    arc->start->arcs.remove(arc);
    arc->finish->arcs.remove(arc);
    arcSet.remove(arc);
    delete arc;
}

template<typename NodeType,typename ArcType>
inline bool Graph<NodeType,ArcType>::isConnected(std::string s1,std::string s2){
    return isConnected(nameMap.get(s1),nameMap.get(s2));
}

template<typename NodeType,typename ArcType>
inline bool Graph<NodeType,ArcType>::isConnected(NodeType* n1,NodeType* n2){
    for(ArcType* ap: n1->arcs){
        if(ap->start==n1&&ap->finsih==n2) return true;
    }
    return false;
}

template<typename NodeType,typename ArcType>
inline Set<NodeType*> Graph<NodeType,ArcType>::getNodeSet(){
    return nodeSet;
}

template<typename NodeType,typename ArcType>
inline Set<ArcType*> Graph<NodeType,ArcType>::getArcSet(){
    return arcSet;
}

template<typename NodeType,typename ArcType>
inline Set<ArcType*> Graph<NodeType,ArcType>::getArcSet(std::string s1){
    return nameMap.get(s1)->arcs;
}

template<typename NodeType,typename ArcType>
inline Set<ArcType*> Graph<NodeType,ArcType>::getArcSet(NodeType* n1){
    return n1->arcs;
}

template<typename NodeType,typename ArcType>
inline Set<NodeType*> Graph<NodeType,ArcType>::getNeighbors(std::string name){
    return getNeighbors(nameMap.get(name));
}

template<typename NodeType,typename ArcType>
inline Set<NodeType*> Graph<NodeType,ArcType>::getNeighbors(NodeType* node){
    Set<NodeType*> result;
    for(ArcType* arc : node->arcs){
        if(arc->start!=node) result.add(arc->start);
        else result.add(arc->finish);
    }
    return result;
}

template<typename NodeType,typename ArcType>
inline Graph<NodeType,ArcType>::Graph(const Graph& src){
    deepCopy(src);
}

template<typename NodeType,typename ArcType>
inline const Graph<NodeType,ArcType>& Graph<NodeType,ArcType>::operator=(const Graph& src){
    // Why return a const class?
    if(src!=*this){   // Ensure that the lhs and rhs not the same object!
        clear();
        deepCopy(src);
    }
    return *this;
}

template<typename NodeType,typename ArcType>
inline void Graph<NodeType,ArcType>::deepCopy(const Graph& src){
    for(NodeType* np : src.nodeSet){
        addNode(np.getName());
    }
    for(ArcType* ap : src.arcSet){
        ArcType* arc=new ArcType;
        *arc=*ap;
        arc->start=nameMap.get(ap->start->name);
        arc->finish=nameMap.get(ap->finsih->name);
        addArc(arc);
    }
}



std::string catchWord(std::string &str);
int catchSymbol(std::string & str);
double catchCost(std::string & str);



template<typename NodeType,typename ArcType>
inline void Graph<NodeType,ArcType>::readGraph(std::ifstream & infile){
    clear();
    std::string fromName;
    std::string toName;
    std::string tmp;
    double cost;
    int dir;
    while(true){
        getline(infile,tmp);
        if(tmp=="") break;
        cost=catchCost(tmp);
        fromName=catchWord(tmp);
        if(!nameMap.containsKey(fromName))
            addNode(fromName);
        dir=catchSymbol(tmp);
        toName=catchWord(tmp);
        if(!nameMap.containsKey(toName))
            addNode(toName);
        switch (dir) {
        case -1:
            addArc(nameMap.get(toName),nameMap.get(fromName),cost);
            break;
        case 1:
            addArc(nameMap.get(fromName),nameMap.get(toName),cost);
            break;
        case 0:
            addArc(nameMap.get(fromName),nameMap.get(toName),cost);
            addArc(nameMap.get(toName),nameMap.get(fromName),cost);
            break;
        }

    }
}

template<typename NodeType,typename ArcType>
inline ArcType* Graph<NodeType,ArcType>::addArc(NodeType *n1, NodeType *n2,const int & cost){
    ArcType* ap=new ArcType;
    ap->start=n1;
    ap->finish=n2;
    ap->distance=cost;
    return addArc(ap);
}

class City {

public:
   std::string getName() {
      return name;
   }

private:
   std::string name;
   Set<Flight *> arcs;
   std::string airportCode;
   friend class Graph<City,Flight>;
};

/*
 * Class: Flight
 * -------------
 * This class defines the arc type for the airport graph.
 */

class Flight {

public:
   City *getStart() {
      return start;
   }

   City *getFinish() {
      return finish;
   }

   int getDistance() {
      return distance;
   }

   void setDistance(int miles) {
      distance = miles;
   }

private:
   City *start;
   City *finish;
   int distance;
   friend class Graph<City,Flight>;
};





#endif // GRAPH_H
