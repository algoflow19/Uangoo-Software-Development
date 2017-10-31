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

    string str="",tmpstr;
    char tmp;


    while(!infile.eof()){
        tmp=infile.get();
        if(tmp=='\n'){
            str="";
            outfile<<endl;
        }
        else if(tmp =='\t'){
            int len=str.length();
            for(int i=0; i <= 7-len;i++)
                str += ' ';
            outfile<<str;
            str="";
        }
        else
        {
            str += tmp;
        }
    }






    return 0;

}



