#include<iostream>
#include<string.h>
#include"strlib.h"
// #include"console.h"
#include<iomanip>   // include setw() setfill() setprecision() three method!
#include<fstream>
#include<sstream>
#include "vector.h"
#include "grid.h"
using namespace std;

#define line_ 4
#define line_num (line_-1)

bool isMagicSqure(Grid<int> & squre);

void countCrossLine(Grid<int> & squre,int & sum, bool & ifContinue,int & rows,int & cols);

int main() {

    ifstream infile;
    infile.open("sourcefile");  // This file save the numbers!!!
    Grid<int> magicSqure(line_,line_);

    for(int row=0;row<=line_num;row++){

        for(int col=0;col<=line_num;col++){
            int testnum;
            infile>>testnum;

            magicSqure[row][col]=testnum;
           // cout<<magicSqure[row][col]<<" "<<row<<" "<<col<<endl;
        }
    }

    cout<<isMagicSqure(magicSqure)<<endl;


    infile.close();
    return 0;

}
/*
    resize numRows


*/

bool isMagicSqure(Grid<int> & squre){

    int rows=squre.numRows();
    int cols=squre.numCols();

    int sum=0;
    bool ifContinue;
    countCrossLine(squre,sum,ifContinue,rows,cols);

    if(!ifContinue) return false;

    int tmpsum;


        for(int x=0;x<=rows-1;x++){
            tmpsum=0;
            for(int i=0;i<=rows-1;i++) tmpsum += squre[i][x];
            if(tmpsum!=sum)  return false;
        }



        for(int x=0;x<=rows-1;x++){
            tmpsum=0;
            for(int i=0;i<=rows-1;i++) tmpsum += squre[x][i];
            if(tmpsum!=sum)  return false;
        }




    return true;
}

void countCrossLine(Grid<int> & squre,int & sum, bool & ifContinue,int & rows,int & cols){

    if(rows!=cols) {
        ifContinue=false;
        return;
    }
    int Truesum=0;

    for(int i=0;i<=rows-1;i++){
        sum += squre[i][i];
    }

    for(int i=0;i<=rows-1;i++){
        Truesum += squre[i][rows-1-i];
    }

    ifContinue = (sum==Truesum);
    return;
}
