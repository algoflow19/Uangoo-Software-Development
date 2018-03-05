#include "graphpriv.h"
#include<string>
using namespace std;

std::string catchWord(std::string &str){
    std::string result;
    int head,tail;
    head=tail=-1;
    for(int i=0;i<str.length();i++){
        if(head==-1&&str[i]!=' ') head=i;
        if(head!=-1){
            if(str[i]=='-'||str[i]=='<')
                break;
            if(str[i]!=' ') tail=i;

        }
    }
    result=str.substr(head,tail-head+1);
    if(tail!=str.size()-1)
        str=str.substr(tail+1);
    return result;
}

int catchSymbol(std::string & str){
    int result=0;
    for(int i=0;i<str.length();i++){
        if(str[i]=='<'){
            result--;
            continue;
        }
        if(str[i]=='>'){
            result++;
            continue;
        }
        if(str[i]!=' '&&str[i]!='-'){
            str=str.substr(i);
            return result;
        }
    }
    return result;
}

double catchCost(std::string & str){
    int left,right;

    for(int i=str.length()-1;i>=0;i--){
        if(str[i]==')') right=i;
        if(str[i]=='(') {
            left=i;
            break;
        }
    }
    double result=stringToDouble(str.substr(left+1,right-left-1));
    str=str.substr(0,left);
    return result;
}
