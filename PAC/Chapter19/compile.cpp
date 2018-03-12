#include <iostream>
#include<fstream>
#include <string>
#include "error.h"
#include "exp.h"
#include "parser.h"
#include "tokenscanner.h"
#include"console.h"
using namespace std;

void compile(istream& infile,ostream& outfile);
void stackMachineOperator(Expression* src,ostream& outfile);
string pushTostack(Expression* src); // pushTostack operation

int main() {
   EvaluationContext context;
   TokenScanner scanner;
   scanner.ignoreWhitespace();
   scanner.scanNumbers();
   ifstream infile;
   ofstream outfile;
   infile.open("infile");
   outfile.open("outfile");
   compile(infile,outfile);

   return 0;
}

void compile(istream& infile,ostream& outfile){
    string tmp;
    TokenScanner scanner;
    while(true){
        getline(infile,tmp);
        if(infile.fail()) break;
        scanner.ignoreWhitespace();
        scanner.scanNumbers();
        scanner.setInput(tmp);
        Expression* exp=parseExp(scanner);
        stackMachineOperator(exp,outfile);
        outfile<<"DISPALY"<<endl;
        delete exp;
    }
}

void stackMachineOperator(Expression* src, ostream &outfile){
    if(src->getType()==CONSTANT)
        outfile<<"LOAD #"<<src->getConstantValue()<<endl;
    if(src->getType()==IDENTIFIER)
        outfile<<"LOAD "<<src->getIdentifierName()<<endl;
    if(src->getType()==COMPOUND){
        string op=src->getOperator();
        if(op=="+"||op=="-"||op=="*"||op=="/"){
            stackMachineOperator(src->getLHS(),outfile);
            stackMachineOperator(src->getRHS(),outfile);
        switch (op[0]) {
        case '-':
            outfile<<"SUB";
            break;
        case '+':
            outfile<<"ADD";
            break;
        case '*':
            outfile<<"MUL";
            break;
        case '/':
            outfile<<"DIV";
            break;
        default:
            break;
        }
        outfile<<endl;
        }
        else if(op=="="){
            stackMachineOperator(src->getRHS(),outfile);
            outfile<<"STORE "<<src->getLHS()->getIdentifierName()<<endl;
        }
    }
}
