#include <iostream>
#include <string>
#include<iomanip>
#include"error.h"
#include<cassert>
#include"strlib.h"
#include"mystring.h"
//#include"console.h"

using namespace std;

int main() {


    MyString str1("123456789");
    assert(str1.length()==9);
    for(int i=1;i<=9;i++)
        assert(str1.get(i-1)=='0'+i);

    assert((str1.toString())=="123456789");
    assert( (str1.substr(0,2)).toString() =="12");
    assert((str1.substr(1,5)).toString() =="23456");
    assert((str1.substr(3)).toString() =="456789");
    MyString str2("abc123");
    assert((str1+str2).length()==15);
    assert((str1+str2).toString()=="123456789abc123");
    str1+= str2;
    assert(str1.toString()=="123456789abc123");
    MyString tmpStr("If this could be show? /end!");
    cout<<str1<<endl;
    cout<<tmpStr<<endl;
    for(int i=0;i<9;i++)
        assert(str1[i]=='1'+i);
    for(int i=0;i<9;i++)
        str1[i]='0'+i;
    for(int i=0;i<9;i++)
        assert(str1[i]=='0'+i);
    MyString blStr1("abc");
    MyString blStr2("abce");
    MyString blStr3("dbce");
    MyString blStr4("dbce");
    assert(blStr1<blStr2);
    assert(blStr4==blStr3);
    assert(blStr3>blStr2);
    assert(blStr3>=blStr4);
    assert(blStr3<=blStr4);

    return 0;
}


