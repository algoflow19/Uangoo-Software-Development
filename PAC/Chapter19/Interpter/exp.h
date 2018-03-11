/*
 * File: exp.h
 * -----------
 * This interface defines a class hierarchy for arithmetic expressions.
 */

#ifndef _exp_h
#define _exp_h

#include <string>
#include "map.h"
#include "tokenscanner.h"

/* Forward reference */

#define int double

class EvaluationContext;

/*
 * Type: ExpressionType
 * --------------------
 * This enumerated type is used to differentiate the three different
 * expression types: CONSTANT, IDENTIFIER, and COMPOUND.
 */

enum ExpressionType { CONSTANT, IDENTIFIER, COMPOUND ,SINGLEOPEXP };

/*
 * Class: Expression
 * -----------------
 * This class is used to represent a node in an expression tree.
 * Expression itself is an abstract class, which means that there are
 * never any objects whose primary type is Expression.  All objects are
 * instead created using one of the three concrete subclasses:
 *
 *  1. ConstantExp   -- an integer constant
 *  2. IdentifierExp -- a string representing an identifier
 *  3. CompoundExp   -- two expressions combined by an operator
 *  4. SingleOpExp   -- one expressions combined by an operator
 * The Expression class defines the interface common to all expressions;
 * each subclass provides its own implementation of the common interface.
 */



class Expression {

public:

/*
 * Constructor: Expression
 * -----------------------
 * Specifies the constructor for the base Expression class.  Each subclass
 * defines its own constructor as well.
 */

   Expression();

/*
 * Destructor: ~Expression
 * Usage: delete exp;
 * ------------------
 * Deallocates the storage for this expression.  This method must be
 * declared virtual to ensure that the correct subclass destructor
 * is called when deleting an expression.
 */

   virtual ~Expression();

/*
 * Method: eval
 * Usage: int value = exp->eval(context);
 * --------------------------------------
 * Evaluates this expression and returns its value in the context of
 * the specified EvaluationContext object.
 */

   virtual int eval(EvaluationContext & context) = 0;

/*
 * Method: toString
 * Usage: string str = exp->toString();
 * ------------------------------------
 * Returns a string representation of this expression.
 */

   virtual std::string toString() = 0;

/*
 * Method: getType
 * Usage: ExpressionType type = exp->getType();
 * --------------------------------------------
 * Returns the type of the expression, which must be one of the constants
 * CONSTANT, IDENTIFIER, or COMPOUND.
 */

   virtual ExpressionType getType() = 0;

/*
 * Getter methods for convenience
 * ------------------------------
 * The following methods get the fields of the appropriate subclass.  Calling
 * these methods on an object of the wrong subclass generates an error.
 */

   virtual int getConstantValue();
   virtual std::string getIdentifierName();
   virtual std::string getOperator();
   virtual Expression *getLHS();
   virtual Expression *getRHS();
   virtual Expression *getHS();
};

/*
 * Subclass: ConstantExp
 * ---------------------
 * This subclass represents an integer constant.
 */

class ConstantExp : public Expression {

public:

/*
 * Constructor: ConstantExp
 * Usage: Expression *exp = new ConstantExp(value);
 * ------------------------------------------------
 * Creates a new integer constant expression.
 */

   ConstantExp(int value);

/* Prototypes for the virtual methods overridden by this class */

   virtual int eval(EvaluationContext & context);
   virtual std::string toString();
   virtual ExpressionType getType();
   virtual int getConstantValue();

private:
   int value;                   /* The value of the integer constant */

};

/*
 * Subclass: IdentifierExp
 * -----------------------
 * This subclass represents an identifier used as a variable name.
 */

class IdentifierExp : public Expression {

public:

/*
 * Constructor: IdentifierExp
 * Usage: Expression *exp = new IdentifierExp(name);
 * -------------------------------------------------
 * Creates an identifier expression with the specified name.
 */

   IdentifierExp(std::string name);

/* Prototypes for the virtual methods overridden by this class */

   virtual int eval(EvaluationContext & context);
   virtual std::string toString();
   virtual ExpressionType getType();
   virtual std::string getIdentifierName();

private:
   std::string name;            /* The name of the identifier */

};

/*
 * Subclass: CompoundExp
 * ---------------------
 * This subclass represents a compound expression consisting of
 * two subexpressions joined by an operator.
 */

class CompoundExp : public Expression {

public:

/*
 * Constructor: CompoundExp
 * Usage: Expression *exp = new CompoundExp(op, lhs, rhs);
 * -------------------------------------------------------
 * Creates a new compound expression composed of the operator (op)
 * and the left and right subexpressions (lhs and rhs).
 */

   CompoundExp(std::string op, Expression *lhs, Expression *rhs);

/* Prototypes for the virtual methods overridden by this class */

   virtual ~CompoundExp();
   virtual int eval(EvaluationContext & context);
   virtual std::string toString();
   virtual ExpressionType getType();
   virtual std::string getOperator();
   virtual Expression *getLHS();
   virtual Expression *getRHS();

private:

   std::string op;              /* The operator string (+, -, *, /)  */
   Expression *lhs, *rhs;       /* The left and right subexpression  */

};

/*
 * Class: SingleOpExp
 * ------------------
 * To support single operator exp.
 */
class SingleOpExp : public Expression{
public:

    SingleOpExp(Expression* hs,std::string op);
    virtual int eval(EvaluationContext & context);
    virtual std::string toString();
    virtual ExpressionType getType();
    virtual std::string getOperator();
    virtual Expression* getHS();
private:
   std::string op;
   Expression* hs;
};



/*
 * Class: EvaluationContext
 * ------------------------
 * This class encapsulates the information that the evaluator needs to
 * know in order to evaluate an expression.
 */

class EvaluationContext {

public:

/*
 * Method: setValue
 * Usage: context.setValue(var, value);
 * ------------------------------------
 * Sets the value associated with the specified var.
 */

   void setValue(std::string var, int value);

/*
 * Method: getValue
 * Usage: int value = context.getValue(var);
 * -----------------------------------------
 * Returns the value associated with the specified variable.
 */

   int getValue(std::string var);

/*
 * Method: isDefined
 * Usage: if (context.isDefined(var)) . . .
 * ----------------------------------------
 * Returns true if the specified variable is defined.
 */

   bool isDefined(std::string var);

private:

   Map<std::string,int> symbolTable;

};

#undef int
#endif
