#ifndef DISPLAYLIST_H
#define DISPLAYLIST_H
#include"vector.h"
#include"_gobjects.h"

class DisplayList : public Vector<GObject* >
{
public:
    DisplayList();

    void moveForward(GObject* obj);
    void moveBackward(GObject* obj);
    void moveFront(GObject* obj);
    void moveBehind(GObject* obj);
    void draw(GWindow& gw) const;
    GObject* getElementAt(double x,double y);

private:

    int getObjectIndex(GObject* obj) const;
};

#endif // DISPLAYLIST_H
