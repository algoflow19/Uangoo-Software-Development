#include<iostream>
#include"card.h"
#include<stdlib.h>
#include<cctype>
#include<sstream>

using namespace std;

int getrank(string & init){

    switch(init[0]){
    case 'A':
        return 1;
    case 'J':
        return 11;
    case 'Q':
        return 12;
    case 'K':
        return 13;
    default:
        if(init.length()>2)
            return 10;
        else
            return init[0]-'0';

    }
}

int getsuit(string init){

    switch(toupper(init[init.length()-1])){
    case 'C':
        return 0;
    case 'D':
        return 1;
    case 'H':
        return 2;
    case 'S':
        return 3;
    default:
        return 0;

    }
}

string rankToStr(int rank){

    switch(rank){
    case 1:
        return "A";
    case 11:
        return "J";
    case 12:
        return "Q";
    case 13:
        return "K";
    default:
        return "";

    }

}

string suitToStr(int suit){

    switch(suit){
    case 0:
        return "C";
    case 1:
        return "D";
    case 2:
        return "H";
    case 3:
        return "S";
    default:
        return "E";
    }
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++



Card::Card(){

}

Card::Card(int suit, int rank){

    Rank=rank;
    cardSuit=Suit(suit);

}

Card::Card(string init){

    Rank=getrank(init);
    cardSuit=Suit(getsuit(init));

}

void Card::setRank(int value){

    Rank=value;

}

void Card::setSuit(int value){

    cardSuit=Suit(value);

}

string Card::toString(){

    stringstream ss;
    string strRank,strSuit;   //The stringstream is a simple way to String num transform!
    if(Rank>1&&Rank<=10)
    ss<<Rank;
    else
        ss<<rankToStr(Rank);
    strRank=ss.str();

    strSuit=suitToStr(cardSuit);

    return strRank+strSuit;

}

Suit operator++(Suit & suit,int){
    Suit old=suit;
    suit=Suit(suit+1);
    return old;
}

Suit operator++(Suit & suit ){
    return suit=Suit(suit+1);
}


std::ostream & operator<<(std::ostream & os,Card  card){
    os<<card.toString();
    return os;
}

