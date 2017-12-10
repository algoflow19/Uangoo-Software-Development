#include<iostream>
#include<string.h>
#include"strlib.h"
#include"console.h"
#include<iomanip>   // include setw() setfill() setprecision() three method!
#include<fstream>
#include<sstream>
#include<cctype>

using namespace std;


void emliateMatch(string & receiver, string targetList);

string promptInput(string prompt="Enter the input file:");

void openFileStream(ifstream &stream);
void openFileStream(ofstream &stream);

int main() {

//    double Pi = 3.141592695358979323846;
//    double SPEED_OF_LIGHT = 2.99792458E+8;
//    double FINE_STRUCTURE = 7.2579525E-3;



    ifstream infile;
    ofstream outfile;
    string shotDownStr;

    openFileStream(infile);
    openFileStream(outfile);
    infile.open("sourcefile");
    outfile.open("tragetfile");

    cout<<"Please enter the char you want to emliate:"<<endl;
    cin>>shotDownStr;
    string tmpStr;
    while(!infile.eof()){
        getline(infile,tmpStr);
        emliateMatch(tmpStr,shotDownStr);
        cout<<tmpStr<<endl;
        outfile<<tmpStr;
        if(!infile.eof())
            outfile<<endl;
    }





    return 0;

}







void openFileStream(ifstream & stream){
    while(true){

        stream.open(promptInput("Enter the input file:").c_str());
        if(!stream.is_open())
            cout<<"Can't open the file, please try again!\n";
        else
            break;
    }
}

void openFileStream(ofstream &stream){
    while(true){

        stream.open(promptInput("Enter the input file:").c_str());
        if(!stream.is_open())
            cout<<"Can't open the file, please try again!\n";
        else
            break;
    }
}




void emliateMatch(string & receiver,string targetList){
    int i;
    while(targetList[0]!='\0'){
        targetList[0]=toupper(targetList[0]);
        while((i=receiver.find(targetList[0]))!=string::npos)
            receiver.erase(i,1);
        targetList[0]=tolower(targetList[0]);
        while((i=receiver.find(targetList[0]))!=string::npos)
            receiver.erase(i,1);
        targetList.erase(0,1);
    }
    return;
}



string promptInput(string prompt){
    cout<<prompt;
    string tmp;
    getline(cin,tmp);
    return tmp;

}

