#include<iostream>
#include<string.h>
#include"strlib.h"
//#include"console.h"
#include<iomanip>// include setw() setfill() setprecision() three method!
#include<fstream>
#include "vector.h"
#include "random.h"
#include "queue.h"
using namespace std;

const double ARRIBAL_PROBABILITY = 0.1;
const int MIN_SERVICE_TIME = 5;
const int MAX_SERVICE_TIME = 15;
const int SIMULATION_TIME = 2000;
const int QUEUE_NUM = 1;

void runSimulation(int & nServed, int & totalWaitTime,int & totalQueueLength,
                   Vector< Queue<int> >  & queuelist);

void printReport(int & nServed, int & totalWaitTime, int & totalQueueLength);

int findshortestqueue(Vector< Queue<int> >  & queuelist);

int main() {

    int nServed;
    int totalWaitTime;
    int totalQueueLength;

    Vector< Queue<int> > queuelist(QUEUE_NUM);
    runSimulation(nServed,totalWaitTime,totalQueueLength,queuelist);
    printReport(nServed,totalWaitTime,totalQueueLength);

    return 0;
}

void runSimulation(int & nServed, int & totalWaitTime,int & totalQueueLength,
                   Vector< Queue<int> >  & queuelist){

    nServed=0;
    totalQueueLength=0;
    totalWaitTime=0;
    int remaintime[QUEUE_NUM];

    for(int i=0;i<=QUEUE_NUM-1;i++)
        remaintime[i]=0;


    for(int time=0;time<=SIMULATION_TIME;time++){
        if(randomChance(ARRIBAL_PROBABILITY))
            queuelist[findshortestqueue(queuelist)].enqueue(time);


        for(int i=0;i<=QUEUE_NUM-1;i++){
            if(remaintime[i]>0)
                remaintime[i]--;

            else if(!queuelist[i].isEmpty()){

                totalWaitTime += time-queuelist[i].dequeue();
                remaintime[i] += randomInteger( MIN_SERVICE_TIME , MAX_SERVICE_TIME );
                nServed++;
            }

            totalQueueLength += queuelist[i].size();

        }
    }


}

void printReport(int & nServed,int & totalWaitTime,int & totalQueueLength){
    cout<<"Simulation result report:"<<endl;
    cout<<"   SIMULATION TIME:  "<<SIMULATION_TIME<<endl;
    cout<<"   ARRIVAL_PROBABILITY:  "<<ARRIBAL_PROBABILITY<<endl;
    cout<<"   MIN_SERIVER_TIME:  "<<MIN_SERVICE_TIME<<endl;
    cout<<"   MAX_SERIVER_TIME:  "<<MAX_SERVICE_TIME<<endl<<endl<<endl;
    cout<<"   CUSTROM_SERIVED:   "<<nServed<<endl;
    cout<<"   QUEUE_NUM:  "<<QUEUE_NUM<<endl;
    cout<<"   Average waiting time:  "<<totalWaitTime/double(QUEUE_NUM*nServed)<<"seconds"<<endl;
    cout<<"   Average queue length:  "<<totalQueueLength/double(QUEUE_NUM*SIMULATION_TIME)<<"people"<<endl;

}

int findshortestqueue(Vector< Queue<int> >  & queuelist){

    int signal=queuelist[0].size();
    int Rnum=0;

    for(int i=0;i<=QUEUE_NUM-1;i++){
        if(signal>queuelist[i].size())
            Rnum=i;
    }

    return Rnum;

}
