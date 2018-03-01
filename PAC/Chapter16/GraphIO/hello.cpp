#include <iostream>
#include <string>
#include<assert.h>
#include<fstream>
#include"graphio.h"
using namespace std;



int main() {
    ifstream infile;
    ofstream outfile;
    SimpleGraph g;
    infile.open("AirlineGraph");

    readGraph(g,infile);
    outfile.open("testfile");
    writeGraph(g,outfile);
    infile.close();
    outfile.close();
    return 0;

}


