#include <iostream>
#include <string>
#include "error.h"
#include<cmath>
#include"vector.h"
#include<algorithm>
#include"assert.h"
// #include"console.h"
using namespace std;

bool lessIgnoringCase(string s1, string s2);

int main() {

    Vector<string> v;
    v.add("Abc");
    v.add("bbc");
    v.add("bbd");
    v.add("XBd");
    v.add("Xzd");
    v.add("bbc");
    sort(v.begin(),v.end(),lessIgnoringCase);
    for(Vector<string>::iterator it=v.begin();it<v.end();it++){
        cout<<*it<<endl;
    }
    return 0;
}


bool lessIgnoringCase(string s1, string s2) {
    int length = s1.length();
    for (int i = 0; i < length; i++) {
        unsigned short cs1 = s1[i];
        unsigned short cs2 = s2[i];
        if (cs1 > 90) cs1 -= 32;
        if (cs2 > 90) cs2 -= 32;
        if (cs1 != cs2) return cs1 < cs2;
    }
    return false;
}
