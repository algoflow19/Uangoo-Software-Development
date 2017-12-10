#ifndef RATIONAL_H
#define RATIONAL_H


#include <string>
#include <iostream>

/*
 * Class: Rational
 * ---------------
 * The Rational class is used to represent rational numbers, which
 * are defined to be the quotient of two integers.
 */

class Rational {

public:

/*
 * Constructor: Rational
 * Usage: Rational zero;
 *        Rational num(n);
 *        Rational r(x, y);
 * ------------------------
 * Creates a Rational object.  The default constructor creates the
 * rational number 0.  The single-argument form creates a rational
 * number equal to the specified integer, and the two-argument form
 * creates a rational number corresponding to the fraction x/y.
 */

   Rational();
   Rational(int n);
   Rational(int x, int y);

/*
 * Method: toString()
 * Usage: string str = r.toString();
 * ---------------------------------
 * Returns the string representation of this rational number.
 */

   std::string toString() const;

/* Declare the operator functions as friends */

   friend Rational operator+(const Rational& r1,const Rational& r2);
   friend Rational operator-(const Rational& r1,const Rational& r2);
   friend Rational operator*(const Rational& r1,const Rational& r2);
   friend Rational operator/(const Rational& r1,const Rational& r2);

/* Private section */

private:

/* Instance variables */

   int num;    /* The numerator of this Rational object   */
   int den;    /* The denominator of this Rational object */

};

/*
 * Operator: <<
 * ------------
 * Overloads the << operator so that it is able to display Rational values.
 */

std::ostream & operator<<(std::ostream & os,const Rational& rat);

/*
 * Operator: +
 * Usage: r1 + r2
 * --------------
 * Overloads the + operator so that it can add rational numbers.
 */

Rational operator+(const Rational& r1,const Rational& r2);

/*
 * Operator: -
 * Usage: r1 - r2
 * --------------
 * Overloads the - operator so that it can subtract rational numbers.
 */

Rational operator-(const Rational& r1,const Rational& r2);

/*
 * Operator: *
 * Usage: r1 * r2
 * --------------
 * Overloads the * operator so that it can multiply rational numbers.
 */

Rational operator*(const Rational& r1,const Rational& r2);

/*
 * Operator: /
 * Usage: r1 / r2
 * --------------
 * Overloads the / operator so that it can divide rational numbers.
 */

Rational operator/(const Rational& r1,const Rational& r2);

#endif // RATIONAL_H
