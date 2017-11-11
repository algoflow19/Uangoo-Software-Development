#include <iostream>
#include <string>
#include<iomanip>
#include<grid.h>
#include"error.h"
#include"vector.h"
#include"domino.h"

using namespace std;

/*  By list all possible and test the need of stockLength, you can get the min require number! */
int cutStock(Vector<int> & requests, int stockLength);
int doneCutStock(Vector<int> & requests, int stockLength, int & count);

int main() {

    

    return 0;

}



int cutStock(Vector<int> & requests, int stockLength){
    int count=1;
    doneCutStock(requests,stockLength,count);
    return count;
}

bool doneCutStock(Vector<int> & requests, int stockLength,int & count){
    int tmpsum=0;
    for(int Eilment : requests){
        tmpsum+= Eilment;
    }
    if(tmpsum<=stockLength) return true;
    
    count++;
    
    
    
}
