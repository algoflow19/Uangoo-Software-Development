#include <iostream>
#include <string>
#include<iomanip>
#include"error.h"
#include"vector.h"
using namespace std;

int findDuplicate(Vector<int> & vec);

int main() {
    Vector<int> IntArray = {1,2,3,4,5,6,7,8};
    cout<<findDuplicate(IntArray)<<endl;

    return 0;
}
int findDuplicate(Vector<int> & vec){
    int count=0;
    int N=vec.size();
    for(int i=0;i<N;i++)
        count+=vec[i];
    
    return (count-(N*(N-1))/2);
}
