#ifndef NIMGAME_H
#define NIMGAME_H
#include"vector.h"
enum side { HUMAN, COMPUTER };

struct Move {
    int rows;
    int nTaken;
};

class NimGame
{
public:
    NimGame();
    ~NimGame();

    void printInstructions();
    void play();


private:
    /* State saver*/
    Vector<int> coinLeft; // init the state in "initgame"

    side whosTurn;

    /* Play ruler fun!*/

    void initGame();
    bool gameIsOver();
    void displayGame();
    side getCurrentPlayer();
    Move getUserMove();
    void displayMove(Move move);  // Only use for computer!
    void makeMove(Move move);     // Working in background.
    void retractMove(Move move);
    void switchTurn();
    void announceResult();

    /* Computer move maker*/

    void generateMoveList(Vector<Move> & moveList);
    Move getComputerMove();
    Move findBestMove();
    Move findBestMove(int depth, int &rating);
    int evaluatePosition(int depth);
    int evaluateStaticPosition();
};


#endif // NIMGAME_H
