#include<iostream>
#include<string.h>
#include"strlib.h"
//#include"console.h"
#include<iomanip>// include setw() setfill() setprecision() three method!
#include<fstream>
#include "vector.h"
#include "random.h"
#include "queue.h"
#include "grid.h"
using namespace std;

const int MIN_FLOAT_TIME=1;
const int MAX_FLOAT_TIME=4;

void printReport(int & simulation,int & maxAtomNum,double & tragetTrapCount);

int main() {

    Grid<bool> bottomTrap(25,25);
    int simulationTime=0;
    Vector<int> airSpace;
    int maxAtomNum=0;
    int tmprow,tmpcol;
    double TragetTrapCount=0;

    airSpace.add(1);

    while(true){
        for(int i=airSpace.size()-1;i>=0;i--){
            airSpace[i]--;
            if(airSpace[i]==0){
                airSpace.remove(i);
                if(bottomTrap[tmprow=randomInteger(0,24)][tmpcol=randomInteger(0,24)]);
            else
                   {
                    bottomTrap[tmprow][tmpcol]=true;
                    airSpace.add(randomInteger(MIN_FLOAT_TIME,MAX_FLOAT_TIME));
                    airSpace.add(randomInteger(MIN_FLOAT_TIME,MAX_FLOAT_TIME));
                }
            }
        }

        if(airSpace.size()>maxAtomNum)
            maxAtomNum=airSpace.size();

        simulationTime++;


        if(airSpace.size()==0)
            break;
    }

    for(int rows=0;rows<=24;rows++)
        for(int cols=0;cols<=24;cols++){
            if(bottomTrap[rows][cols]==true)
                TragetTrapCount++;
        }


    printReport(simulationTime,maxAtomNum,TragetTrapCount);

    return 0;
}

void printReport(int & simulation,int & maxAtomNum,double & tragetTrapCount){
    cout<<"The total simulation time is "<<simulation<<" clcys"<<endl;
    cout<<"The max atom num is "<<maxAtomNum<<endl;
    cout<<"PrcentAge is "<<tragetTrapCount/625<<endl;

}
