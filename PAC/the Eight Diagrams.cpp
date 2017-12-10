#include <iostream>
#include "gwindow.h"

using namespace std;
const int LENGTH=600,WIDTH=600;

int main() {

    GWindow gw(LENGTH,WIDTH);

    // Set the background color
    gw.setColor("WHITE");
    gw.fillRect(0,0,LENGTH,WIDTH);
    gw.setColor("BLACK");
    gw.fillOval(0,0,LENGTH,WIDTH);
    gw.setColor("WHITE");
    gw.fillRect(0,0,LENGTH/2,WIDTH);
    gw.setColor("BLACK");
    gw.drawOval(0,0,LENGTH,WIDTH);
    gw.fillOval(LENGTH/4,WIDTH/2,LENGTH/2,WIDTH/2);
    gw.setColor("WHITE");
    gw.fillOval(LENGTH/4,0,LENGTH/2,WIDTH/2);
    gw.fillOval(7*LENGTH/16,11*WIDTH/16,LENGTH/8,WIDTH/8);
    gw.setColor("BLACK");
    gw.fillOval(7*LENGTH/16,3*WIDTH/16,LENGTH/8,WIDTH/8);


    // Mission Success, But feeled not got a prefect design path, need to learn more!

    return 0;

}
