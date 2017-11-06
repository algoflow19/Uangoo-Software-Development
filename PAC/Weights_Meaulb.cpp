#include<iostream>
#include<string.h>
#include"strlib.h"
//#include"console.h"
#include<iomanip>// include setw() setfill() setprecision() three method!
#include<fstream>
#include"vector.h"

using namespace std;

bool isMeasurable(int targetk,Vector<int> & weights);

int main() {



    int tragetk=11;
    Vector<int> weights={1,3,5,2};

    cout<< isMeasurable(tragetk,weights) << endl;

    return 0;
}


bool isMeasurable(int targetk, Vector<int> &weights){
    if(weights.size()==1)
        return weights[0]==targetk||targetk==0;  // It's easy for me to make this mistake!
                                                 // Miss the simplest condition!
     else{
       Vector<int> reweights=weights;
       int tmpint=reweights[0];
       reweights.remove(0);

       return isMeasurable(targetk-tmpint,reweights)||
                isMeasurable(targetk+tmpint,reweights)||isMeasurable(targetk,reweights);

    }
}
