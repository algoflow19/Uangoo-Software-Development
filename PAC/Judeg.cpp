#include <iostream>
#include <string>
#include<iomanip>
#include"error.h"
#include"vector.h"
#include"strlib.h"
#include"console.h"

using namespace std;

const int MAX_JUDGES=100;
double scores[MAX_JUDGES];

int main() {

    double * currentSelect;
    currentSelect=scores;
    cout<<"Enter a score for each judge in the range 0 to 10"<<endl;
    while (true) {
        cout<<"Judge #"<<currentSelect-scores+1<<":  ";
        string tmp;
        getline(cin,tmp); // capture whitespace!
        if(tmp[0]!=' '&&tmp.length()!=0){
        *currentSelect=stringToReal(tmp);
        currentSelect++;
        }
        if(currentSelect-scores>100||(tmp[0]==' '||tmp.length()==0)){
            double sum=0;
            double min,max;
            min=max=scores[0];

            for(int i=0;i<currentSelect-scores;i++){
            if(min>scores[i])
            min=scores[i];
            if(max<scores[i])
            max=scores[i];
            sum+=scores[i];
            }
            cout<<"The average after eliminating "<<min<<" and "<<max<<" is "<<(sum-max-min)/(currentSelect-scores-2)<<endl;
            return 0;
        }

    }


    return 0;
}
