/*
 * File: gobjects.cpp
 * ------------------
 * This file implements the gobjects.h interface.
 */

#include <string>
#include "_gobjects.h"
#include<cmath>
using namespace std;

/*
 * Implementation notes: GObject class
 * -----------------------------------
 * The constructor for the superclass sets the default color (BLACK).
 */

 GObject::GObject() {
   setColor("BLACK");
}

 void GObject::setLocation(double x, double y) {
   this->x = x;
   this->y = y;
}

 void GObject::move(double dx, double dy) {
   x += dx;
   y += dy;
}

 void GObject::setColor(string color) {
   this->color = color;
}

/*
 * Implementation notes: GLine class
 * ---------------------------------
 * The constructor for the GLine class has to change the specification
 * of the line from the endpoints passed to the constructor to the
 * representation that uses a starting point along with dx/dy values.
 */

 GLine::GLine(double x1, double y1, double x2, double y2) {
   this->x = x1;
   this->y = y1;
   this->dx = x2 - x1;
   this->dy = y2 - y1;
}

 void GLine::draw(GWindow & gw) {
   gw.setColor(color);
   gw.drawLine(x, y, x + dx, y + dy);
}

 bool GLine::contains(double x, double y)
{
    return getPointToLineLength(x,y)<0.5?true:false;
}

 double GLine::getPointToLineLength(const double& x,const double& y)
{
    double A,B,C;
    if(dx==0){
        A=1;
        B=0;
        C=-this->x;
    } else{
        A=(-1)*dy/dx;
        B=1;
        C=this->dy/this->dx-this->y;
    }
    double result=A*x+B*y+C/sqrt(A*A+B*B);
    return result<0?result*(-1):result;
}

/*
 * Implementation notes: GRect and GOval classes
 * ---------------------------------------------
 * The constructors for these classes store their arguments in the
 * corresponding instance variables.  The draw method forwards the
 * appropriate request to the GWindow class.
 */

 GRect::GRect(double x, double y, double width, double height) {
   this->x = x;
   this->y = y;
   this->width = width;
   this->height = height;
}

 void GRect::draw(GWindow & gw) {
   gw.setColor(color);
   if(filledflag)
   gw.fillRect(x, y, width, height);
   else
   gw.drawRect(x,y,width,height);

}

 bool GRect::contains(double x, double y)
{
    return x>this->x&&x<width+this->x&&y>this->y&&y<this->y+height;
}

GOval::GOval(double x, double y, double width, double height) {
   this->x = x;
   this->y = y;
   this->width = width;
   this->height = height;
   cenX=x+width/2;
   cenY=y+height/2;
   a=width/2; // half of X-ray
   b=height/2;// half of Y-ray
}

 void GOval::draw(GWindow & gw) {
   gw.setColor(color);
   if(filledflag)
   gw.fillOval(x, y, width, height);
   else
   gw.drawOval(x,y,width,height);
}

 bool GOval::contains(double x, double y)
{
    return ( (x-cenX)*(x-cenX)/(a*a)+(y-cenY)*(y-cenY)/(b*b))<1;
}

 GSquare::GSquare(double x, double y, double width): GObject()
{
    this->x=x;
    this->y=y;
    this->width=width;
}

 void GSquare::draw(GWindow &gw)
{
    gw.setColor(color);
    if(filledflag)
    gw.fillRect(x,y,width,width);
    else
    gw.drawRect(x,y,width,width);
}

 bool GSquare::contains(double x, double y)
{
    return x>this->x&&x<this->x+width&&y>this->y&&y<this->y+width;
}
