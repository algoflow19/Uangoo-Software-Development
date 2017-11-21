#include "intarray.h"
#include"error.h"

IntArray::IntArray(int n)
{
    arraySize=n;
    ip=new int[n];
    for(int i=0;i<n;i++)
        ip[i]=0;
}

IntArray::IntArray(const IntArray& array)
{
    deepCopy(array);
}

IntArray::~IntArray()
{
    delete[] ip;
}

int IntArray::size() const
{
    return arraySize;
}

int IntArray::get(int k) const
{
    isError(k);
    return ip[k];
}

void IntArray::put(int k, int value)
{
    (*this)[k]=value;
}

IntArray& IntArray::operator=(const IntArray& array)  // '=' should not return void for you may use
{                                                // a1=a2=a3 in some case.
    if(&array!=this){
        delete[] ip;
        deepCopy(array);
    }
    return *this;
}

int &IntArray::operator[](int k)
{
    isError(k);
    return ip[k];
}

void IntArray::isError(int k) const
{
    if(k>=arraySize)
    error("--> Over Bound error");
    if(k<0)
    error("--> Under Bound error");

}

void IntArray::deepCopy(const IntArray &src)
{
    ip=new int[src.size()];
    arraySize=src.size();
    for(int i=0;i<this->size();i++)
       ip[i]=src.get(i);

}

