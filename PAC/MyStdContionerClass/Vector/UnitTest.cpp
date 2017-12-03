#include<iostream>
#include<string>
#include<assert.h>
#include"vector.h"
using namespace std;

int main(){
    Vector<int> v0;
    assert(v0.isEmpty());
    assert(v0.size()==0);
    Vector<int> v1(4,9);
    assert(v1.size()==4);
    Vector<int> v2(3,9);
    assert(v2.size()==3);
    Vector<int> v3(v2);
    assert(v3.size()==3);
    v2.clear();
    assert(v2.isEmpty());
    assert(v2.size()==0);
    v3.add(5);
    assert(v3.get(v3.size()-1)==5);
    v3.set(3,1);
    assert(v3.get(3)==1);
    v1.add(12);
    v2=v3;
    assert(v2.size()==4);
    assert(v2.isEmpty()==false);
    assert(v2[0]==9);
    assert(v2[1]==9);
    assert(v2[2]==9);
    assert(v2[3]==1);
    v2[0]=2;
    assert(v2.get(0)==2);
    assert(v2[0]==2);
    v2[3]=15;
    assert(v2[3]==15);
    v3=v2;
    assert(v3[3]==15);
    assert(v3.get(0)==2);
    Vector<int> v4(v3);
    assert(v4.size()==4);
    assert(v4[1]==9);
    assert(v4[2]==9);
    assert(v4[3]==15);
    v4.set(2,1);
    assert(v4.get(2)==1);

    cout<<"Unit Passed the test!"<<endl;
    return 0;
}
