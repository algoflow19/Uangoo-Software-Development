#include<iostream>
#include<string.h>
#include"strlib.h"
//#include"console.h"
#include<iomanip>// include setw() setfill() setprecision() three method!
#include<fstream>
#include "error.h"
#include"card.h"

using namespace std;


int main() {

    Card aa(1,1);
    ;
    for(Suit suit=CLUBS;suit <= SPADES;suit++){
        for(int rank=ACE;rank <= KING;rank++){
            cout<<" "<< ( Card(int(suit),rank) ) ;
        }
        cout<<endl;
    }

    return 0;
}



