#include "NimGame.h"
#include<iostream>
#include<iomanip>
#include"vector.h"
//#include"console.h"
using namespace std;

const int rowsNum=3;
const int initModel[rowsNum]={3,4,5};

/* There can still be more rows. */

const int NO_GOOD_MOVE = -1;

const int WINNING_POSITION=1000;
const int LOSING_POSITION= -WINNING_POSITION;
const int MAX_DEPTH=10;

NimGame::NimGame()
{
}


NimGame::~NimGame()
{
}

void NimGame::printInstructions()
{
    cout << "Welcome to NimGame!\n";
    cout << "If you don't know how to play this game, ask the people" << endl;
    cout << "who give you this game for help." << endl;
}

void NimGame::play()
{
    initGame();
    while (!gameIsOver())
    {
        displayGame();
        if (getCurrentPlayer() == HUMAN) {
            makeMove(getUserMove());
        }
        else {
            Move move = getComputerMove();
            displayMove(move);
            makeMove(move);
        }
        switchTurn();
    }
    announceResult();
}

void NimGame::initGame()
{
    for(int i=0;i<=rowsNum-1;i++)
        coinLeft.add(initModel[i]);

    cout << "If you want to move frist?(y/n)" << endl;
    cout << "I choose:";
    char inWord;

    while (true)
    {
        cin >> inWord;
        if (inWord == 'y') {
            whosTurn = HUMAN;
            break;
        }
        else if (inWord == 'n') {
            whosTurn = COMPUTER;
            break;
        }
        else {
            cout << "What are you doing?! enter 'y' or 'n' ,try again!" << endl;
            cout << "I choose:";
        }

    }

}

bool NimGame::gameIsOver()
{
    int tmp=0;
    for(int i=0;i<=rowsNum-1;i++)
        tmp+=coinLeft[i];
    return tmp==0;
}

void NimGame::displayGame()
{
    for(int i=0;i<=coinLeft.size()-1;i++){
        cout<<"The "<<i+1<<" row left "<<coinLeft[i]<<" coin(s)."<<endl;
    }
    cout<<endl;

}

side NimGame::getCurrentPlayer()
{
    if (whosTurn == HUMAN)
        return HUMAN;
    return COMPUTER;
}

Move NimGame::getUserMove()
{
    int coinWanted;
    int rowsWanted;
    Move thisMove;
    Vector<Move> moveList;
    generateMoveList(moveList);

    while (true)
    {
        cout<<"Which row do you want to fecth?"<<endl;
        cout << "Enter here:";
        cin >> rowsWanted;
        rowsWanted--;
        cout << "How many coins you want to take?(1-"<<coinLeft[rowsWanted]<<").";
        cout << "Enter here:";
        cin >> coinWanted;
        thisMove.nTaken=coinWanted;
        thisMove.rows=rowsWanted;
        for(Move move : moveList){
            if(move.nTaken==thisMove.nTaken&&move.rows==thisMove.rows)
                return thisMove;
        }
        cout << "Invaild number please try again!" << endl;
    }

}

void NimGame::displayMove(Move move)
{
    cout << "I will take " << move.nTaken <<" coin(s) from row "<<move.rows+1<< endl;
}


void NimGame::makeMove(Move move)
{
    coinLeft[move.rows] -= move.nTaken;

}

void NimGame::retractMove(Move move)
{

    coinLeft[move.rows]+=move.nTaken;

}

void NimGame::switchTurn()
{
    if (whosTurn == HUMAN)
        whosTurn = COMPUTER;
    else whosTurn = HUMAN;
}

void NimGame::announceResult()
{
    if ( whosTurn== HUMAN)
        cout << "You.. You dare to win this,what a genius are you!" << endl;
    else
        cout << "Poor loser! You can never win this!" << endl;
}

void NimGame::generateMoveList(Vector<Move> & moveList)
{
    for(int i=0;i<=rowsNum-1;i++){
        if(coinLeft[i]!=0)
        for(int n=1;n<=coinLeft[i];n++){
            Move move;
            move.nTaken=n;
            move.rows=i;
            moveList.add(move);
        }
    }
}

Move NimGame::getComputerMove()
{
    return findBestMove();
}

Move NimGame::findBestMove()
{
    int rating=0;
    return findBestMove(0, rating);
}

Move NimGame::findBestMove(int depth, int & rating)
{
    Vector<Move> moveList;
    Move bestMove;
    int minRating=WINNING_POSITION+1;
    generateMoveList(moveList);
    if(moveList.isEmpty()) error("No Vaild move found, program has a bug!");
    for(Move move : moveList){
        makeMove(move);
        int moveRating=evaluatePosition(depth+1);
        if(moveRating< minRating){
            bestMove=move;
            minRating=moveRating;
        }
        retractMove(move);
    }
    rating=-minRating;

    return bestMove;

}

int NimGame::evaluatePosition(int depth)
{
    if(gameIsOver() || depth >= MAX_DEPTH)
        return evaluateStaticPosition();
    int rating=0;
    findBestMove(depth,rating);  // Ignore this step that rating value is return by using &.
    return rating;
}

int NimGame::evaluateStaticPosition()
{
    if(gameIsOver()) return WINNING_POSITION;
    int tmp=0;
    for(int i=0;i<=rowsNum-1;i++){
        tmp+=coinLeft[i];
    }
    if(tmp==1) return LOSING_POSITION;

    return tmp-WINNING_POSITION;
}
