#include <iostream>
#include <string>
#include<iomanip>
#include<grid.h>
#include"error.h"
#include"vector.h"
#include"NimGame.h"

using namespace std;



int main() {

    NimGame game;
    game.printInstructions();
    game.play();

    return 0;
}
