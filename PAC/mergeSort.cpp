#include <iostream>
#include <string>
#include<iomanip>
#include"strlib.h"
//#include"console.h"

using namespace std;
void sort(int array[],int n);
void merge(int vec[], int vecLength, int v1[], int v1Length, int v2[], int v2Length);

int main() {
    int array[]= { 1,5,6,2,4,1,3,5,2,37,8};
    unsigned int N=sizeof array / sizeof array[0];
    sort(array,N);
    for(int i=0;i<N;i++)
        cout<<array[i]<<endl;

    return 0;
}

void sort(int array[],int n){
    if(n==1) return;
    int v1[n/2];  // littler number!
    int v2[n/2+n%2];  // bigger number!
    for(int i=0;i<n;i++){
        if(i<n/2)
            v1[i]=array[i];
        else
            v2[i-n/2]=array[i];
    }

    sort(v1,n/2);
    sort(v2,n/2+n%2);
    merge(array,n,v1,n/2,v2,n/2+n%2);

}
void merge(int vec[],int vecLength,int v1[],int v1Length,int v2[],int v2Length){
    int v1p,v2p,vecP;
    v1p=v2p=0;
    for(int i=0;i<vecLength;i++){
        vecP=i;
        if(v1p==v1Length||v2p==v2Length)
            break;
        if(v1[v1p]<v2[v2p]){
            vec[i]=v1[v1p++];
        }
        else{
            vec[i]=v2[v2p++];
        }
    }
    while(v1p!=v1Length){
        vec[vecP++]=v1[v1p++];
    }
    while(v2p!=v2Length){
        vec[vecP++]=v2[v2p++];
    }

}
