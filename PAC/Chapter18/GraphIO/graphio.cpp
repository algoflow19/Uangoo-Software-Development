#include"graphio.h"
#include<string>
#include"strlib.h"

using namespace std;

/*
 * Imporant Note:
 *  Any Method named with "catch" means that it gets the desire result and delete
 *  the data from the param!
*/


void addArc(SimpleGraph &g, Node*  from,Node*  to,const double & cost);
void addNode(SimpleGraph &g,const string & str);
string catchWord(string &str);
int catchSymbol(string & str);
double catchCost(string & str);

void readGraph(SimpleGraph &g, std::istream &infile)
{
    g.arcs.clear();
    g.nodes.clear();
    g.nodeMap.clear();
    string fromName;
    string toName;
    string tmp;
    double cost;
    int dir;
    //缺少整体设计思考,函数设计存在漏洞
    while(true){
        getline(infile,tmp);
        if(tmp=="") break;
        cost=catchCost(tmp);
        fromName=catchWord(tmp);
        if(!g.nodeMap.containsKey(fromName))
            addNode(g,fromName);
        dir=catchSymbol(tmp);
        toName=catchWord(tmp);
        if(!g.nodeMap.containsKey(toName))
            addNode(g,toName);
        switch (dir) {
        case -1:
            addArc(g,g.nodeMap.get(toName),g.nodeMap.get(fromName),cost);
            break;
        case 1:
            addArc(g,g.nodeMap.get(fromName),g.nodeMap.get(toName),cost);
            break;
        case 0:
            addArc(g,g.nodeMap.get(fromName),g.nodeMap.get(toName),cost);
            addArc(g,g.nodeMap.get(toName),g.nodeMap.get(fromName),cost);
            break;
        }
    }

}

void addArc(SimpleGraph &g, Node*  from,Node*  to,const double & cost){
    Arc* ap=new Arc;
    g.arcs.add(ap);
    ap->start=from;
    ap->finish=to;
    ap->cost=cost;
    from->arcs.add(ap);
    to->arcs.add(ap);
}

void addNode(SimpleGraph &g,const string & str){
    Node* np=new Node;
    g.nodes.add(np);
    g.nodeMap.add(str,np);
    np->name=str;
}

//how to easily raise the program Robust, check the code!
string catchWord(string &str){
    string result;
    int head,tail;
    head=tail=-1;
    for(int i=0;i<str.length();i++){
        if(head==-1&&str[i]!=' ') head=i;
        if(head!=-1){
            if(str[i]=='-'||str[i]=='<')
                break;
            if(str[i]!=' ') tail=i;

        }
    }
    result=str.substr(head,tail-head+1);
    if(tail!=str.size()-1)
        str=str.substr(tail+1);
    return result;
}

int catchSymbol(string & str){
    int result=0;
    for(int i=0;i<str.length();i++){
        if(str[i]=='<'){
            result--;
            continue;
        }
        if(str[i]=='>'){
            result++;
            continue;
        }
        if(str[i]!=' '&&str[i]!='-'){
            str=str.substr(i);
            return result;
        }
    }
    return result;
}

double catchCost(string & str){
    int left,right;

    for(int i=str.length()-1;i>=0;i--){
        if(str[i]==')') right=i;
        if(str[i]=='(') {
            left=i;
            break;
        }
    }
    double result=stringToDouble(str.substr(left+1,right-left-1));
    str=str.substr(0,left);
    return result;
}


string catchMoveDir(SimpleGraph &g, Set<Arc *> &arcset, Arc* thisArc);

void writeGraph(SimpleGraph &g, ostream &outfile)
{
    Set<Arc *> tmpArcSet;
    for(Arc* arc:g.arcs){
        if(tmpArcSet.contains(arc)) continue;
        string start=arc->start->name;
        string finish=arc->finish->name;
        double cost=arc->cost;
        outfile<<start<<" "<<catchMoveDir(g,tmpArcSet,arc)<<" "<<finish<<"("<<cost<<")"<<endl;
    }

}

string catchMoveDir(SimpleGraph &g, Set<Arc *> &arcset, Arc* thisArc){
    string result="-";
    for(Arc* revertArc:thisArc->finish->arcs){
        if(revertArc->finish==thisArc->start) {
            arcset.add(revertArc);
            return result;
        }
    }
    return result+">";
}


