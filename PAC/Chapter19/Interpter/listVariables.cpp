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

int main() {
   EvaluationContext context;
   TokenScanner scanner;
   Expression *exp;
   scanner.ignoreWhitespace();
   scanner.scanNumbers();
   while (true) {
      exp = NULL;
      try {
         string line;
         cout << "=> ";
         getline(cin, line);
         if (line == "quit") break;
         scanner.setInput(line);
         Expression *exp = parseExp(scanner);
         listVariables(exp);
      } catch (ErrorException ex) {
         cerr << "Error: " << ex.getMessage() << endl;
      }
      if (exp != NULL) delete exp;
   }
   return 0;
}


void listVariables(Expression* exp){
    Set<string> resultSet;
    collectVariablesName(exp,resultSet);
    for(string name : resultSet){
        cout<<name<<endl;
    }
}

void collectVariablesName(Expression* exp,Set<string>& resultSet){
    if(exp->getType()==CONSTANT) return;
    if(exp->getType()==IDENTIFIER){
        resultSet.add(exp->getIdentifierName());
        return;
    }
    collectVariablesName(exp->getLHS(),resultSet);
    collectVariablesName(exp->getRHS(),resultSet);
}
