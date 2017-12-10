#ifndef CARD_H
#define CARD_H
#include<iostream>
#include<string>

class Card{
public:

    Card();
    Card(int suit,int rank);
    Card(std::string init);

    std::string toString();

    int getRank();
    int getSuit();

    void setRank(int value);
    void setSuit(int value);



private:
    enum Suit { CLUBS,DIMONDS,HEARTS,SPDES } cardSuit;
    int Rank;

    friend std::ostream & operator<<(std::ostream & os,Card  card);

};

const int ACE=1;
const int JACK=11;
const int QUEEN=12;
const int KING=13;

enum Suit { CLUBS,DIMONDS,HEARTS,SPADES };

std::ostream & operator<<(std::ostream & os,Card  card);

Suit operator++(Suit & suit,int);

Suit operator++(Suit & suit );


#endif // CARD_H

