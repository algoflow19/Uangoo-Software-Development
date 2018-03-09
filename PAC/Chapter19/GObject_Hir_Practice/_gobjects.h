/*
 * File: gobjects.h
 * ----------------
 * This file defines a simple hierarchy of graphical objects.
 */

#ifndef _gobjects_h
#define _gobjects_h

#include <string>
#include "gwindow.h"
#include "conflicts.h"

/*
 * Class: GFillable
 * ----------------
 * This class is for showing if the GObject could be filled or not!
 */
class GFillable{
public:
    GFillable(){
        filledflag=false;
    }
    void setFillFlag(bool flag){
        filledflag=flag;
    }

protected:

    bool filledflag;
};






/*
 * Class: GObject
 * --------------
 * This class is the root of the hierarchy and encompasses all objects
 * that can be displayed in a window.
 */

class GObject {

public:

/*
 * Method: setLocation
 * Usage: gobj.setLocation(x, y);
 * ------------------------------
 * Sets the x and y coordinates of gobj to the specified values.
 */

   void setLocation(double x, double y);

/*
 * Method: move
 * Usage: gobj.move(dx, dy);
 * -------------------------
 * Adds dx and dy to the coordinates of the gobj.
 */

   void move(double x, double y);

/*
 * Method: setColor
 * Usage: gobj.setColor(color);
 * ----------------------------
 * Sets the color of the gobj.  The names of the available colors are
 * described in the gwindow.h interface.
 */

   void setColor(std::string color);

/*
 * Abstract method: draw
 * Usage: gobj.draw(gw);
 * ---------------------
 * Draws the graphical object on the GraphicsWindow specified by gw.
 * This method is implemented by the specific GObject subclasses.
 */

   virtual void draw(GWindow & gw) = 0;
   virtual bool contains(double x,double y) = 0;

protected:

/* The following methods and fields are available to the subclasses    */

   GObject();                        /* Superclass constructor         */
   std::string color;                /* The color of the object        */
   double x, y;                      /* The coordinates of the object  */

};

/*
 * Subclass: GLine
 * ---------------
 * The GLine subclass represents a line segment on the window.
 */

class GLine : public GObject {

public:

/*
 * Constructor: GLine
 * Usage: GLine line(x1, y1, x2, y2);
 * ----------------------------------
 * Creates a line segment that extends from (x1, y1) to (x2, y2).
 */

   GLine(double x1, double y1, double x2, double y2);

/* Prototypes for the overridden virtual methods */

   virtual void draw(GWindow & gw);
   virtual bool contains(double x,double y);
private:
   double dx;                      /* Horizontal distance from x1 to x2    */
   double dy;                      /* Vertical distance from y1 to y2      */

   double getPointToLineLength(const double& x,const double& y);
};

/*
 * Subclass: GRect
 * ---------------
 * The GRect subclass represents a rectangle.
 */

class GRect : public GObject ,public GFillable{

public:

/*
 * Constructor: GRect
 * Usage: GRect rect(x, y, width, height);
 * ---------------------------------------
 * Creates a rectangle of the specified size whose upper left corner is (x, y).
 */

   GRect(double x, double y, double width, double height);

/* Prototypes for the overridden virtual methods */

   virtual void draw(GWindow & gw);
   virtual bool contains(double x,double y);

private:
   double width, height;           /* Dimensions of the rectangle          */

};

/*
 * Subclass: GOval
 * ---------------
 * The GOval subclass represents an oval defined by a bounding rectangle.
 */

class GOval : public GObject ,public GFillable{

public:

/*
 * Constructor: GOval
 * Usage: GOval oval(x, y, width, height);
 * ---------------------------------------
 * Creates an oval that fits inside the rectangle indicated by the arguments.
 */

   GOval(double x, double y, double width, double height);

/* Prototypes for the overridden virtual methods */

   virtual void draw(GWindow & gw);
   virtual bool contains(double x,double y);

private:
   double width, height;           /* Dimensions of the bounding rectangle */
   double cenX,cenY;
   double a,b;
};

class GSquare : public GObject,public GFillable{
public:
    GSquare(double x, double y, double width);
    virtual void draw(GWindow &gw);
    virtual bool contains(double x,double y);
private:
    double width;
};


#endif
