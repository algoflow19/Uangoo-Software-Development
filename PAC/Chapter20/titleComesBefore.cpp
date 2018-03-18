#include <iostream>
#include <string>
#include "error.h"
#include<cmath>
#include"vector.h"
#include<algorithm>
#include"tokenscanner.h"
// #include"console.h"
using namespace std;

bool titleComeBefore(string s1,string s2);
string getNextToken(TokenScanner& scanner);
void sharpStrHead(TokenScanner& scanner);
bool lessIgnoringCase(string s1, string s2,bool& equalFlag);
bool lessIgnoringCase(string s1, string s2);

int main() {

    cout<<titleComeBefore("AN k aaa"," x aax")<<endl;

    return 0;
}

bool titleComeBefore(string s1,string s2){
    TokenScanner scanner1(s1);
    TokenScanner scanner2(s2);
    sharpStrHead(scanner1);
    sharpStrHead(scanner2);
    while(true){
        bool isEqual=false;
        bool result=lessIgnoringCase(getNextToken(scanner1),getNextToken(scanner2),isEqual);
        if(!isEqual) return result;
        if(!scanner1.hasMoreTokens()&&!scanner2.hasMoreTokens()) return false;
    }
}


void sharpStrHead(TokenScanner& scanner){
    string token="";
    if(scanner.hasMoreTokens()){
        token=scanner.nextToken();
        if(scanner.getTokenType(token)==WORD){
            bool breakFlag=false;
            lessIgnoringCase(token,"an",breakFlag);
            lessIgnoringCase(token,"a",breakFlag);
            lessIgnoringCase(token,"the",breakFlag);
            if(breakFlag) return;
        }
    }
    scanner.saveToken(token);
}

string getNextToken(TokenScanner& scanner){
    while(scanner.hasMoreTokens()){
        string token=scanner.nextToken();
        if(scanner.getTokenType(token)==OPERATOR) continue;
        if(scanner.getTokenType(token)==WORD) return token;
        if(token==" ") return token;
    }
    return "";
}


bool lessIgnoringCase(string s1, string s2,bool& equalFlag) {
    int length = max(s1.length(),s2.length());
    for (int i = 0; i < length; i++) {
        unsigned short cs1 = s1[i];
        unsigned short cs2 = s2[i];
        if (cs1 > 90) cs1 -= 32;
        if (cs2 > 90) cs2 -= 32;
        if (cs1 != cs2) return cs1 < cs2;
    }
    equalFlag=true;
    return false;
}

bool lessIgnoringCase(string s1, string s2) {
    bool f;
    return lessIgnoringCase(s1,s2,f);
}


