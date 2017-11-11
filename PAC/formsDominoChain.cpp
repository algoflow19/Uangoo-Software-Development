#include <iostream>
#include <string>
#include<iomanip>
#include<grid.h>
#include"error.h"
#include"vector.h"
#include"domino.h"

using namespace std;

bool formsDominoChain(Vector<Domino> & domino);
bool doneDominoChain(Vector<Domino> & domino,int & pos,bool & startFlag);
bool isVaild(Vector<Domino> & domino,int & pos);

int main() {

    Vector<Domino> domino(4);
    domino[0].SetDots(2,6);
    domino[1].SetDots(1,6);
    domino[2].SetDots(4,1);
    domino[3].SetDots(3,4);

    if(formsDominoChain(domino))
        for(int i=0;i<=domino.size()-1;i++)
            cout<<domino[i]<<endl;
    else
        cout<<"Can't find a solution!"<<endl;

    return 0;

}

bool formsDominoChain(Vector<Domino> & domino){
    int pos=0;bool startFlag=false;
    return doneDominoChain(domino,pos,startFlag);
}

bool doneDominoChain(Vector<Domino> & domino, int & pos, bool & startFlag){
    if(!isVaild(domino,pos))
        return false;
    else if(pos==(domino.size()-1)) return true;

    if(startFlag)
       pos++; else
        startFlag=true;

    if(doneDominoChain(domino,pos,startFlag))
        return true;
    domino[pos].SetDots(domino[pos].getRightDots(),domino[pos].getLiftDots());
    if(doneDominoChain(domino,pos,startFlag))
        return true;
    domino[pos].SetDots(domino[pos].getRightDots(),domino[pos].getLiftDots());
    pos--;

    return false;
}

bool isVaild(Vector<Domino> & domino,int & pos){
    if(pos==0) return true;
        return (domino[pos-1].getRightDots()==domino[pos].getLiftDots());
}
