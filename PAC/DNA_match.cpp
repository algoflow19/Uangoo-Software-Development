#include<iostream>
#include<string.h>
#include"strlib.h"

using namespace std;

int findDNAMatch(string s1,string s2,int start=0);

// Find the frist place that s1 showed in s2

string ReverseDNA(string str);

int main() {

    string s1="TGC", \
            s2="TAACGGTACGTC";

    cout<<"Show where is the match place "<<findDNAMatch(s1,s2,6)<<endl;

    return 0;

}


int findDNAMatch(string s1,string s2,int start){
    s1=ReverseDNA(s1);

    return s2.find(s1,start);

}

string ReverseDNA(string str){
    for(int i=0;i<str.length();i++)

        switch(str[i]) {
        case('A'):
            str[i]='T';
            break;

        case('T'):
            str[i]='A';
            break;

        case('G'):
            str[i]='C';
            break;

        case('C'):
            str[i]='G';
            break;

        }
        return str;
}
