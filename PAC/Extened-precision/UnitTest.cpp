#include<iostream>
#include<string>
#include<assert.h>
#include<string>
#include"bigint.h"
#include<iomanip>
using namespace std;

int main(){

    string a="1";
    for(int i=1;i<=99;i++){
        a=(BigInt(i)*BigInt(a)).toString();
        cout<<"The "<<setw(2)<<i<<"! is "<<a<<endl;
    }

    cout<<"Mission Success!"<<endl;


    return 0;
}



