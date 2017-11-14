#include <iostream>
#include <string>
#include<iomanip>
#include"error.h"
#include"vector.h"
#include"NimGame.h"
#include "console.h"
using namespace std;

int main() {

    NimGame game;
    game.printInstructions();
    game.play();

    return 0;
}
