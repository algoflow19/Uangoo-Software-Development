#include "displaylist.h"

DisplayList::DisplayList()
{
}

void DisplayList::moveForward(GObject *obj)
{
    int index=getObjectIndex(obj);
    if(index==size()-1) return;
    set(index,get(index+1));
    set(index+1,obj);
    return;
}

void DisplayList::moveBackward(GObject *obj)
{
    int index=getObjectIndex(obj);
    if(index==0) return;
    set(index,get(index-1));
    set(index-1,obj);
    return;
}

void DisplayList::moveFront(GObject *obj)
{
    int index=getObjectIndex(obj);
    if(index==size()-1) return ;
    remove(index);
    add(obj);

}

void DisplayList::moveBehind(GObject *obj)
{
    int index=getObjectIndex(obj);
    if(index==0) return;
    remove(index);
    insert(0,obj);
}

void DisplayList::draw(GWindow &gw) const
{
    for(int i=0;i<size();i++)
        get(i)->draw(gw);
}

_GObject* DisplayList::getElementAt(double x, double y)
{
    for(int i=size()-1;i>=0;i--)
        if(get(i)->contains(x,y))
            return get(i);
    return NULL;
}

int DisplayList::getObjectIndex(GObject *obj) const
{
    for(int i=0;i<size();i++)
        if(get(i)==obj) return i;
    error("Can't Found target item in list");
    return -1;
}

