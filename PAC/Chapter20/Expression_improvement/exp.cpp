/*
 * File: exp.cpp
 * -------------
 * This file implements the exp.h interface.
 */

#include <string>
#include "error.h"
#include "exp.h"
#include "strlib.h"
#include"parser.h"
using namespace std;

/*
 * Implementation notes: Expression
 * --------------------------------
 * The Expression class itself implements only those methods that
 * are not designated as pure virtual methods.
 */

#define int double


Expression::Expression() {
   /* Empty */
}

Expression::~Expression() {
   /* Empty */
}

int Expression::getConstantValue() {
   error("getConstantValue: Illegal expression type");
   return 0;
}

std::string Expression::getIdentifierName() {
   error("getIdentifierName: Illegal expression type");
   return "";
}

std::string Expression::getOperator() {
   error("getOperator: Illegal expression type");
   return "";
}

Expression *Expression::getLHS() {
   error("getLHS: Illegal expression type");
   return NULL;
}

Expression *Expression::getRHS() {
   error("getRHS: Illegal expression type");
   return NULL;
}

Expression *Expression::getHS()
{
    error("getHS: Illeagal expression type");
    return NULL;
}

/*
 * Implementation notes: ConstantExp
 * ---------------------------------
 * The ConstantExp subclass represents an integer constant.  The eval
 * method simply returns that value.
 */

ConstantExp::ConstantExp(int value) {
   this->value = value;
}

int ConstantExp::eval(EvaluationContext & context) {
   return value;
}

string ConstantExp::toString() {
   return doubleToString(value);
}

ExpressionType ConstantExp::getType() {
   return CONSTANT;
}

int ConstantExp::getConstantValue() {
   return value;
}

/*
 * Implementation notes: IdentifierExp
 * -----------------------------------
 * The IdentifierExp subclass represents a variable name.  The
 * implementation of eval looks up that name in the evaluation context.
 */

IdentifierExp::IdentifierExp(string name) {
   this->name = name;
}

int IdentifierExp::eval(EvaluationContext & context) {
   if (!context.isDefined(name)) error(name + " is undefined");
   return context.getValue(context.getAddress(name));
}

string IdentifierExp::toString() {
   return name;
}

ExpressionType IdentifierExp::getType() {
   return IDENTIFIER;
}

string IdentifierExp::getIdentifierName() {
   return name;
}

/*
 * Implementation notes: CompoundExp
 * ---------------------------------
 * The implementation of eval for CompoundExp evaluates the left and right
 * subexpressions recursively and then applies the operator.  Assignment is
 * treated as a special case because it does not evaluate the left operand.
 */

CompoundExp::CompoundExp(string op, Expression *lhs, Expression *rhs) {
   this->op = op;
   this->lhs = lhs;
   this->rhs = rhs;
}

CompoundExp::~CompoundExp() {
   delete lhs;
   delete rhs;
}

int CompoundExp::eval(EvaluationContext & context) {
   int right = rhs->eval(context);
   if (op == "=") {
           context.setValue(context.getAddress(lhs->getIdentifierName()), right);
      return right;
   }
   int left = lhs->eval(context);
   if (op == "+") return left + right;
   if (op == "-") return left - right;
   if (op == "*") return left * right;
   if (op == "/") {
      if (right == 0) error("Division by 0");
      return left / right;
   }
   error("Illegal operator in expression");
   return 0;
}

string CompoundExp::toString() {
   return '(' + lhs->toString() + ' ' + op + ' ' + rhs->toString() + ')';
}

ExpressionType CompoundExp::getType() {
   return COMPOUND;
}

string CompoundExp::getOperator() {
   return op;
}

Expression *CompoundExp::getLHS() {
   return lhs;
}

Expression *CompoundExp::getRHS() {
   return rhs;
}

/*
 * Implementation notes: EvaluationContext
 * ---------------------------------------
 * The methods in the EvaluationContext class simply call the appropriate
 * method on the map used to represent the symbol table.
 */



EvaluationContext::EvaluationContext()
{
    functionTable["sin"]=sin;
    functionTable["cos"]=cos;
    functionTable["sqrt"]=sqrt;
    functionTable["log"]=log;
    functionTable["log10"]=log10;
}

bool EvaluationContext::isDefined(string var) {
    return nameMap.containsKey(var);
}

int EvaluationContext::getAddress(string name)
{
    if(!nameMap.containsKey(name)){
        nameMap.add(name,1000+nameMap.size());
    }
    return nameMap.get(name);
}

int EvaluationContext::getValue(int address)
{
    return addressMap.get(address);
}

void EvaluationContext::setValue(int address, int value)
{
    if(!addressMap.containsKey(address)){
        addressMap.add(address,value);
    }
    else
        addressMap[address]=value;
}

bool EvaluationContext::isFun(string funName)
{
    return functionTable.containsKey(funName);
}

doubleFn EvaluationContext::getFun(string funName)
{
    return functionTable.get(funName);
}


funExp::funExp(Expression *exp_, string op_)
{
    this->exp=exp_;
    this->fun=op_;
}

funExp::~funExp()
{
    if(exp!=NULL) delete exp;
}

string funExp::toString()
{
    return fun+"("+exp->toString()+")";
}

int funExp::eval(EvaluationContext &context)
{
    return context.getFun(fun)(exp->eval(context));
}

ExpressionType funExp::getType()
{
    return FUNEXP;
}

string funExp::getFunName()
{
    return fun;
}

Expression *funExp::getHS()
{
    return exp;
}

#undef int

ExpressionFunciton::ExpressionFunciton(string strExp)
{
    scanner.ignoreWhitespace();
    scanner.scanNumbers();
    scanner.setInput(strExp);
    exp=parseExp(scanner);
}

double ExpressionFunciton::operator()(double x)
{
    contest.setValue(contest.getAddress("x"),x);
    return exp->eval(contest);
}
