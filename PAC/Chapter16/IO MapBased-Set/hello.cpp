#include <iostream>
#include <string>
#include"mapset.h"
#include<assert.h>
#include"console.h"

using namespace std;

int main() {

    MapSet<string> s1,s2;

    cout<<"Enter s1:";
    cin>>s1;
    cout<<"Enter s2:";
    cin>>s2;
    cout<<"s1 + s2 = "<<s1+s2<<endl;
    cout<<"s1 * s2 = "<<s1*s2<<endl;
    cout<<"s1 - s2 = "<<s1-s2<<endl;

    return 0;

}


