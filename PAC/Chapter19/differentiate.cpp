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

// When using pointer in c++, you must remember to release the alloced memory.

Expression* differentiate(Expression* exp,int times);
Expression* DoOnceDifferentiate(Expression* exp);
Expression* getClone(Expression* exp);
Expression* getSimpleShow(Expression* exp);

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
         Expression *tmp=differentiate(exp,1);
         tmp=getSimpleShow(tmp);
         cout << tmp->toString()<< endl;
         delete tmp;
      } catch (ErrorException ex) {
         cerr << "Error: " << ex.getMessage() << endl;
      }
      if (exp != NULL) delete exp;
   }
   return 0;
}

Expression* differentiate(Expression* exp,int times){
    Expression* result;
    Expression* tmp=exp;
    if(exp==NULL) return NULL;
    if(times==0){
        cerr<<"Why you want zero stage differentiate?"<<endl;
        return exp;
    }
    result=DoOnceDifferentiate(tmp);
    tmp=result;
    for(int i=times-1;i>0;i--){
        result=DoOnceDifferentiate(tmp);
        delete tmp;
        tmp=result;
    }
    return result;
}



Expression* DoOnceDifferentiate(Expression* exp){
    ExpressionType type=exp->getType();
    if(type==CONSTANT) return new ConstantExp(0);
    if(type==IDENTIFIER) return new ConstantExp(1);
    if(type==COMPOUND){
        string op=exp->getOperator();
        if(op=="+"||op=="-")
            return new CompoundExp(op,DoOnceDifferentiate(exp->getLHS()),DoOnceDifferentiate(exp->getRHS()));
        if(op=="*")
            return new CompoundExp("+",new CompoundExp(op,getClone(exp->getLHS()),DoOnceDifferentiate(exp->getRHS())),
                                   new CompoundExp(op,DoOnceDifferentiate(exp->getLHS()),
                                               getClone(exp->getRHS())
                                               ));
        if(op=="/")
            return new CompoundExp("/",
                                   new CompoundExp("-",new CompoundExp("*",getClone(exp->getLHS()),DoOnceDifferentiate(exp->getRHS())),
                                               new CompoundExp("*",getClone(exp->getRHS()),
                                                               DoOnceDifferentiate(exp->getLHS())
                                                               )),
                                   new CompoundExp( "*",getClone(exp->getRHS()),getClone(exp->getRHS()) )
                                   );

    }
    error("Illegal expression type");
    return NULL;
}

Expression* getClone(Expression* exp){
    ExpressionType type=exp->getType();
    if(type==CONSTANT) return new ConstantExp(exp->getConstantValue());
    if(type==IDENTIFIER) return new IdentifierExp(exp->getIdentifierName());
    if(type==COMPOUND){
        return new CompoundExp(exp->getOperator(),getClone(exp->getLHS()),getClone(exp->getRHS()) );
    }
    error("Illegal expression type");
    return NULL;
}

Expression* getSimpleShow(Expression* exp){
    ExpressionType type=exp->getType();
    if(type==CONSTANT||type==IDENTIFIER) return getClone(exp);
    if(type==COMPOUND&&(exp->getOperator()=="*"||exp->getOperator()=="/")){
        if(exp->getLHS()->getType()==CONSTANT&&exp->getLHS()->getConstantValue()==1){
            Expression* tmp=getClone(exp->getRHS());
            return getSimpleShow(tmp);
        }
        if(exp->getRHS()->getType()==CONSTANT&&exp->getRHS()->getConstantValue()==1){
            Expression* tmp=getClone(exp->getLHS());
            return getSimpleShow(tmp);
        }
    }
    return new CompoundExp(exp->getOperator(),getSimpleShow(exp->getLHS()),getSimpleShow(exp->getRHS()));
}
