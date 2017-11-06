#include<iostream>
#include<string.h>
#include"strlib.h"
//#include"console.h"
#include<iomanip>// include setw() setfill() setprecision() three method!
#include<fstream>
#include"vector.h"

using namespace std;

int countFifteens(Vector<int> & cards);

int ifcountN(Vector<int>  cards,int N);

int main() {

    Vector<int> cards={1,5,10,4,9};
    cout<<countFifteens(cards)<<endl;

    return 0;
}

int countFifteens(Vector<int> & cards){
    return ifcountN(cards,15);
}

int ifcountN(Vector<int>  cards,int N){

    if(N==0) return 1;
    if(cards.size()==1){
        if(cards[0]==N)
            return 1;
    else return 0;
}
    
    int Theint=cards[0];
    cards.remove(0);
    Vector<int> recards=cards;
    /*
    *
    * When using &, you must pay attention to Parallelism!!!
    * Make a mistake here! 
    *         ↘
    */
    return  ifcountN(recards,N)+ifcountN(recards,N-Theint);

}
