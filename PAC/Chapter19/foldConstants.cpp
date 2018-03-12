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
Expression* constantMerge(Expression* src);


int main() {
   EvaluationContext context;
   TokenScanner scanner;
   Expression *exp;
   Expression *chexp;
   scanner.ignoreWhitespace();
   scanner.scanNumbers();
   while(true){
       exp=chexp=NULL;
      try {
         string line;
         cout << "=> ";
         getline(cin, line);
         if (line == "quit") break;
         scanner.setInput(line);
         exp = parseExp(scanner);
         chexp=constantMerge(exp1);
         cout<<constantMerge(exp1)->toString()<<endl;
      } catch (ErrorException ex) {
         cerr << "Error: " << ex.getMessage() << endl;
      }
       if(exp!=NULL) delete exp;
       if(chexp!=NULL) delete chexp;
   }

   return 0;
}

Expression* constantMerge(Expression* src){
    ExpressionType type=src->getType();
    if(type==CONSTANT) return new ConstantExp(src->getConstantValue());
    if(type==IDENTIFIER) return new IdentifierExp(src->getIdentifierName());
    // Ignore SignleOpExp to reduce complex
    if(type==COMPOUND){
        Expression *rhs,*lhs;
        rhs=constantMerge(src->getRHS());
        lhs=constantMerge(src->getLHS());
        EvaluationContext context;
        if(rhs->getType()==CONSTANT&&lhs->getType()==CONSTANT)
            return new ConstantExp(src->eval(context));
        else
            return new CompoundExp(src->getOperator(),lhs,rhs);
    }
    error("Unknow type exp!");
    return NULL;
}

