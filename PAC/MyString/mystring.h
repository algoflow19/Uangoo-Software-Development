#ifndef MYSTRING_H
#define MYSTRING_H
#include<string>
#include<iostream>
#include"error.h"
class MyString
{
public:
    //MyString();
    MyString(const MyString& str);
    MyString(std::string str);
    ~MyString();
    int length() const;
    void deepCopy(const MyString& str);         // It can delete the sp auto(if not NULL)
                                                // It prevent coping itself and delete NULL pointer
    MyString& operator=(const MyString& str);
    std::string toString() const;
    char get(int k) const;


    MyString substr(int start,int n) const;
    MyString substr(int start) const;

    MyString operator+(const MyString& str) const;
    MyString& operator+=(const MyString& str);

    friend std::ostream& operator<<(std::ostream & os,MyString& str);
    char& operator[](int n);

    bool operator==(const MyString& str) const; // This
    bool operator!=(const MyString& str) const;
    bool operator<(const MyString& str) const;  // And this is fulled defined.
    bool operator<=(const MyString& str) const;
    bool operator>(const MyString& str) const;
    bool operator>=(const MyString& str) const;



private:

    void isError(int k) const;
    void chStr(char * sp, int length);
    int strLength;
    char * sp;

};

std::ostream& operator<<(std::ostream & os,MyString& str);

#endif // MYSTRING_H
