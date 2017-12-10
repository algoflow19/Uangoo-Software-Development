#include<iostream>
#include<string.h>
#include"strlib.h"
//#include"console.h"
#include<iomanip>   // include setw() setfill() setprecision() three method!
#include<fstream>
#include<sstream>
#include<cmath>
using namespace std;



int main() {

//    double Pi = 3.141592695358979323846;
//    double SPEED_OF_LIGHT = 2.99792458E+8;
//    double FINE_STRUCTURE = 7.2579525E-3;

    ifstream file;
    file.open("testfile");

    string str;
    int lines=0,words=0,chars=0;

    while(getline(file,str)){

       istringstream sstream(str);
        lines++;
        while(!sstream.eof()){
            words++;
            sstream>>str>>ws;
             int i=0;

            while(str[i]!='\0'){
                cout<<str[i];
                chars++;
                 i++;
            }

        }
}

    cout<<"Lines words and chars is "<<lines<<" "<<words<<" "<<" "<<chars;

    return 0;

}
