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
using namespace std;

bool expMatch(Expression *e1,Expression *e2);
#define comp

void BolandOutput(Expression* exp);


int main() {
   EvaluationContext context;
   TokenScanner scanner;
   Expression *exp;
   scanner.ignoreWhitespace();
   scanner.scanNumbers();
   while(true){
      try {
         string line;
         cout << "=> ";
         getline(cin, line);
         if (line == "quit") break;
         scanner.setInput(line);
         Expression *exp1 = parseExp(scanner);
         BolandOutput(exp1);
         cout<<endl;
      } catch (ErrorException ex) {
         cerr << "Error: " << ex.getMessage() << endl;
      }
   }

   return 0;
}


#ifdef simp
bool expMatch(Expression *e1,Expression *e2){
    return e1->toString()==e2->toString();
}
#endif

#ifdef comp
bool expMatch(Expression *e1,Expression *e2){
    if(e1->getType()==e2->getType()){
        if(e1->getType()==CONSTANT)
            return e1->getConstantValue()==e2->getConstantValue();
        if(e1->getType()==IDENTIFIER)
            return e1->getIdentifierName()==e2->getIdentifierName();
        if(e1->getType()==SINGLEOPEXP)
            return expMatch(e1->getHS(),e2->getHS());
        return expMatch(e1->getRHS(),e2->getRHS())&&expMatch(e1->getLHS(),e2->getLHS());
    }
    return false;
}
#endif

void BolandOutput(Expression* exp){
    ExpressionType type=exp->getType();
    if(type==CONSTANT) cout<<exp->toString()<<" ";
    else if(type==IDENTIFIER) cout<<exp->getIdentifierName()<<" ";
    else if(type==SINGLEOPEXP){
        cout<<"-";
        BolandOutput(exp->getHS());
    }
    else if(type==COMPOUND){
        BolandOutput(exp->getLHS());
        BolandOutput(exp->getRHS());
        cout<<exp->getOperator()<<" ";
    }
}
