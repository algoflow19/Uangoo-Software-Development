#include <iostream>
#include <string>
#include<iomanip>
#include"vector.h"
#include<iomanip>
#include<ctime>


using namespace std;

void quickSort(Vector<int> &vec,int start,int finish);
int partition(Vector<int> & vec,int start,int finish);
void selectSort(Vector<int> & vec, int start, int finish);
void HybridSort(Vector<int> & vec,int start,int finish);


void judgeMethod();

int main() {

    Vector<int> IntArray = {3,2,1,4,1,3};
    //quickSort(IntArray,0,IntArray.size()-1);
    judgeMethod();
    //selectSort(IntArray,1,IntArray.size()-2);
    //for(int i=0;i<IntArray.size();i++)
    //    cout<<IntArray[i]<<endl;

    return 0;
}

void quickSort(Vector<int> & vec, int start, int finish){
    if(start>=finish) return;

    int standPos=partition(vec,start,finish);
    quickSort(vec,start,standPos-1);
    quickSort(vec,standPos+1,finish);

    return;
}

int partition(Vector<int> & vec,int start,int finish){

    int lh=start+1;
    int rh=finish;
    while(true){
        while(vec[rh]>=vec[start] && rh>lh) rh--;
        while(vec[lh]<=vec[start] && rh>lh) lh++;
        if(rh==lh) break; //
        int tmp=vec[rh];
        vec[rh]=vec[lh];
        vec[lh]=tmp;
    }
     if(vec[start]>vec[lh])   // Lost a suitation!
        {
            int tmp=vec[start];
            vec[start]=vec[rh];
            vec[lh]=tmp;
            return lh;
        }

        return start;
    }



void judgeMethod(){
    Vector< Vector<int> > testset ;
    Vector<int> setsVolume = { 10,50,100,500,1000,10000};
    for(int i=0;i<setsVolume.size();i++){
        Vector<int> initVector={};
        testset.add(initVector);
        for(int n=0;n< setsVolume[i];n++){
            testset[i].add(rand());
        }
    }

    Vector<double> time(setsVolume.size(),0);

    for(int i=0;i<setsVolume.size();i++){
        double start=double(clock())/CLOCKS_PER_SEC;
        for(int n=0;n<10;n++){
            Vector<int> tmpset=testset[i];
            quickSort(tmpset,0,tmpset.size()-1);   //change here to choose method!   ******************************
            
            //HybridSort(tmpset,0,tmpset.size()-1);
        }
        double finish=double(clock())/CLOCKS_PER_SEC;
        time[i]=(finish-start)/10;
    }
    cout<<setw(12)<<"N"<<"   |"<<setw(12)<<"Time (msec)"<<endl;
    cout<<"----------------------------"<<endl;
    for(int i=0;i<setsVolume.size();i++){
        cout<<setw(12)<<setsVolume[i]<<"   |"<<setw(12)<<time[i]<<endl;
    }

}

void selectSort(Vector<int> & vec,int start,int finish){
    for(int endFlag=start;endFlag<=finish;endFlag++){

        if(vec[start]>=vec[endFlag]){
            int tmp=vec[endFlag];
            for(int i=endFlag;i>start;i--)
                vec[i]=vec[i-1];
            vec[start]=tmp;
            continue;
        }

        for(int i=start;i<endFlag;i++){
            if(vec[i]<=vec[endFlag]&&vec[i+1]>=vec[endFlag]){
                int tmp=vec[endFlag];
                for(int n=endFlag;n>i+1;n--)
                    vec[n]=vec[n-1];
                vec[i+1]=tmp;
                break;
            }
        }
    }
}

void HybridSort(Vector<int> & vec,int start,int finish){
    if(start>=finish) return;

    int standPos=partition(vec,start,finish);

    if(standPos-start>50)
        quickSort(vec,start,standPos-1);
    else
        selectSort(vec,start,standPos-1);

    if(finish-standPos>50)
        quickSort(vec,standPos+1,finish);
    else
        selectSort(vec,standPos+1,finish);

    return;
}
