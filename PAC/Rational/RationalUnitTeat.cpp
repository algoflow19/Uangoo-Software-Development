#include <iostream>
#include <string>
#include<iomanip>
#include"error.h"
#include<cassert>
#include"strlib.h"
#include"rational.h"
#include<sstream>
//#include"console.h"

using namespace std;

int main() {

    Rational rat1;
    Rational rat2(3);
    Rational rat3(2,5);

    assert(rat1.toString()=="0");
    assert(rat2.toString()=="3");
    assert(rat3.toString()=="2/5");
    stringstream sstr;
    sstr<<rat3;
    string str;
    sstr>>str;
    assert(str=="2/5");
    stringstream sstr2;
    sstr2<<rat1;
    string str2;
    sstr2>>str2;
    assert(str2=="0");
    assert((rat1+rat3).toString()=="2/5");
    assert((rat1-rat3).toString()=="-2/5");
    assert((rat1*rat3).toString()=="0");
    assert((rat1/rat3).toString()=="0");
    assert((rat1+rat2).toString()=="3");
    assert((rat1-rat2).toString()=="-3");
    assert((rat1*rat2).toString()=="0");
    assert((rat1/rat2).toString()=="0");
    assert((rat2+rat3).toString()=="17/5");
    assert((rat2-rat3).toString()=="13/5");
    assert((rat2*rat3).toString()=="6/5");
    assert((rat2/rat3).toString()=="15/2");

    return 0;
}


