#include <iostream>
#include <string>
#include<iomanip>
#include"vector.h"

using namespace std;

void generateGrayCode(int nBits);
void doneGrayCodeGenerate(int nBits, Vector<string> &codeList);


int main() {

    generateGrayCode(4);

    return 0;
}

void generateGrayCode(int nBits){
    Vector<string> codeList = { "0","1"};
    doneGrayCodeGenerate(nBits,codeList);
}

void doneGrayCodeGenerate(int nBits,Vector<string> & codeList){
    if(nBits==1){
        for(int i=0;i<codeList.size();i++)
            cout<<codeList[i]<<endl;
        return;
    }
    Vector<string> nextCodeList;
    for(int i=0;i<codeList.size();i++){
        nextCodeList.add("0"+codeList[i]);
    }
    for(int i=codeList.size()-1;i>=0;i--){
        nextCodeList.add("1"+codeList[i]);
    }

    return doneGrayCodeGenerate(nBits-1,nextCodeList);
}
