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

void plot(GWindow &gw, string strExp, double minX, double maxX, double minY, double maxY);
void plot(GWindow &gw, string strExp, double minX, double maxX);
const double PI=3.1415926;

int main() {
    GWindow gw;

    plot(gw,string("sin(2*x)+cos(3*x)"),-1*PI,PI);  // When Using "sin(2*x)+cos(3*x)",compiler fail to know
                                                    // match which function.
    return 0;
}

void plot(GWindow &gw, string strExp, double minX, double maxX, double minY, double maxY){
    plot(gw,ExpressionFunciton(strExp),minX,maxX,minY,maxY);
}
void plot(GWindow &gw, string strExp, double minX, double maxX){
    plot(gw,ExpressionFunciton(strExp),minX,maxX);
}
