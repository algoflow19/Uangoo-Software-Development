#include <iostream>
#include <string>
#include "error.h"
#include "exp.h"
#include "parser.h"
#include "tokenscanner.h"
#include"plot.h"
#include<cmath>
// #include"console.h"
using namespace std;

const double PI=3.14159265358;
double integrate(double (*fn)(double),double minX,double maxX,int squareNumber);

int main() {


    cout<<integrate(cos,0,PI,40)<<endl;
    return 0;
}

double integrate(double (*fn)(double),double minX,double maxX,int squareNumber){
    double dx=(maxX-minX)/squareNumber;
    double x0=minX;
    double result=0;
    for(int i=0;i<squareNumber;i++){
        double x1=x0+dx;
        double x=(x0+x1)/2;
        result+=fn(x);
        x0=x1;
    }
    return (maxX-minX)*result/squareNumber;
}
