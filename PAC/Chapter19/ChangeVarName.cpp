/*
 * File: Interpreter.cpp
 * ---------------------
 * This program simulates the top level of an expression interpreter.  The
 * program reads an expression, evaluates it, and then displays the result.
 */

#include <iostream>
#include <string>
#include "error.h"
#include "exp.h"
#include "parser.h"
#include "tokenscanner.h"
#include"console.h"
#include"set.h"
#include<string>
using namespace std;



void listVariables(Expression* exp);
void collectVariablesName(Expression* exp,Set<string>& resultSet);
Expression* changeVariable(Expression* exp,string oldName,string newName);


int main() {
   EvaluationContext context;
   TokenScanner scanner;
   Expression *exp;
   Expression *chexp;
   scanner.ignoreWhitespace();
   scanner.scanNumbers();
   while (true) {
      exp = NULL;
      chexp=NULL;
      try {
         string line;
         cout << "=> ";
         getline(cin, line);
         if (line == "quit") break;
         scanner.setInput(line);
         Expression *exp = parseExp(scanner);
         chexp=changeVariable(exp,"x","y");
         cout<<"Before:"<<exp->toString()<<endl;
         cout<<"After:"<<chexp->toString()<<endl;
      } catch (ErrorException ex) {
         cerr << "Error: " << ex.getMessage() << endl;
      }
      if (exp != NULL) delete exp;
      if (exp != NULL) delete chexp;
   }
   return 0;
}



Expression* changeVariable(Expression* exp,string oldName,string newName){
    Expression* newexp=NULL;
    if(exp->getType()==CONSTANT)
        newexp=new ConstantExp(exp->getConstantValue());
    if(exp->getType()==IDENTIFIER){
        string hereName=exp->getIdentifierName();
        if(hereName==oldName)
            newexp=new IdentifierExp(newName);
        else
            newexp=new IdentifierExp(hereName);
    }
    if(exp->getType()==COMPOUND)
    newexp=new CompoundExp(exp->getOperator(),changeVariable(exp->getLHS(),oldName,newName),
                           changeVariable(exp->getRHS(),oldName,newName));
    if(newexp==NULL) error("Unknow exp type!");
    return newexp;
}

