#include "NimGame.h"
#include<iostream>
#include<iomanip>
#include"vector.h"
//#include"console.h"

using namespace std;



/* There can still be more rows. */

const int NO_GOOD_MOVE = -1;

const int WINNING_POSITION=1000;
const int LOSING_POSITION= -WINNING_POSITION;
const int MAX_DEPTH=15;

NimGame::NimGame()
{
}


NimGame::~NimGame()
{
}

void NimGame::printInstructions()
{
    cout << "Welcome to TicTacToe, the game of three in a row"<<endl;
    cout << "I'll be X, and you'll be O." << endl;
    cout << "The squares are numbered like this:" << endl<<endl;
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
    for(int i=1;i<=9;i++)
        currentState.add(BLANK);

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
    side winner;
    bool IfhasWinner;

    evaluateWinner(winner,IfhasWinner);
    if(IfhasWinner) return true;

    for(int i=0;i<=currentState.size()-1;i++)
        if(currentState[i]==BLANK)
            return false;

    return true;
}

void NimGame::displayGame()
{
    for(int i=0;i<=currentState.size()-1;i++){
        switch(currentState[i]){
        case CIRCLE:
            cout<<" O |";
            break;
        case CROSS:
            cout<<" X |";
            break;
        case BLANK:
            cout<<"   |";
        }
        if(i%3==2){
            cout<<"\n";
            cout<<"---+---+---+"<<endl;
        }
    }

}

side NimGame::getCurrentPlayer()
{
    if (whosTurn == HUMAN)
        return HUMAN;
    return COMPUTER;
}

Move NimGame::getUserMove()
{
    int placeWanted;
    Move thisMove;
    Vector<Move> moveList;
    generateMoveList(moveList);
    while (true)
    {
        cout<<"where do you want to marked?"<<endl;
        cout << "Enter here:";
        cin >> placeWanted;
        placeWanted--;
        thisMove.markedPlace=placeWanted;
        for(Move move : moveList){
            if(move.markedPlace==thisMove.markedPlace)
                return thisMove;
        }
        cout << "Invaild number please try again!" << endl;
    }

}

void NimGame::displayMove(Move move)
{
    cout << "I will mark " << move.markedPlace+1 <<" place."<< endl;
}


void NimGame::makeMove(Move move)
{
    if(whosTurn==HUMAN)
        currentState[move.markedPlace]=CIRCLE;
    else
        currentState[move.markedPlace]=CROSS;

}

void NimGame::retractMove(Move move)
{
    currentState[move.markedPlace]=BLANK;

}

void NimGame::switchTurn()
{
    if (whosTurn == HUMAN)
        whosTurn = COMPUTER;
    else whosTurn = HUMAN;
}

void NimGame::announceResult()
{
    displayGame();
    side winner;
    bool ifHasWinner;
    evaluateWinner(winner,ifHasWinner);
    if(ifHasWinner)
        if(winner==HUMAN){
            cout << "You.. You dare to win this,what a genius are you!" << endl;
            return;
        }
    else{
            cout << "Poor loser! You can never win this!" << endl;
            return;
        }
    cout<<"This is a cat game!"<<endl;
}

void NimGame::evaluateWinner(side & winner, bool & IfhasWinner)
{
    graphFilled graph;
    IfhasWinner=false;
    for(int rows=0;rows<=6;rows+=3)
        if(currentState[rows]==currentState[rows+1]&&currentState[rows+1]==currentState[rows+2]
                &&currentState[rows]!=BLANK)
        {
            graph=currentState[rows];
            IfhasWinner=true;
        }
    for(int cols=0;cols<=2;cols++)
        if(currentState[cols]==currentState[cols+3]&&currentState[cols+3]==currentState[cols+6]
                &&currentState[cols]!=BLANK)
        {
            graph=currentState[cols];
            IfhasWinner=true;
        }
    if(currentState[0]==currentState[4]&&currentState[4]==currentState[8]&&currentState[0]!=BLANK)
    {
        graph=currentState[0];
        IfhasWinner=true;
    }
    if(currentState[2]==currentState[4]&&currentState[4]==currentState[6]&&currentState[2]!=BLANK)
    {
        graph=currentState[2];
        IfhasWinner=true;
    }
    if(IfhasWinner){
        switch(graph){
        case CIRCLE:
            winner=HUMAN;
            break;
        case CROSS:
            winner=COMPUTER;
            break;
        default:
            error("program error!");
        }
    }

}

void NimGame::generateMoveList(Vector<Move> & moveList)
{
    for(int i=0;i<=currentState.size()-1;i++){
        if(currentState[i]==BLANK){
            Move move;
            move.markedPlace=i;
            moveList.add(move);
        }

    }
}

bool NimGame::ifHasVectorChance(side player)
{
    return false;
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
        switchTurn();
        int moveRating=evaluatePosition(depth+1);
        if(moveRating< minRating){
            bestMove=move;
            minRating=moveRating;
        }
        switchTurn();
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
    if(whosTurn==HUMAN){
        side winner;
        bool ifHasWinner;
        evaluateWinner(winner,ifHasWinner);
        if(ifHasWinner){
            if(winner==COMPUTER)
                return LOSING_POSITION;
        }
    }
    else {
        side winner;
        bool ifHasWinner;
        evaluateWinner(winner,ifHasWinner);
        if(ifHasWinner){
            if(winner==HUMAN)
                return LOSING_POSITION;
        }
    }

    return 5;

}
