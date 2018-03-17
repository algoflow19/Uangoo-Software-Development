#include<iostream>
#include"gwindow.h"
#include"plot.h"
#include<cmath>
using namespace std;

double nlogn(double n){
    return (n*log(n));
}
double constant(double n){
    return 1;
}
double liner(double n){
    return n;
}
double  multinomial(double n){
    return n*n;
}

int main() {

    GWindow gw;
    plot(gw,exp,0,15);
    plot(gw,liner,1,15);
    plot(gw,nlogn,1,15);
    plot(gw,multinomial,1,15);
    plot(gw,log,1,15);

    return 0;
}
