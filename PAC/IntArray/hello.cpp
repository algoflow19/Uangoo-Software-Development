#include <iostream>
#include <string>
#include<iomanip>
#include"error.h"
#include<cassert>
#include"strlib.h"
#include"intarray.h"
//#include"console.h"

using namespace std;

int main() {

    IntArray myArray(10);
    for(int i=0;i<10;i++)
        assert(myArray[i]==0);
    assert(myArray.size()==10);
    for(int i=0;i<10;i++)
        myArray.put(i,i);
    for(int i=0;i<10;i++)
        assert(myArray.get(i)==i);
    for(int i=0;i<10;i++)
        assert(myArray[i]==i);
    for(int i=0;i<10;i++)
        myArray[i]=9-i;
    for(int i=0;i<10;i++)
        assert(myArray[i]==(9-i));

    IntArray testArray1(3);

    for(int i=0;i<testArray1.size();i++)
        testArray1[i]=i;

    myArray=testArray1;
    assert(myArray.size()==3);
    for(int i=0;i<myArray.size();i++)
        assert(myArray[i]==i);

    IntArray testArray2(testArray1);
    assert(testArray2.size()==3);
    for(int i=0;i<testArray2.size();i++)
        assert(testArray2[i]==i);

    myArray[0]=12;
    cout<<myArray[0]<<endl;

    return 0;

}


