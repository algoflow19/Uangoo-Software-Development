#include<iostream>
#include<string.h>
#include"strlib.h"
//#include"console.h"
#include<iomanip>// include setw() setfill() setprecision() three method!
#include<fstream>

using namespace std;

void listPermutations(string str);

void getPermutations(int n,string & str);

int main() {

    listPermutations("1234");

    return 0;
}

void listPermutations(string str){
    getPermutations(0,str);
}

void getPermutations(int n,string & str){
    if( n== (str.length()-1) ){
        cout<<str<<endl;
    }
    else
    {
        for(int i=str.length()-1;i>=n;i--){
            char tmp;
            tmp=str[i];                    //Not Have a fully unstood for how the procress happened!
            str[i]=str[n];                 //And it makes bug!
            str[n]=tmp;
            getPermutations(n+1,str);
            str[n]=str[i];
            str[i]=tmp;
        }
    }
}
