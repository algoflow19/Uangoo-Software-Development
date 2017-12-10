#include<iostream>
#include<string.h>
#include"strlib.h"
// #include"console.h"
#include<iomanip>   // include setw() setfill() setprecision() three method!
#include<fstream>
#include<sstream>
#include<cctype>

using namespace std;



int main() {

//    double Pi = 3.141592695358979323846;
//    double SPEED_OF_LIGHT = 2.99792458E+8;
//    double FINE_STRUCTURE = 7.2579525E-3;

    ifstream infile;
    ofstream outfile;

    infile.open("sourcefile");
    outfile.open("tragetfile");

    string tmpStr;
    char thisChar;

    while(!infile.eof()) {
        thisChar = infile.get();

        if(!infile.eof()&&thisChar!='/')
            outfile << thisChar;

        else if(!infile.eof()&&(thisChar=infile.get())=='*'){

             while(true){
                 while(infile.get()!='*');
                 if(infile.get()=='/')
                     break;
             }

        }
        else if(thisChar=='/'){
            while(infile.get() != '\n') ;
            outfile << '\n';
        }
        else
            if(!infile.eof())
            {
            outfile<<'/'<<thisChar;
            }
    }


    infile.close();
    outfile.close();
    return 0;

}
