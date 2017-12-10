#include <iostream>
#include "gwindow.h"

using namespace std;
const int LENGTH=400,WIDTH=400;


void fillLineRect(GWindow & gw,int begin_pos,int whichLine,char color); //begin_pos = 0 or 1, color = 'G' 'W'

void fillLineOvel(GWindow & gw,int begin_pos_x,int whichLine,char color); //begin_pos = 0 or 1, color = 'B' 'R'

int main() {

    GWindow gw(LENGTH,WIDTH);

    for(int i=0;i<=7;i++){
        fillLineRect(gw,(i+1)%2,i,'G');
    }

    for(int i=0;i<=2;i++){
        fillLineOvel(gw,(i+1)%2,i,'R');
    }

    for(int i=5;i<=7;i++){
        fillLineOvel(gw,(i+1)%2,i,'B');
    }


    // Mission Success, But feeled not got a prefect design path, need to learn more!

    return 0;

}

void fillLineRect(GWindow & gw,int begin_pos_x,int whichLine,char color){
    if(color=='G')
        gw.setColor("LIGHT_GRAY");
    else if(color=='W')
        gw.setColor("WHITE");
    else {
        cout << "Please Enter a supported color"<<endl;
        return;
    }

    for(int i=0;i<=3;i++){
        gw.fillRect( (begin_pos_x+2*i) * (LENGTH)/8 , whichLine*WIDTH/8 , LENGTH/8,WIDTH/8);
    }

}
void fillLineOvel(GWindow & gw,int begin_pos_x,int whichLine,char color){
    if(color=='B')
        gw.setColor("BLACK");
    else if(color=='R')
        gw.setColor("RED");
    else {
        cout << "Please Enter a supported color"<<endl;
        return;
    }

    for(int i=0;i<=3;i++){
        gw.fillOval((begin_pos_x+2*i) * (LENGTH)/8 , whichLine*WIDTH/8 , LENGTH/8,WIDTH/8);
    }

}
