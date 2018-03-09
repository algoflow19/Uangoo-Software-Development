#include <iostream>
#include <string>
#include<assert.h>
#include<fstream>
#include"console.h"
#include"_gobjects.h"
#include"displaylist.h"
using namespace std;

int main() {

    GWindow gw;
    gw.setCanvasSize(1000,1000);
    GObject* rect1=new GRect(0,400,400,400);
    rect1->setColor("BLACK");
    GObject* rect2=new GRect(0,400,300,300);
    rect2->setColor("RED");
    GObject* rect3=new GRect(0,400,200,200);
    rect3->setColor("YELLOW");
    GObject* rect4=new GRect(0,400,100,100);
    rect4->setColor("PINK");
    DisplayList list;
    list.add(rect1);
    list.add(rect2);
    list.add(rect3);
    list.add(rect4);
    GSquare square(300,300,100);
    square.setFillFlag(true);
    square.setColor("RED");
    square.draw(gw);

    list.draw(gw);
    list.getElementAt(2,550)->draw(gw);

    return 0;
}

