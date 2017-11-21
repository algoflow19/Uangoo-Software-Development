#include "mystring.h"
using namespace std;


MyString::MyString(const MyString &str)
{

    deepCopy(str);
}

MyString::MyString(std::__cxx11::string str)
{
    sp=new char[str.length()];
    strLength=str.length();
    for(int i=0;i<strLength;i++)
        sp[i]=str[i];
}

MyString::~MyString()
{
    //cout<<"Run the ~MyString"<<endl;
    delete[] sp;
}

int MyString::length() const
{
    return strLength;
}

char &MyString::operator[](int n)
{
    isError(n);
    return sp[n];
}

bool MyString::operator==(const MyString &str) const
{
    if(str.length()!=strLength)
        return false;
    for(int i=0;i<strLength ;i++)
        if(this->get(i)!=str.get(i)) return false;
    return true;
}

bool MyString::operator!=(const MyString &str) const
{
    return !(*this==str);
}

bool MyString::operator<(const MyString &str) const
{
    for(int i=0;i<min(this->length(),str.length());i++){
        if(this->get(i)!=str.get(i))
            return this->get(i)<str.get(i);
    }

    return this->length()<str.length();
}

bool MyString::operator<=(const MyString &str) const
{
    return *this==str||*this<str;
}

bool MyString::operator>(const MyString &str) const
{
    return !(*this<=str);
}

bool MyString::operator>=(const MyString &str) const
{
    return *this==str||*this>str;
}

char MyString::get(int k) const
{

    isError(k);
    return sp[k];
}

MyString MyString::substr(int start, int n) const
{
    isError(start);
    if(start+n>strLength) error("Over bound error");
    MyString tmpStr("");
    char *tmpSp=new char[n];
    tmpStr.chStr(tmpSp,n);
    for(int i=0;i<n;i++)
        tmpStr[i]=this->get(start+i);

    return tmpStr;
}

MyString MyString::substr(int start) const
{
    return substr(start,strLength-start);
}

MyString MyString::operator+(const MyString &str) const
{
    char *tmpSp;
    MyString tmpStr("");
    tmpSp=new char[this->length()+str.length()];
    for(int i=0;i<strLength;i++)
        tmpSp[i]=this->get(i);
    for(int i=0;i<str.length();i++)
        tmpSp[i+strLength]=str.get(i);

    tmpStr.chStr(tmpSp,strLength+str.length());
    return tmpStr;
}

MyString& MyString::operator+=(const MyString &str)
{
    return *this=(*this+str);
}

void MyString::deepCopy(const MyString &str)
{
    sp=new char[str.length()];
    strLength=str.length();
    for(int i=0;i<this->length();i++)
        sp[i]=str.get(i);

}

MyString &MyString::operator=(const MyString &str)
{
    if(this!=&str){
        delete[] sp;
        deepCopy(str);
    }
    return *this;
}

string MyString::toString() const
{
    string str="";
    str.resize(strLength);
    for(int i=0;i<strLength;i++)
        str[i]=this->get(i);

    return str;
}

void MyString::isError(int k) const
{
    if(k>=strLength)
    error("--> Over Bound error");
    if(k<0)
    error("--> Under Bound error");

}

void MyString::chStr(char *sp, int length)
{
    delete[] this->sp;
    this->sp=sp;
    this->strLength=length;

}


ostream &operator<<(ostream &os, MyString &str)
{
    for(int i=0;i<str.length();i++)
        os<<str[i];
    return os;
}
