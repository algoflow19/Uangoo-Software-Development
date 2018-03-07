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

indexToName ChangeList;

void ARPANETsim(Graph<IMP,ConnectLine> &g);
void updateIMP(Graph<IMP,ConnectLine> &g,IMP* node);

int main() {

    Graph<IMP,ConnectLine> g;
    ifstream infile;
    infile.open("AirlineGraph");
    g.readGraph(infile);
    ARPANETsim(g);
    for(IMP* node : g.getNodeSet()){
        cout<<node->getName()<<": ";
        for(int i=0;i<10;i++)
            cout<<ChangeList.get(i)<<":"<<node->getPosDistance(ChangeList.get(i))<<" ";
        cout<<endl;
    }
    return 0;
}

void ARPANETsim(Graph<IMP,ConnectLine> &g){
    for(IMP* node : g.getNodeSet())
        node->SetPosDistance(node->getName(),0);

    int i=0;
    while(i!=10){
        for(IMP* node : g.getNodeSet()){
            updateIMP(g,node);
        }

        bool isFinished=true;
        for(int i=0;i<10;i++){
            string ThisName=ChangeList.get(i);
            IMP* node=g.getNode(ThisName);
            cout<<node->size()<<endl;
           if((node->size())!=10) isFinished=false;
        }
        i++;
    }
}

void updateIMP(Graph<IMP,ConnectLine> &g,IMP* node){
    Map<string,int> tmpList;
    cout<<node->getName()<<"'s Negbrious are";
    for(IMP* ip: g.getNeighbors(node)){
        cout<<ip->getName()<<" ";
        for(int i=0;i<10;i++){
            string ThisName=ChangeList.get(i);
            if(!ip->isPosInit(ThisName)) continue;
            int ThisDistance=ip->getPosDistance(ThisName);
            if(tmpList.containsKey(ThisName)){
                if(tmpList.get(ThisName)>ThisDistance){
                    cout<<"give Name:"<<ThisName<<":"<<ThisDistance;
                    tmpList[ThisName]=ThisDistance;
                }
            } else{
                tmpList.add(ThisName,ThisDistance);
                cout<<"G-Name:"<<ThisName<<":"<<ThisDistance<<" ";
            }
        }
    cout<<"**";
    }

    for(int i=0;i<10;i++){
        string ThisName=ChangeList.get(i);
        if(node->isPosInit(ThisName)){
            if(tmpList.containsKey(ThisName))
            if(tmpList.get(ThisName)<node->getPosDistance(ThisName)-1)
                node->SetPosDistance(ThisName,tmpList.get(ThisName)+1);
        } else{
            if(tmpList.containsKey(ThisName))
                node->SetPosDistance(ThisName,tmpList.get(ThisName)+1);
        }
    }
    cout<<endl<<"{";
    for(int i=0;i<10;i++){
        string ThisName=ChangeList.get(i);
        if(node->isPosInit(ThisName))
            cout<<ThisName<<node->getPosDistance(ThisName)<<",";
    }
    cout<<"}";
    cout<<endl;
}
